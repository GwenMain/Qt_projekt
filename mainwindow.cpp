#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include "imagepickerdialog.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeDatabase();
    // Připojení signálu změny indexu combo boxu k odpovídajícímu slotu
    connect(ui->genreComboBox, &QComboBox::currentTextChanged, this, &MainWindow::on_genreComboBox_currentIndexChanged);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchTextChanged);


    ui->searchModeComboBox->addItems({"Název", "Studio", "Rok vydání"});

    ui->searchModeComboBox->setCurrentIndex(0); // Nastavení "Název" jako výchozí
    ui->tableWidget->setSortingEnabled(true);
    // Inicializace databáze


    // Inicializace combo boxu pro filtrování žánrů
    populateGenreComboBox();

    // Načtení všech her do tabulky
    loadGames();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("games.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Chyba", "Nelze otevřít databázi: " + db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS games ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "studio TEXT, "
               "release_year INTEGER, "
               "genre TEXT, "
               "rating INTEGER, "
               "image_path TEXT)");
}


void MainWindow::loadGames()
{
    ui->tableWidget->setSortingEnabled(false);

    QSqlQuery query("SELECT id, name, studio, release_year, genre, rating, image_path FROM games ORDER BY rating DESC");

    if (!query.exec()) {
        qDebug() << "Chyba při načítání her: " << query.lastError().text();
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);


    ui->tableWidget->setColumnCount(7); // Počet sloupců
    ui->tableWidget->setHorizontalHeaderLabels({"Obrázek", "Název hry", "Studio", "Rok vydání", "Žánr", "Hodnocení", "Akce"});

    int row = 0;
    while (query.next()) {
        qDebug() << "Načítám hru: " << query.value("name").toString();
        ui->tableWidget->insertRow(row);

        // Obrázek
        QString imagePath = query.value(6).toString();
        if (!imagePath.isEmpty()) {
            QPixmap pixmap(imagePath);
            QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel *imageLabel = new QLabel();
            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setAlignment(Qt::AlignCenter);
            ui->tableWidget->setCellWidget(row, 0, imageLabel);
        }

        // Textové hodnoty
        QStringList values = {query.value(1).toString(), query.value(2).toString(),
                              query.value(3).toString(), query.value(4).toString(),
                              query.value(5).toString()};

        for (int col = 1; col <= 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col - 1]);
            item->setFont(QFont("Arial", 12));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(row, col, item);
        }

        // Akce (tlačítka)
        int gameId = query.value(0).toInt();
        QWidget *buttonWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(buttonWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(5);

        QPushButton *deleteButton = new QPushButton();
        deleteButton->setIcon(QIcon(":/resources/delete.png"));
        deleteButton->setIconSize(QSize(32, 32));
        deleteButton->setToolTip("Smazat hru");
        connect(deleteButton, &QPushButton::clicked, [this, gameId]() {
            onDeleteGameButtonClicked(gameId);
        });

        QPushButton *editButton = new QPushButton();
        editButton->setIcon(QIcon(":/resources/settings.png"));
        editButton->setIconSize(QSize(32, 32));
        editButton->setToolTip("Upravit hru");
        connect(editButton, &QPushButton::clicked, [this, gameId]() {
            onEditGameButtonClicked(gameId);
        });

        layout->addWidget(deleteButton);
        layout->addWidget(editButton);
        ui->tableWidget->setCellWidget(row, 6, buttonWidget);

        ui->tableWidget->setRowHeight(row, 100);
        ++row;
    }

    ui->tableWidget->setSortingEnabled(true); // Znovu povolí řazení po načtení dat
}










void MainWindow::addGame(const QString &name, const QString &studio, int year, const QString &genre, int rating, const QString &imagePath)
{
    QSqlQuery query;
    query.prepare("INSERT INTO games (name, studio, release_year, genre, rating, image_path) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(studio);
    query.addBindValue(year);
    query.addBindValue(genre);
    query.addBindValue(rating);
    query.addBindValue(imagePath.isEmpty() ? QVariant::fromValue(QString()) : imagePath);

    if (!query.exec()) {
        qDebug() << "Error inserting game:" << query.lastError().text();
    } else {
        loadGames(); // Načtení dat do tabulky
    }
}

void MainWindow::on_addGameButton_clicked()
{
    AddGameDialog dialog(this);

    // Otevření dialogu a zpracování výstupu
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString studio = dialog.getStudio();
        int year = dialog.getYear();
        QString genre = dialog.getGenre();
        QString imagePath = dialog.getImagePath();
        int rating = dialog.getRating();

        // Kontrola povinných polí
        if (name.isEmpty() || studio.isEmpty()) {
            QMessageBox::warning(this, "Chyba", "Název hry a Studio nesmí být prázdné.");
            return;
        }

        // Přidání hry do databáze
        addGame(name, studio, year, genre, rating, imagePath);

        // Potvrzení přidání
        QMessageBox::information(this, "Hotovo", "Hra byla úspěšně přidána.");
    }
}






void MainWindow::populateGenreComboBox()
{
    // Vyprázdnění combo boxu
    ui->genreComboBox->clear();

    // Přidání pevně definovaných žánrů
    ui->genreComboBox->addItems({
        "Všechny",  // Možnost zobrazit všechny hry
        "RPG",
        "FPS",
        "Strategy",
        "Adventure",
        "Simulation",
        "Sports",
        "Puzzle",
        "Horror"
    });

    // Nastavení "Všechny" jako výchozí volby
    ui->genreComboBox->setCurrentIndex(0);
}

void MainWindow::on_genreComboBox_currentIndexChanged(const QString &genre)
{
    ui->tableWidget->setSortingEnabled(false); // Zakázat řazení

    if (genre == "Všechny") {
        loadGames(); // Zobrazit všechny hry
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id, name, studio, release_year, genre, rating, image_path FROM games WHERE genre = ?");
    query.addBindValue(genre);

    if (!query.exec()) {
        qDebug() << "Error filtering games by genre:" << query.lastError().text();
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Obrázek
        QString imagePath = query.value(6).toString();
        if (!imagePath.isEmpty()) {
            QPixmap pixmap(imagePath);
            QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel *imageLabel = new QLabel();
            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setAlignment(Qt::AlignCenter);
            ui->tableWidget->setCellWidget(row, 0, imageLabel);
        }

        // Textové hodnoty
        QStringList values = {query.value(1).toString(), query.value(2).toString(),
                              query.value(3).toString(), query.value(4).toString(),
                              query.value(5).toString()};

        for (int col = 1; col <= 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col - 1]);
            item->setFont(QFont("Arial", 12));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(row, col, item);
        }

        // Akce (tlačítka)
        int gameId = query.value(0).toInt();
        QWidget *buttonWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(buttonWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(5);

        QPushButton *deleteButton = new QPushButton();
        deleteButton->setIcon(QIcon(":/resources/delete.png"));
        deleteButton->setIconSize(QSize(32, 32));
        deleteButton->setToolTip("Smazat hru");
        connect(deleteButton, &QPushButton::clicked, [this, gameId]() {
            onDeleteGameButtonClicked(gameId);
        });

        QPushButton *editButton = new QPushButton();
        editButton->setIcon(QIcon(":/resources/settings.png"));
        editButton->setIconSize(QSize(32, 32));
        editButton->setToolTip("Upravit hru");
        connect(editButton, &QPushButton::clicked, [this, gameId]() {
            onEditGameButtonClicked(gameId);
        });

        layout->addWidget(deleteButton);
        layout->addWidget(editButton);
        ui->tableWidget->setCellWidget(row, 6, buttonWidget);

        ui->tableWidget->setRowHeight(row, 100);
        ++row;
    }

    ui->tableWidget->setSortingEnabled(true); // Povolí řazení
}




void MainWindow::on_searchTextChanged(const QString &searchText)
{
    ui->tableWidget->setSortingEnabled(false); // Zakázat řazení

    QString queryStr;

    if (searchText.trimmed().isEmpty()) {
        loadGames(); // Zobrazit všechny hry
        ui->tableWidget->setSortingEnabled(true); // Povolí řazení
        return;
    }

    QString searchMode = ui->searchModeComboBox->currentText();
    if (searchMode == "Název") {
        queryStr = "SELECT id, name, studio, release_year, genre, rating, image_path FROM games WHERE name LIKE ?";
    } else if (searchMode == "Studio") {
        queryStr = "SELECT id, name, studio, release_year, genre, rating, image_path FROM games WHERE studio LIKE ?";
    } else if (searchMode == "Rok vydání") {
        queryStr = "SELECT id, name, studio, release_year, genre, rating, image_path FROM games WHERE release_year LIKE ?";
    }

    QSqlQuery query;
    query.prepare(queryStr);
    query.addBindValue("%" + searchText.trimmed() + "%");

    if (!query.exec()) {
        qDebug() << "Error searching games dynamically:" << query.lastError().text();
        ui->tableWidget->setSortingEnabled(true); // Povolí řazení
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Obrázek
        QString imagePath = query.value(6).toString();
        if (!imagePath.isEmpty()) {
            QPixmap pixmap(imagePath);
            QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel *imageLabel = new QLabel();
            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setAlignment(Qt::AlignCenter);
            ui->tableWidget->setCellWidget(row, 0, imageLabel);
        }

        // Textové hodnoty
        QStringList values = {query.value(1).toString(), query.value(2).toString(),
                              query.value(3).toString(), query.value(4).toString(),
                              query.value(5).toString()};

        for (int col = 1; col <= 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col - 1]);
            item->setFont(QFont("Arial", 12));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(row, col, item);
        }

        // Akce (tlačítka)
        int gameId = query.value(0).toInt();
        QWidget *buttonWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(buttonWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(5);

        QPushButton *deleteButton = new QPushButton();
        deleteButton->setIcon(QIcon(":/resources/delete.png"));
        deleteButton->setIconSize(QSize(32, 32));
        deleteButton->setToolTip("Smazat hru");
        connect(deleteButton, &QPushButton::clicked, [this, gameId]() {
            onDeleteGameButtonClicked(gameId);
        });

        QPushButton *editButton = new QPushButton();
        editButton->setIcon(QIcon(":/resources/settings.png"));
        editButton->setIconSize(QSize(32, 32));
        editButton->setToolTip("Upravit hru");
        connect(editButton, &QPushButton::clicked, [this, gameId]() {
            onEditGameButtonClicked(gameId);
        });

        layout->addWidget(deleteButton);
        layout->addWidget(editButton);
        ui->tableWidget->setCellWidget(row, 6, buttonWidget);

        ui->tableWidget->setRowHeight(row, 100);
        ++row;
    }

    ui->tableWidget->setSortingEnabled(true); // Povolí řazení
}





void MainWindow::onDeleteGameButtonClicked(int gameId)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Smazat hru",
                                                              "Opravdu chcete smazat tuto hru?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM games WHERE id = ?");
        query.addBindValue(gameId);

        if (!query.exec()) {
            qDebug() << "Chyba při mazání hry:" << query.lastError().text();
        } else {
            loadGames();
        }
    }
}

void MainWindow::onEditGameButtonClicked(int gameId)
{
    QSqlQuery query;
    query.prepare("SELECT name, studio, release_year, genre, rating, image_path FROM games WHERE id = ?");
    query.addBindValue(gameId);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Chyba", "Nelze načíst data hry.");
        return;
    }

    // Získání dat z databáze
    QString name = query.value(0).toString();
    QString studio = query.value(1).toString();
    int year = query.value(2).toInt();
    QString genre = query.value(3).toString();
    int rating = query.value(4).toInt();
    QString imagePath = query.value(5).toString();

    // Otevření dialogu pro úpravu
    EditGameDialog dialog(this);
    dialog.setGameData(name, studio, year, genre, rating, imagePath);

    if (dialog.exec() == QDialog::Accepted) {
        // Získání aktualizovaných hodnot
        QString updatedName = dialog.getName();
        QString updatedStudio = dialog.getStudio();
        int updatedYear = dialog.getYear();
        QString updatedGenre = dialog.getGenre();
        int updatedRating = dialog.getRating();
        QString updatedImagePath = dialog.getImagePath();

        // Aktualizace v databázi
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE games SET name = ?, studio = ?, release_year = ?, genre = ?, rating = ?, image_path = ? WHERE id = ?");
        updateQuery.addBindValue(updatedName);
        updateQuery.addBindValue(updatedStudio);
        updateQuery.addBindValue(updatedYear);
        updateQuery.addBindValue(updatedGenre);
        updateQuery.addBindValue(updatedRating);
        updateQuery.addBindValue(updatedImagePath.isEmpty() ? QVariant::fromValue(QString()) : updatedImagePath);
        updateQuery.addBindValue(gameId);

        if (!updateQuery.exec()) {
            QMessageBox::warning(this, "Chyba", "Aktualizace hry selhala: " + updateQuery.lastError().text());
        } else {
            loadGames();
            QMessageBox::information(this, "Hotovo", "Hra byla úspěšně aktualizována.");
        }
    }
}




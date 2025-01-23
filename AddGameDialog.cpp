#include "addgamedialog.h"
#include "ui_addgamedialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "utils.h"


AddGameDialog::AddGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGameDialog)
{
    ui->setupUi(this);

    // Nastavení výchozích hodnot
    ui->yearSpinBox->setRange(1980, 2030); // Nastavení rozsahu pro rok vydání
    ui->ratingSpinBox->setRange(1, 5);     // Nastavení rozsahu pro hodnocení

    // Přidání pevně daných žánrů do ComboBoxu
    ui->genreComboBox->addItems({"RPG", "FPS", "Strategy", "Adventure", "Simulation", "Sports", "Puzzle", "Horror"});

    // Připojení tlačítek OK a Cancel k akcím dialogu
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

AddGameDialog::~AddGameDialog()
{
    delete ui;
}

QString AddGameDialog::getName() const
{
    return ui->nameLineEdit->text();
}

QString AddGameDialog::getStudio() const
{
    return ui->studioLineEdit->text();
}

int AddGameDialog::getYear() const
{
    return ui->yearSpinBox->value();
}

QString AddGameDialog::getGenre() const
{
    return ui->genreComboBox->currentText();
}


QString AddGameDialog::getImagePath() const {
    if (!imagePath.isEmpty()) {
        QString copiedPath = copyImageToAppFolder(imagePath); // Zkopíruje obrázek
        return copiedPath;
    }
    return "";
}


int AddGameDialog::getRating() const
{
    return ui->ratingSpinBox->value();
}

void AddGameDialog::on_browseButton_clicked() {
    QString file = QFileDialog::getOpenFileName(this, "Vyberte obrázek hry", "", "Obrázky (*.png *.jpg *.jpeg *.bmp)");
    if (!file.isEmpty()) {
        imagePath = file; // Uloží pouze původní cestu
        ui->imageLineEdit->setText(file); // Zobrazí cestu v uživatelském rozhraní
    }
}



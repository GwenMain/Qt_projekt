#include "editgamedialog.h"
#include "ui_editgamedialog.h"
#include <QFileDialog>

EditGameDialog::EditGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGameDialog)
{
    ui->setupUi(this);

    // Nastavení rozsahu a výchozích hodnot
    ui->editYearSpinBox->setRange(1980, 2030);
    ui->editRatingSpinBox->setRange(1, 5);

    // Přidání pevně definovaných žánrů
    ui->editGenreComboBox->addItems({"RPG", "FPS", "Strategy", "Adventure", "Simulation", "Sports", "Puzzle", "Horror"});

    // Připojení tlačítek OK a Cancel
    connect(ui->editButtonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->editButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

EditGameDialog::~EditGameDialog()
{
    delete ui;
}

void EditGameDialog::setGameData(const QString &name, const QString &studio, int year, const QString &genre, int rating, const QString &imagePath)
{
    ui->editNameLineEdit->setText(name);
    ui->editStudioLineEdit->setText(studio);
    ui->editYearSpinBox->setValue(year);
    ui->editGenreComboBox->setCurrentText(genre);
    ui->editRatingSpinBox->setValue(rating);
    ui->editImageLineEdit->setText(imagePath);
    this->imagePath = imagePath;
}

QString EditGameDialog::getName() const
{
    return ui->editNameLineEdit->text();
}

QString EditGameDialog::getStudio() const
{
    return ui->editStudioLineEdit->text();
}

int EditGameDialog::getYear() const
{
    return ui->editYearSpinBox->value();
}

QString EditGameDialog::getGenre() const
{
    return ui->editGenreComboBox->currentText();
}

QString EditGameDialog::getImagePath() const
{
    return imagePath;
}

int EditGameDialog::getRating() const
{
    return ui->editRatingSpinBox->value();
}

void EditGameDialog::on_editBrowseButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Vyberte obrázek hry", "", "Obrázky (*.png *.jpg *.jpeg *.bmp)");
    if (!file.isEmpty()) {
        imagePath = file;
        ui->editImageLineEdit->setText(file);
    }
}

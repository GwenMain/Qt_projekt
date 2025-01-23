#include "editgamedialog.h"
#include "ui_editgamedialog.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QUuid>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include "utils.h"


EditGameDialog::EditGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGameDialog)
{
    ui->setupUi(this);

    // Připojení tlačítek OK a Cancel
    connect(ui->editButtonBox, &QDialogButtonBox::accepted, this, &EditGameDialog::accept);
    connect(ui->editButtonBox, &QDialogButtonBox::rejected, this, &EditGameDialog::reject);

    // Naplnění ComboBoxu pro žánr
    ui->editGenreComboBox->addItems({
        "RPG", "FPS", "Strategy", "Adventure", "Simulation",
        "Sports", "Puzzle", "Horror"
    });
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

    originalImagePath = imagePath; // Uložení původní cesty obrázku
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

int EditGameDialog::getRating() const
{
    return ui->editRatingSpinBox->value();
}

QString EditGameDialog::getImagePath() const
{
    QString currentImagePath = ui->editImageLineEdit->text();

    // Pokud je cesta nová (není shodná s původní), zkopírujte obrázek
    if (!currentImagePath.isEmpty() && currentImagePath != originalImagePath) {
        QString copiedPath = copyImageToAppFolder(currentImagePath); // Zkopíruje obrázek do složky aplikace
        return copiedPath; // Vrátí novou cestu
    }

    // Pokud je cesta prázdná, znamená to, že byl obrázek odstraněn
    if (currentImagePath.isEmpty()) {
        return ""; // Vrátí prázdnou cestu
    }

    // Pokud se cesta nezměnila, vrátí původní cestu
    return originalImagePath;
}

void EditGameDialog::on_editBrowseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Vyberte obrázek", QString(), "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!filePath.isEmpty()) {
        ui->editImageLineEdit->setText(filePath); // Zobrazí cestu v uživatelském rozhraní
    }
}


void EditGameDialog::on_clearImageButton_clicked()
{
    ui->editImageLineEdit->clear(); // Vyprázdnění pole cesty
}


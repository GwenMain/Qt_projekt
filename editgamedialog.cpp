#include "editgamedialog.h"
#include "ui_editgamedialog.h"
#include <QFileDialog>

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
    return ui->editImageLineEdit->text();
}

void EditGameDialog::on_editBrowseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Vyberte obrázek", QString(), "Images (*.png *.xpm *.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        ui->editImageLineEdit->setText(filePath);
    }
}

void EditGameDialog::on_clearImageButton_clicked()
{
    ui->editImageLineEdit->clear(); // Vymaže text v poli
}

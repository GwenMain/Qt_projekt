#include "imagepickerdialog.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QLabel>

ImagePickerDialog::ImagePickerDialog(QWidget *parent)
    : QDialog(parent), selectedImagePath("")
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Popisek
    QLabel *label = new QLabel("Vyberte obrázek hry nebo pokračujte bez obrázku:");
    mainLayout->addWidget(label);

    // Řádek pro zobrazení cesty obrázku
    imagePathLineEdit = new QLineEdit(this);
    imagePathLineEdit->setPlaceholderText("Cesta k obrázku...");
    imagePathLineEdit->setReadOnly(true);
    mainLayout->addWidget(imagePathLineEdit);

    // Tlačítko pro procházení
    QPushButton *browseButton = new QPushButton("Procházet", this);
    connect(browseButton, &QPushButton::clicked, this, &ImagePickerDialog::onBrowseClicked);
    mainLayout->addWidget(browseButton);

    // Tlačítka pro potvrzení
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    buttonLayout->addWidget(okButton);

    QPushButton *continueButton = new QPushButton("Pokračovat bez obrázku", this);
    connect(continueButton, &QPushButton::clicked, this, &ImagePickerDialog::onContinueWithoutImage);
    buttonLayout->addWidget(continueButton);

    QPushButton *cancelButton = new QPushButton("Zrušit", this);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);
}

QString ImagePickerDialog::getImagePath() const
{
    return selectedImagePath;
}

void ImagePickerDialog::onBrowseClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Vyberte obrázek", "", "Obrázky (*.png *.jpg *.jpeg *.bmp)");
    if (!filePath.isEmpty()) {
        imagePathLineEdit->setText(filePath);
        selectedImagePath = filePath;
    }
}

void ImagePickerDialog::onContinueWithoutImage()
{
    selectedImagePath = ""; // Žádný obrázek
    accept();
}

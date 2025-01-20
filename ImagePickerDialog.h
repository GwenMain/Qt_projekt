#ifndef IMAGEPICKERDIALOG_H
#define IMAGEPICKERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class ImagePickerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImagePickerDialog(QWidget *parent = nullptr);
    QString getImagePath() const;

private slots:
    void onBrowseClicked();
    void onContinueWithoutImage();

private:
    QLineEdit *imagePathLineEdit;
    QString selectedImagePath;
};

#endif // IMAGEPICKERDIALOG_H

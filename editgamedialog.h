#ifndef EDITGAMEDIALOG_H
#define EDITGAMEDIALOG_H

#include <QDialog>
#include <QString>



namespace Ui {
class EditGameDialog;
}

class EditGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditGameDialog(QWidget *parent = nullptr);
    ~EditGameDialog();

    void setGameData(const QString &name, const QString &studio, int year, const QString &genre, int rating, const QString &imagePath);
    QString getName() const;
    QString getStudio() const;
    int getYear() const;
    QString getGenre() const;
    int getRating() const;
    QString getImagePath() const;

private slots:
    void on_editBrowseButton_clicked();
    void on_clearImageButton_clicked();


private:
    Ui::EditGameDialog *ui;
    QString originalImagePath;
};

#endif // EDITGAMEDIALOG_H

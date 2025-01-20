#ifndef EDITGAMEDIALOG_H
#define EDITGAMEDIALOG_H

#include <QDialog>

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
    QString getImagePath() const;
    int getRating() const;

private slots:
    void on_editBrowseButton_clicked();

private:
    Ui::EditGameDialog *ui;
    QString imagePath;
};

#endif // EDITGAMEDIALOG_H

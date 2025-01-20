#ifndef ADDGAMEDIALOG_H
#define ADDGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class AddGameDialog;
}

class AddGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGameDialog(QWidget *parent = nullptr);
    ~AddGameDialog();

    QString getName() const;
    QString getStudio() const;
    int getYear() const;
    QString getGenre() const;
    QString getImagePath() const;
    int getRating() const;

private slots:
    void on_browseButton_clicked();

private:
    Ui::AddGameDialog *ui;
    QString imagePath;
};

#endif // ADDGAMEDIALOG_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "addgamedialog.h"
#include "editgamedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addGameButton_clicked();
    void on_genreComboBox_currentIndexChanged(const QString &genre);
    void on_searchTextChanged(const QString &searchText);
    void onDeleteGameButtonClicked(int gameId);
    void onEditGameButtonClicked(int gameId);



private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    void initializeDatabase();
    void loadGames();
    void addGame(const QString &name, const QString &studio, int year, const QString &genre, int rating, const QString &imagePath);
    void populateGenreComboBox();
};

#endif // MAINWINDOW_H

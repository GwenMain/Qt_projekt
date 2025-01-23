#include "utils.h"
#include <QFile>
#include <QDir>
#include <QUuid>
#include <QFileInfo>
#include <QDebug>
#include <QCoreApplication>


QString copyImageToAppFolder(const QString &sourcePath) {
    if (sourcePath.isEmpty()) {
        return "";
    }

    QString appFolder = QCoreApplication::applicationDirPath() + "/../../images";
    QDir().mkpath(appFolder); // Vytvoří složku, pokud neexistuje

    QString uniqueName = QUuid::createUuid().toString(QUuid::Id128) + "." + QFileInfo(sourcePath).suffix();
    QString destinationPath = appFolder + "/" + uniqueName;

    if (QFile::copy(sourcePath, destinationPath)) {
        return destinationPath;
    } else {
        qDebug() << "Chyba při kopírování souboru z" << sourcePath << "do" << destinationPath;
        return "";
    }
}

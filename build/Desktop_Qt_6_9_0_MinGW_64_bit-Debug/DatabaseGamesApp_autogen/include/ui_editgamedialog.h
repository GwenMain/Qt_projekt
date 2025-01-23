/********************************************************************************
** Form generated from reading UI file 'editgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITGAMEDIALOG_H
#define UI_EDITGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditGameDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_9;
    QLineEdit *editNameLineEdit;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_10;
    QLineEdit *editStudioLineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_11;
    QComboBox *editGenreComboBox;
    QLabel *label_12;
    QSpinBox *editYearSpinBox;
    QLabel *label_13;
    QSpinBox *editRatingSpinBox;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_14;
    QLineEdit *editImageLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *editBrowseButton;
    QPushButton *clearImageButton;
    QDialogButtonBox *editButtonBox;

    void setupUi(QDialog *EditGameDialog)
    {
        if (EditGameDialog->objectName().isEmpty())
            EditGameDialog->setObjectName("EditGameDialog");
        EditGameDialog->resize(500, 350);
        gridLayout = new QGridLayout(EditGameDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(EditGameDialog);
        label_8->setObjectName("label_8");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Shape::NoFrame);
        label_8->setFrameShadow(QFrame::Shadow::Plain);
        label_8->setLineWidth(2);
        label_8->setMidLineWidth(0);
        label_8->setTextFormat(Qt::TextFormat::AutoText);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8->setMargin(3);
        label_8->setIndent(0);

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        label_9 = new QLabel(EditGameDialog);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        editNameLineEdit = new QLineEdit(EditGameDialog);
        editNameLineEdit->setObjectName("editNameLineEdit");

        verticalLayout_5->addWidget(editNameLineEdit);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        label_10 = new QLabel(EditGameDialog);
        label_10->setObjectName("label_10");

        verticalLayout_5->addWidget(label_10);

        editStudioLineEdit = new QLineEdit(EditGameDialog);
        editStudioLineEdit->setObjectName("editStudioLineEdit");

        verticalLayout_5->addWidget(editStudioLineEdit);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_11 = new QLabel(EditGameDialog);
        label_11->setObjectName("label_11");

        verticalLayout_6->addWidget(label_11);

        editGenreComboBox = new QComboBox(EditGameDialog);
        editGenreComboBox->setObjectName("editGenreComboBox");

        verticalLayout_6->addWidget(editGenreComboBox);

        label_12 = new QLabel(EditGameDialog);
        label_12->setObjectName("label_12");

        verticalLayout_6->addWidget(label_12);

        editYearSpinBox = new QSpinBox(EditGameDialog);
        editYearSpinBox->setObjectName("editYearSpinBox");
        editYearSpinBox->setMinimum(1900);
        editYearSpinBox->setMaximum(2030);
        editYearSpinBox->setValue(2025);

        verticalLayout_6->addWidget(editYearSpinBox);

        label_13 = new QLabel(EditGameDialog);
        label_13->setObjectName("label_13");

        verticalLayout_6->addWidget(label_13);

        editRatingSpinBox = new QSpinBox(EditGameDialog);
        editRatingSpinBox->setObjectName("editRatingSpinBox");
        editRatingSpinBox->setMaximum(5);
        editRatingSpinBox->setValue(3);

        verticalLayout_6->addWidget(editRatingSpinBox);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        label_14 = new QLabel(EditGameDialog);
        label_14->setObjectName("label_14");

        verticalLayout_4->addWidget(label_14);

        editImageLineEdit = new QLineEdit(EditGameDialog);
        editImageLineEdit->setObjectName("editImageLineEdit");
        editImageLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        editImageLineEdit->setReadOnly(true);

        verticalLayout_4->addWidget(editImageLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        editBrowseButton = new QPushButton(EditGameDialog);
        editBrowseButton->setObjectName("editBrowseButton");

        horizontalLayout->addWidget(editBrowseButton);

        clearImageButton = new QPushButton(EditGameDialog);
        clearImageButton->setObjectName("clearImageButton");

        horizontalLayout->addWidget(clearImageButton);


        verticalLayout_4->addLayout(horizontalLayout);

        editButtonBox = new QDialogButtonBox(EditGameDialog);
        editButtonBox->setObjectName("editButtonBox");
        editButtonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_4->addWidget(editButtonBox);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(EditGameDialog);

        QMetaObject::connectSlotsByName(EditGameDialog);
    } // setupUi

    void retranslateUi(QDialog *EditGameDialog)
    {
        EditGameDialog->setWindowTitle(QCoreApplication::translate("EditGameDialog", "Editace", nullptr));
        label_8->setText(QCoreApplication::translate("EditGameDialog", "Editov\303\241n\303\255 hry", nullptr));
        label_9->setText(QCoreApplication::translate("EditGameDialog", "N\303\241zev", nullptr));
        label_10->setText(QCoreApplication::translate("EditGameDialog", "Studio", nullptr));
        label_11->setText(QCoreApplication::translate("EditGameDialog", "\305\275\303\241nr", nullptr));
        label_12->setText(QCoreApplication::translate("EditGameDialog", "Rok vyd\303\241n\303\255", nullptr));
        label_13->setText(QCoreApplication::translate("EditGameDialog", "Hodnocen\303\255", nullptr));
        label_14->setText(QCoreApplication::translate("EditGameDialog", "Obr\303\241zek / ikonka hry (nepovinn\303\251)", nullptr));
        editImageLineEdit->setText(QCoreApplication::translate("EditGameDialog", "Cesta k obr\303\241zku", nullptr));
        editBrowseButton->setText(QCoreApplication::translate("EditGameDialog", "Proch\303\241zet...", nullptr));
        clearImageButton->setText(QCoreApplication::translate("EditGameDialog", "Zru\305\241it cestu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditGameDialog: public Ui_EditGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITGAMEDIALOG_H

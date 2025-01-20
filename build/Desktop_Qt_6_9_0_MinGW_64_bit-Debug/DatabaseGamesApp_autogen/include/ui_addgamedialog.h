/********************************************************************************
** Form generated from reading UI file 'addgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGAMEDIALOG_H
#define UI_ADDGAMEDIALOG_H

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

class Ui_AddGameDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLineEdit *studioLineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *genreComboBox;
    QLabel *label_4;
    QSpinBox *yearSpinBox;
    QLabel *label_6;
    QSpinBox *ratingSpinBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLineEdit *imageLineEdit;
    QPushButton *browseButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddGameDialog)
    {
        if (AddGameDialog->objectName().isEmpty())
            AddGameDialog->setObjectName("AddGameDialog");
        AddGameDialog->resize(500, 350);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddGameDialog->sizePolicy().hasHeightForWidth());
        AddGameDialog->setSizePolicy(sizePolicy);
        AddGameDialog->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        gridLayout = new QGridLayout(AddGameDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_7 = new QLabel(AddGameDialog);
        label_7->setObjectName("label_7");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setFrameShadow(QFrame::Shadow::Plain);
        label_7->setLineWidth(2);
        label_7->setMidLineWidth(0);
        label_7->setTextFormat(Qt::TextFormat::AutoText);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7->setMargin(3);
        label_7->setIndent(0);

        verticalLayout_3->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(AddGameDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(AddGameDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        verticalLayout->addWidget(nameLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_2 = new QLabel(AddGameDialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        studioLineEdit = new QLineEdit(AddGameDialog);
        studioLineEdit->setObjectName("studioLineEdit");

        verticalLayout->addWidget(studioLineEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(AddGameDialog);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        genreComboBox = new QComboBox(AddGameDialog);
        genreComboBox->setObjectName("genreComboBox");

        verticalLayout_2->addWidget(genreComboBox);

        label_4 = new QLabel(AddGameDialog);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        yearSpinBox = new QSpinBox(AddGameDialog);
        yearSpinBox->setObjectName("yearSpinBox");
        yearSpinBox->setMinimum(1900);
        yearSpinBox->setMaximum(2030);
        yearSpinBox->setValue(2025);

        verticalLayout_2->addWidget(yearSpinBox);

        label_6 = new QLabel(AddGameDialog);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        ratingSpinBox = new QSpinBox(AddGameDialog);
        ratingSpinBox->setObjectName("ratingSpinBox");
        ratingSpinBox->setMaximum(5);
        ratingSpinBox->setValue(3);

        verticalLayout_2->addWidget(ratingSpinBox);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_5 = new QLabel(AddGameDialog);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        imageLineEdit = new QLineEdit(AddGameDialog);
        imageLineEdit->setObjectName("imageLineEdit");
        imageLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        imageLineEdit->setReadOnly(true);

        verticalLayout_3->addWidget(imageLineEdit);

        browseButton = new QPushButton(AddGameDialog);
        browseButton->setObjectName("browseButton");

        verticalLayout_3->addWidget(browseButton);

        buttonBox = new QDialogButtonBox(AddGameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_3->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(AddGameDialog);

        QMetaObject::connectSlotsByName(AddGameDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGameDialog)
    {
        AddGameDialog->setWindowTitle(QCoreApplication::translate("AddGameDialog", "P\305\231id\303\241n\303\255 nov\303\251 hry", nullptr));
        label_7->setText(QCoreApplication::translate("AddGameDialog", "P\305\231id\303\241n\303\255 nov\303\251 hry", nullptr));
        label->setText(QCoreApplication::translate("AddGameDialog", "N\303\241zev", nullptr));
        label_2->setText(QCoreApplication::translate("AddGameDialog", "Studio", nullptr));
        label_3->setText(QCoreApplication::translate("AddGameDialog", "\305\275\303\241nr", nullptr));
        label_4->setText(QCoreApplication::translate("AddGameDialog", "Rok vyd\303\241n\303\255", nullptr));
        label_6->setText(QCoreApplication::translate("AddGameDialog", "Hodnocen\303\255", nullptr));
        label_5->setText(QCoreApplication::translate("AddGameDialog", "Obr\303\241zek / ikonka hry (nepovinn\303\251)", nullptr));
        imageLineEdit->setText(QCoreApplication::translate("AddGameDialog", "Cesta k obr\303\241zku", nullptr));
        browseButton->setText(QCoreApplication::translate("AddGameDialog", "Proch\303\241zet...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGameDialog: public Ui_AddGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGAMEDIALOG_H

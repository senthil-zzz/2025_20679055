/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *nameEdit;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QSpinBox *spinBox;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_2;
    QWidget *formLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName("OptionDialog");
        OptionDialog->resize(400, 237);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 190, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        nameEdit = new QLineEdit(OptionDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(0, 0, 401, 21));
        formLayoutWidget = new QWidget(OptionDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 50, 331, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName("spinBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, spinBox);

        spinBox_3 = new QSpinBox(formLayoutWidget);
        spinBox_3->setObjectName("spinBox_3");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, spinBox_3);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName("spinBox_2");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, spinBox_2);

        formLayoutWidget_2 = new QWidget(OptionDialog);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(10, 49, 41, 121));
        verticalLayout = new QVBoxLayout(formLayoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget_2);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Swis721 BlkEx BT")});
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);


        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, OptionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, OptionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QCoreApplication::translate("OptionDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("OptionDialog", "R", nullptr));
        label_2->setText(QCoreApplication::translate("OptionDialog", "G", nullptr));
        label_3->setText(QCoreApplication::translate("OptionDialog", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H

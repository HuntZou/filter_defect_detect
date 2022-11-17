/********************************************************************************
** Form generated from reading UI file 'doublecameraconfig.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLECAMERACONFIG_H
#define UI_DOUBLECAMERACONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleCameraConfig
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_8;

    void setupUi(QDialog *DoubleCameraConfig)
    {
        if (DoubleCameraConfig->objectName().isEmpty())
            DoubleCameraConfig->setObjectName(QString::fromUtf8("DoubleCameraConfig"));
        DoubleCameraConfig->resize(414, 300);
        buttonBox = new QDialogButtonBox(DoubleCameraConfig);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(DoubleCameraConfig);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 40, 291, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spinBox_3 = new QSpinBox(formLayoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_3);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton = new QRadioButton(formLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(formLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(false);

        horizontalLayout->addWidget(radioButton_2);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(9999.000000000000000);
        doubleSpinBox->setValue(20.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        doubleSpinBox_2 = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setValue(8.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_2);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);


        retranslateUi(DoubleCameraConfig);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DoubleCameraConfig, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DoubleCameraConfig, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DoubleCameraConfig);
    } // setupUi

    void retranslateUi(QDialog *DoubleCameraConfig)
    {
        DoubleCameraConfig->setWindowTitle(QCoreApplication::translate("DoubleCameraConfig", "\345\217\214\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("DoubleCameraConfig", "\347\224\237\344\272\247\351\200\237\347\216\207", nullptr));
        label_2->setText(QCoreApplication::translate("DoubleCameraConfig", "\351\275\277\350\275\256\351\227\264\350\267\235", nullptr));
        label_3->setText(QCoreApplication::translate("DoubleCameraConfig", "\347\233\270\346\234\2721\344\275\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("DoubleCameraConfig", "\347\233\270\346\234\2722\344\275\215\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("DoubleCameraConfig", "\351\231\244\346\235\202\345\231\250\344\275\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("DoubleCameraConfig", "\344\275\277\347\224\250\346\226\271\345\274\217", nullptr));
        radioButton->setText(QCoreApplication::translate("DoubleCameraConfig", "\345\271\266\350\241\214\346\243\200\346\265\213", nullptr));
        radioButton_2->setText(QCoreApplication::translate("DoubleCameraConfig", "\345\206\227\344\275\231\346\243\200\346\265\213", nullptr));
        doubleSpinBox->setSuffix(QString());
        label_7->setText(QCoreApplication::translate("DoubleCameraConfig", "/min", nullptr));
        label_8->setText(QCoreApplication::translate("DoubleCameraConfig", "mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleCameraConfig: public Ui_DoubleCameraConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLECAMERACONFIG_H

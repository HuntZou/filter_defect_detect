/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionddd;
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_12;
    QLabel *label_16;
    QLineEdit *status;
    QLabel *label_17;
    QLineEdit *defect;
    QLabel *label_6;
    QLineEdit *cost;
    QFormLayout *formLayout_13;
    QLabel *label_28;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_18;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *p1;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *p2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *p3;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *p4;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *p5;
    QLineEdit *lineEdit_9;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_4;
    QGridLayout *shapeGrid;
    QPushButton *COIN;
    QPushButton *PEACH;
    QPushButton *STAR;
    QPushButton *HEART_BIG;
    QPushButton *WINTERSWEET_SMALL;
    QPushButton *CIRCLE;
    QPushButton *RAY;
    QPushButton *HEART_SMALL;
    QPushButton *WINTERSWEET_BIG;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *layoutWidget;
    QFormLayout *formLayout_15;
    QLabel *label_23;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QSlider *FN_detach_threshold_slider;
    QSpinBox *FN_detach_threshold_input;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_15;
    QPushButton *shapeParmsReset;
    QHBoxLayout *horizontalLayout_5;
    QSlider *defect_threshold_slider;
    QSpinBox *defect_threshold_input;
    QLabel *label_5;
    QSlider *resize_filter_img_slider;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QPushButton *saveImage;
    QPushButton *pushButton_4;
    QPushButton *Stop;
    QPushButton *Start;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_14;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QPushButton *pushButton_6;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SingleGrab;
    QPushButton *Attribute;
    QPushButton *double_camera_config_btn;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_17;
    QLabel *label_26;
    QLineEdit *lineEdit_22;
    QLabel *label_27;
    QLineEdit *lineEdit_23;
    QLabel *label_29;
    QLineEdit *lineEdit_27;
    QLabel *label_25;
    QLineEdit *lineEdit_21;
    QFormLayout *formLayout_16;
    QLabel *label_24;
    QLineEdit *lineEdit_20;
    QLabel *label_14;
    QLineEdit *lineEdit_4;
    QLabel *label_20;
    QLineEdit *lineEdit_5;
    QLabel *label_21;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_4;
    QLabel *pic2;
    QLabel *pic1;
    QGroupBox *groupBox_6;
    QLabel *label_8;
    QLabel *label_11;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        actionddd = new QAction(MainWindow);
        actionddd->setObjectName(QString::fromUtf8("actionddd"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(50, 350, 561, 153));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_16);

        status = new QLineEdit(gridLayoutWidget_2);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFocusPolicy(Qt::NoFocus);
        status->setAutoFillBackground(false);
        status->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 102,76);\n"
"color: rgb(255, 255, 255);"));

        formLayout_12->setWidget(0, QFormLayout::FieldRole, status);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_12->setWidget(1, QFormLayout::LabelRole, label_17);

        defect = new QLineEdit(gridLayoutWidget_2);
        defect->setObjectName(QString::fromUtf8("defect"));
        defect->setFocusPolicy(Qt::NoFocus);

        formLayout_12->setWidget(1, QFormLayout::FieldRole, defect);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_12->setWidget(2, QFormLayout::LabelRole, label_6);

        cost = new QLineEdit(gridLayoutWidget_2);
        cost->setObjectName(QString::fromUtf8("cost"));
        cost->setFocusPolicy(Qt::NoFocus);

        formLayout_12->setWidget(2, QFormLayout::FieldRole, cost);


        gridLayout_2->addLayout(formLayout_12, 0, 2, 1, 1);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QString::fromUtf8("formLayout_13"));
        label_28 = new QLabel(gridLayoutWidget_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_28);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_13->setWidget(1, QFormLayout::LabelRole, label_2);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_13->setWidget(2, QFormLayout::LabelRole, label);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_13->setWidget(3, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_13->setWidget(4, QFormLayout::LabelRole, label_19);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        p1 = new QLineEdit(gridLayoutWidget_2);
        p1->setObjectName(QString::fromUtf8("p1"));
        p1->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_7->addWidget(p1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_7->addWidget(lineEdit_2);


        formLayout_13->setLayout(0, QFormLayout::FieldRole, horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        p2 = new QLineEdit(gridLayoutWidget_2);
        p2->setObjectName(QString::fromUtf8("p2"));
        p2->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_8->addWidget(p2);

        lineEdit_3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_8->addWidget(lineEdit_3);


        formLayout_13->setLayout(1, QFormLayout::FieldRole, horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        p3 = new QLineEdit(gridLayoutWidget_2);
        p3->setObjectName(QString::fromUtf8("p3"));
        p3->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_9->addWidget(p3);

        lineEdit_7 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_9->addWidget(lineEdit_7);


        formLayout_13->setLayout(2, QFormLayout::FieldRole, horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        p4 = new QLineEdit(gridLayoutWidget_2);
        p4->setObjectName(QString::fromUtf8("p4"));
        p4->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_10->addWidget(p4);

        lineEdit_8 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_10->addWidget(lineEdit_8);


        formLayout_13->setLayout(3, QFormLayout::FieldRole, horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        p5 = new QLineEdit(gridLayoutWidget_2);
        p5->setObjectName(QString::fromUtf8("p5"));
        p5->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_11->addWidget(p5);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_11->addWidget(lineEdit_9);


        formLayout_13->setLayout(4, QFormLayout::FieldRole, horizontalLayout_11);


        gridLayout_2->addLayout(formLayout_13, 0, 3, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(650, 10, 331, 331));
        gridLayoutWidget_4 = new QWidget(groupBox);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 30, 311, 161));
        shapeGrid = new QGridLayout(gridLayoutWidget_4);
        shapeGrid->setObjectName(QString::fromUtf8("shapeGrid"));
        shapeGrid->setContentsMargins(0, 0, 0, 0);
        COIN = new QPushButton(gridLayoutWidget_4);
        COIN->setObjectName(QString::fromUtf8("COIN"));
        COIN->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(COIN, 2, 0, 1, 1);

        PEACH = new QPushButton(gridLayoutWidget_4);
        PEACH->setObjectName(QString::fromUtf8("PEACH"));
        PEACH->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(PEACH, 2, 2, 1, 1);

        STAR = new QPushButton(gridLayoutWidget_4);
        STAR->setObjectName(QString::fromUtf8("STAR"));
        STAR->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(STAR, 0, 2, 1, 1);

        HEART_BIG = new QPushButton(gridLayoutWidget_4);
        HEART_BIG->setObjectName(QString::fromUtf8("HEART_BIG"));
        HEART_BIG->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(HEART_BIG, 1, 0, 1, 1);

        WINTERSWEET_SMALL = new QPushButton(gridLayoutWidget_4);
        WINTERSWEET_SMALL->setObjectName(QString::fromUtf8("WINTERSWEET_SMALL"));
        WINTERSWEET_SMALL->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(WINTERSWEET_SMALL, 0, 1, 1, 1);

        CIRCLE = new QPushButton(gridLayoutWidget_4);
        CIRCLE->setObjectName(QString::fromUtf8("CIRCLE"));
        CIRCLE->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(CIRCLE, 1, 2, 1, 1);

        RAY = new QPushButton(gridLayoutWidget_4);
        RAY->setObjectName(QString::fromUtf8("RAY"));
        RAY->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(RAY, 2, 1, 1, 1);

        HEART_SMALL = new QPushButton(gridLayoutWidget_4);
        HEART_SMALL->setObjectName(QString::fromUtf8("HEART_SMALL"));
        HEART_SMALL->setMinimumSize(QSize(0, 30));
        HEART_SMALL->setCheckable(false);
        HEART_SMALL->setAutoDefault(false);
        HEART_SMALL->setFlat(false);

        shapeGrid->addWidget(HEART_SMALL, 0, 0, 1, 1);

        WINTERSWEET_BIG = new QPushButton(gridLayoutWidget_4);
        WINTERSWEET_BIG->setObjectName(QString::fromUtf8("WINTERSWEET_BIG"));
        WINTERSWEET_BIG->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(WINTERSWEET_BIG, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(pushButton_2, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(pushButton_7, 3, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget_4);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 30));

        shapeGrid->addWidget(pushButton_8, 3, 2, 1, 1);

        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 200, 311, 123));
        formLayout_15 = new QFormLayout(layoutWidget);
        formLayout_15->setObjectName(QString::fromUtf8("formLayout_15"));
        formLayout_15->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        formLayout_15->setWidget(0, QFormLayout::LabelRole, label_23);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_15->setWidget(1, QFormLayout::LabelRole, label_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        FN_detach_threshold_slider = new QSlider(layoutWidget);
        FN_detach_threshold_slider->setObjectName(QString::fromUtf8("FN_detach_threshold_slider"));
        FN_detach_threshold_slider->setMaximum(254);
        FN_detach_threshold_slider->setValue(185);
        FN_detach_threshold_slider->setTracking(false);
        FN_detach_threshold_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(FN_detach_threshold_slider);

        FN_detach_threshold_input = new QSpinBox(layoutWidget);
        FN_detach_threshold_input->setObjectName(QString::fromUtf8("FN_detach_threshold_input"));
        FN_detach_threshold_input->setMaximum(254);
        FN_detach_threshold_input->setValue(185);

        horizontalLayout_3->addWidget(FN_detach_threshold_input);


        formLayout_15->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_15->setWidget(3, QFormLayout::LabelRole, label_12);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_15 = new QPushButton(layoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        horizontalLayout_4->addWidget(pushButton_15);

        shapeParmsReset = new QPushButton(layoutWidget);
        shapeParmsReset->setObjectName(QString::fromUtf8("shapeParmsReset"));

        horizontalLayout_4->addWidget(shapeParmsReset);


        formLayout_15->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        defect_threshold_slider = new QSlider(layoutWidget);
        defect_threshold_slider->setObjectName(QString::fromUtf8("defect_threshold_slider"));
        defect_threshold_slider->setMaximum(3000);
        defect_threshold_slider->setValue(1000);
        defect_threshold_slider->setTracking(false);
        defect_threshold_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(defect_threshold_slider);

        defect_threshold_input = new QSpinBox(layoutWidget);
        defect_threshold_input->setObjectName(QString::fromUtf8("defect_threshold_input"));
        defect_threshold_input->setMaximum(3000);
        defect_threshold_input->setValue(1000);

        horizontalLayout_5->addWidget(defect_threshold_input);


        formLayout_15->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_15->setWidget(2, QFormLayout::LabelRole, label_5);

        resize_filter_img_slider = new QSlider(layoutWidget);
        resize_filter_img_slider->setObjectName(QString::fromUtf8("resize_filter_img_slider"));
        resize_filter_img_slider->setMaximum(1600);
        resize_filter_img_slider->setValue(1000);
        resize_filter_img_slider->setTracking(true);
        resize_filter_img_slider->setOrientation(Qt::Horizontal);
        resize_filter_img_slider->setTickPosition(QSlider::TicksBelow);

        formLayout_15->setWidget(2, QFormLayout::FieldRole, resize_filter_img_slider);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(650, 350, 331, 171));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 31, 311, 131));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        saveImage = new QPushButton(layoutWidget1);
        saveImage->setObjectName(QString::fromUtf8("saveImage"));
        saveImage->setMinimumSize(QSize(0, 50));

        gridLayout_4->addWidget(saveImage, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 50));

        gridLayout_4->addWidget(pushButton_4, 1, 0, 1, 1);

        Stop = new QPushButton(layoutWidget1);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Stop->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Stop->sizePolicy().hasHeightForWidth());
        Stop->setSizePolicy(sizePolicy);
        Stop->setMinimumSize(QSize(0, 50));
        Stop->setAutoDefault(false);
        Stop->setFlat(false);

        gridLayout_4->addWidget(Stop, 0, 1, 1, 1);

        Start = new QPushButton(layoutWidget1);
        Start->setObjectName(QString::fromUtf8("Start"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(Start->sizePolicy().hasHeightForWidth());
        Start->setSizePolicy(sizePolicy1);
        Start->setMinimumSize(QSize(0, 50));
        Start->setBaseSize(QSize(0, 0));

        gridLayout_4->addWidget(Start, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(650, 530, 331, 171));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 311, 121));
        formLayout_14 = new QFormLayout(layoutWidget2);
        formLayout_14->setObjectName(QString::fromUtf8("formLayout_14"));
        formLayout_14->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_14->setWidget(0, QFormLayout::LabelRole, label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_2 = new QRadioButton(layoutWidget2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(layoutWidget2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);


        formLayout_14->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_14->setWidget(1, QFormLayout::LabelRole, label_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(lineEdit);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_6->addWidget(label_13);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_6->addWidget(pushButton_6);


        formLayout_14->setLayout(1, QFormLayout::FieldRole, horizontalLayout_6);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_14->setWidget(2, QFormLayout::LabelRole, label_3);

        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        formLayout_14->setWidget(2, QFormLayout::FieldRole, pushButton_5);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_14->setWidget(3, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        SingleGrab = new QPushButton(layoutWidget2);
        SingleGrab->setObjectName(QString::fromUtf8("SingleGrab"));

        horizontalLayout_2->addWidget(SingleGrab);

        Attribute = new QPushButton(layoutWidget2);
        Attribute->setObjectName(QString::fromUtf8("Attribute"));

        horizontalLayout_2->addWidget(Attribute);

        double_camera_config_btn = new QPushButton(layoutWidget2);
        double_camera_config_btn->setObjectName(QString::fromUtf8("double_camera_config_btn"));

        horizontalLayout_2->addWidget(double_camera_config_btn);


        formLayout_14->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(50, 510, 561, 191));
        gridLayoutWidget_3 = new QWidget(groupBox_5);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 541, 151));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_17 = new QFormLayout();
        formLayout_17->setObjectName(QString::fromUtf8("formLayout_17"));
        label_26 = new QLabel(gridLayoutWidget_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        formLayout_17->setWidget(1, QFormLayout::LabelRole, label_26);

        lineEdit_22 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setFocusPolicy(Qt::NoFocus);

        formLayout_17->setWidget(1, QFormLayout::FieldRole, lineEdit_22);

        label_27 = new QLabel(gridLayoutWidget_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        formLayout_17->setWidget(2, QFormLayout::LabelRole, label_27);

        lineEdit_23 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setFocusPolicy(Qt::NoFocus);

        formLayout_17->setWidget(2, QFormLayout::FieldRole, lineEdit_23);

        label_29 = new QLabel(gridLayoutWidget_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        formLayout_17->setWidget(3, QFormLayout::LabelRole, label_29);

        lineEdit_27 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));
        lineEdit_27->setFocusPolicy(Qt::NoFocus);

        formLayout_17->setWidget(3, QFormLayout::FieldRole, lineEdit_27);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout_17->setWidget(0, QFormLayout::LabelRole, label_25);

        lineEdit_21 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setFocusPolicy(Qt::NoFocus);

        formLayout_17->setWidget(0, QFormLayout::FieldRole, lineEdit_21);


        gridLayout_3->addLayout(formLayout_17, 0, 3, 1, 1);

        formLayout_16 = new QFormLayout();
        formLayout_16->setObjectName(QString::fromUtf8("formLayout_16"));
        label_24 = new QLabel(gridLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        formLayout_16->setWidget(0, QFormLayout::LabelRole, label_24);

        lineEdit_20 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setFocusPolicy(Qt::NoFocus);

        formLayout_16->setWidget(0, QFormLayout::FieldRole, lineEdit_20);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_16->setWidget(1, QFormLayout::LabelRole, label_14);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFocusPolicy(Qt::NoFocus);

        formLayout_16->setWidget(1, QFormLayout::FieldRole, lineEdit_4);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_16->setWidget(2, QFormLayout::LabelRole, label_20);

        lineEdit_5 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFocusPolicy(Qt::NoFocus);

        formLayout_16->setWidget(2, QFormLayout::FieldRole, lineEdit_5);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_16->setWidget(3, QFormLayout::LabelRole, label_21);

        lineEdit_6 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFocusPolicy(Qt::NoFocus);

        formLayout_16->setWidget(3, QFormLayout::FieldRole, lineEdit_6);


        gridLayout_3->addLayout(formLayout_16, 0, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 1, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(50, 20, 271, 291));
        pic2 = new QLabel(groupBox_4);
        pic2->setObjectName(QString::fromUtf8("pic2"));
        pic2->setGeometry(QRect(0, 20, 271, 271));
        pic2->setPixmap(QPixmap(QString::fromUtf8("resource/placeholder1.jpg")));
        pic2->setScaledContents(true);
        pic2->setWordWrap(true);
        pic1 = new QLabel(groupBox_4);
        pic1->setObjectName(QString::fromUtf8("pic1"));
        pic1->setGeometry(QRect(0, 20, 104, 80));
        pic1->setPixmap(QPixmap(QString::fromUtf8("resource/placeholder2.jpg")));
        pic1->setScaledContents(true);
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(340, 20, 271, 291));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 20, 271, 271));
        label_8->setPixmap(QPixmap(QString::fromUtf8("resource/placeholder1.jpg")));
        label_8->setScaledContents(true);
        label_8->setWordWrap(true);
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 20, 104, 80));
        label_11->setPixmap(QPixmap(QString::fromUtf8("resource/placeholder2.jpg")));
        label_11->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionddd);
        menu->addAction(action);
        menu_2->addAction(action_2);

        retranslateUi(MainWindow);

        HEART_SMALL->setDefault(false);
        Stop->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\277\207\346\273\244\345\230\264\346\210\252\351\235\242\347\221\225\347\226\265\346\243\200\346\265\213", nullptr));
        actionddd->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\346\211\200\345\234\250\344\275\215\347\275\256", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\351\205\215\347\275\256\346\226\207\344\273\266\344\275\215\347\275\256", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\227\245\345\277\227\346\226\207\344\273\266\345\244\271", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        status->setText(QCoreApplication::translate("MainWindow", "Bad", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\221\225\347\226\265\351\207\217", nullptr));
        defect->setText(QCoreApplication::translate("MainWindow", "1280", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\350\200\227\346\227\266", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\344\270\200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\344\272\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\344\270\211", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\345\233\233", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\344\272\224", nullptr));
        p1->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        p2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        p3->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        p4->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        p5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\345\233\276\345\275\242", nullptr));
        COIN->setText(QCoreApplication::translate("MainWindow", "\351\223\234\345\270\201\345\275\242", nullptr));
        PEACH->setText(QCoreApplication::translate("MainWindow", "\346\241\203\345\275\242", nullptr));
        STAR->setText(QCoreApplication::translate("MainWindow", "\344\272\224\350\247\222\346\230\237", nullptr));
        HEART_BIG->setText(QCoreApplication::translate("MainWindow", "\345\277\203\345\275\242\357\274\210\345\244\247\357\274\211", nullptr));
        WINTERSWEET_SMALL->setText(QCoreApplication::translate("MainWindow", "\346\242\205\350\212\261\357\274\210\345\260\217\357\274\211", nullptr));
        CIRCLE->setText(QCoreApplication::translate("MainWindow", "\345\234\206\345\275\242", nullptr));
        RAY->setText(QCoreApplication::translate("MainWindow", "\345\260\204\347\272\277\345\275\242", nullptr));
        HEART_SMALL->setText(QCoreApplication::translate("MainWindow", "\345\277\203\345\275\242\357\274\210\345\260\217\357\274\211", nullptr));
        WINTERSWEET_BIG->setText(QCoreApplication::translate("MainWindow", "\346\242\205\350\212\261\357\274\210\345\244\247\357\274\211", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\344\270\211\350\247\222\345\275\242", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "W\345\275\242", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\345\256\236\345\277\203", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\347\221\225\347\226\265\351\230\210\345\200\274", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\211\215\346\231\257\345\210\206\347\246\273", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
        shapeParmsReset->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\345\244\247\345\260\217", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\265\201\347\250\213\346\216\247\345\210\266", nullptr));
        saveImage->setText(QCoreApplication::translate("MainWindow", "\346\212\223\346\213\215\344\277\235\345\255\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\215\225\345\272\224\347\237\253\346\255\243", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242 Stop", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213 Start", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\200\350\256\276\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\247\246\345\217\221\346\226\271\345\274\217", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\344\277\241\345\217\267\351\207\217", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\212\223\346\213\215\351\200\237\347\216\207", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ps", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\213\215\346\240\241\345\207\206", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\212\223\346\213\215\345\217\226\347\202\271", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\350\256\276\345\256\232", nullptr));
        SingleGrab->setText(QCoreApplication::translate("MainWindow", "\345\215\225\345\274\240\346\212\223\345\217\226", nullptr));
        Attribute->setText(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247\350\256\276\347\275\256", nullptr));
        double_camera_config_btn->setText(QCoreApplication::translate("MainWindow", "\345\217\214\347\233\270\346\234\272", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\350\211\257\345\223\201\351\207\217", nullptr));
        lineEdit_22->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\345\212\243\345\223\201\351\207\217", nullptr));
        lineEdit_23->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\350\211\257\345\223\201\347\216\207", nullptr));
        lineEdit_27->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\211\271\346\254\241\351\207\217", nullptr));
        lineEdit_21->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\346\200\273\351\207\217", nullptr));
        lineEdit_20->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\350\211\257\345\223\201\351\207\217", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\345\212\243\345\223\201\351\207\217", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\350\211\257\345\223\201\347\216\207", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Camera 1", nullptr));
        pic2->setText(QString());
        pic1->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Camera 2", nullptr));
        label_8->setText(QString());
        label_11->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

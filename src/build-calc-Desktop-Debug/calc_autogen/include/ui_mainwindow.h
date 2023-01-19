/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_14;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QGridLayout *gridLayout;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(822, 499);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #333;\n"
"\n"
"    }\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_14 = new QGridLayout(centralwidget);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lineEdit);


        gridLayout_14->addLayout(verticalLayout, 0, 0, 1, 3);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButton_33 = new QPushButton(centralwidget);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(pushButton_33, 0, 0, 1, 1);

        pushButton_34 = new QPushButton(centralwidget);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        sizePolicy3.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(pushButton_34, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_12, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_3);


        gridLayout_14->addLayout(horizontalLayout, 3, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        sizePolicy3.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(pushButton_13, 0, 0, 1, 1);

        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy3.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(pushButton_14, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_2, 3, 2, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        pushButton_29 = new QPushButton(centralwidget);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        sizePolicy3.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(pushButton_29, 0, 0, 1, 1);

        pushButton_30 = new QPushButton(centralwidget);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        sizePolicy3.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(pushButton_30, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_10, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_5);


        gridLayout_14->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy3.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(pushButton_15, 0, 0, 1, 1);

        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy3.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(pushButton_16, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_3, 4, 2, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        pushButton_31 = new QPushButton(centralwidget);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        sizePolicy3.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy3);

        gridLayout_11->addWidget(pushButton_31, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(centralwidget);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        sizePolicy3.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy3);

        gridLayout_11->addWidget(pushButton_32, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_11, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_9);


        gridLayout_14->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        sizePolicy3.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pushButton_17, 0, 0, 1, 1);

        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        sizePolicy3.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pushButton_18, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_4, 5, 2, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_35 = new QPushButton(centralwidget);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
        sizePolicy3.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_36 = new QPushButton(centralwidget);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
        sizePolicy3.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(pushButton_36, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 6, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy3.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_11, 0, 0, 1, 1);

        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy3.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_12, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy3.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_10, 0, 2, 1, 1);


        gridLayout_14->addLayout(gridLayout, 6, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        sizePolicy3.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_19, 0, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_5, 6, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        pushButton_37 = new QPushButton(centralwidget);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
        sizePolicy3.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(pushButton_37);

        pushButton_38 = new QPushButton(centralwidget);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
        sizePolicy3.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(pushButton_38);


        gridLayout_14->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_35->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_36->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_38->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

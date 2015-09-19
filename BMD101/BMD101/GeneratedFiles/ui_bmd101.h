/********************************************************************************
** Form generated from reading UI file 'bmd101.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMD101_H
#define UI_BMD101_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_BMD101Class
{
public:
    QWidget *centralWidget;
    QGroupBox *ControlGroupBox;
    QPushButton *BaseDataButton;
    QPushButton *ChartButton;
    QPushButton *SettingButton;
    QGroupBox *ShowGroupBox;
    QWidget *BaseDataWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *RawWaveVaueLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *PoorSignalQualityLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *HeartRateLabel;
    QWidget *SettingWidget;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *PortComboBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *BaudComboBox;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *DataNumComboBox;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *StopComboBox;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *CheckComboBox;
    QCustomPlot *QCustomPlotWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BMD101Class)
    {
        if (BMD101Class->objectName().isEmpty())
            BMD101Class->setObjectName(QStringLiteral("BMD101Class"));
        BMD101Class->resize(600, 368);
        QIcon icon;
        icon.addFile(QStringLiteral(":/BMD101/WindowIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        BMD101Class->setWindowIcon(icon);
        BMD101Class->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(BMD101Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        ControlGroupBox = new QGroupBox(centralWidget);
        ControlGroupBox->setObjectName(QStringLiteral("ControlGroupBox"));
        ControlGroupBox->setGeometry(QRect(10, 10, 120, 291));
        BaseDataButton = new QPushButton(ControlGroupBox);
        BaseDataButton->setObjectName(QStringLiteral("BaseDataButton"));
        BaseDataButton->setGeometry(QRect(10, 30, 99, 51));
        QFont font;
        font.setPointSize(12);
        BaseDataButton->setFont(font);
        ChartButton = new QPushButton(ControlGroupBox);
        ChartButton->setObjectName(QStringLiteral("ChartButton"));
        ChartButton->setGeometry(QRect(10, 120, 99, 51));
        ChartButton->setFont(font);
        SettingButton = new QPushButton(ControlGroupBox);
        SettingButton->setObjectName(QStringLiteral("SettingButton"));
        SettingButton->setGeometry(QRect(10, 210, 99, 51));
        SettingButton->setFont(font);
        ShowGroupBox = new QGroupBox(centralWidget);
        ShowGroupBox->setObjectName(QStringLiteral("ShowGroupBox"));
        ShowGroupBox->setGeometry(QRect(140, 10, 441, 291));
        BaseDataWidget = new QWidget(ShowGroupBox);
        BaseDataWidget->setObjectName(QStringLiteral("BaseDataWidget"));
        BaseDataWidget->setGeometry(QRect(10, 20, 421, 261));
        layoutWidget = new QWidget(BaseDataWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 181, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        RawWaveVaueLabel = new QLabel(layoutWidget);
        RawWaveVaueLabel->setObjectName(QStringLiteral("RawWaveVaueLabel"));
        RawWaveVaueLabel->setFont(font);

        horizontalLayout->addWidget(RawWaveVaueLabel);

        layoutWidget1 = new QWidget(BaseDataWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 181, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        PoorSignalQualityLabel = new QLabel(layoutWidget1);
        PoorSignalQualityLabel->setObjectName(QStringLiteral("PoorSignalQualityLabel"));
        PoorSignalQualityLabel->setFont(font);

        horizontalLayout_2->addWidget(PoorSignalQualityLabel);

        layoutWidget2 = new QWidget(BaseDataWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 100, 181, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        HeartRateLabel = new QLabel(layoutWidget2);
        HeartRateLabel->setObjectName(QStringLiteral("HeartRateLabel"));
        HeartRateLabel->setFont(font);

        horizontalLayout_3->addWidget(HeartRateLabel);

        SettingWidget = new QWidget(ShowGroupBox);
        SettingWidget->setObjectName(QStringLiteral("SettingWidget"));
        SettingWidget->setGeometry(QRect(10, 20, 421, 261));
        groupBox_2 = new QGroupBox(SettingWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 391, 151));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 30, 161, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        PortComboBox = new QComboBox(layoutWidget3);
        PortComboBox->setObjectName(QStringLiteral("PortComboBox"));

        horizontalLayout_4->addWidget(PortComboBox);

        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(210, 30, 151, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        BaudComboBox = new QComboBox(layoutWidget4);
        BaudComboBox->setObjectName(QStringLiteral("BaudComboBox"));

        horizontalLayout_5->addWidget(BaudComboBox);

        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 70, 161, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        DataNumComboBox = new QComboBox(layoutWidget5);
        DataNumComboBox->setObjectName(QStringLiteral("DataNumComboBox"));

        horizontalLayout_6->addWidget(DataNumComboBox);

        layoutWidget6 = new QWidget(groupBox_2);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(210, 71, 151, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        StopComboBox = new QComboBox(layoutWidget6);
        StopComboBox->setObjectName(QStringLiteral("StopComboBox"));

        horizontalLayout_7->addWidget(StopComboBox);

        layoutWidget7 = new QWidget(groupBox_2);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(30, 110, 161, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        CheckComboBox = new QComboBox(layoutWidget7);
        CheckComboBox->setObjectName(QStringLiteral("CheckComboBox"));

        horizontalLayout_8->addWidget(CheckComboBox);

        QCustomPlotWidget = new QCustomPlot(ShowGroupBox);
        QCustomPlotWidget->setObjectName(QStringLiteral("QCustomPlotWidget"));
        QCustomPlotWidget->setGeometry(QRect(9, 19, 421, 261));
        QCustomPlotWidget->setCursor(QCursor(Qt::ArrowCursor));
        BMD101Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BMD101Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuBar->setStyleSheet(QStringLiteral(""));
        BMD101Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BMD101Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral(""));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(true);
        BMD101Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BMD101Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral(""));
        BMD101Class->setStatusBar(statusBar);

        retranslateUi(BMD101Class);

        QMetaObject::connectSlotsByName(BMD101Class);
    } // setupUi

    void retranslateUi(QMainWindow *BMD101Class)
    {
        BMD101Class->setWindowTitle(QApplication::translate("BMD101Class", "BMD101", 0));
        ControlGroupBox->setTitle(QApplication::translate("BMD101Class", "\346\216\247\345\210\266\345\214\272", 0));
        BaseDataButton->setText(QApplication::translate("BMD101Class", "\345\237\272\346\234\254\346\225\260\346\215\256", 0));
        ChartButton->setText(QApplication::translate("BMD101Class", "\346\263\242\345\275\242", 0));
        SettingButton->setText(QApplication::translate("BMD101Class", "\350\256\276\347\275\256", 0));
        ShowGroupBox->setTitle(QApplication::translate("BMD101Class", "\346\230\276\347\244\272\345\214\272", 0));
        label_3->setText(QApplication::translate("BMD101Class", "\345\216\237\345\247\213\347\224\265\345\216\213\345\200\274\357\274\232", 0));
        RawWaveVaueLabel->setText(QApplication::translate("BMD101Class", "0", 0));
        label_5->setText(QApplication::translate("BMD101Class", "\350\277\236\346\216\245\350\264\250\351\207\217\357\274\232", 0));
        PoorSignalQualityLabel->setText(QApplication::translate("BMD101Class", "0", 0));
        label->setText(QApplication::translate("BMD101Class", "\346\257\217\345\210\206\351\222\237\345\277\203\350\267\263\357\274\232", 0));
        HeartRateLabel->setText(QApplication::translate("BMD101Class", "0", 0));
        groupBox_2->setTitle(QApplication::translate("BMD101Class", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("BMD101Class", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("BMD101Class", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        label_6->setText(QApplication::translate("BMD101Class", "\346\225\260\346\215\256\344\275\215\357\274\232", 0));
        label_7->setText(QApplication::translate("BMD101Class", "\345\201\234\346\255\242\344\275\215\357\274\232", 0));
        label_8->setText(QApplication::translate("BMD101Class", "\346\240\241\351\252\214\344\275\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class BMD101Class: public Ui_BMD101Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMD101_H

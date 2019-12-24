/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QToolBox *LogicBox;
    QWidget *Gates;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_nor;
    QLabel *lbl_and;
    QLabel *lbl_xor;
    QLabel *lbl_not;
    QLabel *lbl_or;
    QLabel *lbl_nand;
    QWidget *Plexers;
    QWidget *Arithmetic;
    QWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 341);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(700, 100));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LogicBox = new QToolBox(centralWidget);
        LogicBox->setObjectName(QStringLiteral("LogicBox"));
        sizePolicy.setHeightForWidth(LogicBox->sizePolicy().hasHeightForWidth());
        LogicBox->setSizePolicy(sizePolicy);
        LogicBox->setMaximumSize(QSize(180, 16777215));
        LogicBox->setCursor(QCursor(Qt::OpenHandCursor));
        LogicBox->setFrameShape(QFrame::NoFrame);
        LogicBox->setLineWidth(1);
        LogicBox->setMidLineWidth(0);
        Gates = new QWidget();
        Gates->setObjectName(QStringLiteral("Gates"));
        Gates->setGeometry(QRect(0, 0, 180, 150));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Gates->sizePolicy().hasHeightForWidth());
        Gates->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(Gates);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbl_nor = new QLabel(Gates);
        lbl_nor->setObjectName(QStringLiteral("lbl_nor"));

        verticalLayout->addWidget(lbl_nor);

        lbl_and = new QLabel(Gates);
        lbl_and->setObjectName(QStringLiteral("lbl_and"));

        verticalLayout->addWidget(lbl_and);

        lbl_xor = new QLabel(Gates);
        lbl_xor->setObjectName(QStringLiteral("lbl_xor"));

        verticalLayout->addWidget(lbl_xor);

        lbl_not = new QLabel(Gates);
        lbl_not->setObjectName(QStringLiteral("lbl_not"));

        verticalLayout->addWidget(lbl_not);

        lbl_or = new QLabel(Gates);
        lbl_or->setObjectName(QStringLiteral("lbl_or"));

        verticalLayout->addWidget(lbl_or);

        lbl_nand = new QLabel(Gates);
        lbl_nand->setObjectName(QStringLiteral("lbl_nand"));

        verticalLayout->addWidget(lbl_nand);

        LogicBox->addItem(Gates, QStringLiteral("Gates"));
        Plexers = new QWidget();
        Plexers->setObjectName(QStringLiteral("Plexers"));
        Plexers->setGeometry(QRect(0, 0, 180, 169));
        LogicBox->addItem(Plexers, QStringLiteral("Plexers"));
        Arithmetic = new QWidget();
        Arithmetic->setObjectName(QStringLiteral("Arithmetic"));
        Arithmetic->setGeometry(QRect(0, 0, 180, 169));
        LogicBox->addItem(Arithmetic, QStringLiteral("Arithmetic"));

        horizontalLayout->addWidget(LogicBox);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(100, 100));
        widget->setStyleSheet(QStringLiteral("background:  rgb(252, 233, 79);"));

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        LogicBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Circuit Designer", Q_NULLPTR));
        lbl_nor->setText(QApplication::translate("MainWindow", "NOr", Q_NULLPTR));
        lbl_and->setText(QApplication::translate("MainWindow", "And", Q_NULLPTR));
        lbl_xor->setText(QApplication::translate("MainWindow", "Xor", Q_NULLPTR));
        lbl_not->setText(QApplication::translate("MainWindow", "Not", Q_NULLPTR));
        lbl_or->setText(QApplication::translate("MainWindow", "Or", Q_NULLPTR));
        lbl_nand->setText(QApplication::translate("MainWindow", "NAnd", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Gates), QApplication::translate("MainWindow", "Gates", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Plexers), QApplication::translate("MainWindow", "Plexers", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Arithmetic), QApplication::translate("MainWindow", "Arithmetic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

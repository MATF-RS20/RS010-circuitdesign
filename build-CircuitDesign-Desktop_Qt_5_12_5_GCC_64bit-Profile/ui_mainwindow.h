/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMove;
    QAction *actionConnect;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *trashButton;
    QToolButton *moveButton;
    QToolButton *connectButton;
    QGraphicsView *graphicsView;
    QToolBox *LogicBox;
    QWidget *InOut;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *inButton;
    QLabel *inLabel;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *outButton;
    QLabel *outLabel;
    QWidget *Gates;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *andGate;
    QToolButton *andButton;
    QLabel *andLabel;
    QHBoxLayout *orGate;
    QToolButton *orButton;
    QLabel *orLabel;
    QHBoxLayout *xorGate;
    QToolButton *xorButton;
    QLabel *xorLabel;
    QHBoxLayout *nandGate;
    QToolButton *nandButton;
    QLabel *nandLabel;
    QHBoxLayout *norGate;
    QToolButton *norButton;
    QLabel *norLabel;
    QHBoxLayout *notGate;
    QToolButton *notButton;
    QLabel *notLabel;
    QWidget *Plexers;
    QVBoxLayout *verticalLayout_3;
    QToolButton *multiplexerButton;
    QWidget *Arithmetic;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroupConnectMove;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 468);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QString::fromUtf8("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionConnect->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connections.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(700, 100));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        trashButton = new QToolButton(centralWidget);
        trashButton->setObjectName(QString::fromUtf8("trashButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        trashButton->setIcon(icon2);
        trashButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(trashButton);

        moveButton = new QToolButton(centralWidget);
        buttonGroupConnectMove = new QButtonGroup(MainWindow);
        buttonGroupConnectMove->setObjectName(QString::fromUtf8("buttonGroupConnectMove"));
        buttonGroupConnectMove->addButton(moveButton);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setIcon(icon);
        moveButton->setCheckable(true);

        horizontalLayout->addWidget(moveButton);

        connectButton = new QToolButton(centralWidget);
        buttonGroupConnectMove->addButton(connectButton);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setIcon(icon1);
        connectButton->setCheckable(true);

        horizontalLayout->addWidget(connectButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMouseTracking(false);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));

        gridLayout_2->addWidget(graphicsView, 1, 1, 1, 1);

        LogicBox = new QToolBox(centralWidget);
        LogicBox->setObjectName(QString::fromUtf8("LogicBox"));
        sizePolicy.setHeightForWidth(LogicBox->sizePolicy().hasHeightForWidth());
        LogicBox->setSizePolicy(sizePolicy);
        LogicBox->setMinimumSize(QSize(180, 0));
        LogicBox->setMaximumSize(QSize(180, 16777215));
        LogicBox->setCursor(QCursor(Qt::OpenHandCursor));
        LogicBox->setFrameShape(QFrame::NoFrame);
        LogicBox->setLineWidth(1);
        LogicBox->setMidLineWidth(0);
        InOut = new QWidget();
        InOut->setObjectName(QString::fromUtf8("InOut"));
        InOut->setGeometry(QRect(0, 0, 180, 245));
        layoutWidget = new QWidget(InOut);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 101, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inButton = new QToolButton(layoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setExclusive(true);
        buttonGroup->addButton(inButton);
        inButton->setObjectName(QString::fromUtf8("inButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/in_false.png"), QSize(), QIcon::Normal, QIcon::Off);
        inButton->setIcon(icon3);
        inButton->setCheckable(true);

        horizontalLayout_2->addWidget(inButton);

        inLabel = new QLabel(layoutWidget);
        inLabel->setObjectName(QString::fromUtf8("inLabel"));

        horizontalLayout_2->addWidget(inLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        outButton = new QToolButton(layoutWidget);
        buttonGroup->addButton(outButton);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/out_false.png"), QSize(), QIcon::Normal, QIcon::Off);
        outButton->setIcon(icon4);
        outButton->setCheckable(true);

        horizontalLayout_3->addWidget(outButton);

        outLabel = new QLabel(layoutWidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));

        horizontalLayout_3->addWidget(outLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        LogicBox->addItem(InOut, QString::fromUtf8("InOut"));
        Gates = new QWidget();
        Gates->setObjectName(QString::fromUtf8("Gates"));
        Gates->setGeometry(QRect(0, 0, 180, 245));
        sizePolicy.setHeightForWidth(Gates->sizePolicy().hasHeightForWidth());
        Gates->setSizePolicy(sizePolicy);
        layoutWidget1 = new QWidget(Gates);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 121, 211));
        sizePolicy1.setHeightForWidth(layoutWidget1->sizePolicy().hasHeightForWidth());
        layoutWidget1->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        andGate = new QHBoxLayout();
        andGate->setSpacing(6);
        andGate->setObjectName(QString::fromUtf8("andGate"));
        andButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(andButton);
        andButton->setObjectName(QString::fromUtf8("andButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/and.png"), QSize(), QIcon::Normal, QIcon::Off);
        andButton->setIcon(icon5);
        andButton->setIconSize(QSize(20, 20));
        andButton->setCheckable(true);
        andButton->setAutoExclusive(false);

        andGate->addWidget(andButton);

        andLabel = new QLabel(layoutWidget1);
        andLabel->setObjectName(QString::fromUtf8("andLabel"));

        andGate->addWidget(andLabel);


        verticalLayout->addLayout(andGate);

        orGate = new QHBoxLayout();
        orGate->setSpacing(6);
        orGate->setObjectName(QString::fromUtf8("orGate"));
        orButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(orButton);
        orButton->setObjectName(QString::fromUtf8("orButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/or.png"), QSize(), QIcon::Normal, QIcon::Off);
        orButton->setIcon(icon6);
        orButton->setIconSize(QSize(20, 20));
        orButton->setCheckable(true);
        orButton->setAutoExclusive(false);

        orGate->addWidget(orButton);

        orLabel = new QLabel(layoutWidget1);
        orLabel->setObjectName(QString::fromUtf8("orLabel"));

        orGate->addWidget(orLabel);


        verticalLayout->addLayout(orGate);

        xorGate = new QHBoxLayout();
        xorGate->setSpacing(6);
        xorGate->setObjectName(QString::fromUtf8("xorGate"));
        xorButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(xorButton);
        xorButton->setObjectName(QString::fromUtf8("xorButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/xor.png"), QSize(), QIcon::Normal, QIcon::Off);
        xorButton->setIcon(icon7);
        xorButton->setIconSize(QSize(20, 20));
        xorButton->setCheckable(true);
        xorButton->setAutoExclusive(false);

        xorGate->addWidget(xorButton);

        xorLabel = new QLabel(layoutWidget1);
        xorLabel->setObjectName(QString::fromUtf8("xorLabel"));
        sizePolicy1.setHeightForWidth(xorLabel->sizePolicy().hasHeightForWidth());
        xorLabel->setSizePolicy(sizePolicy1);

        xorGate->addWidget(xorLabel);


        verticalLayout->addLayout(xorGate);

        nandGate = new QHBoxLayout();
        nandGate->setSpacing(6);
        nandGate->setObjectName(QString::fromUtf8("nandGate"));
        nandButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(nandButton);
        nandButton->setObjectName(QString::fromUtf8("nandButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/nand.png"), QSize(), QIcon::Normal, QIcon::Off);
        nandButton->setIcon(icon8);
        nandButton->setIconSize(QSize(20, 20));
        nandButton->setCheckable(true);
        nandButton->setAutoExclusive(false);

        nandGate->addWidget(nandButton);

        nandLabel = new QLabel(layoutWidget1);
        nandLabel->setObjectName(QString::fromUtf8("nandLabel"));
        sizePolicy1.setHeightForWidth(nandLabel->sizePolicy().hasHeightForWidth());
        nandLabel->setSizePolicy(sizePolicy1);

        nandGate->addWidget(nandLabel);


        verticalLayout->addLayout(nandGate);

        norGate = new QHBoxLayout();
        norGate->setSpacing(6);
        norGate->setObjectName(QString::fromUtf8("norGate"));
        norButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(norButton);
        norButton->setObjectName(QString::fromUtf8("norButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        norButton->setIcon(icon9);
        norButton->setIconSize(QSize(20, 20));
        norButton->setCheckable(true);
        norButton->setAutoExclusive(false);

        norGate->addWidget(norButton);

        norLabel = new QLabel(layoutWidget1);
        norLabel->setObjectName(QString::fromUtf8("norLabel"));
        sizePolicy1.setHeightForWidth(norLabel->sizePolicy().hasHeightForWidth());
        norLabel->setSizePolicy(sizePolicy1);

        norGate->addWidget(norLabel);


        verticalLayout->addLayout(norGate);

        notGate = new QHBoxLayout();
        notGate->setSpacing(6);
        notGate->setObjectName(QString::fromUtf8("notGate"));
        notButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(notButton);
        notButton->setObjectName(QString::fromUtf8("notButton"));
        notButton->setAcceptDrops(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/not.png"), QSize(), QIcon::Normal, QIcon::Off);
        notButton->setIcon(icon10);
        notButton->setIconSize(QSize(20, 20));
        notButton->setCheckable(true);

        notGate->addWidget(notButton);

        notLabel = new QLabel(layoutWidget1);
        notLabel->setObjectName(QString::fromUtf8("notLabel"));
        sizePolicy1.setHeightForWidth(notLabel->sizePolicy().hasHeightForWidth());
        notLabel->setSizePolicy(sizePolicy1);

        notGate->addWidget(notLabel);


        verticalLayout->addLayout(notGate);

        LogicBox->addItem(Gates, QString::fromUtf8("Gates"));
        Plexers = new QWidget();
        Plexers->setObjectName(QString::fromUtf8("Plexers"));
        Plexers->setGeometry(QRect(0, 0, 180, 245));
        verticalLayout_3 = new QVBoxLayout(Plexers);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        multiplexerButton = new QToolButton(Plexers);
        buttonGroup->addButton(multiplexerButton);
        multiplexerButton->setObjectName(QString::fromUtf8("multiplexerButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/multiplexer.png"), QSize(), QIcon::Normal, QIcon::Off);
        multiplexerButton->setIcon(icon11);
        multiplexerButton->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(multiplexerButton);

        LogicBox->addItem(Plexers, QString::fromUtf8("Plexers"));
        Arithmetic = new QWidget();
        Arithmetic->setObjectName(QString::fromUtf8("Arithmetic"));
        Arithmetic->setGeometry(QRect(0, 0, 180, 245));
        LogicBox->addItem(Arithmetic, QString::fromUtf8("Arithmetic"));

        gridLayout_2->addWidget(LogicBox, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        LogicBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Circuit Designer", nullptr));
        actionMove->setText(QApplication::translate("MainWindow", "Move", nullptr));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        trashButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        moveButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        inButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        inLabel->setText(QApplication::translate("MainWindow", "In", nullptr));
        outButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        outLabel->setText(QApplication::translate("MainWindow", "Out", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(InOut), QApplication::translate("MainWindow", "InOut", nullptr));
        andButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        andLabel->setText(QApplication::translate("MainWindow", "And", nullptr));
        orButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        orLabel->setText(QApplication::translate("MainWindow", "Or", nullptr));
        xorButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        xorLabel->setText(QApplication::translate("MainWindow", "Xor", nullptr));
        nandButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        nandLabel->setText(QApplication::translate("MainWindow", "Nand", nullptr));
        norButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        norLabel->setText(QApplication::translate("MainWindow", "Nor", nullptr));
        notButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        notLabel->setText(QApplication::translate("MainWindow", "Not", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(Gates), QApplication::translate("MainWindow", "Gates", nullptr));
        multiplexerButton->setText(QString());
        LogicBox->setItemText(LogicBox->indexOf(Plexers), QApplication::translate("MainWindow", "Plexers", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(Arithmetic), QApplication::translate("MainWindow", "Arithmetic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

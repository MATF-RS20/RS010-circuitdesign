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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMove;
    QAction *actionConnection;
    QAction *actionDelete;
    QAction *actionInputs;
    QAction *actionOutputs;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
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
    QHBoxLayout *horizontalLayout_8;
    QToolButton *clockButton;
    QLabel *labelClock;
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
    QHBoxLayout *idGate;
    QToolButton *idButton;
    QLabel *idLabel;
    QHBoxLayout *notGate;
    QToolButton *notButton;
    QLabel *notLabel;
    QWidget *Plexers;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *multiplexerButton;
    QLabel *labelMultiplexer;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *demultiplexerButton;
    QLabel *labelDemultiplexer;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *decoderButton;
    QLabel *labelDecoder;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *encoderButton;
    QLabel *labelEncoder;
    QWidget *Arithmetic;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *adderButton;
    QLabel *labelAdder;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *subtractorButton;
    QLabel *labelSubtractor;
    QWidget *FlipFlop;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *JKButton;
    QLabel *labelJK;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *SRButton;
    QLabel *labelSR;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *DButton;
    QLabel *labelD;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *TButton;
    QLabel *labelT;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QButtonGroup *buttonGroup;

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
        actionConnection = new QAction(MainWindow);
        actionConnection->setObjectName(QString::fromUtf8("actionConnection"));
        actionConnection->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connections.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnection->setIcon(icon1);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon2);
        actionInputs = new QAction(MainWindow);
        actionInputs->setObjectName(QString::fromUtf8("actionInputs"));
        actionOutputs = new QAction(MainWindow);
        actionOutputs->setObjectName(QString::fromUtf8("actionOutputs"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(700, 100));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMouseTracking(false);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));

        gridLayout_2->addWidget(graphicsView, 0, 2, 1, 1);

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
        InOut->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget = new QWidget(InOut);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 1, 103, 124));
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
        inButton->setIconSize(QSize(20, 20));
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
        outButton->setIconSize(QSize(20, 20));
        outButton->setCheckable(true);

        horizontalLayout_3->addWidget(outButton);

        outLabel = new QLabel(layoutWidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));

        horizontalLayout_3->addWidget(outLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        clockButton = new QToolButton(layoutWidget);
        buttonGroup->addButton(clockButton);
        clockButton->setObjectName(QString::fromUtf8("clockButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        clockButton->setIcon(icon5);
        clockButton->setIconSize(QSize(20, 20));
        clockButton->setCheckable(true);
        clockButton->setAutoExclusive(false);

        horizontalLayout_8->addWidget(clockButton);

        labelClock = new QLabel(layoutWidget);
        labelClock->setObjectName(QString::fromUtf8("labelClock"));

        horizontalLayout_8->addWidget(labelClock);


        verticalLayout_2->addLayout(horizontalLayout_8);

        LogicBox->addItem(InOut, QString::fromUtf8("InOut"));
        Gates = new QWidget();
        Gates->setObjectName(QString::fromUtf8("Gates"));
        Gates->setGeometry(QRect(0, 0, 180, 230));
        sizePolicy.setHeightForWidth(Gates->sizePolicy().hasHeightForWidth());
        Gates->setSizePolicy(sizePolicy);
        layoutWidget1 = new QWidget(Gates);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 171, 241));
        sizePolicy2.setHeightForWidth(layoutWidget1->sizePolicy().hasHeightForWidth());
        layoutWidget1->setSizePolicy(sizePolicy2);
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/and.png"), QSize(), QIcon::Normal, QIcon::Off);
        andButton->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/or.png"), QSize(), QIcon::Normal, QIcon::Off);
        orButton->setIcon(icon7);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/xor.png"), QSize(), QIcon::Normal, QIcon::Off);
        xorButton->setIcon(icon8);
        xorButton->setIconSize(QSize(20, 20));
        xorButton->setCheckable(true);
        xorButton->setAutoExclusive(false);

        xorGate->addWidget(xorButton);

        xorLabel = new QLabel(layoutWidget1);
        xorLabel->setObjectName(QString::fromUtf8("xorLabel"));
        sizePolicy2.setHeightForWidth(xorLabel->sizePolicy().hasHeightForWidth());
        xorLabel->setSizePolicy(sizePolicy2);

        xorGate->addWidget(xorLabel);


        verticalLayout->addLayout(xorGate);

        nandGate = new QHBoxLayout();
        nandGate->setSpacing(6);
        nandGate->setObjectName(QString::fromUtf8("nandGate"));
        nandButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(nandButton);
        nandButton->setObjectName(QString::fromUtf8("nandButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/nand.png"), QSize(), QIcon::Normal, QIcon::Off);
        nandButton->setIcon(icon9);
        nandButton->setIconSize(QSize(20, 20));
        nandButton->setCheckable(true);
        nandButton->setAutoExclusive(false);

        nandGate->addWidget(nandButton);

        nandLabel = new QLabel(layoutWidget1);
        nandLabel->setObjectName(QString::fromUtf8("nandLabel"));
        sizePolicy2.setHeightForWidth(nandLabel->sizePolicy().hasHeightForWidth());
        nandLabel->setSizePolicy(sizePolicy2);

        nandGate->addWidget(nandLabel);


        verticalLayout->addLayout(nandGate);

        norGate = new QHBoxLayout();
        norGate->setSpacing(6);
        norGate->setObjectName(QString::fromUtf8("norGate"));
        norButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(norButton);
        norButton->setObjectName(QString::fromUtf8("norButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        norButton->setIcon(icon10);
        norButton->setIconSize(QSize(20, 20));
        norButton->setCheckable(true);
        norButton->setAutoExclusive(false);

        norGate->addWidget(norButton);

        norLabel = new QLabel(layoutWidget1);
        norLabel->setObjectName(QString::fromUtf8("norLabel"));
        sizePolicy2.setHeightForWidth(norLabel->sizePolicy().hasHeightForWidth());
        norLabel->setSizePolicy(sizePolicy2);

        norGate->addWidget(norLabel);


        verticalLayout->addLayout(norGate);

        idGate = new QHBoxLayout();
        idGate->setSpacing(6);
        idGate->setObjectName(QString::fromUtf8("idGate"));
        idButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(idButton);
        idButton->setObjectName(QString::fromUtf8("idButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/id.png"), QSize(), QIcon::Normal, QIcon::Off);
        idButton->setIcon(icon11);
        idButton->setIconSize(QSize(20, 20));
        idButton->setCheckable(true);

        idGate->addWidget(idButton);

        idLabel = new QLabel(layoutWidget1);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        idGate->addWidget(idLabel);


        verticalLayout->addLayout(idGate);

        notGate = new QHBoxLayout();
        notGate->setSpacing(6);
        notGate->setObjectName(QString::fromUtf8("notGate"));
        notButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(notButton);
        notButton->setObjectName(QString::fromUtf8("notButton"));
        notButton->setAcceptDrops(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/not.png"), QSize(), QIcon::Normal, QIcon::Off);
        notButton->setIcon(icon12);
        notButton->setIconSize(QSize(20, 20));
        notButton->setCheckable(true);

        notGate->addWidget(notButton);

        notLabel = new QLabel(layoutWidget1);
        notLabel->setObjectName(QString::fromUtf8("notLabel"));
        sizePolicy2.setHeightForWidth(notLabel->sizePolicy().hasHeightForWidth());
        notLabel->setSizePolicy(sizePolicy2);

        notGate->addWidget(notLabel);


        verticalLayout->addLayout(notGate);

        LogicBox->addItem(Gates, QString::fromUtf8("Gates"));
        Plexers = new QWidget();
        Plexers->setObjectName(QString::fromUtf8("Plexers"));
        Plexers->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget2 = new QWidget(Plexers);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 11, 136, 136));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        multiplexerButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(multiplexerButton);
        multiplexerButton->setObjectName(QString::fromUtf8("multiplexerButton"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/multiplexer.png"), QSize(), QIcon::Normal, QIcon::Off);
        multiplexerButton->setIcon(icon13);
        multiplexerButton->setIconSize(QSize(20, 20));
        multiplexerButton->setCheckable(true);

        horizontalLayout_5->addWidget(multiplexerButton);

        labelMultiplexer = new QLabel(layoutWidget2);
        labelMultiplexer->setObjectName(QString::fromUtf8("labelMultiplexer"));

        horizontalLayout_5->addWidget(labelMultiplexer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        demultiplexerButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(demultiplexerButton);
        demultiplexerButton->setObjectName(QString::fromUtf8("demultiplexerButton"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/demultiplexer.png"), QSize(), QIcon::Normal, QIcon::Off);
        demultiplexerButton->setIcon(icon14);
        demultiplexerButton->setIconSize(QSize(20, 20));
        demultiplexerButton->setCheckable(true);

        horizontalLayout_4->addWidget(demultiplexerButton);

        labelDemultiplexer = new QLabel(layoutWidget2);
        labelDemultiplexer->setObjectName(QString::fromUtf8("labelDemultiplexer"));

        horizontalLayout_4->addWidget(labelDemultiplexer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        decoderButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(decoderButton);
        decoderButton->setObjectName(QString::fromUtf8("decoderButton"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/decoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        decoderButton->setIcon(icon15);
        decoderButton->setIconSize(QSize(20, 20));
        decoderButton->setCheckable(true);

        horizontalLayout_6->addWidget(decoderButton);

        labelDecoder = new QLabel(layoutWidget2);
        labelDecoder->setObjectName(QString::fromUtf8("labelDecoder"));

        horizontalLayout_6->addWidget(labelDecoder);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        encoderButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(encoderButton);
        encoderButton->setObjectName(QString::fromUtf8("encoderButton"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/encoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        encoderButton->setIcon(icon16);
        encoderButton->setIconSize(QSize(20, 20));
        encoderButton->setCheckable(true);

        horizontalLayout_7->addWidget(encoderButton);

        labelEncoder = new QLabel(layoutWidget2);
        labelEncoder->setObjectName(QString::fromUtf8("labelEncoder"));

        horizontalLayout_7->addWidget(labelEncoder);


        verticalLayout_3->addLayout(horizontalLayout_7);

        LogicBox->addItem(Plexers, QString::fromUtf8("Plexers"));
        Arithmetic = new QWidget();
        Arithmetic->setObjectName(QString::fromUtf8("Arithmetic"));
        Arithmetic->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget3 = new QWidget(Arithmetic);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 11, 109, 60));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        adderButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(adderButton);
        adderButton->setObjectName(QString::fromUtf8("adderButton"));
        adderButton->setCheckable(true);

        horizontalLayout_12->addWidget(adderButton);

        labelAdder = new QLabel(layoutWidget3);
        labelAdder->setObjectName(QString::fromUtf8("labelAdder"));

        horizontalLayout_12->addWidget(labelAdder);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        subtractorButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(subtractorButton);
        subtractorButton->setObjectName(QString::fromUtf8("subtractorButton"));
        subtractorButton->setCheckable(true);

        horizontalLayout_13->addWidget(subtractorButton);

        labelSubtractor = new QLabel(layoutWidget3);
        labelSubtractor->setObjectName(QString::fromUtf8("labelSubtractor"));

        horizontalLayout_13->addWidget(labelSubtractor);


        verticalLayout_5->addLayout(horizontalLayout_13);

        LogicBox->addItem(Arithmetic, QString::fromUtf8("Arithmetic"));
        FlipFlop = new QWidget();
        FlipFlop->setObjectName(QString::fromUtf8("FlipFlop"));
        FlipFlop->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget4 = new QWidget(FlipFlop);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 101, 124));
        gridLayout = new QGridLayout(layoutWidget4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        JKButton = new QToolButton(layoutWidget4);
        buttonGroup->addButton(JKButton);
        JKButton->setObjectName(QString::fromUtf8("JKButton"));
        JKButton->setIconSize(QSize(20, 20));
        JKButton->setCheckable(true);

        horizontalLayout->addWidget(JKButton);

        labelJK = new QLabel(layoutWidget4);
        labelJK->setObjectName(QString::fromUtf8("labelJK"));

        horizontalLayout->addWidget(labelJK);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        SRButton = new QToolButton(layoutWidget4);
        buttonGroup->addButton(SRButton);
        SRButton->setObjectName(QString::fromUtf8("SRButton"));
        SRButton->setIconSize(QSize(20, 20));
        SRButton->setCheckable(true);

        horizontalLayout_9->addWidget(SRButton);

        labelSR = new QLabel(layoutWidget4);
        labelSR->setObjectName(QString::fromUtf8("labelSR"));

        horizontalLayout_9->addWidget(labelSR);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        DButton = new QToolButton(layoutWidget4);
        buttonGroup->addButton(DButton);
        DButton->setObjectName(QString::fromUtf8("DButton"));
        DButton->setCheckable(true);

        horizontalLayout_10->addWidget(DButton);

        labelD = new QLabel(layoutWidget4);
        labelD->setObjectName(QString::fromUtf8("labelD"));

        horizontalLayout_10->addWidget(labelD);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        TButton = new QToolButton(layoutWidget4);
        buttonGroup->addButton(TButton);
        TButton->setObjectName(QString::fromUtf8("TButton"));
        TButton->setCheckable(true);

        horizontalLayout_11->addWidget(TButton);

        labelT = new QLabel(layoutWidget4);
        labelT->setObjectName(QString::fromUtf8("labelT"));

        horizontalLayout_11->addWidget(labelT);


        gridLayout->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        LogicBox->addItem(FlipFlop, QString::fromUtf8("Flip Flop"));

        gridLayout_2->addWidget(LogicBox, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionMove);
        toolBar->addAction(actionConnection);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionInputs);

        retranslateUi(MainWindow);

        LogicBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Circuit Designer", nullptr));
        actionMove->setText(QApplication::translate("MainWindow", "Move", nullptr));
        actionConnection->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        actionInputs->setText(QApplication::translate("MainWindow", "Inputs", nullptr));
        actionOutputs->setText(QApplication::translate("MainWindow", "Outputs", nullptr));
        inButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        inLabel->setText(QApplication::translate("MainWindow", "In", nullptr));
        outButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        outLabel->setText(QApplication::translate("MainWindow", "Out", nullptr));
        clockButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelClock->setText(QApplication::translate("MainWindow", "Clock", nullptr));
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
        idButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        idLabel->setText(QApplication::translate("MainWindow", "Id", nullptr));
        notButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        notLabel->setText(QApplication::translate("MainWindow", "Not", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(Gates), QApplication::translate("MainWindow", "Gates", nullptr));
        multiplexerButton->setText(QString());
        labelMultiplexer->setText(QApplication::translate("MainWindow", "Multiplexer", nullptr));
        demultiplexerButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelDemultiplexer->setText(QApplication::translate("MainWindow", "Demultiplexer", nullptr));
        decoderButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelDecoder->setText(QApplication::translate("MainWindow", "Decoder", nullptr));
        encoderButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelEncoder->setText(QApplication::translate("MainWindow", "Encoder", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(Plexers), QApplication::translate("MainWindow", "Plexers", nullptr));
        adderButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelAdder->setText(QApplication::translate("MainWindow", "Adder", nullptr));
        subtractorButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelSubtractor->setText(QApplication::translate("MainWindow", "Subtractor", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(Arithmetic), QApplication::translate("MainWindow", "Arithmetic", nullptr));
        JKButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelJK->setText(QApplication::translate("MainWindow", "JK", nullptr));
        SRButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelSR->setText(QApplication::translate("MainWindow", "SR", nullptr));
        DButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelD->setText(QApplication::translate("MainWindow", "D", nullptr));
        TButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelT->setText(QApplication::translate("MainWindow", "T", nullptr));
        LogicBox->setItemText(LogicBox->indexOf(FlipFlop), QApplication::translate("MainWindow", "Flip Flop", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

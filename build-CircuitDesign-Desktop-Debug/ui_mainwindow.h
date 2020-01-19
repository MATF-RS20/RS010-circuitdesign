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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *adderButton;
    QLabel *labelAdder;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *subtractorButton;
    QLabel *labelSubtractor;
    QWidget *FlipFlop;
    QWidget *layoutWidget3;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 468);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon);
        actionConnection = new QAction(MainWindow);
        actionConnection->setObjectName(QStringLiteral("actionConnection"));
        actionConnection->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/connections.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnection->setIcon(icon1);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionDelete->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon2);
        actionInputs = new QAction(MainWindow);
        actionInputs->setObjectName(QStringLiteral("actionInputs"));
        actionOutputs = new QAction(MainWindow);
        actionOutputs->setObjectName(QStringLiteral("actionOutputs"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(700, 100));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
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
        LogicBox->setObjectName(QStringLiteral("LogicBox"));
        sizePolicy.setHeightForWidth(LogicBox->sizePolicy().hasHeightForWidth());
        LogicBox->setSizePolicy(sizePolicy);
        LogicBox->setMinimumSize(QSize(180, 0));
        LogicBox->setMaximumSize(QSize(180, 16777215));
        LogicBox->setCursor(QCursor(Qt::OpenHandCursor));
        LogicBox->setFrameShape(QFrame::NoFrame);
        LogicBox->setLineWidth(1);
        LogicBox->setMidLineWidth(0);
        InOut = new QWidget();
        InOut->setObjectName(QStringLiteral("InOut"));
        InOut->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget = new QWidget(InOut);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 1, 103, 124));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        inButton = new QToolButton(layoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->setExclusive(true);
        buttonGroup->addButton(inButton);
        inButton->setObjectName(QStringLiteral("inButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/in_false.png"), QSize(), QIcon::Normal, QIcon::Off);
        inButton->setIcon(icon3);
        inButton->setIconSize(QSize(20, 20));
        inButton->setCheckable(true);

        horizontalLayout_2->addWidget(inButton);

        inLabel = new QLabel(layoutWidget);
        inLabel->setObjectName(QStringLiteral("inLabel"));

        horizontalLayout_2->addWidget(inLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        outButton = new QToolButton(layoutWidget);
        buttonGroup->addButton(outButton);
        outButton->setObjectName(QStringLiteral("outButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/out_false.png"), QSize(), QIcon::Normal, QIcon::Off);
        outButton->setIcon(icon4);
        outButton->setIconSize(QSize(20, 20));
        outButton->setCheckable(true);

        horizontalLayout_3->addWidget(outButton);

        outLabel = new QLabel(layoutWidget);
        outLabel->setObjectName(QStringLiteral("outLabel"));

        horizontalLayout_3->addWidget(outLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        clockButton = new QToolButton(layoutWidget);
        buttonGroup->addButton(clockButton);
        clockButton->setObjectName(QStringLiteral("clockButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        clockButton->setIcon(icon5);
        clockButton->setIconSize(QSize(20, 20));
        clockButton->setCheckable(true);
        clockButton->setAutoExclusive(false);

        horizontalLayout_8->addWidget(clockButton);

        labelClock = new QLabel(layoutWidget);
        labelClock->setObjectName(QStringLiteral("labelClock"));

        horizontalLayout_8->addWidget(labelClock);


        verticalLayout_2->addLayout(horizontalLayout_8);

        LogicBox->addItem(InOut, QStringLiteral("InOut"));
        Gates = new QWidget();
        Gates->setObjectName(QStringLiteral("Gates"));
        Gates->setGeometry(QRect(0, 0, 180, 230));
        sizePolicy.setHeightForWidth(Gates->sizePolicy().hasHeightForWidth());
        Gates->setSizePolicy(sizePolicy);
        layoutWidget1 = new QWidget(Gates);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 171, 241));
        sizePolicy2.setHeightForWidth(layoutWidget1->sizePolicy().hasHeightForWidth());
        layoutWidget1->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        andGate = new QHBoxLayout();
        andGate->setSpacing(6);
        andGate->setObjectName(QStringLiteral("andGate"));
        andButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(andButton);
        andButton->setObjectName(QStringLiteral("andButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/and.png"), QSize(), QIcon::Normal, QIcon::Off);
        andButton->setIcon(icon6);
        andButton->setIconSize(QSize(20, 20));
        andButton->setCheckable(true);
        andButton->setAutoExclusive(false);

        andGate->addWidget(andButton);

        andLabel = new QLabel(layoutWidget1);
        andLabel->setObjectName(QStringLiteral("andLabel"));

        andGate->addWidget(andLabel);


        verticalLayout->addLayout(andGate);

        orGate = new QHBoxLayout();
        orGate->setSpacing(6);
        orGate->setObjectName(QStringLiteral("orGate"));
        orButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(orButton);
        orButton->setObjectName(QStringLiteral("orButton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/or.png"), QSize(), QIcon::Normal, QIcon::Off);
        orButton->setIcon(icon7);
        orButton->setIconSize(QSize(20, 20));
        orButton->setCheckable(true);
        orButton->setAutoExclusive(false);

        orGate->addWidget(orButton);

        orLabel = new QLabel(layoutWidget1);
        orLabel->setObjectName(QStringLiteral("orLabel"));

        orGate->addWidget(orLabel);


        verticalLayout->addLayout(orGate);

        xorGate = new QHBoxLayout();
        xorGate->setSpacing(6);
        xorGate->setObjectName(QStringLiteral("xorGate"));
        xorButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(xorButton);
        xorButton->setObjectName(QStringLiteral("xorButton"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/xor.png"), QSize(), QIcon::Normal, QIcon::Off);
        xorButton->setIcon(icon8);
        xorButton->setIconSize(QSize(20, 20));
        xorButton->setCheckable(true);
        xorButton->setAutoExclusive(false);

        xorGate->addWidget(xorButton);

        xorLabel = new QLabel(layoutWidget1);
        xorLabel->setObjectName(QStringLiteral("xorLabel"));
        sizePolicy2.setHeightForWidth(xorLabel->sizePolicy().hasHeightForWidth());
        xorLabel->setSizePolicy(sizePolicy2);

        xorGate->addWidget(xorLabel);


        verticalLayout->addLayout(xorGate);

        nandGate = new QHBoxLayout();
        nandGate->setSpacing(6);
        nandGate->setObjectName(QStringLiteral("nandGate"));
        nandButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(nandButton);
        nandButton->setObjectName(QStringLiteral("nandButton"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/nand.png"), QSize(), QIcon::Normal, QIcon::Off);
        nandButton->setIcon(icon9);
        nandButton->setIconSize(QSize(20, 20));
        nandButton->setCheckable(true);
        nandButton->setAutoExclusive(false);

        nandGate->addWidget(nandButton);

        nandLabel = new QLabel(layoutWidget1);
        nandLabel->setObjectName(QStringLiteral("nandLabel"));
        sizePolicy2.setHeightForWidth(nandLabel->sizePolicy().hasHeightForWidth());
        nandLabel->setSizePolicy(sizePolicy2);

        nandGate->addWidget(nandLabel);


        verticalLayout->addLayout(nandGate);

        norGate = new QHBoxLayout();
        norGate->setSpacing(6);
        norGate->setObjectName(QStringLiteral("norGate"));
        norButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(norButton);
        norButton->setObjectName(QStringLiteral("norButton"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        norButton->setIcon(icon10);
        norButton->setIconSize(QSize(20, 20));
        norButton->setCheckable(true);
        norButton->setAutoExclusive(false);

        norGate->addWidget(norButton);

        norLabel = new QLabel(layoutWidget1);
        norLabel->setObjectName(QStringLiteral("norLabel"));
        sizePolicy2.setHeightForWidth(norLabel->sizePolicy().hasHeightForWidth());
        norLabel->setSizePolicy(sizePolicy2);

        norGate->addWidget(norLabel);


        verticalLayout->addLayout(norGate);

        idGate = new QHBoxLayout();
        idGate->setSpacing(6);
        idGate->setObjectName(QStringLiteral("idGate"));
        idButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(idButton);
        idButton->setObjectName(QStringLiteral("idButton"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/id.png"), QSize(), QIcon::Normal, QIcon::Off);
        idButton->setIcon(icon11);
        idButton->setIconSize(QSize(20, 20));
        idButton->setCheckable(true);

        idGate->addWidget(idButton);

        idLabel = new QLabel(layoutWidget1);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        idGate->addWidget(idLabel);


        verticalLayout->addLayout(idGate);

        notGate = new QHBoxLayout();
        notGate->setSpacing(6);
        notGate->setObjectName(QStringLiteral("notGate"));
        notButton = new QToolButton(layoutWidget1);
        buttonGroup->addButton(notButton);
        notButton->setObjectName(QStringLiteral("notButton"));
        notButton->setAcceptDrops(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/not.png"), QSize(), QIcon::Normal, QIcon::Off);
        notButton->setIcon(icon12);
        notButton->setIconSize(QSize(20, 20));
        notButton->setCheckable(true);

        notGate->addWidget(notButton);

        notLabel = new QLabel(layoutWidget1);
        notLabel->setObjectName(QStringLiteral("notLabel"));
        sizePolicy2.setHeightForWidth(notLabel->sizePolicy().hasHeightForWidth());
        notLabel->setSizePolicy(sizePolicy2);

        notGate->addWidget(notLabel);


        verticalLayout->addLayout(notGate);

        LogicBox->addItem(Gates, QStringLiteral("Gates"));
        Plexers = new QWidget();
        Plexers->setObjectName(QStringLiteral("Plexers"));
        Plexers->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget2 = new QWidget(Plexers);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 11, 136, 136));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        multiplexerButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(multiplexerButton);
        multiplexerButton->setObjectName(QStringLiteral("multiplexerButton"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/multiplexer.png"), QSize(), QIcon::Normal, QIcon::Off);
        multiplexerButton->setIcon(icon13);
        multiplexerButton->setIconSize(QSize(20, 20));
        multiplexerButton->setCheckable(true);

        horizontalLayout_5->addWidget(multiplexerButton);

        labelMultiplexer = new QLabel(layoutWidget2);
        labelMultiplexer->setObjectName(QStringLiteral("labelMultiplexer"));

        horizontalLayout_5->addWidget(labelMultiplexer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        demultiplexerButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(demultiplexerButton);
        demultiplexerButton->setObjectName(QStringLiteral("demultiplexerButton"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/demultiplexer.png"), QSize(), QIcon::Normal, QIcon::Off);
        demultiplexerButton->setIcon(icon14);
        demultiplexerButton->setIconSize(QSize(20, 20));
        demultiplexerButton->setCheckable(true);

        horizontalLayout_4->addWidget(demultiplexerButton);

        labelDemultiplexer = new QLabel(layoutWidget2);
        labelDemultiplexer->setObjectName(QStringLiteral("labelDemultiplexer"));

        horizontalLayout_4->addWidget(labelDemultiplexer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        decoderButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(decoderButton);
        decoderButton->setObjectName(QStringLiteral("decoderButton"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/decoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        decoderButton->setIcon(icon15);
        decoderButton->setIconSize(QSize(20, 20));
        decoderButton->setCheckable(true);

        horizontalLayout_6->addWidget(decoderButton);

        labelDecoder = new QLabel(layoutWidget2);
        labelDecoder->setObjectName(QStringLiteral("labelDecoder"));

        horizontalLayout_6->addWidget(labelDecoder);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        encoderButton = new QToolButton(layoutWidget2);
        buttonGroup->addButton(encoderButton);
        encoderButton->setObjectName(QStringLiteral("encoderButton"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/encoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        encoderButton->setIcon(icon16);
        encoderButton->setIconSize(QSize(20, 20));
        encoderButton->setCheckable(true);

        horizontalLayout_7->addWidget(encoderButton);

        labelEncoder = new QLabel(layoutWidget2);
        labelEncoder->setObjectName(QStringLiteral("labelEncoder"));

        horizontalLayout_7->addWidget(labelEncoder);


        verticalLayout_3->addLayout(horizontalLayout_7);

        LogicBox->addItem(Plexers, QStringLiteral("Plexers"));
        Arithmetic = new QWidget();
        Arithmetic->setObjectName(QStringLiteral("Arithmetic"));
        Arithmetic->setGeometry(QRect(0, 0, 180, 230));
        widget = new QWidget(Arithmetic);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 11, 109, 60));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        adderButton = new QToolButton(widget);
        buttonGroup->addButton(adderButton);
        adderButton->setObjectName(QStringLiteral("adderButton"));
        adderButton->setCheckable(true);

        horizontalLayout_12->addWidget(adderButton);

        labelAdder = new QLabel(widget);
        labelAdder->setObjectName(QStringLiteral("labelAdder"));

        horizontalLayout_12->addWidget(labelAdder);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        subtractorButton = new QToolButton(widget);
        buttonGroup->addButton(subtractorButton);
        subtractorButton->setObjectName(QStringLiteral("subtractorButton"));
        subtractorButton->setCheckable(true);

        horizontalLayout_13->addWidget(subtractorButton);

        labelSubtractor = new QLabel(widget);
        labelSubtractor->setObjectName(QStringLiteral("labelSubtractor"));

        horizontalLayout_13->addWidget(labelSubtractor);


        verticalLayout_5->addLayout(horizontalLayout_13);

        LogicBox->addItem(Arithmetic, QStringLiteral("Arithmetic"));
        FlipFlop = new QWidget();
        FlipFlop->setObjectName(QStringLiteral("FlipFlop"));
        FlipFlop->setGeometry(QRect(0, 0, 180, 230));
        layoutWidget3 = new QWidget(FlipFlop);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 101, 124));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        JKButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(JKButton);
        JKButton->setObjectName(QStringLiteral("JKButton"));
        JKButton->setIconSize(QSize(20, 20));
        JKButton->setCheckable(true);

        horizontalLayout->addWidget(JKButton);

        labelJK = new QLabel(layoutWidget3);
        labelJK->setObjectName(QStringLiteral("labelJK"));

        horizontalLayout->addWidget(labelJK);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        SRButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(SRButton);
        SRButton->setObjectName(QStringLiteral("SRButton"));
        SRButton->setIconSize(QSize(20, 20));
        SRButton->setCheckable(true);

        horizontalLayout_9->addWidget(SRButton);

        labelSR = new QLabel(layoutWidget3);
        labelSR->setObjectName(QStringLiteral("labelSR"));

        horizontalLayout_9->addWidget(labelSR);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        DButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(DButton);
        DButton->setObjectName(QStringLiteral("DButton"));
        DButton->setCheckable(true);

        horizontalLayout_10->addWidget(DButton);

        labelD = new QLabel(layoutWidget3);
        labelD->setObjectName(QStringLiteral("labelD"));

        horizontalLayout_10->addWidget(labelD);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        TButton = new QToolButton(layoutWidget3);
        buttonGroup->addButton(TButton);
        TButton->setObjectName(QStringLiteral("TButton"));
        TButton->setCheckable(true);

        horizontalLayout_11->addWidget(TButton);

        labelT = new QLabel(layoutWidget3);
        labelT->setObjectName(QStringLiteral("labelT"));

        horizontalLayout_11->addWidget(labelT);


        gridLayout->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        LogicBox->addItem(FlipFlop, QStringLiteral("Flip Flop"));

        gridLayout_2->addWidget(LogicBox, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Circuit Designer", Q_NULLPTR));
        actionMove->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        actionConnection->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        actionInputs->setText(QApplication::translate("MainWindow", "Inputs", Q_NULLPTR));
        actionOutputs->setText(QApplication::translate("MainWindow", "Outputs", Q_NULLPTR));
        inButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        inLabel->setText(QApplication::translate("MainWindow", "In", Q_NULLPTR));
        outButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        outLabel->setText(QApplication::translate("MainWindow", "Out", Q_NULLPTR));
        clockButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelClock->setText(QApplication::translate("MainWindow", "Clock", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(InOut), QApplication::translate("MainWindow", "InOut", Q_NULLPTR));
        andButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        andLabel->setText(QApplication::translate("MainWindow", "And", Q_NULLPTR));
        orButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        orLabel->setText(QApplication::translate("MainWindow", "Or", Q_NULLPTR));
        xorButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        xorLabel->setText(QApplication::translate("MainWindow", "Xor", Q_NULLPTR));
        nandButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        nandLabel->setText(QApplication::translate("MainWindow", "Nand", Q_NULLPTR));
        norButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        norLabel->setText(QApplication::translate("MainWindow", "Nor", Q_NULLPTR));
        idButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        idLabel->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        notButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        notLabel->setText(QApplication::translate("MainWindow", "Not", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Gates), QApplication::translate("MainWindow", "Gates", Q_NULLPTR));
        multiplexerButton->setText(QString());
        labelMultiplexer->setText(QApplication::translate("MainWindow", "Multiplexer", Q_NULLPTR));
        demultiplexerButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelDemultiplexer->setText(QApplication::translate("MainWindow", "Demultiplexer", Q_NULLPTR));
        decoderButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelDecoder->setText(QApplication::translate("MainWindow", "Decoder", Q_NULLPTR));
        encoderButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelEncoder->setText(QApplication::translate("MainWindow", "Encoder", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Plexers), QApplication::translate("MainWindow", "Plexers", Q_NULLPTR));
        adderButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelAdder->setText(QApplication::translate("MainWindow", "Adder", Q_NULLPTR));
        subtractorButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelSubtractor->setText(QApplication::translate("MainWindow", "Subtractor", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(Arithmetic), QApplication::translate("MainWindow", "Arithmetic", Q_NULLPTR));
        JKButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelJK->setText(QApplication::translate("MainWindow", "JK", Q_NULLPTR));
        SRButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelSR->setText(QApplication::translate("MainWindow", "SR", Q_NULLPTR));
        DButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelD->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        TButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        labelT->setText(QApplication::translate("MainWindow", "T", Q_NULLPTR));
        LogicBox->setItemText(LogicBox->indexOf(FlipFlop), QApplication::translate("MainWindow", "Flip Flop", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

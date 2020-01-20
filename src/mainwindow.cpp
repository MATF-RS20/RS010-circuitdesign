#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gateitem.h"
#include "scene.h"
#include "connection.h"
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>
#include <iostream>

#define SCENESIZE_W 1000
#define SCENESIZE_H 500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(QRectF(0, 0, SCENESIZE_W, SCENESIZE_H));
    ui->graphicsView->setScene(scene);

    setUp();
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    connect(scene, SIGNAL(itemInserted()),
            this, SLOT(itemInserted()));
    connect(ui->actionDelete, SIGNAL(triggered()),
            this, SLOT(deleteItem()));
    connect(ui->actionMove, SIGNAL(triggered()),
            this, SLOT(changeModMove()));
    connect(ui->actionConnection, SIGNAL(triggered()),
            this, SLOT(changeModConnect()));
    connect(ui->actionInputs, SIGNAL(triggered()),
            this, SLOT(setNumOfInputs()));

    ui->actionInputs->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeModMove()
{
  scene->setMode(Scene::MoveItem);
}
void MainWindow::changeModConnect()
{
  scene->setMode(Scene::InsertLine);
}


void MainWindow::setNumOfInputs()
{
   bool ok;
   int numOf;
   switch(dialogType){
     case InserInput:
       numOf = QInputDialog::getInt(this,"Input","Enter number of input:",1,1,8,1,&ok);
       break;
     case InsertSelector:
       numOf = QInputDialog::getInt(this,"Selector","Enter number of selectors:",1,1,5,1,&ok);
       break;
     case InsertArithmetic:
       numOf = QInputDialog::getInt(this,"Arithmetic","Enter size of number:",1,1,6,1,&ok);
   }

   scene->setNumOfInputs(numOf);
}

void MainWindow::setUp()
{
   ui->buttonGroup->setId(ui->andButton, LogicElement::And);
   ui->buttonGroup->setId(ui->clockButton, LogicElement::Clock);
   ui->buttonGroup->setId(ui->orButton, LogicElement::Or);
   ui->buttonGroup->setId(ui->xorButton, LogicElement::Xor);
   ui->buttonGroup->setId(ui->nandButton, LogicElement::Nand);
   ui->buttonGroup->setId(ui->norButton, LogicElement::Nor);
   ui->buttonGroup->setId(ui->idButton, LogicElement::Id);
   ui->buttonGroup->setId(ui->notButton, LogicElement::Not);
   ui->buttonGroup->setId(ui->inButton, LogicElement::In);
   ui->buttonGroup->setId(ui->outButton, LogicElement::Out);
   ui->buttonGroup->setId(ui->multiplexerButton, LogicElement::Multiplexer);
   ui->buttonGroup->setId(ui->demultiplexerButton, LogicElement::Demultiplexer);
   ui->buttonGroup->setId(ui->decoderButton, LogicElement::Decoder);
   ui->buttonGroup->setId(ui->encoderButton, LogicElement::Encoder);
   ui->buttonGroup->setId(ui->JKButton, LogicElement::JK);
   ui->buttonGroup->setId(ui->SRButton, LogicElement::SR);
   ui->buttonGroup->setId(ui->DButton, LogicElement::D);
   ui->buttonGroup->setId(ui->TButton, LogicElement::T);
   ui->buttonGroup->setId(ui->adderButton, LogicElement::Adder);
   ui->buttonGroup->setId(ui->subtractorButton , LogicElement::Subtractor);

   actionGroup = new QActionGroup(this);
   actionGroup->addAction(ui->actionDelete);
   actionGroup->addAction(ui->actionMove);
   actionGroup->addAction(ui->actionConnection);
   actionGroup->setExclusive(true);
}

void MainWindow::buttonGroupClicked(int id)
{
  if(actionGroup->checkedAction())
      actionGroup->checkedAction()->setChecked(false);
  scene->setElementType(LogicElement::ElementType(id));
  scene->setMode(Scene::InsertItem);

  if(id < LogicElement::Multiplexer)
  {
      ui->actionInputs->setEnabled(true);
      dialogType = InserInput;
  }
  else if(id < LogicElement::Adder)
  {
      ui->actionInputs->setEnabled(true);
      dialogType = InsertArithmetic;
  }
  else if(id < LogicElement::Decoder)
  {
      ui->actionInputs->setEnabled(true);
      dialogType = InsertSelector;
  }
  else
  {
      ui->actionInputs->setEnabled(false);
  }
}


void MainWindow::deleteItem()
{
  QList<QGraphicsItem *> selectedItems = scene->selectedItems();
  for (QGraphicsItem *item : qAsConst(selectedItems)) {
      if (item->type() == Connection::Type){
          scene->removeItem(item);
          Connection* conn = qgraphicsitem_cast<Connection*>(item);
          conn->startItem()->removeConnection(conn);
          conn->endItem()->removeConnection(conn);
          delete item;
       }
   }

  selectedItems = scene->selectedItems();
  for (QGraphicsItem *item : qAsConst(selectedItems))
  {
       if (item->type() == LogicElement::Type)
       {
            qgraphicsitem_cast<LogicElement *>(item)->removeConnections();
       }
       scene->removeItem(item);
       delete item;
  }

  ui->actionDelete->setChecked(false);
}

void MainWindow::itemInserted()
{
  ui->actionInputs->setEnabled(false);
  ui->buttonGroup->setExclusive(false);
  ui->buttonGroup->checkedButton()->setChecked(false);
  ui->buttonGroup->setExclusive(true);
  scene->setMode(Scene::MoveItem);
}

/*
void MainWindow::wheelEvent(QWheelEvent *event)
{
  if(event->delta() > 0)
    ui->graphicsView->scale(1.05, 1.05);
  else
    ui->graphicsView->scale(0.95, 0.95);
}
*/

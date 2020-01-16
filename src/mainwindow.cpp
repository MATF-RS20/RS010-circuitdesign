#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gateitem.h"
#include "scene.h"
#include "connection.h"
#include <QPixmap>
#include <QPainter>
#include <iostream>


#define SCENESIZE_W 1000
#define SCENESIZE_H 500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(QRectF(0, 0, SCENESIZE_W, SCENESIZE_H));

    setUpButtonsIds();
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    connect(scene, SIGNAL(itemInserted(LogicElement*)),
            this, SLOT(itemInserted(LogicElement*)));
    connect(ui->buttonGroupConnectMove, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupConnectMoveClicked(int)));
    connect(ui->trashButton, SIGNAL(clicked()), this, SLOT(deleteItem()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpButtonsIds(){
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
 ui->buttonGroup->setId(ui->SRButton, LogicElement::T);




 ui->buttonGroupConnectMove->setId(ui->connectButton,Scene::Mode::InsertLine);
 ui->buttonGroupConnectMove->setId(ui->moveButton,Scene::Mode::MoveItem);
}

void MainWindow::buttonGroupClicked(int id){
  scene->setElementType(LogicElement::ElementType(id));
  scene->setMode(Scene::InsertItem);
}


void MainWindow::buttonGroupConnectMoveClicked(int id){
  scene->setMode(Scene::Mode(id));
}


void MainWindow::deleteItem(){
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

}

void MainWindow::itemInserted(LogicElement* item){
  // zasto ne radi prva linija, zasto se button nakon iscrtavanja ne unchekira ?
  ui->buttonGroup->button(item->elementType())->setChecked(false);
  scene->setMode(Scene::MoveItem);
}


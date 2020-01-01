#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gateitem.h"
#include "scene.h"
#include "connection.h"
#include <QPixmap>
#include <QPainter>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(QRectF(0, 0, 1000, 500));

    setUpButtonsIds();
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    connect(scene, SIGNAL(itemInserted(GateItem*)),
            this, SLOT(itemInserted(GateItem*)));
    connect(ui->buttonGroupConnectMove, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupConnectMoveClicked(int)));
    connect(ui->trashButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpButtonsIds(){
 ui->buttonGroup->setId(ui->andButton, GateItem::And);
 ui->buttonGroup->setId(ui->orButton, GateItem::Or);
 ui->buttonGroup->setId(ui->xorButton, GateItem::Xor);
 ui->buttonGroup->setId(ui->nandButton, GateItem::Nand);
 ui->buttonGroup->setId(ui->norButton, GateItem::Nor);
 ui->buttonGroup->setId(ui->notButton, GateItem::Not);
 ui->buttonGroup->setId(ui->inButton, GateItem::In);
 ui->buttonGroup->setId(ui->outButton, GateItem::Out);

 ui->buttonGroupConnectMove->setId(ui->connectButton,Scene::Mode::InsertLine);
 ui->buttonGroupConnectMove->setId(ui->moveButton,Scene::Mode::MoveItem);
}

void MainWindow::buttonGroupClicked(int id){
  scene->setItemType(GateItem::GateType(id));
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
  for (QGraphicsItem *item : qAsConst(selectedItems)) {
       if (item->type() == GateItem::Type)
           qgraphicsitem_cast<GateItem*>(item)->removeConnections();
       scene->removeItem(item);
       delete item;
   }
}

void MainWindow::itemInserted(GateItem* item){
  // zasto ne radi prva linija, zasto se button nakon iscrtavanja ne unchekira ?
  ui->buttonGroup->button(item->gateType())->setChecked(false);
  scene->setMode(Scene::MoveItem);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gateitem.h"
#include "scene.h"
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
    connect(scene, SIGNAL(itemInserted(GateItem*)),
            this, SLOT(itemInserted(GateItem*)));
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    connect(ui->buttonGroupConnectMove, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupConnectMoveClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpButtonsIds(){
 ui->buttonGroup->setId(ui->andButton, 0);
 ui->buttonGroup->setId(ui->orButton, 1);
 ui->buttonGroup->setId(ui->xorButton, 2);
 ui->buttonGroup->setId(ui->nandButton, 3);
 ui->buttonGroup->setId(ui->norButton, 4);
 ui->buttonGroup->setId(ui->notButton, 5);

 ui->buttonGroupConnectMove->setId(ui->connectButton,1);
 ui->buttonGroupConnectMove->setId(ui->moveButton,2);
}

void MainWindow::buttonGroupClicked(int id){
  scene->setItemType(GateItem::GateType(id));
  scene->setMode(Scene::InsertItem);
}

void MainWindow::buttonGroupConnectMoveClicked(int id){
  scene->setMode(Scene::Mode(id));
}


void MainWindow::deleteItem(){
  /*  QList<QGraphicsItem *> selectedItems = scene->selectedItems();
  for (QGraphicsItem *item : qAsConst(selectedItems)) {
      if(item->type() == Connection)
      if (item->type() == GateItem::Type)
          qgraphicsitem_cast<GateItem *>(item)->removeConnections();
       scene->removeItem(item);
       delete item;
  }*/
}

void MainWindow::itemInserted(GateItem* item){
  // zasto ne radi prva linija, zasto se button nakon iscrtavanja ne unchekira ?
  ui->buttonGroup->button(item->gateType())->setChecked(false);
  scene->setMode(Scene::MoveItem);
}


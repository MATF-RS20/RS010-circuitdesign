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
}

void MainWindow::buttonGroupClicked(int id){
  //  std::cout << "buttonGroupClicked on " << id << " " << GateItem::GateType(id)<< std::endl;

  /*
   Umesto ovoga sam stavila buttonGroup exclusive
   QButtonGroup* buttonGroup = ui->buttonGroup;
   const QList<QAbstractButton*> buttons = buttonGroup->buttons();
      for (QAbstractButton *button : buttons) {
         if (buttonGroup->button(id) != button)
              button->setChecked(false);
       }
  */

  scene->setItemType(GateItem::GateType(id));
  scene->setMode(Scene::InsertItem);
}

void MainWindow::deleteItem(){
  QList<QGraphicsItem *> selectedItems = scene->selectedItems();
  selectedItems = scene->selectedItems();
  for (QGraphicsItem *item : qAsConst(selectedItems)) {
       //if (item->type() == GateItem::Type)
         //  qgraphicsitem_cast<GateItem *>(item)->removeArrows();
       scene->removeItem(item);
       delete item;
  }
}

void MainWindow::itemInserted(GateItem* item){
   // ui->buttonGroup->button(int(GateItem::MoveItem))->setChecked(true);
  QButtonGroup* buttonGroup = ui->buttonGroup;

  //pointerTypeGroup->button(int(DiagramScene::MoveItem))->setChecked(true);
   //scene->setMode(Scene::Mode(pointerTypeGroup->checkedId()));
  buttonGroup->button(int(item->gateType()))->setChecked(false);
  std::cout << "ItemInserted " << std::endl;
}

/*
void MainWindow::paintEvent(QPaintEvent *event)
{
  std::cout << "paintEvent" << std::endl;
}
*/


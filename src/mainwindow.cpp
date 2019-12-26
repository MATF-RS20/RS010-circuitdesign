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
    scene = new Scene(this);
    ui->setupUi(this);

    setUpButtonsIds();
    connect(scene, &Scene::itemInserted,
            this, &MainWindow::itemInserted);
    connect(ui->buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::buttonGroupClicked);
   // view = ui->graphicsView;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpButtonsIds(){
 ui->buttonGroup->setId(ui->andButton, 1);
 ui->buttonGroup->setId(ui->orButton, 2);
 ui->buttonGroup->setId(ui->xorButton, 3);
 ui->buttonGroup->setId(ui->nandButton, 4);
 ui->buttonGroup->setId(ui->norButton, 5);
 ui->buttonGroup->setId(ui->notButton, 6);
}

void MainWindow::buttonGroupClicked(int id){
  std::cout << "buttonGroupClicked on " << id << " " << GateItem::GateType(id)<< std::endl;
  QButtonGroup* buttonGroup = ui->buttonGroup;
  const QList<QAbstractButton*> buttons = buttonGroup->buttons();
  for (QAbstractButton *button : buttons) {
      if (buttonGroup->button(id) != button)
          button->setChecked(false);
  }

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
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}


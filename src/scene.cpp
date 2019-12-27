#include "scene.h"
#include <iostream>

Scene::Scene(QObject* parent)
  : QGraphicsScene(parent)
{
  myItemType = GateItem::And;
  myMode = MoveItem;
  line = nullptr;
}

void Scene::setMode(Mode mode) {
  myMode = mode;
}

void Scene::setItemType(GateItem::GateType type){
  myItemType = type;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
 // if (event->button() != Qt::LeftButton)
 //   return;

  GateItem* item;
  switch (myMode){
    case InsertItem:
      item = new GateItem(myItemType);
      addItem(item);
      item->setPos(event->scenePos());
      emit itemInserted(item);
      myMode = MoveItem;
      break;
    case InsertLine:
      line = new QGraphicsLineItem(QLineF(event->scenePos(),
                                  event->scenePos()));
      addItem(line);
      break;
    default:
      ;
  }
  QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(myMode == InsertLine && line != nullptr){
        QLineF newLine(line->line().p1(), event->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem){
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    /*
      if (line != nullptr && myMode == InsertLine){
            QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == GateItem::Type &&
            endItems.first()->type() == GateItem::Type &&
            startItems.first() != endItems.first()) {
            GateItem *startItem = qgraphicsitem_cast<GateItem *>(startItems.first());
            GateItem *endItem = qgraphicsitem_cast<GateItem *>(endItems.first());
              Arrow *arrow = new Arrow(startItem, endItem);
              arrow->setColor(myLineColor);
              startItem->addArrow(arrow);
              endItem->addArrow(arrow);
              arrow->setZValue(-1000.0);
              addItem(arrow);
              arrow->updatePosition();
        }
    }

  line = nullptr;
  */
  QGraphicsScene::mouseReleaseEvent(event);
}

bool Scene::isItemChange(int type) const{
  const QList<QGraphicsItem *> items = selectedItems();
  const auto cb = [type](const QGraphicsItem *item) { return item->type() == type; };
  return std::find_if(items.begin(), items.end(), cb) != items.end();
}

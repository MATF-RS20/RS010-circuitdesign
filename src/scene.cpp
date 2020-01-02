#include "scene.h"
#include "connection.h"
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

  GateItem* item;
  switch (myMode){
    case InsertItem:
      item = getNewGateItem(myItemType);
      addItem(item);
      item->setPos(event->scenePos());
      emit itemInserted(item);
      break;
    case InsertLine:
      line = new QGraphicsLineItem(QLineF(event->scenePos(),
                                  event->scenePos()));
      addItem(line);
      break;
    case MoveItem:
      QList<QGraphicsItem *> selectedItems = items(event->scenePos());
      for(QGraphicsItem* selected: selectedItems)
      {
        if(selected->type() == GateItem::Type)
        {
           GateItem* item = qgraphicsitem_cast<GateItem*>(selected);
           if(item->gateType() == GateItem::GateType::In)
           {
              item->calculate();
              item->update();
           }
        }
      }
  }
  QGraphicsScene::mousePressEvent(event);
}

GateItem* Scene::getNewGateItem(GateItem::GateType type){
  switch (type) {
    case GateItem::GateType::In:
      return new InputGate();
    case GateItem::GateType::Out:
      return new OutputGate();
    case GateItem::GateType::And:
      return new And();
    case GateItem::GateType::Or:
      return new Or();
    case GateItem::GateType::Xor:
      return new Xor();
    case GateItem::GateType::Nand:
      return new Nand();
    case GateItem::GateType::Nor:
      return new Nor();
    case GateItem::GateType::Not:
      return new Not();
   }
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
      if (line != nullptr && myMode == InsertLine){
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0
        && (startItems.first()->type() == GateItem::Type)
        && (endItems.first()->type() == GateItem::Type)
        && startItems.first() != endItems.first()) {
            GateItem *startItem = qgraphicsitem_cast<GateItem *>(startItems.first());
            GateItem *endItem = qgraphicsitem_cast<GateItem *>(endItems.first());
            if(startItem->gateType() != GateItem::GateType::Out && endItem->gateType() != GateItem::GateType::In)
            {
              Connection *conn = new Connection(startItem, endItem);
              if(startItem->addConnection(conn))
              {
                if(endItem->addConnection(conn))
                {
                  addItem(conn);
                  conn->updatePosition();
                }
                else
                {
                  startItem->removeConnection(conn);
                  delete conn;
                }
              }
              else
              {
                 delete conn;
              }
            }
        }
    }

  line = nullptr;

  QGraphicsScene::mouseReleaseEvent(event);
}

bool Scene::isItemChange(int type) const{
  const QList<QGraphicsItem *> items = selectedItems();
  const auto cb = [type](const QGraphicsItem *item) { return item->type() == type; };
  return std::find_if(items.begin(), items.end(), cb) != items.end();
}

#include "scene.h"
#include "connection.h"
#include <iostream>

Scene::Scene(QObject* parent)
  : QGraphicsScene(parent)
{
  myItemType = LogicElement::And;
  myMode = MoveItem;
  line = nullptr;

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()),this, SLOT(update()));
  timer->start(10);
}

void Scene::setMode(Mode mode)
{
  myMode = mode;
}

void Scene::setElementType(LogicElement::ElementType type)
{
  myItemType = type;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

  LogicElement* item;
  switch (myMode)
  {
    case InsertItem:
        item = getNewElement(myItemType);
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
            if(selected->type() == LogicElement::Type)
            {
                LogicElement* item = qgraphicsitem_cast<LogicElement*>(selected);
                if(item->elementType() == LogicElement::ElementType::In)
                {
                    item->calculate();
                    item->update();
                }
            }
        }
  }

  QGraphicsScene::mousePressEvent(event);
}

LogicElement* Scene::getNewElement(LogicElement::ElementType type){
  switch (type) {
    case LogicElement::ElementType::In:
      return new InputGate();
    case LogicElement::ElementType::Clock:
      return new ClockGate();
    case LogicElement::ElementType::Out:
      return new OutputGate();
    case LogicElement::ElementType::And:
      return new And();
    case LogicElement::ElementType::Or:
      return new Or();
    case LogicElement::ElementType::Xor:
      return new Xor();
    case LogicElement::ElementType::Nand:
      return new Nand();
    case LogicElement::ElementType::Nor:
      return new Nor();
    case LogicElement::ElementType::Not:
      return new Not();
    case LogicElement::ElementType::Multiplexer:
      return new Multiplexer();
    case LogicElement::ElementType::Id:
      return new Id();
    case LogicElement::ElementType::Demultiplexer:
      return new Demultiplexer();
    case LogicElement::ElementType::Decoder:
      return new Decoder();
    case LogicElement::ElementType::Encoder:
      return new Encoder();
  }
}


void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(myMode == InsertLine && line != nullptr)
    {
        QLineF newLine(line->line().p1(), event->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem)
    {
        QGraphicsScene::mouseMoveEvent(event);
    }

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
      if (line != nullptr && myMode == InsertLine)
      {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();


        QPointF positionStart = line->line().p1();
        QPointF positionEnd = line->line().p2();
        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0
        && (startItems.first()->type() == LogicElement::Type)
        && (endItems.first()->type() == LogicElement::Type)
        && startItems.first() != endItems.first())
        {
            LogicElement *startItem = qgraphicsitem_cast<LogicElement *>(startItems.first());
            LogicElement *endItem = qgraphicsitem_cast<LogicElement *>(endItems.first());

            Connection *conn = new Connection(startItem,endItem);
            bool success1 = startItem->addConnection(conn, LogicElement::StartItem, positionStart);
            bool success2 = endItem->addConnection(conn, LogicElement::EndItem, positionEnd);

            if(!(success1 && success2))
            {
                startItem->removeConnection(conn);
                endItem->removeConnection(conn);
                delete conn;
            }
            else
            {
               addItem(conn);
            }
        }
      }

  line = nullptr;
  QGraphicsScene::mouseReleaseEvent(event);
}





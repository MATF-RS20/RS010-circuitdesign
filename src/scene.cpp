#include "scene.h"
#include "connection.h"
#include <iostream>

Scene::Scene(QObject* parent)
  : QGraphicsScene(parent)
{
  myItemType = LogicElement::And;
  myMode = MoveItem;
  line = nullptr;
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

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0
        && (startItems.first()->type() == LogicElement::Type)
        && (endItems.first()->type() == LogicElement::Type)
        && startItems.first() != endItems.first())
        {
            LogicElement *startItem = qgraphicsitem_cast<LogicElement *>(startItems.first());
            LogicElement *endItem = qgraphicsitem_cast<LogicElement *>(endItems.first());

            /*
            Connection *conn = new Connection(startItem,endItem);
            if(!startItem->addConnection(conn))
                delete conn;
            else if(!endItem->addConnection(conn)){
                delete conn;
            }
            */


           /* if (startItem->elementType() == LogicElement::Multiplexer)
            {
                mouseReleaseMultiplexerStart(startItem, endItem, line->line().p2());
            }
            else if (startItem->elementType() == LogicElement::In)

            if (endItem->elementType() == LogicElement::Multiplexer)
            {
                mouseReleaseMultiplexerEnd(startItem, endItem);
            }

            if(startItem->type() == InputGate::Type){
                Connection* conn
            }
            else if(endItem->type() == OutputGate::Type){

            }*/


            /*if (endItem->elementType() == LogicElement::Multiplexer)
                mouseReleaseMultiplexerEnd(startItem, endItem,line->line().p2());
            else if(startItem->elementType() == LogicElement::Multiplexer)
                mouseReleaseMultiplexerStart(startItem,endItem);
            else{
                Connection *conn = new Connection(startItem, endItem);
                if(startItem->addConnection(conn))
                {
                  if(endItem->addConnection(conn))
                  {
                    addItem(conn);
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
            }*/
          }
      }

  line = nullptr;
  QGraphicsScene::mouseReleaseEvent(event);
}



void Scene::mouseReleaseMultiplexerEnd(GateItem* startItem, GateItem* endItem,QPointF endPoint)
{
  QPointF position = endItem->pos();
  qreal posX = position.rx();
  qreal posY = position.ry();
  qreal endX = endPoint.rx();
  qreal endY = endPoint.ry();

  Multiplexer* item = qgraphicsitem_cast<Multiplexer*>(endItem);
  if(endX < posX + qreal(60)){
    if(endY < posY + qreal(50)){
        std::cout << "added and0" << std::endl;
       Multiplexer::connect(startItem, item->AndGates[0]);
    } else if( endY < posY + qreal(100)){
        std::cout << "added and1" << std::endl;
        Multiplexer::connect(startItem, item->AndGates[1]);
    } else if(endY < posY + qreal(150)){
        std::cout << "added and2" << std::endl;
        Multiplexer::connect(startItem, item->AndGates[2]);
    } else if(endY < posY + qreal(200)) {
        std::cout << "added and3" << std::endl;
        Multiplexer::connect(startItem, item->AndGates[3]);
    }

    Connection* conn = new Connection(startItem,item);
    item->addConnection(conn);
    startItem->addConnection(conn);
    addItem(conn);

  } else {
    if(endX < posX + qreal(120)){
      std::cout << "added s1" << std::endl;
        Multiplexer::connect(startItem, item->NotGates[1]);
        Multiplexer::connect(startItem, item->AndGates[2]);
        Multiplexer::connect(startItem, item->AndGates[3]);
    } else{
      std::cout << "added s0" << std::endl;
        Multiplexer::connect(startItem, item->NotGates[0]);
        Multiplexer::connect(startItem, item->AndGates[1]);
        Multiplexer::connect(startItem, item->AndGates[3]);
    }
    Connection* conn = new Connection(startItem,item);
    //item->addConnection(conn);
    startItem->addConnection(conn);
    item->addSelector(conn);
    addItem(conn);
   }
}

void Scene::mouseReleaseMultiplexerStart(GateItem *startItem, GateItem *endItem){
  Multiplexer* item = qgraphicsitem_cast<Multiplexer*>(startItem);

  Connection* conn = new Connection(item,endItem);
  item->addConnection(conn);
  endItem->addConnection(conn);
  addItem(conn);
}


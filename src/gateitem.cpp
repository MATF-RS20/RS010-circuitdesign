#include "gateitem.h"
#include <iostream>
#include "connection.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

GateItem::GateItem(GateType type, QGraphicsItem* parent)
  : QGraphicsRectItem(parent), myGateType(type)
{
    switch (myGateType) {
      case And:
        pixmap.load("../images/and.png");
        break;
      case Or:
        pixmap.load("../images/or.png");
        break;
      case Xor:
        pixmap.load("../images/xor.png");
        break;
      case Nand:
        pixmap.load("../images/nand.png");
        break;
      case Nor:
        pixmap.load("../images/nor.png");
        break;
      case Not:
        pixmap.load("../images/not.png");
        break;
      case In:
        pixmap.load("../images/in_false.png");
        break;
      case Out:
        pixmap.load("../images/out_false.png");
        break;
    }

    myValue = false;
    setRect(0,0,70,50);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,true);
}

GateItem::~GateItem()
{
}

bool GateItem::getValue() const
{
  return myValue;
}

void GateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  painter->drawPixmap(0,0,70,50,pixmap);
}

InputGate::InputGate()
  : GateItem(GateItem::GateType::In)
{}

InputGate::~InputGate()
{
  for (Connection *conn : connectionsFrom)
  {
    conn->endItem()->removeConnection(conn);
    scene()->removeItem(conn);
    delete conn;
  }
}

void InputGate::removeConnection(Connection *conn)
{
  connectionsFrom.removeAll(conn);
}

void InputGate::addConnection(Connection *conn)
{
  connectionsFrom.append(conn);
}

OutputGate::OutputGate()
 : GateItem(GateItem::GateType::Out)
{}

OutputGate::~OutputGate()
{
  connection->startItem()->removeConnection(connection);
  scene()->removeItem(connection);
  delete connection;
}

void OutputGate::removeConnection(Connection*)
{
   return;
}

void OutputGate::addConnection(Connection* conn)
{
  connection = conn;
}

InnerGate::InnerGate(GateType type)
  : GateItem(type)
{}

InnerGate::~InnerGate()
{
  for(Connection* conn: connectionTo){
    conn->startItem()->removeConnection(conn);
    scene()->removeItem(conn);
    delete conn;
  }

  for(Connection* conn: connectionFrom){
      conn->endItem()->removeConnection(conn);
      scene()->removeItem(conn);
      delete conn;
  }
}



/*
void GateItem::removeConnection(Connection *conn){
    connections.removeAll(conn);
}

void GateItem::removeConnections(){
  for (Connection * conn : connections){
      conn->startItem()->removeConnection(conn);
      conn->endItem()->removeConnection(conn);
      scene()->removeItem(conn);
      delete conn;
   }
}

void GateItem::addConnection(Connection *conn){
  connections.append(conn);
}
*/

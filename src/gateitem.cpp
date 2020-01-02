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

void InputGate::removeConnections()
{
  for (Connection *conn : connectionsFrom)
  {
    conn->endItem()->removeConnection(conn);
    conn->startItem()->removeConnection(conn);
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

void OutputGate::removeConnections()
{
  if(!connection.empty())
  {
    connection.first()->startItem()->removeConnection(connection.first());
    connection.first()->endItem()->removeConnection(connection.first());
    scene()->removeItem(connection.first());
    delete connection.first();
  }
}

void OutputGate::removeConnection(Connection* conn)
{
   connection.removeAll(conn);
}

void OutputGate::addConnection(Connection* conn)
{
  connection.append(conn);
  calculate();
}


InnerGate::InnerGate(GateType type)
  : GateItem(type)
{}

void InnerGate::removeConnections()
{
  for(Connection* conn: connectionTo)
  {
    conn->startItem()->removeConnection(conn);
    conn->endItem()->removeConnection(conn);
    scene()->removeItem(conn);
    delete conn;
  }

  for(Connection* conn: connectionFrom)
  {
      conn->startItem()->removeConnection(conn);
      conn->endItem()->removeConnection(conn);
      scene()->removeItem(conn);
      delete conn;
  }
}

void InnerGate::addConnection(Connection *conn)
{
  if(conn->startItem() == this)
  {
    connectionFrom.append(conn);
  }
  else
  {
    connectionTo.append(conn);
    calculate();
  }
}

void InnerGate::removeConnection(Connection *conn)
{
  if(conn->startItem() == this){
      connectionFrom.removeAll(conn);
  }
  else
  {
    connectionTo.removeAll(conn);
    calculate();
  }
}


And::And()
  : InnerGate(GateItem::GateType::And)
{}

Or::Or()
  : InnerGate(GateItem::GateType::Or)
{}

Xor::Xor()
  : InnerGate(GateItem::GateType::Xor)
{}

Nand::Nand()
  : InnerGate(GateItem::GateType::Nand)
{}

Nor::Nor()
  : InnerGate(GateItem::GateType::Nor)
{}

Not::Not()
  : InnerGate(GateItem::GateType::Not)
{}


/* Calculate functions **************************/

void InputGate::calculate()
{
  myValue = !myValue;
  myValue ? pixmap.load("../images/in_true.png") : pixmap.load("../images/in_false.png");

  for(Connection* conn : connectionsFrom)
    conn->endItem()->calculate();
}

void OutputGate::calculate()
{
  myValue = connection.front()->startItem()->getValue();
  std::cout << myValue << std::endl;
  myValue ? pixmap.load("../images/out_true.png") : pixmap.load("../images/out_false.png");
  this->update();
}

void And::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionTo )
     newValue = newValue && conn->startItem()->getValue();
  myValue = newValue;
  for(Connection* conn: connectionFrom)
      conn->endItem()->calculate();
}

void Or::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionTo)
     newValue = newValue || conn->startItem()->getValue();
  myValue = newValue;
  for(Connection* conn: connectionFrom)
      conn->endItem()->calculate();
}

void Xor::calculate()
{
  unsigned numTrue = 0;
  for(Connection* conn: connectionTo)
    if (conn->startItem()->getValue() == true)
      numTrue++;
  myValue = numTrue % 2 == 0 ? false : true;

  for(Connection* conn: connectionFrom)
      conn->endItem()->calculate();
}

void Nand::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionTo )
     newValue = newValue && conn->startItem()->getValue();
  myValue = !newValue;
  for(Connection* conn: connectionFrom)
      conn->endItem()->calculate();
}

void Nor::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionTo)
     newValue = newValue || conn->startItem()->getValue();
  myValue = !newValue;
  for(Connection* conn: connectionFrom)
      conn->endItem()->calculate();
}

void Not::calculate()
{
   myValue = !(connectionTo.front()->startItem()->getValue());
   for(Connection* conn: connectionFrom)
       conn->endItem()->calculate();
}

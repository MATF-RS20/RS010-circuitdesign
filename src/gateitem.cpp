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
      case Multiplexer:
        pixmap.load("../images/multiplexer.png");
        break;
    }

    myValue = false;
    setRect(0,0,100,100);
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
  const auto connectionsFromCopy = connectionsFrom;
  for (Connection *conn : connectionsFromCopy)
  {
    conn->endItem()->removeConnection(conn);
    this->removeConnection(conn);

    // OVDE PUCA!!!
    if(conn->scene() != nullptr){
        std::cout << "Uslo u if" << std::endl;
        conn->scene()->removeItem(conn);  
    }
    delete conn;
  }
}

void InputGate::removeConnection(Connection *conn)
{
  connectionsFrom.removeAll(conn);
}

bool InputGate::addConnection(Connection *conn)
{
  if(conn->endItem() == this)
    return false;
  connectionsFrom.append(conn);
  return true;
}

/*
void InputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0,0,45,45);
  painter->drawPixmap(0,0,45,45,pixmap);
}*/

OutputGate::OutputGate()
 : GateItem(GateItem::GateType::Out)
{}

void OutputGate::removeConnections()
{
  if(!connection.empty())
  {
    connection.first()->startItem()->removeConnection(connection.first());
    this->removeConnection(connection.first());
    scene()->removeItem(connection.first());
    delete connection.first();
  }
}

void OutputGate::removeConnection(Connection* conn)
{
   connection.removeAll(conn);
}

bool OutputGate::addConnection(Connection* conn)
{
  if(connection.size() != 0)
    return false;

  connection.append(conn);
  calculate();
  return  true;
}

/*
void OutputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0,0,45,45);
  painter->drawPixmap(0,0,50,30,pixmap);
}*/

InnerGate::InnerGate(GateType type)
  : GateItem(type)
{}

void InnerGate::removeConnections()
{
  const auto connectionsToCopy = connectionsTo;
  for(Connection* conn: connectionsToCopy)
  {
    conn->startItem()->removeConnection(conn);
    this->removeConnection(conn);
    scene()->removeItem(conn);
    delete conn;
  }

  const auto connectionsFromCopy = connectionsFrom;
  for(Connection* conn: connectionsFromCopy)
  {
      this->removeConnection(conn);
      conn->endItem()->removeConnection(conn);
      scene()->removeItem(conn);
      delete conn;
  }
}

bool InnerGate::addConnection(Connection *conn)
{
  if(conn->startItem() == this)
  {
    //Ako je u pitanju povezivanje od ovog elementa.
    connectionsFrom.append(conn);
  }
  else
  {
    if(gateType() == GateItem::GateType::Not && connectionsTo.size() != 0)
      return false;

    connectionsTo.append(conn);
    calculate();
  }
  return true;
}

void InnerGate::removeConnection(Connection *conn)
{
  if(conn->startItem() == this){
      connectionsFrom.removeAll(conn);
  }
  else
  {
    connectionsTo.removeAll(conn);
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
  myValue ? pixmap.load("../images/out_true.png") : pixmap.load("../images/out_false.png");
  this->update();
}

void And::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionsTo )
     newValue = newValue && conn->startItem()->getValue();
  myValue = newValue;
  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Or::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionsTo)
     newValue = newValue || conn->startItem()->getValue();
  myValue = newValue;
  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Xor::calculate()
{
  unsigned numTrue = 0;
  for(Connection* conn: connectionsTo)
    if (conn->startItem()->getValue() == true)
      numTrue++;
  myValue = numTrue % 2 == 0 ? false : true;

  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Nand::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionsTo )
     newValue = newValue && conn->startItem()->getValue();
  myValue = !newValue;
  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Nor::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionsTo)
     newValue = newValue || conn->startItem()->getValue();
  myValue = !newValue;
  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Not::calculate()
{
   myValue = !(connectionsTo.front()->startItem()->getValue());
   for(Connection* conn: connectionsFrom)
       conn->endItem()->calculate();
}


Multiplexer::Multiplexer()
  :InnerGate(GateItem::Multiplexer)
{

  NotGates.append(new class Not());
  NotGates.append(new class Not());
  AndGates.append(new class And());
  AndGates.append(new class And());
  AndGates.append(new class And());
  AndGates.append(new class And());
  OrGate = new class Or();

  for(class And* andG: AndGates){
      connect(andG, OrGate);
      for(class Not* notG : NotGates)
        connect(notG,andG);
  }
}

void Multiplexer::calculate(){
  OrGate->calculate();
  myValue = OrGate->getValue();
}


void Multiplexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
   setRect(0,0,250,180);
   painter->drawPixmap(0,0,250,180,pixmap);
}

Connection* Multiplexer::connect(GateItem* g1, GateItem* g2){
    Connection* conn = new Connection(g1,g2);
    g1->addConnection(conn);
    g2->addConnection(conn);

    return conn;
}


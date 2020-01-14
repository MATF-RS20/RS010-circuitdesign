#include "gateitem.h"
#include <iostream>
#include <cmath>
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
    Connection* conn = connection.first();
    conn->startItem()->removeConnection(conn);
    this->removeConnection(conn);
    if(conn->scene() != nullptr)
      scene()->removeItem(conn);
    delete conn;
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
    if(conn->scene() != nullptr)
       conn->scene()->removeItem(conn);
    delete conn;
  }

  const auto connectionsFromCopy = connectionsFrom;
  for(Connection* conn: connectionsFromCopy)
  {
      this->removeConnection(conn);
      conn->endItem()->removeConnection(conn);
      if(conn->scene() != nullptr)
        conn->scene()->removeItem(conn);
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

void And::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(10,10,50,10);
    painter->drawLine(10,10,10,60);
    painter->drawLine(10,60,50,60);
    painter->drawArc(QRect(35,10,30,50), -90*16, 180*16);

    painter->drawLine(0, 20, 10, 20);
    painter->drawLine(0, 50, 10, 50);
    painter->drawLine(65, 35, 75, 35);

    setRect(0, 0, 77, 62);
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

void Or::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawArc(QRect(0,10,20,50), -90*16, 180*16);
    painter->drawLine(10, 10, 30, 10);
    painter->drawLine(10, 60, 30, 60);

    painter->drawArc(QRect(-20,10,100,50), 0, 90*16);
    painter->drawArc(QRect(-20,10,100,50), -90*16, 90*16);

    painter->drawLine(0, 20, 17, 20);
    painter->drawLine(0, 50, 17, 50);
    painter->drawLine(79, 35, 89, 35);

    setRect(0, 0, 91, 62);
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

void Xor::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawArc(QRect(0,10,20,50), -90*16, 180*16);
    painter->drawArc(QRect(-5,10,20,50), -90*16, 180*16);
    painter->drawLine(10, 10, 30, 10);
    painter->drawLine(10, 60, 30, 60);

    painter->drawArc(QRect(-20,10,100,50), 0, 90*16);
    painter->drawArc(QRect(-20,10,100,50), -90*16, 90*16);

    painter->drawLine(0, 20, 12, 20);
    painter->drawLine(0, 50, 12, 50);
    painter->drawLine(79, 35, 89, 35);

    setRect(0, 0, 91, 62);
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

void Nand::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(10,10,50,10);
    painter->drawLine(10,10,10,60);
    painter->drawLine(10,60,50,60);
    painter->drawArc(QRect(35,10,30,50), -90*16, 180*16);

    QPointF center(69, 35);
    painter->drawEllipse(center, 4, 4);

    painter->drawLine(0, 20, 10, 20);
    painter->drawLine(0, 50, 10, 50);
    painter->drawLine(73, 35, 83, 35);

    setRect(0, 0, 85, 62);
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

void Nor::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawArc(QRect(0,10,20,50), -90*16, 180*16);
    painter->drawLine(10, 10, 30, 10);
    painter->drawLine(10, 60, 30, 60);

    painter->drawArc(QRect(-20,10,100,50), 0, 90*16);
    painter->drawArc(QRect(-20,10,100,50), -90*16, 90*16);

    QPointF center(84, 35);
    painter->drawEllipse(center, 4, 4);

    painter->drawLine(0, 20, 17, 20);
    painter->drawLine(0, 50, 17, 50);
    painter->drawLine(88, 35, 98, 35);

    setRect(0, 0, 100, 62);
}

void Not::calculate()
{
   myValue = !(connectionsTo.front()->startItem()->getValue());
   for(Connection* conn: connectionsFrom)
       conn->endItem()->calculate();
}

void Not::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(10, 10, 40, 25);
    painter->drawLine(10, 10, 10, 40);
    painter->drawLine(10, 40, 40, 25);

    painter->drawLine(0, 25, 10, 25);
    QPointF center(44, 25);
    painter->drawEllipse(center, 4, 4);
    painter->drawLine(48, 25, 58, 25);

    setRect(0, 0, 60, 42);
}


Multiplexer::Multiplexer()
  :InnerGate(GateItem::Multiplexer)
{

  for(int i=0;i < numOfNot; i++){
    NotGates.append(new class Not());
  }

  for(int i=0;i < numOfAnd; i++){
    AndGates.append(new class And());
  }

  OrGate = new class Or();

// konektovanje svih elemenata medjusobno
for(int i = 0; i < AndGates.size(); i++){
    for(int j = 0; j <NotGates.size(); j++){
        if(!getBit(i,j))
          connect(NotGates[j], AndGates[i]);
     }
    connect(AndGates[i], OrGate);
  }
}

int Multiplexer::getBit(int n,int k){
  int mask =  1 << k;
  int masked_n = n & mask;
  int thebit = masked_n >> k;
  return thebit;
}

void Multiplexer::calculate(){
  OrGate->calculate();
  myValue = OrGate->getValue();
  for(Connection* conn: connectionsFrom){
      conn->endItem()->calculate();
  }
}


void Multiplexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
   painter->drawRect(10, 10, 80, 100);

   painter->drawLine(0, 30, 10, 30);
   painter->drawLine(0, 50, 10, 50);
   painter->drawLine(0, 70, 10, 70);
   painter->drawLine(0, 90, 10, 90);

   painter->drawLine(90, 60, 100, 60);

   painter->drawLine(40, 110, 40, 120);
   painter->drawLine(60, 110, 60, 120);

   setRect(0, 0, 102, 122);
}

Connection* Multiplexer::connect(GateItem* g1, GateItem* g2){
    Connection* conn = new Connection(g1,g2);
    g1->addConnection(conn);
    g2->addConnection(conn);

    return conn;
}


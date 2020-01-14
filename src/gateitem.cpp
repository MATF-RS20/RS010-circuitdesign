#include "gateitem.h"
#include <iostream>
#include <cmath>
#include "connection.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

#define GATESIZE_X 70.0
#define GATESIZE_Y 50.0
#define PLEXERSIZE_X 250.0
#define PLEXERSIZE_Y 180.0
#define INOUTSIZE_X 35.0
#define INOUTSIZE_Y 25.0

LogicElement::LogicElement(ElementType type, QGraphicsItem* parent)
  : QGraphicsRectItem(parent), myElementType(type)
{
    switch (myElementType) {
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
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,true);
}

bool LogicElement::getValue() const
{
  return myValue;
}

QPointF LogicElement::getConnPosIn(Connection*){
   return QPointF(0,GATESIZE_Y/2);
}

QPointF LogicElement::getConnPosOut(Connection*){
  return QPointF(GATESIZE_X, GATESIZE_Y/2);
}

/******************************************************************************************/

InputGate::InputGate()
  : LogicElement(LogicElement::ElementType::In)
{}


bool InputGate::addConnection(Connection *conn)
{
  // pokusati implementirati proveru mogucnosti povezivanja ovde
  if(conn->endItem() == this)
     return false;
  connectionsFrom.append(conn);
  return true;
}

void InputGate::removeConnection(Connection *conn)
{
  connectionsFrom.removeAll(conn);
}

void InputGate::removeConnections()
{
  const auto connectionsFromCopy = connectionsFrom;
  for (Connection *conn : connectionsFromCopy)
  {
    conn->endItem()->removeConnection(conn);
    this->removeConnection(conn);

    if(conn->scene() != nullptr){
        conn->scene()->removeItem(conn);  
    }
    delete conn;
  }
}

void InputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0, 0, INOUTSIZE_X, INOUTSIZE_Y);
  painter->drawPixmap(0, 0, INOUTSIZE_X, INOUTSIZE_Y, pixmap);
}

/******************************************************************************************/

OutputGate::OutputGate()
 : LogicElement(LogicElement::ElementType::Out)
{}

bool OutputGate::addConnection(Connection* conn)
{
  if(connection.size() != 0)
    return false;

  connection.append(conn);
  calculate();
  return true;
}

void OutputGate::removeConnection(Connection* conn)
{
   connection.removeAll(conn);
}

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

void OutputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0, 0, INOUTSIZE_X, INOUTSIZE_Y);
  painter->drawPixmap(0, 0, INOUTSIZE_X, INOUTSIZE_Y, pixmap);
}

/***************************************************************************************/

InnerGate::InnerGate(ElementType type)
  : LogicElement(type)
{}


bool InnerGate::addConnectionTo(Connection *conn)
{
    if(elementType() == LogicElement::ElementType::Not && connectionsTo.size() != 0)
        return false;

    connectionsTo.append(conn);
    calculate();
}

bool InnerGate::addConnectionFrom(Connection *conn)
{
    connectionsFrom.append(conn);
}


void InnerGate::removeConnection(Connection *conn)
{
  if(conn->startItem() == this)
  {
      connectionsFrom.removeAll(conn);
  }
  else
  {
      connectionsTo.removeAll(conn);
      calculate();
  }
}

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

void InnerGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    setRect(0, 0, GATESIZE_X, GATESIZE_Y);
    painter->drawPixmap(0, 0, GATESIZE_X, GATESIZE_Y, pixmap);
}

QPointF InnerGate::getConnPosIn(Connection* conn){
  int size = connectionsTo.size();
  int idx = connectionsTo.indexOf(conn);
  return QPointF(0,GATESIZE_Y / (size+1)*(idx+1));
}

/**********************************************************************************************/

And::And()
  : InnerGate(LogicElement::ElementType::And)
{}

Or::Or()
  : InnerGate(LogicElement::ElementType::Or)
{}

Xor::Xor()
  : InnerGate(LogicElement::ElementType::Xor)
{}

Nand::Nand()
  : InnerGate(LogicElement::ElementType::Nand)
{}

Nor::Nor()
  : InnerGate(LogicElement::ElementType::Nor)
{}

Not::Not()
  : InnerGate(LogicElement::ElementType::Not)
{}

/*********************************************************************************************/

Plexer::Plexer(LogicElement::ElementType type)
  :LogicElement(type)
{}


bool Plexer::addConnectionTo(Connection *conn)
{
    connectionsTo.append(conn);
    calculate();
    return true;
}

bool Plexer::addConnectionFrom(Connection* conn)
{
  connectionsFrom.append(conn);
}

bool Plexer::addConnectionSelector(Connection* conn)
{
  connectionsSelector.append(conn);
  calculate();
  return true;
}

void Plexer::removeConnection(Connection *conn)
{
  if(conn->startItem() == this)
  {
      connectionsFrom.removeAll(conn);
  }
  else
  {
      connectionsTo.removeAll(conn);
      connectionsSelector.removeAll(conn);
      calculate();
  }
}

void Plexer::removeConnections()
{
    const auto connectionsSelectorCopy = connectionsSelector;
    for(Connection* conn: connectionsSelectorCopy)
    {
        conn->startItem()->removeConnection(conn);
        connectionsSelector.removeAll(conn);

        if(conn->scene() != nullptr)
           conn->scene()->removeItem(conn);
        delete conn;
    }

    const auto connectionsToCopy = connectionsTo;
    for(Connection* conn: connectionsToCopy)
    {
        conn->startItem()->removeConnection(conn);

        connectionsTo.removeAll(conn);
        calculate();

        if(conn->scene() != nullptr)
             conn->scene()->removeItem(conn);
        delete conn;
    }

    const auto connectionsFromCopy = connectionsFrom;
    for(Connection* conn: connectionsFromCopy)
    {
        conn->endItem()->removeConnection(conn);
        connectionsFrom.removeAll(conn);
        if(conn->scene() != nullptr)
            conn->scene()->removeItem(conn);
        delete conn;
    }
}

void Plexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   setRect(0,0,PLEXERSIZE_X,PLEXERSIZE_Y);
   painter->drawPixmap(0,0,PLEXERSIZE_X,PLEXERSIZE_Y,pixmap);
}

/******************************************************************************/

QPointF Multiplexer::getConnPosIn(Connection *conn)
{
  if(connectionsSelector.indexOf(conn) > 0)
  {
 //     int idx = selectorConn.indexOf(conn);
 //     return QPointF(PLEXERSIZE_X/(numOfNot+1)*(idx+1),PLEXERSIZE_Y);
      return QPointF(90,0);
  }
  else
  {
      return QPointF(0,0);
  }
}


Multiplexer::Multiplexer(int ands, int nots)
  : Plexer(LogicElement::Multiplexer),
    numOfAnd(ands), numOfNot(nots)
{
  for(int i=0;i < numOfNot; i++)
  {
    NotGates.append(new class Not());
  }

  for(int i=0;i < numOfAnd; i++)
  {
    AndGates.append(new class And());
  }

  OrGate = new class Or();

// konektovanje svih elemenata medjusobno
for(int i = 0; i < AndGates.size(); i++){
    for(int j = 0; j < NotGates.size(); j++){
        if(!getBit(i,j))
          connect(NotGates[j], AndGates[i]);
     }
    connect(AndGates[i], OrGate);
  }
}




int Multiplexer::getBit(int n,int k)
{
  int mask =  1 << k;
  int masked_n = n & mask;
  int thebit = masked_n >> k;
  return thebit;
}


Connection* Multiplexer::connect(LogicElement* g1, LogicElement* g2)
{
    Connection* conn = new Connection(g1,g2);
//    g1->addConnection(conn);
//    g2->addConnection(conn);

    return conn;
}


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

void Multiplexer::calculate(){
  OrGate->calculate();
  myValue = OrGate->getValue();
  for(Connection* conn: connectionsFrom){
      conn->endItem()->calculate();
  }
}

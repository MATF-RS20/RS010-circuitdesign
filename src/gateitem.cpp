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
    setRect(0,0,GATESIZE_X,GATESIZE_Y);
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


QPointF GateItem::getConnPosIn(Connection*){
   return QPointF(0,GATESIZE_Y/2);
}

QPointF GateItem::getConnPosOut(Connection*){
  return QPointF(GATESIZE_X, GATESIZE_Y/2);
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

BaseGate::BaseGate(GateType type)
  : GateItem(type)
{}

void BaseGate::removeConnections()
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

bool BaseGate::addConnection(Connection *conn)
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

void BaseGate::removeConnection(Connection *conn)
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


QPointF BaseGate::getConnPosIn(Connection* conn){
  int size = connectionsTo.size();
  int idx = connectionsTo.indexOf(conn);
  return QPointF(0,GATESIZE_Y / (size+1)*(idx+1));
}

/*************************************************************************/



Plexer::Plexer(GateItem::GateType type)
  :GateItem(type)
{}

void Plexer::removeConnections(){
  for(Connection* conn: selectorConn){
     selectorConn.removeAll(conn);
  }

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

void Plexer::removeConnection(Connection *conn){
  if(conn->startItem() == this){
      connectionsFrom.removeAll(conn);
  }
  else
  {
    connectionsTo.removeAll(conn);
    selectorConn.removeAll(conn);
    calculate();
  }
}

bool Plexer::addConnection(Connection *conn){
  if(conn->startItem() == this)
  {
    connectionsFrom.append(conn);
  }
  else
  {
    connectionsTo.append(conn);
    calculate();
  }
  return true;
}

void Plexer::addSelector(Connection* conn){
  selectorConn.append(conn);
}


QPointF Multiplexer::getConnPosIn(Connection *conn){
  if(selectorConn.indexOf(conn) > 0) {
      //selecotr je u pitanju
      int idx = selectorConn.indexOf(conn);
      return QPointF(PLEXERSIZE_X/(numOfNot+1)*(idx+1),PLEXERSIZE_Y);
  } else {

     return QPointF(0,0);
  }
}

And::And()
  : BaseGate(GateItem::GateType::And)
{}

Or::Or()
  : BaseGate(GateItem::GateType::Or)
{}

Xor::Xor()
  : BaseGate(GateItem::GateType::Xor)
{}

Nand::Nand()
  : BaseGate(GateItem::GateType::Nand)
{}

Nor::Nor()
  : BaseGate(GateItem::GateType::Nor)
{}

Not::Not()
  : BaseGate(GateItem::GateType::Not)
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
  :Plexer(GateItem::Multiplexer)
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
    for(int j = 0; j < NotGates.size(); j++){
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
   setRect(0,0,PLEXERSIZE_X,PLEXERSIZE_Y);
   painter->drawPixmap(0,0,PLEXERSIZE_X,PLEXERSIZE_Y,pixmap);
}

Connection* Multiplexer::connect(GateItem* g1, GateItem* g2){
    Connection* conn = new Connection(g1,g2);
    g1->addConnection(conn);
    g2->addConnection(conn);

    return conn;
}


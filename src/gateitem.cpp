#include "gateitem.h"
#include <iostream>
#include <cmath>
#include "connection.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

#define GATESIZE_X 70.0
#define GATESIZE_Y 50.0
#define PLEXERSIZE_X 100.0
#define PLEXERSIZE_Y 120.0
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
      case Id:
        pixmap.load("../images/id.png");
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
      case Demultiplexer:
        pixmap.load("../images/demultiplexer.png");
        break;
      case Decoder:
        pixmap.load("../images/decoder.jpg");
        break;
      case Encoder:
        pixmap.load("../images/encoder.jpg");
        break;
    }


    myValue = false;
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,true);
}

bool LogicElement::getValue(Connection*)
{
    return myValue;
}

QPointF LogicElement::getConnPosIn(Connection *)
{
    return QPointF(0,INOUTSIZE_Y/2);
}

QPointF LogicElement::getConnPosOut(Connection *)
{
    return QPointF(INOUTSIZE_X, INOUTSIZE_Y/2);
}

/***************************************************************************************************/

InputGate::InputGate()
  : LogicElement(LogicElement::ElementType::In)
{}


bool InputGate::addConnection(Connection *conn, ConnectionType type, QPointF)
{
  if(type == ConnectionType::EndItem)
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

void InputGate::calculate()
{
  myValue = !myValue;
  myValue ? pixmap.load("../images/in_true.png") : pixmap.load("../images/in_false.png");

  for(Connection* conn : connectionsFrom)
    conn->endItem()->calculate();
}

void InputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0, 0, INOUTSIZE_X, INOUTSIZE_Y);
  painter->drawPixmap(0, 0, INOUTSIZE_X, INOUTSIZE_Y, pixmap);
}

/***************************************************************************************************/

OutputGate::OutputGate()
 : LogicElement(LogicElement::ElementType::Out)
{}

bool OutputGate::addConnection(Connection* conn,ConnectionType type, QPointF)
{
  if(connection.size() != 0 || type == ConnectionType::StartItem)
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

void OutputGate::calculate()
{
  myValue = connection.front()->startItem()->getValue(connection.front());
  myValue ? pixmap.load("../images/out_true.png") : pixmap.load("../images/out_false.png");
  this->update();
}

void OutputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  setRect(0, 0, INOUTSIZE_X, INOUTSIZE_Y);
  painter->drawPixmap(0, 0, INOUTSIZE_X, INOUTSIZE_Y, pixmap);
}

/***************************************************************************************************/


InnerGate::InnerGate(ElementType type, int numOfInput)
  : LogicElement(type), numOfInput(numOfInput)
{}


bool InnerGate::addConnection(Connection *conn, ConnectionType type, QPointF)
{
    if(type == ConnectionType::StartItem){
        connectionsFrom.append(conn);
    } else {
        if (connectionsTo.size() >= numOfInput)
            return false;
        connectionsTo.append(conn);
        calculate();
    }

    return true;
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

QPointF InnerGate::getConnPosIn(Connection* conn){
  int size = connectionsTo.size();
  int idx = connectionsTo.indexOf(conn);
  return QPointF(0,GATESIZE_Y / (size+1)*(idx+1));
}

QPointF InnerGate::getConnPosOut(Connection*)
{
  return QPointF(GATESIZE_X, GATESIZE_Y/2);
}

/**********************************************************************************************/

And::And(int numOfInput)
  : InnerGate(LogicElement::ElementType::And, numOfInput)
{}

void And::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionsTo )
     newValue = newValue && conn->startItem()->getValue(conn);
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

Or::Or(int numOfInput)
  : InnerGate(LogicElement::ElementType::Or, numOfInput)
{}

void Or::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionsTo)
     newValue = newValue || conn->startItem()->getValue(conn);
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

Xor::Xor(int numOfInput)
  : InnerGate(LogicElement::ElementType::Xor, numOfInput)
{}

void Xor::calculate()
{
  unsigned numTrue = 0;
  for(Connection* conn: connectionsTo)
    if (conn->startItem()->getValue(conn) == true)
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

Nand::Nand(int numOfInput)
  : InnerGate(LogicElement::ElementType::Nand, numOfInput)
{}

void Nand::calculate()
{
  bool newValue = true;
  for(Connection* conn: connectionsTo )
     newValue = newValue && conn->startItem()->getValue(conn);
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

Nor::Nor(int numOfInput)
  : InnerGate(LogicElement::ElementType::Nor, numOfInput)
{}

void Nor::calculate()
{
  bool newValue = false;
  for(Connection* conn: connectionsTo)
     newValue = newValue || conn->startItem()->getValue(conn);
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

Not::Not()
  : InnerGate(LogicElement::ElementType::Not, 1)
{}

void Not::calculate()
{
   myValue = !(connectionsTo.front()->startItem()->getValue(connectionsTo.front()));
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

Id::Id()
  : InnerGate(LogicElement::ElementType::Id, 1)
{}

void Id::calculate()
{
  myValue = connectionsTo.front()->startItem()->getValue(connectionsTo.front());
  for(Connection* conn: connectionsFrom)
      conn->endItem()->calculate();
}

void Id::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(10, 10, 40, 25);
    painter->drawLine(10, 10, 10, 40);
    painter->drawLine(10, 40, 40, 25);

    painter->drawLine(0, 25, 10, 25);
    painter->drawLine(40, 25, 50, 25);

    setRect(0, 0, 60, 42);
}

/*********************************************************************************************/

Plexer::Plexer(ElementType type, int numOfInput, int numOfOutput, int numOfSelector)
    : LogicElement(type), numOfInput(numOfInput), numOfOutput(numOfOutput), numOfSelector(numOfSelector)
{
    connectionsTo.fill(nullptr, numOfInput);
    connectionsSelector.fill(nullptr, numOfSelector);
}

void Plexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   setRect(0,0,PLEXERSIZE_X,PLEXERSIZE_Y);
   painter->drawPixmap(0,0,PLEXERSIZE_X,PLEXERSIZE_Y,pixmap);
}

void Plexer::removeConnections()
{
    const auto connectionsToCopy = connectionsTo;
    for (Connection* conn: connectionsToCopy)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);

            if(conn->scene() != nullptr)
               conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsTo.clear();

    const auto connectionsSelectorCopy = connectionsSelector;
    for(Connection* conn: connectionsSelectorCopy)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);

            if(conn->scene() != nullptr)
               conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsSelector.clear();

    const auto connectionsFromCopy = connectionsFrom;
    for(Connection* conn: connectionsFromCopy)
    {
        conn->endItem()->removeConnection(conn);
        if(conn->scene() != nullptr)
            conn->scene()->removeItem(conn);
        delete conn;
    }
    connectionsFrom.clear();
}


QPointF Plexer::getConnPosIn(Connection *conn)
{
  int idx;
  if((idx = connectionsSelector.indexOf(conn)) >= 0)
  {
      return QPointF(PLEXERSIZE_X/(numOfSelector + 1)*(idx + 1), PLEXERSIZE_Y);
  }
  else
  {
      idx = connectionsTo.indexOf(conn);
      return QPointF(0, PLEXERSIZE_Y/(numOfInput + 1) * (idx + 1));
  }
}

QPointF Plexer::getConnPosOut(Connection *)
{
  return QPointF(PLEXERSIZE_X, PLEXERSIZE_Y/2);
}


/******************************************************************************/


Multiplexer::Multiplexer(int numOfInput, int numOfSelector)
  : Plexer(LogicElement::Multiplexer, numOfInput, 1, numOfSelector)
{}

bool Multiplexer::addConnection(Connection *conn, ConnectionType type, QPointF point)
{
    if(type == ConnectionType::EndItem)
    {
        QPointF position = this->pos();
        qreal posX = position.rx();
        qreal posY = position.ry();
        qreal relX = point.rx();
        qreal relY = point.ry();

        if(relX < posX + qreal(60))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + qreal(PLEXERSIZE_Y/numOfInput) * (i+1))
                {
                    if (connectionsTo[i] != nullptr)
                        return false;
                    connectionsTo[i] = conn;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < numOfSelector; i++)
            {
                if(relX < posX + qreal(PLEXERSIZE_X/numOfSelector) * (i+2))
                {
                    if (connectionsSelector[i] != nullptr)
                        return false;
                    connectionsSelector[i] = conn;
                    break;
                }
            }
        }
        calculate();
    }
    else
    {
        connectionsFrom.append(conn);
    }

    return true;
}

void Multiplexer::removeConnection(Connection *conn)
{
    if (conn->startItem() == this)
    {
        connectionsFrom.removeAll(conn);
    }
    else
    {
        int idx = connectionsTo.indexOf(conn);
        if (idx >= 0)
            connectionsTo[idx] = nullptr;
        else if ((idx = connectionsSelector.indexOf(conn)) >= 0)
            connectionsSelector[idx] = nullptr;
        calculate();
    }
}

void Multiplexer::calculate()
{
    int idx = 0;
    for (int i = 0; i < numOfSelector; i++)
    {
        if (connectionsSelector[i] != nullptr && connectionsSelector[i]->startItem()->getValue(connectionsSelector[i]))
        {
            idx += pow(2, i);
        }
    }

    myValue = connectionsTo[idx] == nullptr ? false : connectionsTo[idx]->startItem()->getValue(connectionsTo[idx]);

    for (Connection* conn: connectionsFrom)
    {
        if (conn != nullptr)
        {
            conn->endItem()->calculate();
        }
    }
}

void Multiplexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawRect(10, 10, 80, 100);

    int i, x, y;
    for (i = 1; i <= numOfInput; i++)
    {
        y = 100 / (numOfInput+1)*i + 10;
        painter->drawLine(0, y, 10, y);
    }

    for (i = 1; i <= numOfSelector; i++)
    {
        x = 80 / (numOfSelector+1)*i + 10;
        painter->drawLine(x, 110, x, 120);
    }

    painter->drawLine(90, 60, 100, 60);

    QFont font = painter->font();
    font.setPixelSize(12);
    font.bold();
    painter->setFont(font);

    const QRect rectangle = QRect(30, 50, 40, 20);
    painter->drawText(rectangle, Qt::AlignCenter, "MUX");


    setRect(0, 0, PLEXERSIZE_X, PLEXERSIZE_Y);
}

/*********************************************************************************/

Demultiplexer::Demultiplexer(int numOfOutput, int numOfSelector)
    : Plexer(LogicElement::Demultiplexer, 1, numOfOutput, numOfSelector)
{
    myValues.fill(false, numOfOutput);
}

bool Demultiplexer::addConnection(Connection *conn, ConnectionType type, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (type == ConnectionType::EndItem)
    {
        if (relX < posX + qreal(60))
        {
            if(connectionsTo[0] != nullptr)
              return false;
            connectionsTo[0] = conn;
        }
        else
        {
            for(int i = 0; i < numOfSelector; i++)
            {
                if(relX < posX + qreal(60) * (i+2))
                {
                    if(connectionsSelector[i] != nullptr)
                        return false;

                    connectionsSelector[i] = conn;
                    break;
                }
            }
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + qreal(50) * (i+1))
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(i);
                break;
            }
        }
    }
    return true;
}

void Demultiplexer::removeConnection(Connection *conn)
{
    if (conn->startItem() == this)
    {
        int idx = connectionsFrom.indexOf(conn);
        if (idx >= 0)
        {
            indexConnectionFrom.removeAt(idx);
            connectionsFrom.removeAt(idx);
        }
    }
    else
    {
        int idx = connectionsSelector.indexOf(conn);
        if (idx >= 0)
            connectionsSelector[idx] = nullptr;
        else if (connectionsTo[0] == conn)
            connectionsTo[0] = nullptr;
        calculate();
    }
}

void Demultiplexer::calculate()
{
    myValues.fill(false, numOfOutput);
    if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue(connectionsTo[0]))
    {
        int idx = 0;
        int i = 1;
        for (Connection* conn: connectionsSelector)
        {
            if (conn != nullptr && conn->startItem()->getValue(conn))
            {
                idx += i;
            }
            i *= 2;
        }
        myValues[idx] = connectionsTo[0]->startItem()->getValue(connectionsTo[0]);
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

bool Demultiplexer::getValue(Connection *conn)
{
    int idx = connectionsFrom.indexOf(conn);
    if (idx < 0)
        return false;

    idx = indexConnectionFrom[idx];
    return myValues[idx];
}

void Demultiplexer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(10, 10, 80, 100);

    painter->drawLine(0, 60, 10, 60);

    int i, x, y;
    for (i = 1; i <= numOfOutput; i++)
    {
        y = 100 / (numOfOutput+1)*i + 10;
        painter->drawLine(90, y, 100, y);
    }

    for (i = 1; i <= numOfSelector; i++)
    {
        x = 80 / (numOfSelector+1)*i + 10;
        painter->drawLine(x, 110, x, 120);
    }

    QFont font = painter->font();
    font.setPixelSize(12);
    font.bold();
    painter->setFont(font);

    const QRect rectangle = QRect(30, 50, 40, 20);
    painter->drawText(rectangle, Qt::AlignCenter, "DEMUX");


    setRect(0, 0, PLEXERSIZE_X, PLEXERSIZE_Y);
}

/*********************************************************************************/

Decoder::Decoder(int numOfInput, int numOfOutput)
    : Plexer(LogicElement::Decoder, numOfInput, numOfOutput, 0)
{
    myValues.fill(false, numOfOutput);
}

bool Decoder::addConnection(Connection *conn, ConnectionType type, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (type == ConnectionType::EndItem)
    {
        if (relX < posX + qreal(60))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + qreal(PLEXERSIZE_Y/numOfInput) * (i+1))
                {
                    if (connectionsTo[i] != nullptr)
                        return false;
                    connectionsTo[i] = conn;
                    break;
                }
            }
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + qreal(50) * (i+1))
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(i);
                break;
            }
        }
    }
    return true;
}

void Decoder::removeConnection(Connection *conn)
{
    if (conn->startItem() == this)
    {
        int idx = connectionsFrom.indexOf(conn);
        if (idx >= 0)
        {
            indexConnectionFrom.removeAt(idx);
            connectionsFrom.removeAt(idx);
        }
    }
    else
    {
        int idx = connectionsTo.indexOf(conn);
        if (idx >= 0)
            connectionsTo[idx] = nullptr;
        calculate();
    }
}

void Decoder::calculate()
{
    myValues.fill(false, numOfOutput);
    int idx = 0;
    for (int i = 0; i < numOfInput; i++)
    {
        if (connectionsTo[i] != nullptr && connectionsTo[i]->startItem()->getValue(connectionsTo[i]))
            idx += pow(2, i);
    }
    myValues[idx] = true;

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

bool Decoder::getValue(Connection *conn)
{
    int idx = connectionsFrom.indexOf(conn);
    if (idx < 0)
        return false;

    idx = indexConnectionFrom[idx];
    return myValues[idx];
}

void Decoder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(10, 10, 80, 100);

    int i, y;
    for (i = 1; i <= numOfInput; i++)
    {
        y = 100 / (numOfInput+1)*i + 10;
        painter->drawLine(0, y, 10, y);
    }

    for (i = 1; i <= numOfOutput; i++)
    {
        y = 100 / (numOfOutput+1)*i + 10;
        painter->drawLine(90, y, 100, y);
    }

    QFont font = painter->font();
    font.setPixelSize(12);
    font.bold();
    painter->setFont(font);

    const QRect rectangle = QRect(30, 50, 40, 20);
    painter->drawText(rectangle, Qt::AlignCenter, "DEC");


    setRect(0, 0, PLEXERSIZE_X, PLEXERSIZE_Y);
}

/*********************************************************************************/

Encoder::Encoder(int numOfInput, int numOfOutput)
    : Plexer(LogicElement::Encoder, numOfInput, numOfOutput, 0)
{
    myValues.fill(false, numOfOutput);
}

bool Encoder::addConnection(Connection *conn, ConnectionType type, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (type == ConnectionType::EndItem)
    {
        if (relX < posX + qreal(60))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + qreal(PLEXERSIZE_Y/numOfInput) * (i+1))
                {
                    if (connectionsTo[i] != nullptr)
                        return false;
                    connectionsTo[i] = conn;
                    break;
                }
            }
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + qreal(50) * (i+1))
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(i);
                break;
            }
        }
    }
    return true;
}

void Encoder::removeConnection(Connection *conn)
{
    if (conn->startItem() == this)
    {
        int idx = connectionsFrom.indexOf(conn);
        if (idx >= 0)
        {
            indexConnectionFrom.removeAt(idx);
            connectionsFrom.removeAt(idx);
        }
    }
    else
    {
        int idx = connectionsTo.indexOf(conn);
        if (idx >= 0)
            connectionsTo[idx] = nullptr;
        calculate();
    }
}

// odluciti sta ce da radi
void Encoder::calculate()
{
    myValues.fill(false, numOfOutput);
    for (int i = 0; i < numOfInput; i++)
    {
        if (connectionsTo[i] != nullptr && connectionsTo[i]->startItem()->getValue(connectionsTo[i]))
        {
            for (int j = 0; j < numOfOutput; j++)
            {
                if (pow(2, j) <= i % (int)(pow(2, j+1)))
                    myValues[j] = true;
            }
        }
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

bool Encoder::getValue(Connection *conn)
{
    int idx = connectionsFrom.indexOf(conn);
    if (idx < 0)
        return false;

    idx = indexConnectionFrom[idx];
    return myValues[idx];
}

void Encoder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(10, 10, 80, 100);

    int i, y;
    for (i = 1; i <= numOfInput; i++)
    {
        y = 100 / (numOfInput+1)*i + 10;
        painter->drawLine(0, y, 10, y);
    }

    for (i = 1; i <= numOfOutput; i++)
    {
        y = 100 / (numOfOutput+1)*i + 10;
        painter->drawLine(90, y, 100, y);
    }

    QFont font = painter->font();
    font.setPixelSize(12);
    font.bold();
    painter->setFont(font);

    const QRect rectangle = QRect(30, 50, 40, 20);
    painter->drawText(rectangle, Qt::AlignCenter, "ENC");

    setRect(0, 0, PLEXERSIZE_X, PLEXERSIZE_Y);
}

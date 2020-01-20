#include "gateitem.h"

#define INOUTSIZE 12.0

LogicElement::LogicElement(ElementType type, QGraphicsItem* parent)
  : QGraphicsRectItem(parent), myElementType(type)
{
    myValue = false;
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,true);

    myPen = QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
}

bool LogicElement::getValue(Connection*)
{
    return myValue;
}

QPointF LogicElement::getConnPosIn(Connection *)
{
    return QPointF(0,INOUTSIZE/2);
}

QPointF LogicElement::getConnPosOut(Connection *)
{
    return QPointF(INOUTSIZE/2, INOUTSIZE/2);
}


/***************************************************************************************************/

InputGate::InputGate(ElementType type)
  : LogicElement(type)
{}


bool InputGate::addConnection(Connection *conn, QPointF)
{
  if(this == conn->endItem())
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

    conn->scene()->removeItem(conn);
    delete conn;
  }
}

void InputGate::calculate()
{
  myValue = !myValue;

  for(Connection* conn : connectionsFrom)
    conn->endItem()->calculate();
}

void InputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (myValue)
        painter->setBrush(Qt::green);
    else
        painter->setBrush(Qt::red);
    painter->drawRect(0, 0, INOUTSIZE, INOUTSIZE);
    setRect(0, 0, INOUTSIZE, INOUTSIZE);
}

/****************************************************************************/
ClockGate::ClockGate()
    : InputGate(LogicElement::ElementType::Clock), QObject()
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&ClockGate::calculate));
    timer->start(2000);
}

void ClockGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(0, 0, INOUTSIZE, INOUTSIZE);

    QFont font = painter->font();
    font.setPixelSize(12);
    font.bold();
    painter->setFont(font);

    const QRect rectangle = QRect(0, 0, INOUTSIZE, INOUTSIZE);
    painter->drawText(rectangle, Qt::AlignCenter, "clk");

    setRect(0, 0, INOUTSIZE, INOUTSIZE);
}

void ClockGate::calculate()
{
  myValue = !myValue;

  for(Connection* conn : connectionsFrom)
    conn->endItem()->calculate();
}

/***************************************************************************************************/

OutputGate::OutputGate()
 : LogicElement(LogicElement::ElementType::Out)
{}

bool OutputGate::addConnection(Connection* conn, QPointF)
{
  if(connection.size() != 0 ||this == conn->startItem())
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

    scene()->removeItem(conn);
    delete conn;
  }
}

void OutputGate::calculate()
{
  myValue = connection.front()->startItem()->getValue(connection.front());
  this->update();
}

void OutputGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if (myValue)
        painter->setBrush(Qt::green);
    else
        painter->setBrush(Qt::red);
    painter->drawEllipse(0, 0, INOUTSIZE, INOUTSIZE);
    setRect(0, 0, INOUTSIZE, INOUTSIZE);
}

/***************************************************************************************************/


InnerGate::InnerGate(ElementType type, int numOfInput)
  : LogicElement(type), numOfInput(numOfInput)
{}


bool InnerGate::addConnection(Connection *conn, QPointF)
{
    if(this == conn->startItem())
    {
        for(Connection* c: connectionsFrom)
          if(c->endItem() == conn->endItem())
              return false;

        connectionsFrom.append(conn);
    }
    else
    {
        for(Connection* c: connectionsFrom)
          if(c->endItem() == conn->startItem())
              return false;

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

    conn->scene()->removeItem(conn);
    delete conn;
  }

  const auto connectionsFromCopy = connectionsFrom;
  for(Connection* conn: connectionsFromCopy)
  {
      this->removeConnection(conn);
      conn->endItem()->removeConnection(conn);

      conn->scene()->removeItem(conn);
      delete conn;
  }
}

QPointF InnerGate::getConnPosIn(Connection* conn)
{
    if (elementType() == ElementType::Id || elementType() == ElementType::Not)
        return QPointF(0, 10);
    int idx = connectionsTo.indexOf(conn);
    return QPointF(0,30.0 / (numOfInput+1) * (idx+1) + 5);
}

QPointF InnerGate::getConnPosOut(Connection*)
{
    ElementType type = elementType();
    if (type == ElementType::Or || type == ElementType::Xor)
      return QPointF(45, 20);
    else if (type == ElementType::Nand)
      return QPointF(49, 20);
    else if (type == ElementType::Nor)
      return QPointF(49, 20);
    else if (type == ElementType::Id)
      return QPointF(30, 10);
    else if (type == ElementType::Not)
      return QPointF(34, 10);
    return QPointF(45, 20);
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
    painter->setPen(myPen);
    painter->drawLine(5, 5, 30, 5);
    painter->drawLine(5, 5, 5, 35);
    painter->drawLine(5, 35, 30, 35);
    painter->drawArc(QRect(20, 5, 20, 30), -90*16, 180*16);

    for (int i = 1; i <= numOfInput; i++)
    {
        painter->drawLine(0, 30.0 / (numOfInput+1) * i + 5, 5, 30.0 / (numOfInput+1) * i + 5);
    }

    painter->drawLine(40, 20, 45, 20);

    setRect(0, 0, 40, 40);
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
    painter->setPen(myPen);
    painter->drawArc(QRect(0, 5, 10, 30), -90*16, 180*16);
    painter->drawLine(5, 5, 17, 5);
    painter->drawLine(5, 35, 17, 35);

    painter->drawArc(QRect(-5, 5, 45, 30), 0, 90*16);
    painter->drawArc(QRect(-5, 5, 45, 30), -90*16, 90*16);

    for (int i = 1; i <= numOfInput; i++)
    {
        painter->drawLine(0, 30.0 / (numOfInput+1) * i + 5, 8, 30.0 / (numOfInput+1) * i + 5);
    }

    painter->drawLine(40, 20, 45, 20);

    setRect(0, 0, 47, 30);
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
    painter->setPen(myPen);
    painter->drawArc(QRect(-2, 5, 8, 30), -90*16, 180*16);
    painter->drawArc(QRect(0, 5, 10, 30), -90*16, 180*16);
    painter->drawLine(5, 5, 17, 5);
    painter->drawLine(5, 35, 17, 35);

    painter->drawArc(QRect(-5, 5, 45, 30), 0, 90*16);
    painter->drawArc(QRect(-5, 5, 45, 30), -90*16, 90*16);

    for (int i = 1; i <= numOfInput; i++)
    {
        painter->drawLine(-2, 30.0 / (numOfInput+1) * i + 5, 5, 30.0 / (numOfInput+1) * i + 5);
    }

    painter->drawLine(40, 20, 45, 20);

    setRect(-2, 0, 49, 30);
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
    painter->setPen(myPen);
    painter->drawLine(5, 5, 30, 5);
    painter->drawLine(5, 5, 5, 35);
    painter->drawLine(5, 35, 30, 35);
    painter->drawArc(QRect(20, 5, 20, 30), -90*16, 180*16);

    for (int i = 1; i <= numOfInput; i++)
    {
        painter->drawLine(0, 30.0 / (numOfInput+1) * i + 5, 5, 30.0 / (numOfInput+1) * i + 5);
    }

    QPointF center = QPointF(42, 20);
    painter->drawEllipse(center, 2, 2);

    painter->drawLine(44, 20, 49, 20);

    setRect(0, 0, 50, 40);
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
    painter->setPen(myPen);
    painter->drawArc(QRect(0, 5, 10, 30), -90*16, 180*16);
    painter->drawLine(5, 5, 17, 5);
    painter->drawLine(5, 35, 17, 35);

    painter->drawArc(QRect(-5, 5, 45, 30), 0, 90*16);
    painter->drawArc(QRect(-5, 5, 45, 30), -90*16, 90*16);

    for (int i = 1; i <= numOfInput; i++)
    {
        painter->drawLine(0, 30.0 / (numOfInput+1) * i + 5, 8, 30.0 / (numOfInput+1) * i + 5);
    }

    QPointF center = QPointF(42, 20);
    painter->drawEllipse(center, 2, 2);

    painter->drawLine(44, 20, 49, 20);

    setRect(0, 0, 49, 30);
}

Not::Not()
  : InnerGate(LogicElement::ElementType::Not, 1)
{}

void Not::calculate()
{
    if (connectionsTo.size() > 0)
        myValue = !(connectionsTo.front()->startItem()->getValue(connectionsTo.front()));
    else
        myValue = false;

    for(Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void Not::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawLine(5, 0, 25, 10);
    painter->drawLine(5, 0, 5, 20);
    painter->drawLine(5, 20, 25, 10);

    painter->drawLine(0, 10, 5, 10);

    QPointF center = QPointF(27, 10);
    painter->drawEllipse(center, 2, 2);

    painter->drawLine(29, 10, 34, 10);

    setRect(0, 0, 35, 20);
}

Id::Id()
  : InnerGate(LogicElement::ElementType::Id, 1)
{}

void Id::calculate()
{
    if (connectionsTo.size() > 0)
        myValue = connectionsTo.front()->startItem()->getValue(connectionsTo.front());
    else
        myValue = false;

    for(Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void Id::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawLine(5, 0, 25, 10);
    painter->drawLine(5, 0, 5, 20);
    painter->drawLine(5, 20, 25, 10);

    painter->drawLine(0, 10, 5, 10);
    painter->drawLine(25, 10, 30, 10);

    setRect(0, 0, 30, 20);
}

/*********************************************************************************************/

Plexer::Plexer(ElementType type, int numOfInput, int numOfOutput, int numOfSelector)
    : LogicElement(type), numOfInput(numOfInput), numOfOutput(numOfOutput), numOfSelector(numOfSelector)
{
    connectionsTo.fill(nullptr, numOfInput);
    connectionsSelector.fill(nullptr, numOfSelector);
}

void Plexer::removeConnections()
{
    const auto connectionsToCopy = connectionsTo;
    for (Connection* conn: connectionsToCopy)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);
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
            conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsSelector.clear();

    const auto connectionsFromCopy = connectionsFrom;
    for(Connection* conn: connectionsFromCopy)
    {
        conn->endItem()->removeConnection(conn);
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
      return QPointF(80.0/(numOfSelector + 1)*(idx + 1) + 10, 120);
  }
  else
  {
      idx = connectionsTo.indexOf(conn);
      return QPointF(0, 100.0/(numOfInput + 1) * (idx + 1) + 10);
  }
}

QPointF Plexer::getConnPosOut(Connection * conn)
{
  int idx;
  if((idx = connectionsFrom.indexOf(conn)) >= 0)
  {
     return QPointF(90, 100.0/(numOfOutput+1) * (idx+1) + 10);
  }

  return QPointF(100, 60);
}

/******************************************************************************/


Multiplexer::Multiplexer(int numOfSelector)
  : Plexer(LogicElement::Multiplexer, static_cast<int> (pow(2, numOfSelector)),1, numOfSelector)
{}

bool Multiplexer::addConnection(Connection *conn, QPointF point)
{
    if(this == conn->endItem())
    {
        QPointF position = this->pos();
        qreal posX = position.rx();
        qreal posY = position.ry();
        qreal relX = point.rx();
        qreal relY = point.ry();

        if(relX < posX + qreal(10))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + 100.0/(numOfInput+1)*(i+1) + 20)
                {
                    if (connectionsTo[i] != nullptr)
                        return false;
                    connectionsTo[i] = conn;
                    break;
                }
            }
        }
        else if(relY > posY + 90)
        {
            for(int i = 0; i < numOfSelector; i++)
            {
                if(relX < posX + 80.0/(numOfSelector+1) * (i+1) + 15)
                {
                    if (connectionsSelector[i] != nullptr)
                        return false;
                    connectionsSelector[i] = conn;
                    break;
                }
            }
        }
        else
        {
            return false;
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
    painter->setPen(myPen);
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


    setRect(0, 0, 100, 120);
}

/*********************************************************************************/

Demultiplexer::Demultiplexer(int numOfSelector)
    : Plexer(LogicElement::Demultiplexer, 1, static_cast<int> (pow(2, numOfSelector)), numOfSelector)
{
    myValues.fill(false, numOfOutput);
}

bool Demultiplexer::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if (relX < posX + qreal(10) && relY > posY + 40 && relY < posY + 80)
        {
            if(connectionsTo[0] != nullptr)
                return false;
            connectionsTo[0] = conn;
        }
        else if(relY > posY + 90)
        {
            for(int i = 0; i < numOfSelector; i++)
            {
                if(relX < posX + 80.0/(numOfSelector+1) * (i+1) + 15)
                {
                    if(connectionsSelector[i] != nullptr)
                        return false;

                    connectionsSelector[i] = conn;
                    break;
                }
            }
        }
        else
        {
            return false;
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + 100.0/(numOfOutput+1)*(i+1) + 20)
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
    painter->setPen(myPen);
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


    setRect(0, 0, 100, 120);
}

/*********************************************************************************/

Decoder::Decoder(int numOfInput, int numOfOutput)
    : Plexer(LogicElement::Decoder, numOfInput, numOfOutput, 0)
{
    myValues.fill(false, numOfOutput);
}

bool Decoder::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + 100.0/(numOfInput+1)*(i+1) + 20)
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
            return false;
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + 100.0/(numOfOutput+1)*(i+1) + 20)
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
    painter->setPen(myPen);
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


    setRect(0, 0, 100, 120);
}

/*********************************************************************************/

Encoder::Encoder(int numOfInput, int numOfOutput)
    : Plexer(LogicElement::Encoder, numOfInput, numOfOutput, 0)
{
    myValues.fill(false, numOfOutput);
}

bool Encoder::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + 100.0/(numOfInput+1)*(i+1) + 20)
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
            return false;
        }
        calculate();
    }
    else
    {
        for(int i=0;i < numOfOutput; i++)
        {
            if(relY < posY + 100.0/(numOfOutput+1)*(i+1) + 20)
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
    painter->setPen(myPen);
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

    setRect(0, 0, 100, 120);
}

/***************************************************************************************************/

FlipFlop::FlipFlop(ElementType type, int numOfInput)
    : LogicElement(type), numOfInput(numOfInput)
{
    connectionsTo.fill(nullptr, numOfInput);
    clock = nullptr;
    numOfOutput = 2;
    myValues.append(false);
    myValues.append(true);
}

void FlipFlop::removeConnections()
{
    const auto connectionsToCopy = connectionsTo;
    for (Connection* conn: connectionsToCopy)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);
            conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsTo.clear();

    if (clock != nullptr)
    {
        clock->startItem()->removeConnection(clock);
        delete clock;
    }

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

void FlipFlop::removeConnection(Connection *conn)
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
        else if (conn == clock)
            clock = nullptr;
        calculate();
    }
}

QPointF FlipFlop::getConnPosIn(Connection *conn)
{
    if (conn == connectionsTo[0])
        return QPointF(0, 30);
    else if (conn == clock)
        return QPointF(0, 60);
    else
        return QPointF(0, 90);
}

QPointF FlipFlop::getConnPosOut(Connection *conn)
{
    if (conn == connectionsFrom[0])
        return QPointF(100, 40);
    else
        return QPointF(100, 80);
}

bool FlipFlop::getValue(Connection *conn)
{
    int idx = connectionsFrom.indexOf(conn);
    if (idx < 0)
        return false;

    idx = indexConnectionFrom[idx];
    return myValues[idx];
}

JK::JK()
    : FlipFlop(ElementType::JK)
{}

bool JK::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            if (relY > posY + 15 && relY < posY + 45)
            {
                if (connectionsTo[0] != nullptr)
                    return false;
                else
                    connectionsTo[0] = conn;
            }
            else if (relY > posY + 45 && relY < posY + 75)
            {
                if (clock != nullptr)
                    return false;
                else
                    clock = conn;
            }
            else if (relY > posY + 75 && relY < posY + 105)
            {
                if (connectionsTo[1] != nullptr)
                    return false;
                else
                    connectionsTo[1] = conn;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        calculate();
    }
    else
    {
        if(relX > posX + qreal(85))
        {
            if (relY > posY + 25 && relY < posY + 60)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(0);
            }
            else if (relY > posY + 60 && relY < posY + 95)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void JK::calculate()
{
    if (clock == nullptr || !clock->startItem()->getValue())
        return;

    if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue())
    {
        if (connectionsTo[1] != nullptr && connectionsTo[1]->startItem()->getValue())
        {
            myValues[0] = !myValues[0];
            myValues[1] = !myValues[1];
        }
        else
        {
            myValues[0] = true;
            myValues[1] = false;
        }
    }
    else if (connectionsTo[1] != nullptr && connectionsTo[1]->startItem()->getValue())
    {
        myValues[0] = false;
        myValues[1] = true;
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void JK::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawRect(10, 10, 80, 100);

    painter->drawLine(0, 30, 10, 30);
    painter->drawLine(0, 90, 10, 90);
    painter->drawLine(0, 60, 10, 60);

    painter->drawLine(90, 40, 100, 40);
    painter->drawLine(90, 80, 100, 80);

    QFont font = painter->font();
    font.setPixelSize(14);
    font.bold();
    painter->setFont(font);

    const QRect rectangle1 = QRect(15, 22, 15, 15);
    painter->drawText(rectangle1, Qt::AlignCenter, "J");

    const QRect rectangle2 = QRect(15, 82, 15, 15);
    painter->drawText(rectangle2, Qt::AlignCenter, "K");

    const QRect rectangle3 = QRect(15, 52, 25, 15);
    painter->drawText(rectangle3, Qt::AlignCenter, "clk");

    const QRect rectangle4 = QRect(75, 32, 15, 15);
    painter->drawText(rectangle4, Qt::AlignCenter, "Q");

    const QRect rectangle5 = QRect(75, 72, 15, 15);
    painter->drawText(rectangle5, Qt::AlignCenter, "!Q");

    setRect(0, 0, 100, 120);
}

SR::SR()
    : FlipFlop(ElementType::SR)
{}

bool SR::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            if (relY > posY + 15 && relY < posY + 45)
            {
                if (connectionsTo[0] != nullptr)
                    return false;
                else
                    connectionsTo[0] = conn;
            }
            else if (relY > posY + 45 && relY < posY + 75)
            {
                if (clock != nullptr)
                    return false;
                else
                    clock = conn;
            }
            else if (relY > posY + 75 && relY < posY + 105)
            {
                if (connectionsTo[1] != nullptr)
                    return false;
                else
                    connectionsTo[1] = conn;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        calculate();
    }
    else
    {
        if(relX > posX + qreal(85))
        {
            if (relY > posY + 25 && relY < posY + 60)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(0);
            }
            else if (relY > posY + 60 && relY < posY + 95)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void SR::calculate()
{
    if (clock == nullptr || !clock->startItem()->getValue())
        return;

    if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue())
    {
        if (connectionsTo[1] != nullptr && connectionsTo[1]->startItem()->getValue())
        {
            myValues[0] = true;
            myValues[1] = true;
        }
        else
        {
            myValues[0] = true;
            myValues[1] = false;
        }
    }
    else if (connectionsTo[1] != nullptr && connectionsTo[1]->startItem()->getValue())
    {
        myValues[0] = false;
        myValues[1] = true;
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void SR::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawRect(10, 10, 80, 100);

    painter->drawLine(0, 30, 10, 30);
    painter->drawLine(0, 90, 10, 90);
    painter->drawLine(0, 60, 10, 60);

    painter->drawLine(90, 40, 100, 40);
    painter->drawLine(90, 80, 100, 80);

    QFont font = painter->font();
    font.setPixelSize(14);
    font.bold();
    painter->setFont(font);

    const QRect rectangle1 = QRect(15, 22, 15, 15);
    painter->drawText(rectangle1, Qt::AlignCenter, "S");

    const QRect rectangle2 = QRect(15, 82, 15, 15);
    painter->drawText(rectangle2, Qt::AlignCenter, "R");

    const QRect rectangle3 = QRect(15, 52, 25, 15);
    painter->drawText(rectangle3, Qt::AlignCenter, "clk");

    const QRect rectangle4 = QRect(75, 32, 15, 15);
    painter->drawText(rectangle4, Qt::AlignCenter, "Q");

    const QRect rectangle5 = QRect(75, 72, 15, 15);
    painter->drawText(rectangle5, Qt::AlignCenter, "!Q");

    setRect(0, 0, 100, 120);
}

D::D()
    : FlipFlop(ElementType::D, 1)
{}

bool D::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            if (relY > posY + 15 && relY < posY + 45)
            {
                if (connectionsTo[0] != nullptr)
                    return false;
                else
                    connectionsTo[0] = conn;
            }
            else if (relY > posY + 45 && relY < posY + 75)
            {
                if (clock != nullptr)
                    return false;
                else
                    clock = conn;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        calculate();
    }
    else
    {
        if(relX > posX + qreal(85))
        {
            if (relY > posY + 25 && relY < posY + 60)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(0);
            }
            else if (relY > posY + 60 && relY < posY + 95)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void D::calculate()
{
    if (clock == nullptr || !clock->startItem()->getValue())
        return;

    if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue())
    {
        myValues[0] = true;
        myValues[1] = false;
    }
    else if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue())
    {
        myValues[0] = false;
        myValues[1] = true;
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void D::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawRect(10, 10, 80, 100);

    painter->drawLine(0, 30, 10, 30);
    painter->drawLine(0, 60, 10, 60);

    painter->drawLine(90, 40, 100, 40);
    painter->drawLine(90, 80, 100, 80);

    QFont font = painter->font();
    font.setPixelSize(14);
    font.bold();
    painter->setFont(font);

    const QRect rectangle1 = QRect(15, 22, 15, 15);
    painter->drawText(rectangle1, Qt::AlignCenter, "D");

    const QRect rectangle3 = QRect(15, 52, 25, 15);
    painter->drawText(rectangle3, Qt::AlignCenter, "clk");

    const QRect rectangle4 = QRect(75, 32, 15, 15);
    painter->drawText(rectangle4, Qt::AlignCenter, "Q");

    const QRect rectangle5 = QRect(75, 72, 15, 15);
    painter->drawText(rectangle5, Qt::AlignCenter, "!Q");

    setRect(0, 0, 100, 120);
}

T::T()
    : FlipFlop(ElementType::T, 1)
{}

bool T::addConnection(Connection *conn, QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (this == conn->endItem())
    {
        if(relX < posX + qreal(10))
        {
            if (relY > posY + 15 && relY < posY + 45)
            {
                if (connectionsTo[0] != nullptr)
                    return false;
                else
                    connectionsTo[0] = conn;
            }
            else if (relY > posY + 45 && relY < posY + 75)
            {
                if (clock != nullptr)
                    return false;
                else
                    clock = conn;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        calculate();
    }
    else
    {
        if(relX > posX + qreal(85))
        {
            if (relY > posY + 25 && relY < posY + 60)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(0);
            }
            else if (relY > posY + 60 && relY < posY + 95)
            {
                connectionsFrom.append(conn);
                indexConnectionFrom.append(1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void T::calculate()
{
    if (clock == nullptr || !clock->startItem()->getValue())
        return;

    if (connectionsTo[0] != nullptr && connectionsTo[0]->startItem()->getValue())
    {
        myValues[0] = !myValues[0];
        myValues[1] = !myValues[1];
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();
}

void T::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(myPen);
    painter->drawRect(10, 10, 80, 100);

    painter->drawLine(0, 30, 10, 30);
    painter->drawLine(0, 60, 10, 60);

    painter->drawLine(90, 40, 100, 40);
    painter->drawLine(90, 80, 100, 80);

    QFont font = painter->font();
    font.setPixelSize(14);
    font.bold();
    painter->setFont(font);

    const QRect rectangle1 = QRect(15, 22, 15, 15);
    painter->drawText(rectangle1, Qt::AlignCenter, "T");

    const QRect rectangle3 = QRect(15, 52, 25, 15);
    painter->drawText(rectangle3, Qt::AlignCenter, "clk");

    const QRect rectangle4 = QRect(75, 32, 15, 15);
    painter->drawText(rectangle4, Qt::AlignCenter, "Q");

    const QRect rectangle5 = QRect(75, 72, 15, 15);
    painter->drawText(rectangle5, Qt::AlignCenter, "!Q");

    setRect(0, 0, 100, 120);
}

/***************************************************************************************************/

Arithmetic::Arithmetic(ElementType type, int numOfInput)
    : LogicElement(type), numOfInput(numOfInput), numOfOutput(numOfInput)
{
    connectionRestIn = nullptr;
    myValues.fill(false, numOfOutput);
    cinValue = false;
}

void Arithmetic::removeConnections()
{
    const auto connectionsToCopy0 = connectionsTo0.values();
    for (Connection* conn: connectionsToCopy0)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);
            conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsTo0.clear();

    const auto connectionsToCopy1 = connectionsTo1.values();
    for (Connection* conn: connectionsToCopy1)
    {
        if (conn != nullptr)
        {
            conn->startItem()->removeConnection(conn);

            if(conn->scene() != nullptr)
               conn->scene()->removeItem(conn);
            delete conn;
        }
    }
    connectionsTo1.clear();

    if (connectionRestIn != nullptr)
    {
        connectionRestIn->startItem()->removeConnection(connectionRestIn);
        delete connectionRestIn;
    }

    const auto connectionsFromCopy = connectionsFrom;
    for(Connection* conn: connectionsFromCopy)
    {
        conn->endItem()->removeConnection(conn);
        if(conn->scene() != nullptr)
            conn->scene()->removeItem(conn);
        delete conn;
    }
    connectionsFrom.clear();

    const auto connectionsRestOutCopy = connectionsRestOut;
    for(Connection* conn: connectionsRestOutCopy)
    {
        conn->endItem()->removeConnection(conn);
        if(conn->scene() != nullptr)
            conn->scene()->removeItem(conn);
        delete conn;
    }
    connectionsRestOut.clear();
}

void Arithmetic::removeConnection(Connection *conn)
{
    if (conn->startItem() == this)
    {
        int idx = connectionsFrom.indexOf(conn);
        if (idx >= 0)
        {
            indexConnectionFrom.removeAt(idx);
            connectionsFrom.removeAt(idx);
        }
        else
        {
            connectionsRestOut.removeAll(conn);
        }
    }
    else
    {
        if (connectionRestIn == conn)
        {
            connectionRestIn = nullptr;
        }
        else
        {
            int idx = connectionsTo0.key(conn, -1);
            if (idx >= 0)
            {
                connectionsTo0.remove(idx);
            }
            else
            {
                idx = connectionsTo1.key(conn, -1);
                connectionsTo1.remove(idx);
            }
        }
        calculate();
    }
}

bool Arithmetic::addConnection(Connection *conn,  QPointF point)
{
    QPointF position = this->pos();
    qreal posX = position.rx();
    qreal posY = position.ry();
    qreal relX = point.rx();
    qreal relY = point.ry();

    if (conn->endItem() == this)
    {
        if(relX < posX + qreal(10))
        {
            for(int i=0; i < numOfInput; i++)
            {
                if(relY < posY + 100.0/(2*numOfInput+1)*(i+1) + 20)
                {
                    if (connectionsTo0.find(i) != connectionsTo0.end())
                        return false;
                    connectionsTo0[i] = conn;
                    return true;
                }
            }
            for(int i = numOfInput; i < 2*numOfInput; i++)
            {
                if(relY < posY + 100.0/(2*numOfInput+1)*(i+1) + 20)
                {
                    if (connectionsTo1.find(i) != connectionsTo1.end())
                        return false;
                    connectionsTo1[i-numOfInput] = conn;
                    break;
                }
            }
        }
        else if (relX > posX + 40 && relX < posX + 60 && relY < posY + 20)
        {
            if (connectionRestIn != nullptr)
                return false;
            connectionRestIn = conn;
        }
        else
            return false;
        calculate();
    }
    else
    {
        if (relX > posX + 90)
        {
            for(int i=0; i < numOfOutput; i++)
            {
                if(relY < posY + 100.0/(numOfOutput+1)*(i+1) + 20)
                {
                    connectionsFrom.append(conn);
                    indexConnectionFrom.append(i);
                    break;
                }
            }
        }
        else if (relX > posX + 40 && relX < posX + 60 && relY > posY + 100)
        {
            connectionsRestOut.append(conn);
        }
        else
            return false;
    }

    return true;
}

QPointF Arithmetic::getConnPosIn(Connection *conn)
{
    int idx;
    if ((idx = connectionsTo0.key(conn, -1)) != -1)
    {
        return QPointF(0, 100.0/(2*numOfInput+1) * (idx+1) + 10);
    }
    else if ((idx = connectionsTo1.key(conn, -1)) != -1)
    {
        return QPointF(0, 100/(2*numOfInput+1) * (numOfInput + idx+1) + 10);
    }
    else
    {
        return QPointF(50, 0);
    }
}

QPointF Arithmetic::getConnPosOut(Connection *conn)
{
    int idx;
    if ((idx = connectionsFrom.indexOf(conn)) >= 0)
    {
        idx = indexConnectionFrom[idx];
        return QPointF(100, 100/(numOfOutput+1)*(idx+1) + 10);
    }
    else
    {
        return QPointF(50, 120);
    }
}

bool Arithmetic::getValue(Connection *conn)
{
    int idx = connectionsFrom.indexOf(conn);
    if (idx >= 0)
    {
        idx = indexConnectionFrom[idx];
        return myValues[idx];
    }
    else if ((idx = connectionsRestOut.indexOf(conn)) >= 0)
    {
        return cinValue;
    }
    else
    {
        return false;
    }
}

void Arithmetic::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(10, 10, 80, 100);

    int i;
    for (i = 1; i <= 2*numOfInput; i++)
    {
        painter->drawLine(0, 100 / (2*numOfInput+1) * i + 10, 10, 100 / (2*numOfInput+1) * i + 10);
    }

    painter->drawLine(50, 0, 50, 10);
    painter->drawLine(50, 110, 50, 120);

    for (i = 1; i <= numOfOutput; i++)
    {
        painter->drawLine(90, 100 / (numOfOutput+1) * i + 10, 100, 100 / (numOfOutput+1) * i + 10);
    }

    QFont font = painter->font();
    font.setPixelSize(10);
    font.bold();
    painter->setFont(font);

    int y;
    for (i = 0; i < numOfInput; i++)
    {
        y = 100 / (2*numOfInput+1) * (i+1) + 10;
        const QRect rectangle = QRect(15, y - 5, 15, 10);
        painter->drawText(rectangle, Qt::AlignCenter, QString("A").append(std::to_string(i)[0]));
    }

    int tmp = y;
    for (i = 1; i <= numOfInput; i++)
    {
        y = 100 / (2*numOfInput+1) * i + tmp;
        const QRect rectangle = QRect(15, y - 5, 15, 10);
        painter->drawText(rectangle, Qt::AlignCenter, QString("B").append(std::to_string(i-1)[0]));
    }

    const QRect rectangle1 = QRect(40, 10, 20, 10);
    painter->drawText(rectangle1, Qt::AlignCenter, "Cin");

    const QRect rectangle2 = QRect(40, 100, 20, 10);
    painter->drawText(rectangle2, Qt::AlignCenter, "Cout");

    for (i = 1; i <= numOfOutput; i++)
    {
        y = 100 / (numOfOutput+1) * i + 10;
        const QRect rectangle = QRect(75, y - 5, 15, 10);
        painter->drawText(rectangle, Qt::AlignCenter, QString("S").append(std::to_string(i-1)[0]));
    }

    const QRect rectangle = QRect(30, 55, 40, 10);
    switch(elementType())
    {
        case ElementType::Adder:
            painter->drawText(rectangle, Qt::AlignCenter, "ADD");
            break;
        default:
            painter->drawText(rectangle, Qt::AlignCenter, "SUB");
            break;
    }

    setRect(0, 0, 100, 120);
}

Adder::Adder(int numOfInput)
    : Arithmetic(ElementType::Adder, numOfInput)
{}

void Adder::calculate()
{
    cinValue = false;
    if (connectionRestIn != nullptr && connectionRestIn->startItem()->getValue())
        cinValue = true;

    int tmp;
    for (int i = 0; i < numOfOutput; i++)
    {
        tmp = 0;
        tmp += cinValue ? 1 : 0;
        tmp += (connectionsTo0.keys().indexOf(i) >= 0) && connectionsTo0[i]->startItem()->getValue() ? 1 : 0;
        tmp += (connectionsTo1.keys().indexOf(i) >= 0) && connectionsTo1[i]->startItem()->getValue() ? 1 : 0;
        cinValue = tmp > 1 ? true : false;
        myValues[i] = (tmp % 2) == 1 ? true : false;
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();

    for (Connection* conn: connectionsRestOut)
        conn->endItem()->calculate();
}

Subtractor::Subtractor(int numOfInput)
    : Arithmetic(ElementType::Subtractor, numOfInput)
{}

void Subtractor::calculate()
{
    cinValue = false;
    if (connectionRestIn != nullptr && connectionRestIn->startItem()->getValue())
        cinValue = true;

    int tmp;
    for (int i = 0; i < numOfOutput; i++)
    {
        bool a = (connectionsTo0.keys().indexOf(i) >= 0) && connectionsTo0[i]->startItem()->getValue();
        bool b = (connectionsTo1.keys().indexOf(i) >= 0) && connectionsTo1[i]->startItem()->getValue();
        tmp = 0;
        tmp += cinValue ? 1 : 0;
        tmp += a ? 1 : 0;
        tmp += b ? 1 : 0;
        cinValue = (a && tmp != 3) || tmp == 0 ? false : true;
        myValues[i] = (tmp % 2) == 1 ? true : false;
    }

    for (Connection* conn: connectionsFrom)
        conn->endItem()->calculate();

    for (Connection* conn: connectionsRestOut)
        conn->endItem()->calculate();
}

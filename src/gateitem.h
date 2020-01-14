#ifndef GATEITEM_H
#define GATEITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>
#include <QGraphicsItemGroup>

QT_BEGIN_NAMESPACE
class Connection;
class QPixmap;
class QGraphicsSceneContextMenuEvent;
class QMenu;
class QRectF;
QT_END_NAMESPACE

class LogicElement : public QGraphicsRectItem
{
public:
  enum ElementType { And, Or, Xor, Nand, Nor, Not, In, Out, Multiplexer};

  LogicElement(ElementType type,  QGraphicsItem* parent = nullptr);

  virtual void calculate() = 0;
  bool getValue() const;

  virtual void removeConnections() = 0;
  virtual void removeConnection(Connection* conn) = 0;
//virtual bool addConnection(Connection* conn) = 0;

  virtual QPointF getConnPosIn(Connection* conn);
  virtual QPointF getConnPosOut(Connection* conn);

  ElementType elementType() const { return myElementType; }
  QPixmap image() const { return pixmap; }

protected:
  ElementType myElementType;
  QPixmap pixmap;
  bool myValue;
};

/***************************************************************************************************/

class InputGate : public LogicElement
{
public:
  InputGate();

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
  QVector<Connection*> connectionsFrom;
};

/***************************************************************************************************/

class OutputGate : public LogicElement
{
public:
  OutputGate( );

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
  QVector<Connection*> connection;
};

/************************************************************************************************/

class InnerGate : public LogicElement
{
public:
  InnerGate(ElementType type);

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnectionTo(Connection *conn);
  bool addConnectionFrom(Connection *conn);

  QPointF getConnPosIn(Connection* conn) override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

protected:
  QVector<Connection*> connectionsTo;
  QVector<Connection*> connectionsFrom;
};

/************************************************************************************************/

class And : public InnerGate
{
public:
  And();
  void calculate() override;
};

class Or : public InnerGate
{
public:
  Or();
  void calculate() override;
};

class Not : public InnerGate
{
public:
  Not();
  void calculate() override;
};

class Xor : public InnerGate
{
public:
  Xor();
  void calculate() override;
};

class Nor : public InnerGate
{
public:
  Nor();
  void calculate() override;
};

class Nand : public InnerGate
{
public:
  Nand();
  void calculate() override;
};

/************************************************************************************************/

class Plexer : public LogicElement
{
public:
  Plexer(ElementType type);

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnectionTo(Connection *conn);
  bool addConnectionFrom(Connection *conn);
  bool addConnectionSelector(Connection* conn);

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

  QVector<Connection*> connectionsSelector;
  QVector<Connection*> connectionsTo;
  QVector<Connection*> connectionsFrom;
};

/************************************************************************************************/

class Multiplexer : public Plexer
{
public:
  Multiplexer(int numOfAnd = 4, int numOfNot = 2);

  void calculate() override;
  QPointF getConnPosIn(Connection* conn) override;

private:
  static Connection* connect(LogicElement* g1, LogicElement* g2);
  int getBit(int n, int k);

  QVector<class And*> AndGates;
  QVector<class Not*> NotGates;
  class Or *OrGate;
  int numOfAnd;
  int numOfNot;
};


#endif // GATEITEM_H

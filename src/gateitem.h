#ifndef GATEITEM_H
#define GATEITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>
#include <QGraphicsItemGroup>

#include <vector>
#include <map>
#include <set>

QT_BEGIN_NAMESPACE
class Connection;
class QPixmap;
class QGraphicsSceneContextMenuEvent;
class QMenu;
class QRectF;
QT_END_NAMESPACE

class GateItem : public QGraphicsRectItem
{
public:
  enum GateType { And, Or, Xor, Nand, Nor, Not, In, Out, Multiplexer};

  GateItem(GateType type,  QGraphicsItem* parent = nullptr);

  virtual void calculate() = 0;
  bool getValue() const;

  virtual void removeConnections() = 0;
  virtual void removeConnection(Connection* conn) = 0;
  virtual bool addConnection(Connection* conn) = 0;

 virtual QPointF getConnPosIn(Connection* conn= nullptr);
  virtual QPointF getConnPosOut(Connection* conn = nullptr);

  GateType gateType() const { return myGateType; }
  QPixmap image() const { return pixmap; }

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
  GateType myGateType;
  QPixmap pixmap;
  bool myValue;
};

/***********************************************************************************************************************/

class InputGate : public GateItem
{
public:
  InputGate();

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

 // void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
  QVector<Connection*> connectionsFrom;
};

/***********************************************************************************************************************/


class OutputGate : public GateItem
{
public:
  OutputGate( );

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

  //void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
  QVector<Connection*> connection;
};

/***********************************************************************************************************************/

class BaseGate : public GateItem
{
public:
  BaseGate(GateType type);

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

  QPointF getConnPosIn(Connection* conn) override;

protected:
  QVector<Connection*> connectionsTo;
  QVector<Connection*> connectionsFrom;
};

class Plexer : public GateItem
{
public:
  Plexer(GateType type);

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;
  void addSelector(Connection* conn);

  QPointF getConnPosIn(Connection* conn) override;
protected:
  QVector<Connection*> selectorConn;

  QVector<Connection*> connectionsTo;
  QVector<Connection*> connectionsFrom;
  //QPointF getConPosOut(Connection* conn) override;
};


class Multiplexer : public Plexer
{
public:
  Multiplexer();

  void calculate() override;
  void virtual paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
  QPointF getConnPosIn(Connection* conn) override;
public:
  QVector<class And*> AndGates;
  QVector<class Not*> NotGates;
  class Or *OrGate;
  int numOfNot = 2;
  int numOfAnd = 4;

  static Connection* connect(GateItem* g1, GateItem* g2);
  int getBit(int n, int k);
};


/***********************************************************************************************************************/

class And : public BaseGate
{
public:
  And();
  void calculate() override;
};

class Or : public BaseGate
{
public:
  Or();
  void calculate() override;
};

class Not : public BaseGate
{
public:
  Not();
  void calculate() override;
};

class Xor : public BaseGate
{
public:
  Xor();
  void calculate() override;
};

class Nor : public BaseGate
{
public:
  Nor();
  void calculate() override;
};

class Nand : public BaseGate
{
public:
  Nand();
  void calculate() override;
};

/***********************************************************************************************************************/


#endif // GATEITEM_H

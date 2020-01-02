#ifndef GATEITEM_H
#define GATEITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>

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
  enum GateType { And, Or, Xor, Nand, Nor, Not, In, Out};

  GateItem(GateType type,  QGraphicsItem* parent = nullptr);

  virtual void calculate() = 0;
  bool getValue() const;
  unsigned getId() const;

  virtual void removeConnections() = 0;
  virtual void removeConnection(Connection* conn) = 0;
  virtual bool addConnection(Connection* conn) = 0;

  GateType gateType() const { return myGateType; }
  QPixmap image() const { return pixmap; }

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
  GateType myGateType;
  QPixmap pixmap;
  bool myValue;
};

class InputGate : public GateItem
{
public:
  InputGate();

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

private:
  QVector<Connection*> connectionsFrom;
};

class OutputGate : public GateItem
{
public:
  OutputGate( );

  void calculate() override;

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

private:
  QVector<Connection*> connection;
};

class InnerGate : public GateItem
{
public:
  InnerGate(GateType type);

  void removeConnections() override;
  void removeConnection(Connection *conn) override;
  bool addConnection(Connection *conn) override;

protected:
  QVector<Connection*> connectionTo;
  QVector<Connection*> connectionFrom;
};

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

#endif // GATEITEM_H

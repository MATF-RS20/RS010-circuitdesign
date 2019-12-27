#ifndef GATEITEM_H
#define GATEITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>

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
  enum GateType { And, Or, Xor, Nand, Nor, Not};

  GateItem(GateType type, QGraphicsItem* parent = nullptr);

  void removeConnection(Connection* conn);
  void removeConnections();
  void addConnection(Connection* conn);


  GateType gateType() const { return myGateType; }
  QPixmap image() const { return pixmap; }

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
  GateType myGateType;
  QPixmap pixmap;
  QVector<Connection*> connections;
};


#endif // GATEITEM_H

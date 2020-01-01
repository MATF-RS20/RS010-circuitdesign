#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class GateItem;

class Connection : public QGraphicsLineItem
{
public:
  Connection(GateItem* startItem, GateItem* endItem,
             QGraphicsItem* parent = nullptr);

  //mozda nece trebati jer povlacimo samo liniju.
  //QRectF boundingRect() const override;
  //QPainterPath shape() const override;

  GateItem* startItem() const { return myStartItem; }
  GateItem* endItem() const { return myEndItem; }
  void updatePosition();

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
  GateItem* myStartItem;
  GateItem* myEndItem;
  QColor myColor = Qt::green;
};

#endif // CONNECTION_H

#include "connection.h"
#include "gateitem.h"
#include <QPainter>
#include <QPen>

Connection::Connection(GateItem* startItem, GateItem* endItem, QGraphicsItem* parent)
  : QGraphicsLineItem(parent), myStartItem(startItem), myEndItem(endItem)
{
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  QPen myPen = pen();
  myPen.setColor(myColor);
  painter->setPen(myPen);
  painter->setBrush(myColor);

  QLineF line(mapFromItem(myStartItem,70,25),
              mapFromItem(myEndItem,10,25));
  setLine(line);

  painter->drawLine(line);
}

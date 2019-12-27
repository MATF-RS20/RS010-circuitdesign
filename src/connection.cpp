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

void Connection::updatePosition(){
    QLineF line(mapFromItem(myStartItem,0,0),
                mapFromItem(myEndItem,0,0));
    setLine(line);
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  // povezivanje cvora sa samim sobom
  if (myStartItem->collidesWithItem(myEndItem))
    return;

  QPen myPen = pen();
  myPen.setColor(myColor);
  painter->setPen(myPen);
  painter->setBrush(myColor);

  QLineF line(mapFromItem(myStartItem,70,25),
              mapFromItem(myEndItem,10,25));
  setLine(line);

  painter->drawLine(line);

}

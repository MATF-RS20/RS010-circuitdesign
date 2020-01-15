#include "connection.h"
#include "gateitem.h"
#include <QPainter>
#include <QPen>

Connection::Connection(LogicElement* startItem, LogicElement* endItem, QGraphicsItem* parent)
  : QGraphicsLineItem(parent), myStartItem(startItem), myEndItem(endItem)
{
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
   QPen myPen = pen();
   QPainterPath path;

  if(startItem()->getValue(this))
      myPen.setColor(Qt::green);
  else
      myPen.setColor(Qt::red);

  painter->setPen(myPen);

  QPointF pointStart = mapFromItem(myStartItem, myStartItem->getConnPosOut(this));
  QPointF pointEnd = mapFromItem(myEndItem, myEndItem->getConnPosIn(this));

  qreal breakX = pointStart.rx() + 1.0/3.0 * (pointEnd.rx() - pointStart.rx());
  QPointF breakPoint(breakX, pointStart.ry());
  QPointF afterBreakPoint(breakX, pointEnd.ry());

  path.moveTo(pointStart);
  path.lineTo(breakPoint);
  path.lineTo(afterBreakPoint);
  path.lineTo(pointEnd);

  painter->drawPath(path);
}

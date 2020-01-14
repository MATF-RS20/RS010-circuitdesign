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
  myPen.setColor(myColor);
  painter->setPen(myPen);
  painter->setBrush(myColor);


  QPointF pointStart = myStartItem->getConnPosOut(this);
  QPointF pointEnd = myEndItem->getConnPosIn(this);

 /*
  if(myStartItem->type() != GateItem::In && myStartItem->type() != GateItem::Out){
      pointStart = qgraphicsitem_cast<InnerGate*>(myStartItem)->getConnPosOut(this);
  } else{
    pointStart = QPointF(20,20);
  }
  if(myEndItem->type() != GateItem::In && myEndItem->type() != GateItem::Out){
      pointEnd = qgraphicsitem_cast<InnerGate*>(myEndItem)->getConnPosIn(this);
  } else{
    pointEnd = QPointF(0,20);
  }
*/
  QLineF line(mapFromItem(myStartItem,pointStart),
              mapFromItem(myEndItem,pointEnd));
  setLine(line);

  painter->drawLine(line);
}

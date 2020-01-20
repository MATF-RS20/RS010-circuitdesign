#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class LogicElement;

class Connection : public QGraphicsLineItem, public QObject
{
public:
  Connection(LogicElement* startItem, LogicElement* endItem,
             QGraphicsItem* parent = nullptr);

  LogicElement* startItem() const { return myStartItem; }
  LogicElement* endItem() const { return myEndItem; }
  QPainterPath shape() const override;

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
  LogicElement* myStartItem;
  LogicElement* myEndItem;
  QColor myColor = Qt::green;

  QPainterPath myPath;
};

#endif // CONNECTION_H

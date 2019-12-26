#ifndef GATEITEM_H
#define GATEITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsSceneContextMenuEvent;
class QMenu;
class QRectF;
QT_END_NAMESPACE

class GateItem : public QGraphicsRectItem
{
public:
  //Za sta nam sluzi ovaj enum ????
  enum { Type = UserType + 15 };
  enum GateType { And, Or, Xor, Nand, Nor, Not};

  GateItem(GateType type, QGraphicsItem* parent = nullptr);
/*
  void removeArrow(Arrow* arrow);
  void removeArrows();
  void addArrow(Arrow* arrow);
*/

  GateType gateType() const { return myGateType; }
  QPixmap image() const { return pixmap; }
  int type() const override { return Type; }

protected:
  //QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
  GateType myGateType;
  QPixmap pixmap;
  //  QVector<Arrow*> arrows;
};


#endif // GATEITEM_H

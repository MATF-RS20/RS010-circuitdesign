#include "gateitem.h"
#include <iostream>

GateItem::GateItem(GateType type, QGraphicsItem* parent)
  : QGraphicsRectItem(parent), myGateType(type)
{
    switch (myGateType) {
      case And:
        pixmap.load("../images/and.png");
        break;
      case Or:
        pixmap.load("../images/or.png");
        break;
      case Xor:
        pixmap.load("../images/xor.png");
        break;
      case Nand:
        pixmap.load("../images/nand.png");
        break;
      case Nor:
        pixmap.load("../images/nor.png");
        break;
      case Not:
        pixmap.load("../images/not.png");
        break;
    }

    std::cout << "Pozvan konstruktor za GateItem" << std::endl;
}

void GateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
  painter->drawPixmap(0,0,50,50,pixmap);
  setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
  std::cout << "Pozvan paint za GateItem" << std::endl;

}

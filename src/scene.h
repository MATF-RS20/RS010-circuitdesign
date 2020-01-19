#ifndef SCENE_H
#define SCENE_H

#include "gateitem.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

QT_BEGIN_NAMESPACE
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class Scene : public QGraphicsScene
{
  Q_OBJECT

public:
  enum Mode { InsertItem, InsertLine, MoveItem };

  explicit Scene(QObject* parent = nullptr);

public slots:
  void setMode(Mode mode);
  void setElementType(LogicElement::ElementType type);
  void setNumOfInputs(int num);

signals:
  void itemInserted();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
  LogicElement* getNewElement(LogicElement::ElementType type);

  LogicElement::ElementType myItemType;
  Mode myMode;
  QPointF startPoint;
  QGraphicsLineItem *line;
  int numOf = 2;
};

#endif // SCENE_H

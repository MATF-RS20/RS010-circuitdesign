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
  void setItemType(GateItem::GateType type);

signals:
  void itemInserted(GateItem* item);
  void buttonClicked(int id);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
  bool isItemChange(int type) const;

  GateItem::GateType myItemType;
  Mode myMode;
  QPointF startPoint;
  QGraphicsLineItem *line;

};

#endif // SCENE_H

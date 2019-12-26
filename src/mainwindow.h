#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gateitem.h"

class Scene;

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

private slots:
    void itemInserted(GateItem *item);
    void deleteItem();
    void buttonGroupClicked(int id);

private:
    Ui::MainWindow *ui;
    Scene* scene;
    QGraphicsView* view;
    void setUpButtonsIds();
};

#endif // MAINWINDOW_H

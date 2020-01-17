#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
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
    enum DialogType {InserInput, InsertSelector};
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void itemInserted();
    void deleteItem();
    void buttonGroupClicked(int id);
    void changeModMove();
    void changeModConnect();
    void setNumOfInputs();

signals:
    void buttonClicked(int id);

private:
    void setUp();
    QActionGroup * actionGroup;
    Ui::MainWindow *ui;
    Scene* scene;
    DialogType dialogType;
};

#endif // MAINWINDOW_H

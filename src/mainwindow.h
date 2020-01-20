#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include "gateitem.h"
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum DialogType {InserInput, InsertSelector, InsertArithmetic};
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void itemInserted();
    void deleteItem();
    void buttonGroupClicked(int id);
    void changeModMove();
    void changeModConnect();
    void setNumOfInputs();


/*
protected Q_SLOTS:
    void wheelEvent(QWheelEvent *event);
*/

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

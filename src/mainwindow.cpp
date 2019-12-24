#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap not_pix("../images/not_1.jpg");
    ui->lbl_not->setPixmap(not_pix.scaled(50, 50, Qt::KeepAspectRatio));
    QPixmap and_pix("../images/and_1.png");
    ui->lbl_and->setPixmap(and_pix.scaled(50, 50, Qt::KeepAspectRatio));
    QPixmap or_pix("../images/or_1.jpg");
    ui->lbl_or->setPixmap(or_pix.scaled(50, 50, Qt::KeepAspectRatio));
    QPixmap nor_pix("../images/nor_1.jpg");
    ui->lbl_nor->setPixmap(nor_pix.scaled(50, 50, Qt::KeepAspectRatio));
    QPixmap nand_pix("../images/nand_1.jpg");
    ui->lbl_nand->setPixmap(nand_pix.scaled(50, 50, Qt::KeepAspectRatio));
    QPixmap xor_pix("../images/xor_1.jpg");
    ui->lbl_xor->setPixmap(xor_pix.scaled(50, 50, Qt::KeepAspectRatio));

//    QListWidgetItem *item = new QListWidgetItem(QIcon("../images/not_1.jpg"), "Not");
//    ui->listWidget->addItem(item);
//    QListWidgetItem *item1 = new QListWidgetItem(QIcon("../images/and_1.jpg"), "And");
//    ui->listWidget->addItem(item1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}


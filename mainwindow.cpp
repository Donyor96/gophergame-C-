#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include"handle.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene3;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->pushButton_start,SIGNAL(clicked()),this->sc,SLOT(startGame()));
    connect(this->ui->pushButton_pause,SIGNAL(clicked()),this->sc,SLOT(pauseGame()));
    connect(this->ui->pushButton_stop,SIGNAL(clicked()),this->sc,SLOT(stopGame()));

    this->score = 0;
    handle *hand1 =  handle::getInstance();

    connect(hand1,SIGNAL(beatMouse()),this,SLOT(updateScore()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int res = QMessageBox::question(this,"tile11","are you sure to close?","Yes","No");

    if(res==1)
    {
        event->ignore();
    }
}


void MainWindow::updateScore()
{
    this->score += 10;
    this->ui->lcdNumber->display(this->score);

}

#ifndef MYSCENE3_H
#define MYSCENE3_H

#include <QObject>
#include<QGraphicsScene>

#include "myitem1.h"
#include "myitem2.h"
#include<QTimer>
class myScene3 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene3(QObject *parent = nullptr);

signals:
public slots:
    void showMouse();
    void startGame();
    void pauseGame();
    void stopGame();
private:
    myItem1 *item;
    myItem2 *item2;
    myItem1 *item3[4][4];
    myItem1 *item4[16];
    QTimer *ptimer;
};

#endif // MYSCENE3_H

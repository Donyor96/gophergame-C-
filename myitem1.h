#ifndef MYITEM1_H
#define MYITEM1_H
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
class myItem1 : public QGraphicsPixmapItem
{
public:
    myItem1();
    void SetPict(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setMouse(bool mou);
    bool isMouse();
    void setStart(bool st);
    bool isStart();



private:
    bool mouse;
    bool start;
};

#endif // MYITEM1_H

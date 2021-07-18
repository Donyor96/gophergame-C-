#include "myitem1.h"
#include<QDebug>

#include "handle.h"
#include<QCursor>
myItem1::myItem1()
{
   this->setPixmap(QPixmap(":/new/prefix2/pic/33.png"));
   this->mouse = false;
    this->start = false;
}
void myItem1::SetPict(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myItem1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/new/prefix2/pic/chui.png")));
    //qDebug()<<"function is ok";
   if(isStart())
   {
       handle *hand1 = handle::getInstance();
       if(isMouse())
       {
           hand1->addScore();
           this->mouse = false;
           qDebug()<<"your hiting is a mouse!";
       }
       else
       {
            qDebug()<<"your hiting is not a mouse!";
       }
   }

}
void myItem1::setMouse(bool mou)
{
    this->mouse = mou;
}

bool myItem1::isMouse()
{
    return  this->mouse;
}

void myItem1::setStart(bool st)
{
    this->start = st;
}

bool myItem1::isStart()
{
    return  this->start;
}

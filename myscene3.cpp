#include "myscene3.h"

myScene3::myScene3(QObject *parent) : QGraphicsScene(parent)
{
   //this->item = new myItem1;
   // item->setPos(0,0);
   //this->addItem(item);
   // this->item2 = new myItem2;
   // item2->setPos(item->boundingRect().width(),0);
   // this->addItem(item2);

   /* for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->item3[i][j] = new myItem1;
            qreal w = item3[i][j]->boundingRect().width();
            qreal h = item3[i][j]->boundingRect().height();

            item3[i][j]->setPos(w*i,h*j);
            this->addItem(item3[i][j]);
        }
    }*/

    for(int k=0;k<16;k++)
    {
        int i = k/4;
        int j = k%4;

        this->item4[k] = new myItem1;
        qreal w = item4[k]->boundingRect().width();
        qreal h = item4[k]->boundingRect().height();

        item4[k]->setPos(w*i,h*j);
        this->addItem(item4[k]);
    }

    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));


}
void myScene3::showMouse()
{
    // mouse count
    int count = rand()%3+1;//[1,3]
    for(int i=0;i<16;i++)
    {
        this->item4[i]->SetPict(":/new/prefix2/pic/33.png");
        this->item4[i]->setMouse(false);
    }
    for(int i=0;i<count;i++)
    {
        //item4[index]
        int index = rand()%16;//[0,15]
        this->item4[index]->SetPict(":/new/prefix1/pic/16.png");
        this->item4[index]->setMouse(true);
    }



    //this->item4[3]->SetPict(":/new/prefix1/pic/16.png");
}
void myScene3::startGame()
{
    for(int i=0;i<16;i++)
    {
        this->item4[i]->setStart(true);
    }
    this->ptimer->start(1500);
}

void myScene3::pauseGame()
{
    for(int i=0;i<16;i++)
    {
        this->item4[i]->setStart(false);
    }
    this->ptimer->stop();
}

void myScene3::stopGame()
{
    for(int i=0;i<16;i++)
    {
        this->item4[i]->setStart(false);
    }
    this->ptimer->stop();
    for(int i=0;i<16;i++)
    {
        this->item4[i]->SetPict(":/new/prefix2/pic/33.png");
        this->item4[i]->setMouse(false);
    }
}

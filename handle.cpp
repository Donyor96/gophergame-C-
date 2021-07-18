#include "handle.h"

handle::handle(QObject *parent) : QObject(parent)
{

}
handle *handle::hand = new handle;
handle * handle::getInstance()
{
    return hand;
}

void handle::addScore()
{
    emit beatMouse();
}

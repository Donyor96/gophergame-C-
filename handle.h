#ifndef HANDLE_H
#define HANDLE_H

#include <QObject>

class handle : public QObject
{
    Q_OBJECT
public:
    static handle * getInstance();
    void addScore();
private: handle(QObject *parent = nullptr);

signals:
    void beatMouse();
private:
    static handle *hand;

};

#endif // HANDLE_H

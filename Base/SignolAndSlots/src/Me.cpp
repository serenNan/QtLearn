#include "Me.h"
#include <qglobal.h>
#include <qobject.h>

Me::Me(QObject *parent) : QObject(parent) {}

void Me::eat(const QString& food)
{
    qDebug() << "我带女友去吃:"<<food;
}
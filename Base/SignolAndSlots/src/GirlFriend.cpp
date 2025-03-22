#include "GirlFriend.h"

GirlFriend::GirlFriend(QObject *parent) : QObject(parent) {}

void GirlFriend::setHungry(const QString& food)
{
    // 触发带参数的hungry信号
    emit hungry(food);
}

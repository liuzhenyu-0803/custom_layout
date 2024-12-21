#include "CustomLayoutMask.h"


CustomLayoutMask::CustomLayoutMask(QWidget *parent)
    : QFrame(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    setWindowOpacity(0.5);
}

CustomLayoutMask::~CustomLayoutMask()
{

}

void CustomLayoutMask::paintEvent(QPaintEvent *event)
{
    
}

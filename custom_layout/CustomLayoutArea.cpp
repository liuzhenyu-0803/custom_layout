#include "CustomLayoutArea.h"  
#include <QVBoxLayout>  


CustomLayoutArea::CustomLayoutArea(QWidget *parent)
    : QFrame(parent)
{
    auto layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
}

CustomLayoutArea::~CustomLayoutArea()
{
}

void CustomLayoutArea::SetWidget(QWidget *widget)
{
    layout()->addWidget(widget);
}

void CustomLayoutArea::SetAreaType(CustomLayoutAreaType area_type)
{
    area_type_ = area_type;
}

CustomLayoutAreaType CustomLayoutArea::GetAreaType() const
{
    return area_type_;
}
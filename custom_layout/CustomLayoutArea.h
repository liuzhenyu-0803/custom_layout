#pragma once  

#include "CustomLayoutDefine.h"  
#include <QFrame>  


class CustomLayoutArea : public QFrame
{
    Q_OBJECT

public:
    explicit CustomLayoutArea(QWidget *parent = nullptr);
    ~CustomLayoutArea();

    void SetWidget(QWidget *widget);
    void SetAreaType(CustomLayoutAreaType area_type);
    CustomLayoutAreaType GetAreaType() const;

private:
    CustomLayoutAreaType area_type_ = CustomLayoutAreaType::Center;
};
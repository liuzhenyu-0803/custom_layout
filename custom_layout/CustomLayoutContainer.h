#pragma once  

#include "CustomLayoutDefine.h"  
#include "CustomLayoutArea.h"  
#include "CustomLayoutItem.h"  
#include "CustomLayoutIndicator.h"
#include "CustomLayoutMask.h"

#include <QFrame>  
#include <QGridLayout>  


class CustomLayoutContainer : public QFrame
{
    Q_OBJECT

public:
    explicit CustomLayoutContainer(QWidget *parent = nullptr);
    ~CustomLayoutContainer();

    void AddItem(CustomLayoutItem *item, CustomLayoutAreaType area);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QGridLayout *layout_{ nullptr };

    CustomLayoutArea *top_area_{ nullptr };
    CustomLayoutArea *left_area_{ nullptr };
    CustomLayoutArea *center_area_{ nullptr };
    CustomLayoutArea *right_area_{ nullptr };
    CustomLayoutArea *bottom_area_{ nullptr };

    CustomLayoutIndicator *indicator_{ nullptr };
    CustomLayoutMask *mask_{ nullptr };
};
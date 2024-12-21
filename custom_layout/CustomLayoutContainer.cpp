#include "CustomLayoutContainer.h"  

#include <QEvent>
#include <QDebug>


CustomLayoutContainer::CustomLayoutContainer(QWidget *parent)
    : QFrame(parent)
{
    layout_ = new QGridLayout(this);
    layout_->setMargin(0);
    layout_->setSpacing(10);

    top_area_ = new CustomLayoutArea(this);
    top_area_->setObjectName("TopFrame");
    top_area_->SetAreaType(CustomLayoutAreaType::Top);
    layout_->addWidget(top_area_, 0, 0, 1, 3);

    left_area_ = new CustomLayoutArea(this);
    left_area_->setObjectName("LeftFrame");
    left_area_->SetAreaType(CustomLayoutAreaType::Left);
    layout_->addWidget(left_area_, 1, 0);

    center_area_ = new CustomLayoutArea(this);
    center_area_->setObjectName("CenterFrame");
    center_area_->SetAreaType(CustomLayoutAreaType::Center);
    layout_->addWidget(center_area_, 1, 1);

    right_area_ = new CustomLayoutArea(this);
    right_area_->setObjectName("RightFrame");
    right_area_->SetAreaType(CustomLayoutAreaType::Right);
    layout_->addWidget(right_area_, 1, 2);

    bottom_area_ = new CustomLayoutArea(this);
    bottom_area_->setObjectName("BottomFrame");
    bottom_area_->SetAreaType(CustomLayoutAreaType::Bottom);
    layout_->addWidget(bottom_area_, 2, 0, 1, 3);

    indicator_ = new CustomLayoutIndicator();
    indicator_->resize(400, 400);
    indicator_->hide();

    mask_ = new CustomLayoutMask();
    mask_->hide();
}

CustomLayoutContainer::~CustomLayoutContainer()
{

}

void CustomLayoutContainer::AddItem(CustomLayoutItem *item, CustomLayoutAreaType area)
{
    CustomLayoutArea *layout_area = nullptr;

    switch (area)
    {
    case CustomLayoutAreaType::Top:
        layout_area = top_area_;
        break;
    case CustomLayoutAreaType::Left:
        layout_area = left_area_;
        break;
    case CustomLayoutAreaType::Right:
        layout_area = right_area_;
        break;
    case CustomLayoutAreaType::Bottom:
        layout_area = bottom_area_;
        break;
    default:
        layout_area = center_area_;
        break;
    }

    layout_area->SetWidget(item);

    item->installEventFilter(this);
}

bool CustomLayoutContainer::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        if (auto item = dynamic_cast<CustomLayoutItem *>(watched))
        {
            if (!indicator_->isVisible())
            {
                auto global_pos = mapToGlobal(QPoint(0, 0));
                indicator_->move(global_pos.x() + (width() - indicator_->width()) / 2, global_pos.y() + (height() - indicator_->height()) / 2);
                indicator_->show();
            }
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        if (auto item = dynamic_cast<CustomLayoutItem *>(watched))
        {
            if (indicator_->isVisible())
            {
                indicator_->hide();
            }

            if (mask_->isVisible())
            {
                mask_->hide();
            }
        }
    }

    return QFrame::eventFilter(watched, event);
}

void CustomLayoutContainer::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);
}


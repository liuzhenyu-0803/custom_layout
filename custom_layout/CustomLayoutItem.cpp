#include "CustomLayoutItem.h"  

#include "CustomLayoutDefine.h"  
#include "CustomLayoutContainer.h"  

#include <QVBoxLayout>  
#include <QEvent>  
#include <QMouseEvent>  
#include <QApplication>  
#include <QCursor>  
#include <QStyle>  


CustomLayoutItem::CustomLayoutItem(QWidget *parent)
    : QFrame(parent)
{
    auto layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    title_frame_ = new QFrame(this);
    title_frame_->setObjectName("CustomLayoutItemTitleFrame");
    title_frame_->setFixedHeight(30);
    layout->addWidget(title_frame_);

    content_frame_ = new QFrame(this);
    content_frame_->setObjectName("CustomLayoutItemContentFrame");
    content_frame_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(content_frame_);
}

CustomLayoutItem::~CustomLayoutItem()
{

}

bool CustomLayoutItem::IsFloating() const
{
    return drag_start_pos_.isNull() ? false : true;
}

void CustomLayoutItem::mousePressEvent(QMouseEvent *event)
{
    if (title_frame_->geometry().contains(event->pos()))
    {
        drag_start_pos_ = QCursor::pos();
    }

    QFrame::mousePressEvent(event);
}

void CustomLayoutItem::mouseMoveEvent(QMouseEvent *event)
{
    if (!drag_start_pos_.isNull())
    {
        auto current_pos = QCursor::pos();
        auto delta = current_pos - drag_start_pos_;
        if (delta.manhattanLength() > 0)
        {
            if (parent())
            {
                SwichToFloat();
            }
            move(pos() + delta);

            drag_start_pos_ = current_pos;
        }
    }

    QFrame::mouseMoveEvent(event);
}

void CustomLayoutItem::mouseReleaseEvent(QMouseEvent *event)
{
    drag_start_pos_ = QPoint();

    QFrame::mouseReleaseEvent(event);
}

void CustomLayoutItem::SwichToFloat()
{
    auto global_pos = mapToGlobal(QPoint(0, 0));
    setParent(nullptr);
    move(global_pos);
    show();
}


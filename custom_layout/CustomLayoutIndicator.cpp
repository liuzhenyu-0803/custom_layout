#include "CustomLayoutIndicator.h"

#include <QGridLayout>


CustomLayoutIndicator::CustomLayoutIndicator(QWidget *parent)
    : QFrame(parent)
{
    setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    //setAttribute(Qt::WA_TransparentForMouseEvents, true);

    auto layout = new QGridLayout(this);

    top_button_ = new QPushButton(this);
    top_button_->setObjectName("top_button");
    top_button_->setFixedSize(40, 40);
    layout->addWidget(top_button_, 0, 1);

    left_button_ = new QPushButton(this);
    left_button_->setObjectName("left_button");
    left_button_->setFixedSize(40, 40);
    layout->addWidget(left_button_, 1, 0);

    center_button_ = new QPushButton(this);
    center_button_->setObjectName("center_button");
    center_button_->setFixedSize(40, 40);
    layout->addWidget(center_button_, 1, 1);

    right_button_ = new QPushButton(this);
    right_button_->setObjectName("right_button");
    right_button_->setFixedSize(40, 40);
    layout->addWidget(right_button_, 1, 2);

    bottom_button_ = new QPushButton(this);
    bottom_button_->setObjectName("bottom_button");
    bottom_button_->setFixedSize(40, 40);
    layout->addWidget(bottom_button_, 2, 1);
}

CustomLayoutIndicator::~CustomLayoutIndicator()
{

}

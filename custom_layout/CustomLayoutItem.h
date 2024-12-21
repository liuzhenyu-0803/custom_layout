#pragma once  

#include "CustomLayoutDefine.h"  
#include <QFrame>  


class CustomLayoutItem : public QFrame
{
    Q_OBJECT

public:
    explicit CustomLayoutItem(QWidget *parent = nullptr);
    ~CustomLayoutItem();

    bool IsFloating() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void SwichToFloat();

private:
    QFrame *title_frame_ = nullptr;
    QFrame *content_frame_ = nullptr;
    QPoint drag_start_pos_;
};
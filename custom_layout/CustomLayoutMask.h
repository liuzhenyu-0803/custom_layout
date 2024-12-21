#pragma once

#include <QFrame>


class CustomLayoutMask : public QFrame
{
    Q_OBJECT

public:
    explicit CustomLayoutMask(QWidget *parent = nullptr);
    ~CustomLayoutMask();

protected:
    void paintEvent(QPaintEvent *event) override;
};


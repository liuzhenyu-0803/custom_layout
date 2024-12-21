#pragma once

#include <QFrame>
#include <QPushButton>


class CustomLayoutIndicator : public QFrame
{
    Q_OBJECT

public:
    explicit CustomLayoutIndicator(QWidget *parent = nullptr);
    ~CustomLayoutIndicator();

private:
    QPushButton *top_button_{ nullptr };
    QPushButton *left_button_{ nullptr };
    QPushButton *center_button_{ nullptr };
    QPushButton *right_button_{ nullptr };
    QPushButton *bottom_button_{ nullptr };
};


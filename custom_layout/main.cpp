#include "CustomLayoutContainer.h"  
#include <QtWidgets/QApplication>  
#include <QFile>  

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("./custom_layout.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
    }

    CustomLayoutContainer f;
    auto ratio = 2;
    f.resize(1024 * ratio, 720 * 2);
    f.show();

    {
        auto item = new CustomLayoutItem;
        f.AddItem(item, CustomLayoutAreaType::Center);
    }

    {
        auto item = new CustomLayoutItem;
        f.AddItem(item, CustomLayoutAreaType::Right);
    }

    return a.exec();
}
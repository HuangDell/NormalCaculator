#include "main.h"
#include <QApplication>
int main(int argc,char* argv[])//启动程序
{
    QApplication app(argc,argv);
    Main main;
    main.show();
    return app.exec();
}

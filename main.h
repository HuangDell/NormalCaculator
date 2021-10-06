#ifndef MAIN_H
#define MAIN_H

#define SETCURSOREND \
QTextCursor text_cursor(ui->view->textCursor());\
text_cursor.movePosition(QTextCursor::End);\
ui->view->setTextCursor(text_cursor); //定义宏：将关标移动至文本末

#define ISCAL \
if(isCal){ui->view->setText(ans);isCal=false;} //判断是否已经计算过，清空保留答案

#define CAL_CLEAR \
if(isCal)ui->view->clear();\
isCal=false;
//判断是否计算过，清空并不保留答案



#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include "tools.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main; }
QT_END_NAMESPACE

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = nullptr);
    ~Main();

private:
    bool isCal;
    QString ans;
    Ui::Main *ui;
    void initMenuBar();
    void initButton();
};
#endif // MAIN_H

#ifndef MAIN_H
#define MAIN_H

#define SETCURSOREND \
QTextCursor text_cursor(ui->view->textCursor());\
text_cursor.movePosition(QTextCursor::End);\
ui->view->setTextCursor(text_cursor);

#define ISCAL \
if(isCal){ui->view->setText(ans);isCal=false;}

#define CAL_CLEAR \
if(isCal)ui->view->clear();\
isCal=false;




#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <fstream>
#include <string>
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

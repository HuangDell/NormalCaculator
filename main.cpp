#include "main.h"
#include "ui_main.h"
Main::Main(QWidget *parent)
    : QMainWindow(parent),isCal(false),ans("0"), ui(new Ui::Main)
{
    ui->setupUi(this);
    ui->view->setText("0");
    setWindowTitle("计算器");
    initButton();
    initMenuBar();
}



void Main::initMenuBar() //初始化菜单栏
{
    connect(ui->author,&QAction::triggered,this,[this](){
        QFile file("./README.md");
        QMessageBox box(this);
        box.setWindowTitle("作者");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        auto txt=file.readAll();
        box.setText(QString(txt));
        box.setTextFormat(Qt::MarkdownText);
        box.exec();
    });
}

void Main::initButton()//初始化按钮
{
    //链接按钮0
    connect(ui->button_0,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("0");
    });
    //链接按钮1
    connect(ui->button_1,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("1");
        else
            ui->view->setText("1");
    });
    //链接按钮2
    connect(ui->button_2,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("2");
        else
            ui->view->setText("2");
    });
    //链接按钮3
    connect(ui->button_3,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("3");
        else
            ui->view->setText("3");
    });
    //链接按钮4
    connect(ui->button_4,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("4");
        else
            ui->view->setText("4");
    });
    //链接按钮5
    connect(ui->button_5,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("5");
        else
            ui->view->setText("5");
    });
    //链接按钮6
    connect(ui->button_6,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("6");
        else
            ui->view->setText("6");
    });
    //链接按钮7
    connect(ui->button_7,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("7");
        else
            ui->view->setText("7");
    });
    //链接按钮8
    connect(ui->button_8,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("8");
        else
            ui->view->setText("8");
    });
    //链接按钮9
    connect(ui->button_9,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        CAL_CLEAR;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText("9");
        else
            ui->view->setText("9");
    });
    //链接按钮Back
    connect(ui->button_back,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        ISCAL;
        ui->show->clear();
        if(ui->view->toPlainText()!="0" && ui->view->toPlainText().size()!=1)
        {
            auto text=ui->view->toPlainText().toStdString();
            ui->view->setText(QString::fromStdString(text.substr(0,text.size()-1)));
        }
        else //全部清空之后就自动显示为0
            ui->view->setText("0");
    });
    //链接按钮add
    connect(ui->button_add,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("+");
    });
    //链接按钮sub
    connect(ui->button_sub,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("-");
    });
    //链接按钮mult
    connect(ui->button_mult,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("*");
    });
    //链接按钮div
    connect(ui->button_div,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("/");
    });
    //链接按钮equ
    connect(ui->button_equ,&QAbstractButton::clicked,this,[this](){
        SETCURSOREND;
        isCal=true;
        ui->show->clear(); //清理逆波兰表达式显示器
        auto equ=ui->view->toPlainText();
        ui->view->insertPlainText("=");
        auto res=tools::calculate(equ);
        if(res.first==INT_MAX)
            ui->view->setText("Error!"); //判段错误信号并返回
        else
        {
            ans=QString::number(res.first);
            ui->view->insertPlainText(ans);
            for(auto st:res.second)
                ui->show->insertPlainText(st);
        }
    });
    //链接按钮(
    connect(ui->button_left,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        auto st=ui->view->toPlainText();
        if(st=="0")
        {
            ui->view->setText("(");
            return;
        }
        if(st[st.size()-1].isDigit() || st[st.size()-1]==')')
            ui->view->insertPlainText("*("); //自动添加乘号
        else
            ui->view->insertPlainText("(");
    });
    //链接按钮)
    connect(ui->button_right,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        if(ui->view->toPlainText()!="0")
            ui->view->insertPlainText(")");
    });
    //链接按钮乘方
    connect(ui->button_squa,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("^");
    });
    //链接按钮阶乘
    connect(ui->button_most,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("!");
    });
    //链接按钮clear
    connect(ui->button_clear,&QAbstractButton::clicked,this,[this](){
        ui->view->setText("0");
        ui->show->clear();
    });
    //链接按钮开方
    connect(ui->button_sqrt,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText("^(1/2)");
    });
    //链接按钮dot
    connect(ui->button_dot,&QAbstractButton::clicked,this,[this](){
        ISCAL;
        SETCURSOREND;
        ui->view->insertPlainText(".");
    });

}
Main::~Main()
{
    delete ui;
}


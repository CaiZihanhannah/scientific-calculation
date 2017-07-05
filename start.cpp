#include "start.h"
#include "ui_start.h"
#include"gamemain.h"
#include<QDebug>

Start::Start(QWidget *parent) :           //设置游戏模式选择界面
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

    this->resize(460,690);
    this->setWindowTitle("Gobang");
    this->setWindowIcon(QIcon(":/image/gobang.ico"));
    QPixmap pixmap(":/image/bird.png");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    ui->hvsh->setStyleSheet("QPushButton{background-color:black;\
                            color: white;   border-radius: 10px;  border: 2px groove gray;\
                            border-style: outset;}"
                            "QPushButton:hover{background-color:white; color: black;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                            border-style: inset; }");
    ui->hvsh->move(120,50);
    ui->hvsc->move(120,200);
    ui->hvsc->setStyleSheet("QPushButton{background-color:black;\
                            color: white;   border-radius: 10px;  border: 2px groove gray;\
                            border-style: outset;}"
                            "QPushButton:hover{background-color:white; color: black;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                            border-style: inset; }");
    ui->radioButton->setText("电脑先行");
    ui->radioButton->move(120,290);
    ui->radioButton_2->setText("您先行");
    ui->radioButton_2->move(200,290);
}

Start::~Start()
{
    delete ui;
}

void Start::on_hvsh_clicked()
{
    this->close();       //关闭当前界面
    w=new GameMain();    //生成游戏主界面
    w->SetGame(PVP);     //模式设置为pvp
    w->show();           //显示游戏主界面

}

void Start::on_hvsc_clicked()
{
    this->close();
    w=new GameMain();
    if(ui->radioButton->isChecked())
        w->SetGame(PVC,0);           //选择pvc  电脑先行
    else
        w->SetGame(PVC,1);           //玩家先行
    w->show();

}



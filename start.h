#ifndef START_H
#define START_H

#include "gamemain.h"
#include <QMainWindow>

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private:
    Ui::Start *ui;
    GameMain *w;
private slots:
   void on_hvsh_clicked();  //点击 双人对战模式
   void on_hvsc_clicked();   //点击 单人对战模式
};

#endif // START_H

#include<QMessageBox>
#include<map>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pokemon.h"
#include "net.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
//    pokemon a("test君");
//    a.attack();
//    a.gain_exp(101);
//    a.take_damage(1919810);
    Charmander b;
    Charmander c("test君二号机");
    b.attack();
    c.attack();
    b.take_damage(c.attack());
    b.take_damage(c.attack());
    b.take_damage(c.attack());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_register_2_clicked()
{
    if(this->ui->t_username->text().isEmpty())/*用户名为空*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "用户名不得为空！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(this->ui->t_password->text().isEmpty())/*密码为空*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "密码不得为空！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    if(user_map.count(this->ui->t_username->text().toStdString())!=0)/*已经存在该用户名*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "用户名已存在！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    user_map.insert(pair<string,string>(this->ui->t_username->text().toStdString(),this->ui->t_password->text().toStdString()));//信息存入哈希表
    QMessageBox::information(this->ui->register_2, "完成", "注册成功！", QMessageBox::Yes |  QMessageBox::Yes);
}

void MainWindow::on_login_clicked()
{
    if(this->ui->t_username->text().isEmpty())/*用户名为空*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "用户名不得为空！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(this->ui->t_password->text().isEmpty())/*密码为空*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "密码不得为空！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    if(user_map.count(this->ui->t_username->text().toStdString())==0)/*该用户名不存在*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "用户名不存在，请先注册！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    else if(this->ui->t_password->text().toStdString()!=user_map[this->ui->t_username->text().toStdString()])/*密码不匹配*/{
        QMessageBox::critical(this->ui->register_2, "啊哦", "密码不正确，请重试！", QMessageBox::Yes | QMessageBox::Yes);
        return;
    }
    QMessageBox::information(this->ui->register_2, "完成", "登录成功！", QMessageBox::Yes |  QMessageBox::Yes);


    Game* d=new Game;
    d->show();//启动游戏窗口
}

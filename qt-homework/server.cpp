#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->lineEdit->setText("127.0.0.1");
    ui->waiting->setVisible(false);
    connect(this, &Server::addnum, this, &Server::addingnum);
}

Server::~Server()
{
    delete ui;
}
QString Server::getHostIp()
{
    return hostIp;
}
void Server::on_okbutton_clicked()
{
    this->hostIp = ui->lineEdit->text();
    std::string str = hostIp.toStdString();
    QHostAddress test;
    if(test.setAddress(str.c_str())){
        ui->waiting->setVisible(true);
        QWidget::repaint();
        emit setmyside(true);
        emit getButton(1);
        this->close();
    }else{
        QMessageBox::warning(this, tr("Error"), tr("错误的IP地址，请重新输入！"));
    }
}

void Server::addingnum(int i){
    QString qstr = ui->lineEdit->text();
    std::string str = qstr.toStdString() + std::to_string(i);
    ui->lineEdit->setText(str.c_str());
}
void Server::on_pushButton_2_clicked()
{
    emit addnum(1);
}


void Server::on_pushButton_3_clicked()
{
    emit addnum(2);
}


void Server::on_pushButton_4_clicked()
{
    emit addnum(3);
}


void Server::on_pushButton_5_clicked()
{
    emit addnum(4);
}


void Server::on_pushButton_6_clicked()
{
    emit addnum(5);
}


void Server::on_pushButton_7_clicked()
{
    emit addnum(6);
}


void Server::on_pushButton_8_clicked()
{
    emit addnum(7);
}


void Server::on_pushButton_9_clicked()
{
    emit addnum(8);
}


void Server::on_pushButton_10_clicked()
{
    emit addnum(9);
}


void Server::on_pushButton_12_clicked()
{
    emit addnum(0);
}


void Server::on_pushButton_11_clicked()
{
    QString qstr = ui->lineEdit->text();
    std::string str = qstr.toStdString() + ".";
    ui->lineEdit->setText(str.c_str());
}


void Server::on_pushButton_13_clicked()
{
    ui->lineEdit->backspace();
}


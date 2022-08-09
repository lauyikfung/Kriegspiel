#include "Create_the_connection.h"
#include "ui_Create_the_connection.h"

creating_connection::creating_connection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creating_connection)
{
    ui->setupUi(this);
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    QString ipAddress;
    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            ipAddress = address.toString();

    }
    ui->label_2->setText(ipAddress);
    this->hostAddress = ipAddress;
}
QString creating_connection::getHostAddress()
{
    return hostAddress;
}
creating_connection::~creating_connection()
{
    delete ui;
}

void creating_connection::on_pushButton_clicked()
{
    emit setmyside(false);
    emit getButton(1);
}


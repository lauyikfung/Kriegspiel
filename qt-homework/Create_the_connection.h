#ifndef CREATE_THE_CONNECTION_H
#define CREATE_THE_CONNECTION_H

#include <QWidget>
#include <QHostAddress>
#include <qhostinfo.h>
#include <string>

#include <QNetworkInterface>
namespace Ui {
class creating_connection;
}

class creating_connection : public QWidget
{
    Q_OBJECT

public:
    explicit creating_connection(QWidget *parent = nullptr);
    QString getHostAddress();
    ~creating_connection();

public slots:
    void on_pushButton_clicked();
signals:
    void getButton(int num);
    void setmyside(bool mysid);
private:
    Ui::creating_connection *ui;
    QString hostAddress;
};

#endif // CREATE_THE_CONNECTION_H

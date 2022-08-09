#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <QWidget>
#include <QMessageBox>
#include <QHostAddress>
namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    QString getHostIp();
    ~Server();

public slots:
    void on_okbutton_clicked();
signals:
    void getButton(int num);
    void setmyside(bool mysid); 

public slots:
    void on_pushButton_2_clicked();
    void addingnum(int i);
signals:
    void addnum(int i);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::Server *ui;
    QString hostIp;
};

#endif // SERVER_H

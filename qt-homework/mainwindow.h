#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <string>
#include <QObject>
#include <Windows.h>
#include <QMessageBox>
#include <QKeyEvent>
#include <QString>
#include <QTimer>
#include "Create_the_connection.h"
#include "server.h"
#include "error_surrender.h"
#include "ui_mainwindow.h"
#include "chesses.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *chess60[12][5];
    int first_x, first_y, second_x, second_y;
    int clicked_order = 0, step = 0, unknownnum = 50;
    int overtime[2] = {0};
    int otherstep[2] = {0};
    int player_color[2] = {-1, -1};
    bool stat = false, overtimed = false, operated = true;
    bool setted = false, shutted = false, started = false;
    bool myside = false, game_ended = false, connected = false;
    bool ready[2] = {0};
    void mousePressEvent ( QMouseEvent * e );
    void closeEvent(QCloseEvent *event);
    void reprint(bool highl, int x, int y);
    void setlabel(int i, int j);
    void setbutton(int i, int k, int l, int m);
    void showcolor();
    void casting();
    void wn();
    void losing();
    void endgame();
    void surrender();
    void timestarted();
    void game(int sta);
    void checkfirstclicked();
    void checksecondclicked();
    void checkendgame();

public slots:
    void on_actionCreate_the_connection_2_triggered();
    void on_actionConnect_to_Server_triggered();
    void on_actionStart_triggered();
    void on_actionAdmit_defeat_triggered();
    void createReturn(int num);
    void connectReturn(int num);
    void readData();

private slots:
    void on_actionDisconnect_triggered();

private:
    Ui::MainWindow *ui;
    Server *sv = nullptr;
    creating_connection *cc;
    QTcpServer *server;
    QTcpSocket *socket = nullptr;
};

#endif // MAINWINDOW_H

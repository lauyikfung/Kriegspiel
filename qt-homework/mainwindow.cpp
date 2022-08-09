#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->installEventFilter(this);
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    ui->label_6->setScaledContents(true);
    setlabel(0, 0);
    setbutton(1, 0, 0, 0);
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 5; j++){
            this->chess60[i][j] = new QLabel(ui->centralwidget);
            this->chess60[i][j]->setObjectName(QString::fromUtf8("label_"+std::to_string(i)+"_"+std::to_string(j)));
            this->chess60[i][j]->setGeometry(QRect(24 + j * 77, 21 + i * 35 + ((i > 5) ? 77 : 0), 51, 26));
            this->chess60[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/notknown.png")));
        }
    }
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 5; j++)
            this->chess60[i][j]->setScaledContents(true);
    setbase();
}
MainWindow::~MainWindow()
{
    delete ui;
}
volatile int press_x;
volatile int press_y;
volatile bool clickked = false;
Side sides[2];
Chess* pos_to_chess[12][5] = {0};
void MainWindow::on_actionCreate_the_connection_2_triggered()
{
    myside = false;
    cc = new creating_connection();
    cc->setWindowTitle("Create the connection");
    cc->show();
    connect(cc, SIGNAL(getButton(int)), this, SLOT(createReturn(int)));
}
void MainWindow::on_actionConnect_to_Server_triggered()
{
    myside = true;
    sv = new Server();
    sv->setWindowTitle("Connect to server");
    sv->show();
    connect(sv, SIGNAL(getButton(int)), this, SLOT(connectReturn(int)));
}
void MainWindow::on_actionStart_triggered()
{
    ready[myside] = true;
    setlabel(0, 0);
    ui->actionStart->setEnabled(false);
    if((!myside) && (!ready[!myside]))
        socket->write("start ");
    else if(ready[!myside] && (!myside)){
        started = true;
        game(0);
    } if(myside)
        socket->write("prepared ");
}
void MainWindow::on_actionAdmit_defeat_triggered()
{
    surrender();
}
void MainWindow::mousePressEvent ( QMouseEvent * e )
{
    if((e->button()==Qt::LeftButton) && (myside == stat) &&(!shutted))
    {
        clickked = true;
        press_x = e->localPos().x();
        press_y = e->localPos().y();
        if((press_x > 24)&&(press_x < 383) &&(press_x % 77 > 24)){
            if((press_y > 46)&&(press_y < 534))
                if((press_y < 247)||(press_y > 333)){
                    if(clicked_order == 1){
                        first_x = press_x;
                        first_y = press_y;
                        checkfirstclicked();
                    }
                    if(clickked&&clicked_order == 2){
                        second_x = press_x;
                        second_y = press_y;
                        checksecondclicked();
                    }
                }
        }
    }
}
void MainWindow::closeEvent(QCloseEvent *event){
    shutted = true;
    if((!game_ended)&&(connected))
        socket->write("quit  ");
}
void MainWindow::createReturn(int num)
{
    if(num == 1)
    {
        server = new QTcpServer(this);
        server->listen(QHostAddress(cc->getHostAddress()), 8888);
        this->myside = false;
        ui->actionCreate_the_connection_2->setEnabled(false);
        ui->actionConnect_to_Server->setEnabled(false);
        QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("waiting"), cc->getHostAddress()+tr(" is waiting for new connection..."),QMessageBox::Cancel,this);
        waiting->setStyleSheet("QLabel{""font: 18px""}");
        bool isconnect = false;
        connect(server, &QTcpServer::newConnection, [&]()
        {
            connected = true;
            ready[0] = ready[1] = false;
            socket = server->nextPendingConnection();
            setbutton(0, 1, 1, 1);
            setlabel(1, 0);
            connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
            isconnect = true;
            waiting->close();
        });

        if(waiting->exec() == QMessageBox::Cancel && !isconnect)
        {
            server->close();
            ui->actionCreate_the_connection_2->setEnabled(true);
            ui->actionConnect_to_Server->setEnabled(true);
        }
    }
}

void MainWindow::connectReturn(int num)
{
    if(num == 1)
    {
        this->myside = true;
        socket = new QTcpSocket(this);
        socket->connectToHost(QHostAddress(sv->getHostIp()),8888);
        if(socket->waitForConnected(3000))
        {
            connected = true;
            ready[0] = ready[1] = false;
            setbutton(0, 1, 1, 1);
            setlabel(1, 0);
            connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
        }
        else
        {
            socket = nullptr;
            QMessageBox::warning(this, tr("Failed!"), tr("\连接失败!"));
        }
    }
}

void MainWindow::readData()
{
    auto messages = QString(socket->readAll()).split(' ');
    bool finished = false;
    while(!finished)
    {
        if((messages[0] == "start")||(messages[0] == "prepared")
                ||(messages[0] == "sucinit")||(messages[0] == "sucsyn")){
            if(messages[0] == "start"){
                ready[!myside] = true;
                setlabel(1, 1);
                if(ready[myside] && (!myside)){
                    setlabel(0, 0);
                    QWidget::update();
                    started = true;
                    game(0);
                }
            } else if(messages[0] == "prepared"){
                ready[!myside] = true;
                if(!ready[myside])
                    setlabel(1, 1);
                else{
                    setlabel(0, 0);
                    started = true;
                    game(0);
                }
            } else if(messages[0] == "sucinit"){
                ui->label_8->setText("本方：");
                ui->label_10->setText("对方：");
                casting();
            } else{
                if(!stat){
                    stat = !stat;
                    checkendgame();
                } else reprint(false, 0, 0);
            }
            if(!messages[1].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 1; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "toinit"){
            setlabel(0, 0);
            ui->label_8->setText("对方：");
            ui->label_10->setText("本方：");
            game(messages[1].toInt());
            if(!messages[2].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 2; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "init"){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 5; j++){
                    syninit(sides[0], sides[1], i,
                            messages[1 + 5 * i].toInt(), messages[2 + 5 * i].toInt(),
                            messages[3 + 5 * i].toInt(), messages[4 + 5 * i].toInt(),
                            messages[5 + 5 * i].toInt());
                }
            }
            reprint(false, 0, 0);
            socket->write("sucsyn ");
            if(stat){
                stat = !stat;
                checkendgame();
            }
            if(!messages[51].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 51; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "time"){
            ui->lcdNumber->setProperty("value", QVariant(messages[1].toInt()));
            QWidget::repaint();
            if(!messages[2].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 2; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "overtime"){
            step++;
            ui->lcdNumber->setProperty("value", QVariant(0));
            QWidget::repaint();
            overtime[!myside]++;
            clicked_order = 0;
            operated = true;
            checkendgame();
            if(!messages[1].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 1; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "disconnect"){
            shutted = true;
            if(connected){
                QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都逃走了！"),QMessageBox::Yes,this);
                if(waiting->exec() == QMessageBox::Yes)
                    waiting->close();
            }
            connected = false;
            if(!myside){
                disconnect(socket, SIGNAL(readyRead), this, SLOT(readData));
                socket->write("checkdis ");
                socket->waitForBytesWritten();
                socket->close();
                server->close();
                delete server;
            } else socket->write("disconnect ");
            setbutton(1, 0, 0, 0);
            setlabel(0, 0);
                finished = true;
        } else if(messages[0] == "checkdis"){
            socket->write("yesdis ");
            disconnect(socket, SIGNAL(readyRead), this, SLOT(readData));
            finished = true;
        } else if(messages[0] == "yesdis"){
            finished = true;
        }
        else if((messages[0] == "win")||(messages[0] == "lose")
                ||(messages[0] == "surrender")||(messages[0] == "quit")){
            operated = true;
            started = false;
            ready[0] = false;
            ready[1] = false;
            setbutton(2, 2, 1, 0);
            if(messages[0] == "win")
                losing();
            else if(messages[0] == "lose")
                wn();
            else if(messages[0] == "surrender"){
                if(!game_ended){
                    game_ended = true;
                    socket->write("win ");
                    QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都投降了！"),QMessageBox::Yes,this);
                    waiting->setStyleSheet("QLabel{""font: 18px""}");
                    if(waiting->exec() == QMessageBox::Yes)
                    {
                        waiting->close();
                    }
                }
                ui->actionStart->setEnabled(true);
            } else{
                QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都逃走了！"),QMessageBox::Yes,this);
                if(waiting->exec() == QMessageBox::Yes)
                {
                    waiting->close();
                }
            }
            if(!messages[1].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 1; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "move"){
            judge(messages[1].toInt(), messages[2].toInt(),
                    messages[3].toInt(), messages[4].toInt());
            ui->lcdNumber->setProperty("value", QVariant(20));
            clicked_order = 0;
            otherstep[0] = messages[3].toInt();
            otherstep[1] = messages[4].toInt();
            operated = true;
            step++;
            reprint(true, messages[3].toInt(), messages[4].toInt());
            checkendgame();
            if(!messages[5].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 5; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
        else if(messages[0] == "roll"){
            unknownnum--;
            ui->lcdNumber->setProperty("value", QVariant(20));
            int x = messages[1].toInt();
            int y = messages[2].toInt();
            otherstep[0] = x;
            otherstep[1] = y;
            pos_to_chess[x][y]->known = true;
            if(!setted){
                if(player_color[stat] < 0)
                    player_color[stat] = pos_to_chess[x][y]->side->color;
                else {
                    if(player_color[stat] == pos_to_chess[x][y]->side->color){
                        setted = true;
                        player_color[!stat] = !(pos_to_chess[x][y]->side->color);
                    } else player_color[stat] = pos_to_chess[x][y]->side->color;
                }
                if(unknownnum == 0){
                    setted = true;
                    player_color[stat] = pos_to_chess[x][y]->side->color;
                    player_color[!stat] = !(pos_to_chess[x][y]->side->color);
                }
            }
            clicked_order = 0;
            operated = true;
            step++;
            reprint(true, x, y);
            checkendgame();
            if(!messages[3].isEmpty())
            {
                auto temp = messages;
                messages.clear();
                for(int i = 3; i < temp.length(); i++)
                    messages << temp[i];
            }
            else
                finished = true;
        }
    }
}
void MainWindow::setlabel(int i, int j){
    if(i != 2)
        ui->label_12->setVisible(i);
    if(j != 2)
        ui->label_13->setVisible(j);
}
void MainWindow::setbutton(int i, int k, int l, int m){
    if(i != 2)
        ui->actionCreate_the_connection_2->setEnabled(i);
    if(i != 2)
        ui->actionConnect_to_Server->setEnabled(i);
    if(k != 2)
        ui->actionDisconnect->setEnabled(k);
    if(l != 2)
        ui->actionStart->setEnabled(l);
    if(m != 2)
        ui->actionAdmit_defeat->setEnabled(m);
}
void MainWindow::reprint(bool highl, int x, int y){
    if(stat == myside)
        ui->label_4->setText("你的回合");
    else
        ui->label_4->setText("对手回合");
    if(highl){
        int act_x, act_y;
        act_x = y * 77 + 22;
        if(x < 6)
            act_y = x * 35 + 20;
        else
            act_y = x * 35 + 20 + 77;
        ui->label_6->setVisible(true);
        ui->label_6->setGeometry(QRect(act_x, act_y, 55, 30));
        ui->label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/highlight.png")));
    }
    else ui->label_6->setVisible(false);
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 5; j++){
            if(pos_to_chess[i][j] == nullptr)
                chess60[i][j]->clear();
            else{
                std::string sider;
                if(!pos_to_chess[i][j]->known){
                    chess60[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/notknown.png")));
                    continue;
                }
                if(pos_to_chess[i][j]->side->color)
                    sider = "r";
                else sider = "b";
                chess60[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/"+sider+pos_to_chess[i][j]->photo)));
            }
        }
    }
    ui->label_9->setText(QString::number(overtime[0]));
    ui->label_11->setText(QString::number(overtime[1]));
    QWidget::repaint();
}
void MainWindow::showcolor(){
    if(!setted){
        ui->label_5->setText("---");
        ui->label_5->setStyleSheet("QLabel{color:rgba(0,0,0,255);}");
    }
    else if(!player_color[stat]){
        ui->label_5->setText("Blue");
        ui->label_5->setStyleSheet("QLabel{color:rgba(0,0,255,255);}");
    }
    else {
        ui->label_5->setText("Red");
        ui->label_5->setStyleSheet("QLabel{color:rgba(255,0,0,255);}");
    }
}
void MainWindow::casting(){
    std::string str = "init ";
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                str += std::to_string((sides[k].sub[i * 5 + j]->pos[0]) * 5 + (sides[k].sub[i * 5 + j]->pos[1]));
                str += " ";
            }
        }
    }
    socket->write(str.c_str());
}
void MainWindow::wn(){
    setbutton(2, 2, 1, 0);
    setlabel(1, 0);
    if(!game_ended){
        game_ended = true;
        socket->write("win  ");
        QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("You win!"), tr("\大佬太强了！"),QMessageBox::Yes,this);
        waiting->setStyleSheet("QLabel{""font: 18px""}");
        if(waiting->exec() == QMessageBox::Yes)
            waiting->close();
    }
}
void MainWindow::losing(){
    setbutton(2, 2, 1, 0);
    setlabel(1, 0);
    if(!game_ended){
        game_ended = true;
        socket->write("lose  ");
        QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("You have lost!"), tr("\大佬总是让对方一局！"),QMessageBox::Yes,this);
        waiting->setStyleSheet("QLabel{""font: 18px""}");
        if(waiting->exec() == QMessageBox::Yes)
            waiting->close();
    }
}
void MainWindow::endgame(){
    operated = true;
    ready[0] = false;
    ready[1] = false;
    setbutton(2, 2, 1, 0);
    if(!sides[player_color[myside]].flagLive){
        ui->label_4->setText("你的回合");
        losing();
    }
    else{
        if(overtime[myside] == 3)
            losing();
        else
            wn();
    }
    started = false;
}
void MainWindow::surrender(){
    if((step > 19)){
        operated = true;
        ready[0] = false;
        ready[1] = false;
        setbutton(2, 2, 1, 0);
        setlabel(1, 0);
        socket->write("surrender ");
        losing();
    } else {
        Error_surrender *e = new Error_surrender();
        e->setWindowTitle("You can not surrender!");
        e->show();
    }
}
void MainWindow::timestarted(){
    overtimed = false;
    operated = false;
    int timeleft = 19;
    std::string str = "time " + std::to_string(20) + "  ";
    ui->lcdNumber->setProperty("value", QVariant(20));
    for(;timeleft >= 0; timeleft--){
        for(int i = 0; i < 10; i++){
            QEventLoop eventloop;
            QTimer::singleShot(100, &eventloop, SLOT(quit()));
            eventloop.exec();
            if(!socket->atEnd()){
                auto messages = QString(socket->readAll()).split(' ');
                bool finished = false;
                if((messages[0] == "win")||(messages[0] == "lose")
                    ||(messages[0] == "surrender")||(messages[0] == "quit")
                        ||(messages[0] == "disconnect")){
                    if(messages[0] == "disconnect"){
                        shutted = true;
                        if(connected){
                            QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都逃走了！"),QMessageBox::Yes,this);
                            if(waiting->exec() == QMessageBox::Yes)
                                waiting->close();
                        }
                        connected = false;
                        setbutton(1, 0, 0, 0);
                        setlabel(0, 0);
                        socket->write("disconnect ");
                        return;
                    }
                    operated = true;
                    started = false;
                    ready[0] = false;
                    ready[1] = false;
                    setbutton(2, 2, 0, 0);
                    if(messages[0] == "win")
                        losing();
                    else if(messages[0] == "lose")
                        wn();
                    else if(messages[0] == "surrender"){
                        if(!game_ended){
                            game_ended = true;
                            socket->write("win ");
                            QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都投降了！"),QMessageBox::Yes,this);
                            waiting->setStyleSheet("QLabel{""font: 18px""}");
                            if(waiting->exec() == QMessageBox::Yes)
                                waiting->close();
                        }
                        ui->actionStart->setEnabled(true);
                        ui->label_12->setVisible(true);
                    } else{
                        QMessageBox *waiting = new QMessageBox(QMessageBox::NoIcon, tr("Enemy escaped!"), tr("\大佬太强了,别人都逃走了！"),QMessageBox::Yes,this);
                        if(waiting->exec() == QMessageBox::Yes)
                            waiting->close();
                    }
                    if(!messages[1].isEmpty())
                        messages.clear();
                }
            }
            if(shutted)
                return;
            if(operated)
                return;
        }
        str = "time " + std::to_string(timeleft) + " ";
        ui->lcdNumber->setProperty("value", QVariant(timeleft));
        if(timeleft > 0)
            socket->write(str.c_str());
        else
            socket->write("overtime ");
        QWidget::repaint();
    }
    overtimed = true;
    step++;
    if(overtimed && (myside == stat)){
        overtime[stat]++;
    }
    overtimed = false;
    stat = !(stat);
    reprint(false, 0, 0);
    showcolor();
    for(int i = 0; i < 2; i++){
        if(overtime[i] == 3){
            if(i == myside)
                socket->write("lose ");
            else socket->write("win ");
            endgame();
            return;
        }
    }
}
void MainWindow::game(int sta){
        shutted = false;
        unknownnum = 50;
        game_ended = false;
        step = 0;
        for(int i = 0 ; i < 2; i++){
            sides[i].initializeSide(i);
            player_color[i] = -1;
            overtime[i] = 0;
        }
        clickked = false;
        clicked_order = 0;
        setted = false;
        overtimed = false;
        if(!myside){
            setIntPos(sides[0], sides[1]);
            reprint(false, 0, 0);
            srand((unsigned)time(NULL));
            stat = (rand() % 2 == 0);
            std::string str = "toinit ";
            str += std::to_string((int)stat);
            str += " ";
            socket->write(str.c_str());
        } else{
            stat = sta;
            started = true;
            socket->write("sucinit ");
        }
        if(started)
            setbutton(0, 1, 0, 1);
}
void MainWindow::checkfirstclicked(){
    int x = 0;
    int y = 0;
    y = (first_x - 22) / 77;
    if(first_y < 247)
        x = (first_y - 45) / 35;
    else
        x = (first_y - 45 - 77) / 35;
    if(!setted){
        if((pos_to_chess[x][y] != nullptr)&&(pos_to_chess[x][y]->known == false)){
            pos_to_chess[x][y]->known = true;
            unknownnum--;
            if(player_color[stat] < 0)
                player_color[stat] = pos_to_chess[x][y]->side->color;
            else {
                if(player_color[stat] == pos_to_chess[x][y]->side->color){
                    setted = true;
                    player_color[!stat] = !(pos_to_chess[x][y]->side->color);
                } else player_color[stat] = pos_to_chess[x][y]->side->color;
            }
            if(unknownnum == 0){
                setted = true;
                player_color[stat] = pos_to_chess[x][y]->side->color;
                player_color[!stat] = !(pos_to_chess[x][y]->side->color);
            }
            stat = !stat;
            clicked_order = 0;
            operated = true;
            step++;
            showcolor();
            reprint(true, x, y);
            std::string str = "roll ";
            str += (std::to_string(x) + " " + std::to_string(y) + " ");
            socket->write(str.c_str());
            return;
        }
    }
    else if(check(x, y, player_color[stat])){
        if((pos_to_chess[x][y] != nullptr)&&(pos_to_chess[x][y]->known == false)){
            pos_to_chess[x][y]->known = true;
            unknownnum--;
            clicked_order = 0;
            operated = true;
            step++;
            stat = !stat;
            showcolor();
            reprint(true, x, y);
            std::string str = "roll ";
            str += (std::to_string(x) + " " + std::to_string(y) + " ");
            socket->write(str.c_str());
            return;
        }
           clicked_order = 2;
           reprint(true, x, y);
           clickked = false;
    }
}
void MainWindow::checksecondclicked(){
    int x = 0;
    int y = 0;
    y = (first_x - 22) / 77;
    if(first_y < 247)
        x = (first_y - 45) / 35;
    else
        x = (first_y - 45 - 77) / 35;
    int x2 = 0;
    int y2 = 0;
    y2 = (second_x - 22) / 77;
    if(second_y < 247){
        x2 = (second_y - 45) / 35;
    } else{
        x2 = (second_y - 45 - 77) / 35;
    }
    if((pos_to_chess[x][y] != nullptr)
            &&pos_to_chess[x][y]->canGet(x2,y2)){
        judge(x, y, x2, y2);
        clicked_order = 0;
        operated = true;
        stat = !stat;
        step++;
        showcolor();
        reprint(true, x2, y2);
        std::string str = "move ";
        str += (std::to_string(x) + " " + std::to_string(y)
                + " " + std::to_string(x2) + " " + std::to_string(y2) + " ");
        socket->write(str.c_str());
    } else{
        reprint(false, 0, 0);
        clicked_order = 1;
    }
}
void MainWindow::checkendgame(){
    operated = true;
    stat = !(stat);
    showcolor();
    if(setted){
        if (unknownnum == 0){
            if(!check_walkable(sides[player_color[stat]])){
                sides[player_color[stat]].flagLive = false;
                if(stat == myside)
                    socket->write("lose ");
                endgame();
                return;
            }
        }
        if(!sides[player_color[stat]].flagLive){
                socket->write("lose ");
            endgame();
            return;
        }
    }
    if(step != 0)
        reprint(true, otherstep[0], otherstep[1]);
    for(int i = 0; i < 2; i++){
        if(overtime[i] == 3){
            if(setted)
                sides[player_color[i]].flagLive = false;
            endgame();
            return;
        }
    }
    clicked_order = 1;
    timestarted();
}

void MainWindow::on_actionDisconnect_triggered()
{
    shutted = true;
    if(connected){
        connected = false;
        socket->write("disconnect ");
        setbutton(1, 0, 0, 0);
        setlabel(0, 0);
    }
}


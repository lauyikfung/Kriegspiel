#ifndef CHESSES_H
#define CHESSES_H
#include <ctime>
#include <cstdlib>
#include <string>
class Side;
class Chess{
public:
    int value;
    bool live;
    Side* side;
    bool known;
    std::string photo;
    int pos[2];
    Chess(int val = 0, bool liv = false): value(val), live(liv){
        switch(val){
        case 10: setPhoto("siling.png"); break;
        case 9: setPhoto("jun.png"); break;
        case 8: setPhoto("shi.png"); break;
        case 7: setPhoto("lv.png"); break;
        case 6: setPhoto("tuan.png"); break;
        case 5: setPhoto("ying.png"); break;
        case 4: setPhoto("lian.png"); break;
        case 3: setPhoto("pai.png"); break;
        case 2: setPhoto("gongbing.png"); break;
        case 1: setPhoto("dilei.png"); break;
        case 0: setPhoto("zha.png"); break;
        case -1: setPhoto("junqi.png"); break;
        }
    }
    void setPos(int i){
        this->pos[0] = i / 5;
        this->pos[1] = i % 5;
    }
    void setPhoto(std::string str){
        this->photo = str;
    }
    bool walkable();
    bool canGet(int x, int y);
};
extern Chess* pos_to_chess[12][5];
class Side{
public:
    bool flagLive = true;
    int dileinum = 3;
    bool color;
    Chess* sub[25];
    Side(){
        this->sub[0] = new Chess(10);
        this->sub[1] = new Chess(9);
        this->sub[2] = new Chess(-1);
        for(int i = 0; i < 2; i++){
            this->sub[3 + i * 5] = new Chess(8);
            this->sub[4 + i * 5] = new Chess(7);
            this->sub[5 + i * 5] = new Chess(6);
            this->sub[6 + i * 5] = new Chess(5);
            this->sub[7 + i * 5] = new Chess(0);
        }
        for(int i = 0; i < 3; i++){
            this->sub[13 + i * 4] = new Chess(4);
            this->sub[14 + i * 4] = new Chess(3);
            this->sub[15 + i * 4] = new Chess(2);
            this->sub[16 + i * 4] = new Chess(1);
        }
    }
    void initializeSide(bool col);
};
void setbase();
void setIntPos(Side sid1, Side sid2);
void judge(int x, int y, int x_other, int y_other);
bool check(int x, int y, bool stat);
bool check_walkable(Side sides);
void syninit(Side sid1, Side sid2, int ord, int num0, int num1, int num2, int num3, int num4);
#endif // CHESSES_H

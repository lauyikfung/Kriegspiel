#include "chesses.h"
bool xingying[12][5] = {0};
bool rail[12][5] = {0};
bool searched[12][5] = {0};
bool success_search;
bool railway[12][5][4] = {0};
const int rect[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
const int dia[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
bool Chess::walkable(){
    if((this->value == -1)||(this->value == 1))
        return false;
    else {
        int x = this->pos[0];
        int y = this->pos[1];
        int x1, y1;
        int special = -1;
        if((y == 1)&&(x > 4)&&(x < 7)){
            special = (x == 5) ? 0 : 1;
        }
        if((y == 3)&&(x > 4)&&(x < 7)){
            special = (x == 5) ? 0 : 1;
        }
        for(int i = 0; i < 4; i++){//上下左右搜索
            if(i == special)
                continue;
            x1 = x + rect[i][0];
            y1 = y + rect[i][1];
            if((x1<0)||(y1<0)||(x1>11)||(y1>4))
                continue;
            if(pos_to_chess[x1][y1] == nullptr){
                return true;
            }
            if(!(pos_to_chess[x1][y1]->known))
                continue;
            if(xingying[x1][y1])
                continue;
            if(pos_to_chess[x1][y1]->side != this->side){
                if((pos_to_chess[x1][y1]->value != 1)&&(pos_to_chess[x1][y1]->value != -1))
                    return true;
                else if(pos_to_chess[x1][y1]->value == 1){
                    if((this->value == 2)||(this->value == 0))
                        return true;
                }
                else if(pos_to_chess[x1][y1]->side->dileinum == 0)
                    return true;
            }
        }
        for(int i = 0; i < 4; i++){//四个对角方向搜索
            x1 = x + dia[i][0];
            y1 = y + dia[i][1];
            if((x1<0)||(y1<0)||(x1>11)||(y1>4))
                continue;
            if((!xingying[x1][y1]) && (!xingying[x][y]))
                continue;
            else if (xingying[x1][y1]){
                if(pos_to_chess[x1][y1] == nullptr)
                    return true;
            } else{
                if(!(pos_to_chess[x1][y1]->known))
                    continue;
                if(pos_to_chess[x1][y1] == nullptr){
                    return true;
                }
                if(pos_to_chess[x1][y1]->side != this->side){
                    if((pos_to_chess[x1][y1]->value != 1)&&(pos_to_chess[x1][y1]->value != -1))
                        return true;
                    else if(pos_to_chess[x1][y1]->value == 1){
                        if((this->value == 2)||(this->value == 0))
                            return true;
                    }
                    else if(pos_to_chess[x1][y1]->side->dileinum == 0)
                        return true;
                }
            }
        }
        return false;
    }
}
void searching(int x, int y, int x2, int y2){//DFS
    for(int i = 0; i < 4; i++){
        if(railway[x][y][i]){
            int x1 = x + rect[i][0];
            int y1 = y + rect[i][1];
            if(searched[x1][y1])
                continue;
            if((x1 == x2) && (y1 == y2))
            {
                success_search = true;
                searched[x1][y1] = true;
                return;
            }
            else if(pos_to_chess[x1][y1] != nullptr)
                continue;
            else {
                searched[x1][y1] = true;
                searching(x1, y1, x2, y2);
            }
        }
    }
}
bool search(int x, int y, int x2, int y2){//DFS
    if((pos_to_chess[x2][y2] != nullptr)&&
            (pos_to_chess[x2][y2]->side == pos_to_chess[x][y]->side))
        return false;
    if((pos_to_chess[x2][y2] != nullptr)&&
            (pos_to_chess[x2][y2]->known == false))
        return false;
    if((pos_to_chess[x2][y2] != nullptr)&&
            (pos_to_chess[x2][y2]->value == -1)&&
            (pos_to_chess[x2][y2]->side->dileinum != 0))
        return false;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 5; j++)
            searched[i][j] = false;
    }
    success_search = false;
    searching(x, y, x2, y2);
    return success_search;
}
bool Chess::canGet(int x2, int y2){
    int x = this->pos[0];
    int y = this->pos[1];
    if((x == x2) && (y == y2))
        return false;
    if(pos_to_chess[x2][y2] != nullptr){
        if((pos_to_chess[x2][y2]->side == this->side)||(!pos_to_chess[x2][y2]->known))
            return false;
    }
    if((!rail[pos[0]][pos[1]]) || (!rail[x2][y2])){//一个端点不是铁路，只能沿8个方向走
        int x1, y1;
        for(int i = 0; i < 4; i++){//上下左右
            x1 = x + rect[i][0];
            y1 = y + rect[i][1];
            if((x1 == x2)&&(y1 == y2)){
                if(pos_to_chess[x1][y1] == nullptr)
                    return true;
                if(xingying[x1][y1])
                    return false;
                if((pos_to_chess[x1][y1]->value != 1)&&(pos_to_chess[x1][y1]->value != -1))
                    return true;
                else if(pos_to_chess[x1][y1]->value == 1){
                    if((this->value == 2)||(this->value == 0))
                        return true;
                }
                else if(pos_to_chess[x1][y1]->side->dileinum == 0)
                    return true;
                return false;
            }
        }
        for(int i = 0; i < 4; i++){//4个对角方向
            x1 = x + dia[i][0];
            y1 = y + dia[i][1];
            if((x1 == x2)&&(y1 == y2)){
                if((!xingying[x1][y1]) && (!xingying[x][y]))
                    return false;
                else if (xingying[x1][y1]){
                    if(pos_to_chess[x1][y1] == nullptr)
                        return true;
                    else return false;
                } else{
                    if(pos_to_chess[x1][y1] == nullptr)
                        return true;
                    if((pos_to_chess[x1][y1]->value != 1)&&(pos_to_chess[x1][y1]->value != -1))
                        return true;
                    else if(pos_to_chess[x1][y1]->value == 1){
                        if((this->value == 2)||(this->value == 0))
                            return true;
                    }
                    else if(pos_to_chess[x1][y1]->side->dileinum == 0)
                        return true;
                }
            }
        }
      return false;
    } else{//均在铁路上
        if(this->value != 2){//非工兵
            if(x == x2){//在一条横线上
                if((x != 1)&&(x != 5)&&(x != 6)&&(x != 10))
                    return false;
              for(int y1 = y; y1 != y2; y1 += (y > y2) ? (-1) : 1){
                  if(y1 == y)
                      continue;
                  if(pos_to_chess[x][y1] != nullptr){
                      return false;
                  }
              }
              if(pos_to_chess[x2][y2] == nullptr)
                  return true;
              if((pos_to_chess[x2][y2]->value != 1)&&(pos_to_chess[x2][y2]->value != -1))
                  return true;
              else if(pos_to_chess[x2][y2]->value == 1){
                  if(this->value == 0)
                      return true;
              }
              else if(pos_to_chess[x2][y2]->side->dileinum == 0)
                  return true;
              else return false;
            } else if(y == y2){//在一条竖线上
                if((y == 1) || (y == 3))
                    return false;
                if(y == 2){
                    if(((x == 5) && (x2 == 6)) || ((x == 6)&&(x2 == 5))){
                        if(pos_to_chess[x2][y2] == nullptr)
                            return true;
                        if((pos_to_chess[x2][y2]->value != 1)&&(pos_to_chess[x2][y2]->value != -1))
                            return true;
                        else if(pos_to_chess[x2][y2]->value == 1){
                            if(this->value == 0)
                                return true;
                        }
                        else if(pos_to_chess[x2][y2]->side->dileinum == 0)
                            return true;
                    }
                    return false;
                }
                for(int x1 = x; x1 != x2; x1 += (x > x2) ? (-1) : 1){
                    if(x1 == x)
                        continue;
                    if(pos_to_chess[x1][y] != nullptr){
                        return false;
                    }
                }
                if(pos_to_chess[x2][y2] == nullptr)
                    return true;
                if((pos_to_chess[x2][y2]->value != 1)&&(pos_to_chess[x2][y2]->value != -1))
                    return true;
                else if(pos_to_chess[x2][y2]->value == 1){
                    if(this->value == 0)
                        return true;
                }
                else if(pos_to_chess[x2][y2]->side->dileinum == 0)
                    return true;
            }
            return false;
        }
        else{//工兵
            if(!search(x, y, x2, y2))
                return false;
            return true;
        }
    }
}
void Side::initializeSide(bool col){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 5; j++)
            pos_to_chess[i][j] = nullptr;
    }
    this->color = col;
    flagLive = true;
    dileinum = 3;
    for(int i = 0; i < 25; i++){
        sub[i]->live = true;
        sub[i]->side = this;
        sub[i]->known = false;
    }
}
void syninit(Side sid1, Side sid2, int ord, int num0, int num1, int num2, int num3, int num4)
{
    if(ord < 5){
        sid1.sub[0 + ord * 5]->setPos(num0);
        pos_to_chess[num0 / 5][num0 % 5] = sid1.sub[0 + ord * 5];
        sid1.sub[1 + ord * 5]->setPos(num1);
        pos_to_chess[num1 / 5][num1 % 5] = sid1.sub[1 + ord * 5];
        sid1.sub[2 + ord * 5]->setPos(num2);
        pos_to_chess[num2 / 5][num2 % 5] = sid1.sub[2 + ord * 5];
        sid1.sub[3 + ord * 5]->setPos(num3);
        pos_to_chess[num3 / 5][num3 % 5] = sid1.sub[3 + ord * 5];
        sid1.sub[4 + ord * 5]->setPos(num4);
        pos_to_chess[num4 / 5][num4 % 5] = sid1.sub[4 + ord * 5];
    }
    else{
        ord -= 5;
        sid2.sub[0 + ord * 5]->setPos(num0);
        pos_to_chess[num0 / 5][num0 % 5] = sid2.sub[0 + ord * 5];
        sid2.sub[1 + ord * 5]->setPos(num1);
        pos_to_chess[num1 / 5][num1 % 5] = sid2.sub[1 + ord * 5];
        sid2.sub[2 + ord * 5]->setPos(num2);
        pos_to_chess[num2 / 5][num2 % 5] = sid2.sub[2 + ord * 5];
        sid2.sub[3 + ord * 5]->setPos(num3);
        pos_to_chess[num3 / 5][num3 % 5] = sid2.sub[3 + ord * 5];
        sid2.sub[4 + ord * 5]->setPos(num4);
        pos_to_chess[num4 / 5][num4 % 5] = sid2.sub[4 + ord * 5];
    }
}
void setbase(){
    xingying[2][1] = true;
    xingying[2][3] = true;
    xingying[3][2] = true;
    xingying[4][1] = true;
    xingying[4][3] = true;
    xingying[7][1] = true;
    xingying[7][3] = true;
    xingying[8][2] = true;
    xingying[9][1] = true;
    xingying[9][3] = true;
    for(int i = 1; i < 10; i++){
        railway[i][0][0] = true;
        railway[i][4][0] = true;
    }
    railway[5][2][0] = true;
    for(int i = 2; i < 11; i++){
        railway[i][0][1] = true;
        railway[i][4][1] = true;
    }
    railway[6][2][1] = true;
    for(int i = 0; i < 4; i++){
        railway[1][i][2] = true;
        railway[5][i][2] = true;
        railway[6][i][2] = true;
        railway[10][i][2] = true;
        railway[1][i + 1][3] = true;
        railway[5][i + 1][3] = true;
        railway[6][i + 1][3] = true;
        railway[10][i + 1][3] = true;
    }
    for(int i = 1; i < 11; i++){
        rail[i][0] = true;
        rail[i][4] = true;
    }
    for(int i = 1; i < 4 ; i++){
        rail[1][i] = true;
        rail[5][i] = true;
        rail[6][i] = true;
        rail[10][i] = true;
    }
}
void setIntPos(Side sid1, Side sid2){
    int allpos[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                      10, 12, 14, 15, 16, 18, 19, 20,
                      22, 24, 25, 26, 27, 28, 29, 30,
                      31, 32, 33, 34, 35, 37, 39, 40,
                      41, 43, 44, 45, 47, 49, 50, 51,
                      52, 53, 54, 55, 56, 57, 58, 59};
    int order[50];
    for (int i = 0; i < 60; i++){
        pos_to_chess[i / 5][i % 5] = nullptr;
    }
    for (int i = 0; i < 50; i++)
            order[i] = i;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 50; i++)
    {
        int j = rand() % (50 - i) + i;
        int k = order[i];
        order[i] = order[j];
        order[j] = k;
    }
    for(int i = 0; i < 25; i++){
        sid1.sub[i]->setPos(allpos[order[i]]);
        pos_to_chess[allpos[order[i]] / 5][allpos[order[i]] % 5] = sid1.sub[i];
    }
    for(int i = 0; i < 25; i++){
        sid2.sub[i]->setPos(allpos[order[i + 25]]);
        pos_to_chess[allpos[order[i + 25]] / 5][allpos[order[i + 25]] % 5] = sid2.sub[i];
    }
}
void judge(int x, int y, int x_other, int y_other){
    Chess* sub = pos_to_chess[x][y];
    Chess* obj = pos_to_chess[x_other][y_other];
    pos_to_chess[x][y]->pos[0] = x_other;
    pos_to_chess[x][y]->pos[1] = y_other;
    if(obj != nullptr){
        if(obj->value == -1){
            if(obj->side->dileinum == 0){
            obj->live = 0;
            obj->side->flagLive = 0;
            }
        }
        else if((sub->value == 2)&&(obj->value == 1)){
            obj->live = 0;
            obj->side->dileinum--;
        }
        else if((sub->value == 0)&&(obj->value == 1)){
            sub->live = 0;
            obj->live = 0;
            obj->side->dileinum--;
        }
        else if((sub->value == 0)||(obj->value == 0)){
            sub->live = 0;
            obj->live = 0;
        }
        else{
            if(sub->value >= obj->value)
                obj->live = 0;
            if(sub->value <= obj->value)
                sub->live = 0;
        }
    }
    if(sub->live != 0){
        pos_to_chess[x_other][y_other] = sub;
    } else if((obj != nullptr)&&(obj->live == 0))
        pos_to_chess[x_other][y_other] = nullptr;
    pos_to_chess[x][y] = nullptr;
}
bool check(int x, int y, bool stat){
    if(pos_to_chess[x][y] == nullptr)
        return false;
    if(pos_to_chess[x][y]->known == false)
        return true;
    if(pos_to_chess[x][y]->side == nullptr)
        return false;
    if(pos_to_chess[x][y]->side->color != stat)
        return false;
    if(pos_to_chess[x][y]->walkable())
        return true;
    else return false;
}
bool check_walkable(Side sides){
    bool walkablity = false;
    for(int i = 0; i < 25; i++){
        walkablity = walkablity || (sides.sub[i]->live && sides.sub[i]->walkable());
    }
    return walkablity;
}

#include <iostream>

using namespace std;

/*rule:五條連成一線 及勝利
       在結束前未完成 則計算三條線的誰最多
       若連成四個 則消除那行旗子
*/

void showCheckerboard();
int playChess();
int checkFull();
int endCheckRule();
int checkRule(int );

void clearRow(int);
void clearLn(int);
void clearRToL();
void clearLToR();

/*const char white = 'O';  //白旗
const char black = 'A';  //黑旗*/
char checkerboard[5][5] = { {'*','*','*','*','*'},
                            {'*','*','*','*','*'},
                            {'*','*','*','*','*'},
                            {'*','*','*','*','*'}, 
                            {'*','*','*','*','*'} };  // 初始化棋盤
int main() 
{
   
    while (1)
    {   
        showCheckerboard();
        int y=playChess();
        int now=checkRule(y);
        if (now != 0) {
            cout << "winner is " << (char)now <<endl;
            break;
        }
        int i=checkFull();
        if (i == 1) {
            endCheckRule();
            break;
        }
    }
    cout << "game End" << endl;
    showCheckerboard();
    return 0;

} 

/*下棋*/
int playChess() {
    int x, y;
    char z;
    printf("選擇位置 y: || x: || O or A:\n");
    scanf_s("%d %d %c", &x, &y, &z);
    checkerboard[x][y] = z;
    return 5*y+x;  //下的位置
}

/*只要確定是否連成五個或是四個*/
int checkRule(int one) {
    char countx[5];
    char county[5];
    char countOblique1[5] = { checkerboard[0][0],
                              checkerboard[1][1],
                              checkerboard[2][2],
                              checkerboard[3][3],
                              checkerboard[4][4]}; //斜的 左上到右下
    char countOblique2[5]= {  checkerboard[4][0],
                              checkerboard[3][1],
                              checkerboard[2][2],
                              checkerboard[1][3],
                              checkerboard[0][4]}; //斜的右下到左上
    int x, y;

    x = one % 5;   // 5 y=1 x=0
    y = one / 5;
    char now = checkerboard[x][y];  //這手棋是黑是白

    for (int i = 0; i < 5; i++) {
        countx[i] = checkerboard[i][y];  //直
        county[i] = checkerboard[x][i];  //橫
    }
    
    if (countx[1] == now &&countx[2] == now && countx[3] == now ) {
        
        if (countx[4] == now && countx[0]==now) {
            return (int)now;
        }else if(countx[4] == now || countx[0] == now){
            clearRow(y);
        } 
    }
    if (county[1] == now&& county[2] == now && county[3] == now) {
        
        if (county[4] == now && county[0]== now) {
            return (int)now;
        }else if (county[4] == now || county[0]== now) {
            clearLn(x);
        }
    }
    if (countOblique1[1] == now&& countOblique1[2] == now && countOblique1[3] == now) {
        
        if (countOblique1[4] == now&&countOblique1[0] == now) {
           return (int)now;
        }
        else if(countOblique1[4] == now || countOblique1[0] == now) {
           clearLToR();
        }  
    }
    if (countOblique2[1] == now&& countOblique2[2] == now && countOblique2[3] == now) { 
        if (countOblique2[4] == now&&countOblique2[0] == now ) {
           return (int)now;
        }
        else if(countOblique2[4] == now || countOblique2[0] == now){
           clearRToL();
        }
    }
    return 0;
}

/*在沒有五個的情況下 且棋盤全滿 計算三個的 四個前面已經篩掉*/
int endCheckRule() {
    return 0;
}

void clearRow(int y) {   //clear橫的
    for (int i = 0; i < 5; i++) {
        checkerboard[i][y] = '*';
    }
}
void clearLn(int x) {   //clear直的
    for (int i = 0; i < 5; i++) {
        checkerboard[x][i] = '*';
    }
}
void clearLToR() {   //clear左到右
    for (int i = 0; i < 5; i++) {
        checkerboard[i][i] = '*';
    }
}
void clearRToL() {   //clear右到左
    for (int i = 0,a=4; i < 5; i++,a--) {
        checkerboard[a][i] = '*';
    }
}

void showCheckerboard() {
    for (int i = 0; i < 5; i++)
    {
        for (auto& c : checkerboard[i])
        {
            printf("\t%c", c);
        }
        printf("\n\n");
    }

}
int checkFull() {
    for (int i = 0; i < 5; i++)
    {
        for (auto& c : checkerboard[i])
        {
            if (c=='*'){
                return 0; //not full
            }
        }
    }
    return 1; //full 
}

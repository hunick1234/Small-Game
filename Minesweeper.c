#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int  map(int );
int  boom_map(int );
int  make_boom(int );
int  ChooseInput();
int  Comparison();
//void windowMax();
int  countboom(int );
void BigBoom();

int xmap;
int ymap;

int chooseInx;
int chooseIny;

int firthtMap[8][8];

char BoomMap[64];
int MapYouSee[64] = {9};


int main() 
{ 
    char c[2] = { '*','*' };
    c[0] = 1;
    printf("%d...", c[0]);
    printf("%c...", c[1]);

    /*
    for (int a = 0; a < 8; a++)
    {
        for (int q = 0; q < 8; q++)
        {
            while (a == 0 && q == 0)
            {
                for (int q = 0; q < 8; q++)
                {
                    printf("\t%d ", q);
                }
                printf("\n\n");
                break;
            }
            printf("\t*");
        }     
        printf("  %d", a);
        printf("\n");
    }
    */
   
    make_boom(8);
    for (int y = 0; y < 8; y++)
    {
        for (int x=0; x<8 ;x++)
        {
            int xy = 8 * y + x;
            //printf("%d",xy );        
            printf("%c", BoomMap[xy]);    
        }
        printf("\n");
    }

    Comparison();
    
    

}

int map(int choose)    //顯示地圖 
{   
    
    MapYouSee[choose] = countboom(choose); 
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            int xy = 8 * y + x;        
            printf(" %d", MapYouSee[xy]);
            //printf(" %d", MapYouSee[xy]);
        }
        printf("\n\n");
    }
    return 0;
}

int boom_map(int boomIn)  //炸彈地圖 
{
   // char BoomMap[64];
    BoomMap[boomIn] = 'B';
    return 0;
}

int make_boom(int max)   //亂數生炸彈
{
    srand(time(0));
    int i = 0;
   // int boom;
    while ( i < 3*max)  
    {       
      int boom = rand() % 64+1;
        boom_map(boom);       
        i++;        
    }

    return 0;
}

int ChooseInput()   //選擇位址
{
    printf("選擇位址\n");
    printf("x:");
    scanf_s("%d", &chooseInx );
    printf("y:");
    scanf_s("%d", &chooseIny );
    int sum = 8*chooseIny + chooseInx ;  //轉一維
    return sum;
}

int Comparison()   //選取位址與炸彈位址比較
{ 
    while (1)
    {              
       int now = ChooseInput(); // 選擇的位址(一維陣列)       
       switch (BoomMap[now] != 'B')
       {
       case 0:
          
           BigBoom();
           printf("boom");
           break;

       case 1:           
          // printf("%d",countboom(now));
           map(now);
           Comparison();
           break;      
       }
       break;
    }
   // printf("you find");
    return 0;
}

int countboom(int now)   //計算四面八方的炸彈
{
    int boomcounter = 0; //轉二為計算時會有點問題

    while (BoomMap[now + 1] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };    
    while ( BoomMap[now - 1] == 'B')  {
        boomcounter = boomcounter + 1;
        break;
    };
    while (BoomMap[now - 9] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };
    while (BoomMap[now - 8] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };
    while (BoomMap[now - 7] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };   
    while (BoomMap[now + 9] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };
    while (BoomMap[now + 8] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    };
    while (BoomMap[now + 7] == 'B') {
        boomcounter = boomcounter + 1;
        break;
    }; 
    return boomcounter;
} //

/*void windowMax()   //遊戲地圖大小
{
}
*/

void BigBoom()
{
    printf("           _._  _, _._        \n"  );
    printf("       (_ ' ( `  )_  .__)    \n"  );
    printf("     ( (  (    )   `)  ) _)  \n"  );
    printf("    (__ (_   (_ . _) _) ,__) \n"  );
    printf("         `~~`\\ ' . /`~~`    \n"  );
    printf("              ;   ;          \n"  );
    printf("              /   \\         \n"  );
    printf("_____________/_ __ \\_____________");
}

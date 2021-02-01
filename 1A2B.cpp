#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

 struct test
{
	int number[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int weighted[10] = { 0 };
} No[5];

void YourMath();
void guessMath();

void PCMath();
void pcGuessMath();

int check();
int pcCheck();

int guessRobot(int, int);

int win = 0;

int HowMore; //要玩幾個數字

int* YourNumber;
int* GuessNumber;

int* PCNumber;
int* pcGuessNumber;
int dd;
int tt = 0;
int main()
{ 
	printf("要玩幾個數字\n");
	scanf_s("%d", &HowMore);

	PCMath();    
	YourMath();  //你輸入的
	
	while (win==0)
	{
		if (check() == 1)
		{		
			return 0;
		}
		if (pcCheck() == 1)
		{		
			return 0;
		}
		++dd;
		printf("%d", dd);
		Sleep(100);
	}
	return 0;
}
void PCMath()
{
	srand(time(NULL));
	int a[] = { 1,2,3,4,5,6,7,8,0,9 };
	PCNumber = (int*)malloc(HowMore * sizeof(int));
	for (int i = 0; i < HowMore; i++)
	{		
	    retry:  int x = rand() % 10;
		
		if (a[x] != 12)
		{
			PCNumber[i] = a[x];
			a[x] = 12;
			//printf("%d  ", PCNumber[i]);
		}
		else if(a[x] == 12)
		{
			goto retry;
		}		
	}
}
void pcGuessMath()  //猜數字輸入
{
	srand(time(NULL));
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	pcGuessNumber = (int*)malloc(HowMore * sizeof(int));
	printf("電腦猜的數字\n");
	for (int i = 0; i < HowMore; i++)
	{	
		retry: int x = rand() % 10;
		if (No[i].number[x] != 11 && a[x] != 12) //檢查自己可猜數字and是否有重複數字
		{
			pcGuessNumber[i] = x;
			a[x] = 12;
		}
		else
		{
			goto retry;
		}			
	}
	for (int a = 0; a < HowMore; a++)
	{
		printf("%d ", pcGuessNumber[a]);
	}
}

void YourMath()    //輸入你的數字
{	
	YourNumber = (int*)malloc(HowMore*sizeof(int));
	printf("你的數字\n");
	for (int i = 0; i < HowMore; i++)
	{
		printf("第%d:", i);
		scanf_s("%d", &YourNumber[i]);
	}		
}
void guessMath()  //猜數字輸入
{
	
	GuessNumber = (int*)malloc(HowMore * sizeof(int));
	printf("你猜的數字\n");
	for (int i = 0; i < HowMore; i++)
	{
		printf("第%d:", i);
		scanf_s("%d", &GuessNumber[i]);
	}
}

int check()   //檢查A.B
{	
		guessMath();
		int CheckA = 0;
		int CheckB = 0;

		for (int a = 0; a < HowMore; a++)
		{
			if (PCNumber[a] == GuessNumber[a])
			{
				CheckA++;
			}
		}
		for (int a = 0; a < HowMore; a++)
		{
			for (int z = 0; z < HowMore; z++)
			{
				if (GuessNumber[a] == PCNumber[z] && a!=z)
				{
					CheckB++;
				}
			}			
		}
		printf("%dA", CheckA);
		printf("%dB\n", CheckB);
		if (CheckA == HowMore)
		{
			printf("you win");
			++win;
		}	

	return win;
}
int pcCheck()   //檢查A.B
{	
	
		pcGuessMath();
		
	
		int pcCheckA = 0;
		int pcCheckB = 0;

		/*for (int a = 0; a < HowMore; a++)
		{
			if (pcGuessNumber[a] == YourNumber[a])
			{
				pcCheckA++;
			}
		}*/
		for (int a = 0; a < HowMore; a++)
		{
			for (int z = 0; z < HowMore; z++)
			{
				if (YourNumber[a] == pcGuessNumber[z] && a != z)
				{
					pcCheckB++;
				}
				else if (YourNumber[a] == pcGuessNumber[z] && a == z)
				{
					pcCheckA++;
				}
			}
		}
		printf("PC:%dA", pcCheckA);
		printf("PC:%dB\n", pcCheckB);

		if (pcCheckA == HowMore)
		{
			printf("pc win");
			win = win + 1;
		}
		guessRobot(pcCheckA,pcCheckB);				
		
		return win;
}

int guessRobot(int pccheckA, int pccheckB)
{
	//static int Weighted[] = { 0,1,2,3,4,5,6,7,8,9 };    //權重表

	if (pccheckB == 0 && pccheckA == 0)
	{
		for (int i = 0; i < HowMore; i++)
		{
			for (int x = 0; x < HowMore; x++)
			{
				No[i].number[pcGuessNumber[x]] = 11;
			}
		}
	}

	if (pccheckB != 0 && pccheckA == 0)
	{
		for (int i = 0; i < HowMore; i++)
		{
			No[i].number[pcGuessNumber[i]] = 11; 
		}
	}

	if (pccheckA != 0 && pccheckB==0)
	{
		
	}
	if (pccheckA != 0 && pccheckB != 0)
	{

	}

	if (pccheckA + pccheckB == HowMore)
	{
		
	}

	
	return 0;
}
/* 11代表這個數字以猜過且不是它  12代表這數字重複猜 */








/*兩種猜法
隨機猜 & 順序
演算法??
把猜的數字猜成一個一個,帶入結構,個別加成數字的權重 //1
前次猜的數字和這次比較 //2
*/

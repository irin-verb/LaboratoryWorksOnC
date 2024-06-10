#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*  x y 
	x y 
	x y 
номера точек - строки i, значения x, y - столбцы j */

//ФУНКЦИЯ СЛУЧАЙНОГО ЗАПОЛНЕНИЯ ЗНАЧЕНИЙ КООРДИНАТ
void RAN (float A [1000][2], int n)
{
	int a,b;
	printf("Введите нижнюю границу диапазона случайных чисел, а=");
	scanf("%d",&a);
	printf("Введите верхнюю границу диапазона случайных чисел, b=");
	do {	
		scanf("%d",&b);
		if (b<=a) 
			printf("Ошибка: значение конца отрезка должно быть больше значения начала, b=");
		} while (b<=a);	
	srand(time(NULL));
	int i,j;
	for (i=1;i<=n;i++)
	for (j=1;j<=2;j++)
	A[i][j]=a+rand()%(b-a+1);
}

//ФУНКЦИЯ РУЧНОГО ЗАПОЛНЕНИЯ ЗНАЧЕНИЙ X И Y
void RUCH (float A [1000][2], int n)
{
	int i,j;
	for (i=1;i<=n;i++)
	for (j=1;j<=2;j++)
	{   
		//printf("A[%d][%d]=",i,j);
		if (j==1) printf("X %d=",i);
		else printf("\rY %d=",i);
		scanf("%f",&A[i][j]);
	}
}

//ФУНКЦИЯ ОПРЕДЕЛЕНИЯ ПОПАДАНИЯ КОНКРЕТНОЙ ТОЧКИ В ЗАДАННУЮ ОБЛАСТЬ
float FLAG(float X, float Y, float R)
{
	float F;
	if ((X*Y<=0) && ((powf(X-R,2)+Y*Y<=R^2) || (powf(X+R,2)+Y*Y<=R^2)))
	F=1;
	else F=0;
	return F;
}

//ФУНКЦИЯ ВЫВОДА ПОПАВШИХ И НЕ ПОПАВШИХ В ОБЛАСТЬ КООРДИНАТ
void FLAGS(float A [1000][2], int n, float R)
{
	printf("\nТОЧКИ, ПОПАДАЮЩИЕ В ОБЛАСТЬ:\n");
	int i;
	for(i=1;i<=n;i++)
		if (FLAG(A[i][1],A[i][2],R)==1)
		printf("(%.1f ; %.1f)\n",A[i][1],A[i][2]);
	printf("ТОЧКИ,  НЕ ПОПАДАЮЩИЕ В ОБЛАСТЬ:\n");
	for(i=1;i<=n;i++)
		if (FLAG(A[i][1],A[i][2],R)==0)
		printf("(%.1f ; %.1f)\n",A[i][1],A[i][2]);
}


//ОСНОВНАЯ ПРОГРАММА
int main()
{
	system("chcp 1251");
	float A [1000][2]; 		
//задаем значение R
	printf("Введите радиус окружностей, R=");
	float R;
	do {	
		scanf("%f",&R);
		if (R<=0) 
			printf("Ошибка: радиус должен быть больше нуля, R=");
		} while (R<=0);	
//ввод количества координат
	printf("Введите количество точек, n=");
	int n;
	do {	
		scanf("%d",&n);
		if (n<=0) 
			printf("Ошибка: количество должно быть больше нуля, n=");
		if (n>1000) 
			printf("Ошибка: количество не может быть больше тысячи, n=");
		} while ((n>1000) || (n<=0));
//выбор и реализация способа заполнения массива
	int key;
	printf("Введите 1 - для случайных значений x и y;\nлюбое другое число - ручной ввод значений x и y:\n");
	scanf("%d",&key);
	if (key==1) RAN(A,n); else RUCH(A,n);
//выводим все точки
	printf("\nИСХОДНЫЕ ЗНАЧЕНИЯ:\n");
	printf("         X            Y\n");
	int i,j;
	for (i=1;i<=n;i++)
	{for (j=1;j<=2;j++)
	printf("%*.1f   ",10,A[i][j]);
	printf("\n");
	}	
//выводим попавшие и не попавшие точки
	FLAGS(A,n,R);
}

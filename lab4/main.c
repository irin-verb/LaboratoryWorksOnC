#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*  x y 
	x y 
*/

//ФУНКЦИЯ СЛУЧАЙНОГО ЗАПОЛНЕНИЯ ЗНАЧЕНИЙ КООРДИНАТ
void RAN (float* ARR, int n)
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
	int i;
	for (i=0;i<n;i++)
	{
	*(ARR+i*2)=a+rand()%(b-a+1);
	*(ARR+i*2+1)=a+rand()%(b-a+1);	
	}
	printf("\nИСХОДНЫЕ ЗНАЧЕНИЯ:\n");
	printf("      X       Y\n");
	for(i=0;i<n;++i)
	printf("%*.1f %*.1f\n",7,*(ARR+i*2),7,*(ARR+i*2+1));
}

//ФУНКЦИЯ РУЧНОГО ЗАПОЛНЕНИЯ ЗНАЧЕНИЙ X И Y
void RUCH (float* ARR, int n)
{
	int i;
	for (i=0;i<n;i++)
	{   
		printf("Координаты точки №%d:  ", i+1);
		scanf("%f %f",&(*(ARR+i*2)),&(*(ARR+i*2+1)));
	}
	printf("\nИСХОДНЫЕ ЗНАЧЕНИЯ:\n");
	printf("      X       Y\n");
	for(i=0;i<n;++i)
	printf("%*.1f %*.1f\n",7,*(ARR+i*2),7,*(ARR+i*2+1));
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
void FLAGS(float* ARR, int n, float R)
{
	printf("\nТОЧКИ, ПОПАДАЮЩИЕ В ОБЛАСТЬ:\n");
	int i;
	for(i=0;i<n;i++)
		if (FLAG(*(ARR+i*2),*(ARR+i*2+1),R)==1)
		printf("(%.1f ; %.1f)\n",*(ARR+i*2),*(ARR+i*2+1));
	printf("ТОЧКИ,  НЕ ПОПАДАЮЩИЕ В ОБЛАСТЬ:\n");
	for(i=0;i<n;i++)
		if (FLAG(*(ARR+i*2),*(ARR+i*2+1),R)==0)
		printf("(%.1f ; %.1f)\n",*(ARR+i*2),*(ARR+i*2+1));
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
	void (*ZAP)(float*, int);
	printf("Введите 1 - для случайных значений x и y;\nлюбое другое число - ручной ввод значений x и y:\n");
	scanf("%d",&key);
	if (key==1) ZAP=RAN; else ZAP=RUCH;
	ZAP((float*)A,n);

//выводим попавшие и не попавшие точки
	FLAGS((float*)A,n,R);
	return 0;
}

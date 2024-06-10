#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*  x y 
	x y 
*/

//������� ���������� ���������� �������� ���������
void RAN (float* ARR, int n)
{
	int a,b;
	printf("������� ������ ������� ��������� ��������� �����, �=");
	scanf("%d",&a);
	printf("������� ������� ������� ��������� ��������� �����, b=");
	do {	
		scanf("%d",&b);
		if (b<=a) 
			printf("������: �������� ����� ������� ������ ���� ������ �������� ������, b=");
		} while (b<=a);	
	srand(time(NULL));
	int i;
	for (i=0;i<n;i++)
	{
	*(ARR+i*2)=a+rand()%(b-a+1);
	*(ARR+i*2+1)=a+rand()%(b-a+1);	
	}
	printf("\n�������� ��������:\n");
	printf("      X       Y\n");
	for(i=0;i<n;++i)
	printf("%*.1f %*.1f\n",7,*(ARR+i*2),7,*(ARR+i*2+1));
}

//������� ������� ���������� �������� X � Y
void RUCH (float* ARR, int n)
{
	int i;
	for (i=0;i<n;i++)
	{   
		printf("���������� ����� �%d:  ", i+1);
		scanf("%f %f",&(*(ARR+i*2)),&(*(ARR+i*2+1)));
	}
	printf("\n�������� ��������:\n");
	printf("      X       Y\n");
	for(i=0;i<n;++i)
	printf("%*.1f %*.1f\n",7,*(ARR+i*2),7,*(ARR+i*2+1));
}

//������� ����������� ��������� ���������� ����� � �������� �������
float FLAG(float X, float Y, float R)
{
	float F;
	if ((X*Y<=0) && ((powf(X-R,2)+Y*Y<=R^2) || (powf(X+R,2)+Y*Y<=R^2)))
	F=1;
	else F=0;
	return F;
}

//������� ������ �������� � �� �������� � ������� ���������
void FLAGS(float* ARR, int n, float R)
{
	printf("\n�����, ���������� � �������:\n");
	int i;
	for(i=0;i<n;i++)
		if (FLAG(*(ARR+i*2),*(ARR+i*2+1),R)==1)
		printf("(%.1f ; %.1f)\n",*(ARR+i*2),*(ARR+i*2+1));
	printf("�����,  �� ���������� � �������:\n");
	for(i=0;i<n;i++)
		if (FLAG(*(ARR+i*2),*(ARR+i*2+1),R)==0)
		printf("(%.1f ; %.1f)\n",*(ARR+i*2),*(ARR+i*2+1));
}


//�������� ���������
int main()
{
	system("chcp 1251");
	float A [1000][2]; 		
//������ �������� R
	printf("������� ������ �����������, R=");
	float R;
	do {	
		scanf("%f",&R);
		if (R<=0) 
			printf("������: ������ ������ ���� ������ ����, R=");
		} while (R<=0);	
//���� ���������� ���������
	printf("������� ���������� �����, n=");
	int n;
	do {	
		scanf("%d",&n);
		if (n<=0) 
			printf("������: ���������� ������ ���� ������ ����, n=");
		if (n>1000) 
			printf("������: ���������� �� ����� ���� ������ ������, n=");
		} while ((n>1000) || (n<=0));
//����� � ���������� ������� ���������� �������
	int key;
	void (*ZAP)(float*, int);
	printf("������� 1 - ��� ��������� �������� x � y;\n����� ������ ����� - ������ ���� �������� x � y:\n");
	scanf("%d",&key);
	if (key==1) ZAP=RAN; else ZAP=RUCH;
	ZAP((float*)A,n);

//������� �������� � �� �������� �����
	FLAGS((float*)A,n,R);
	return 0;
}

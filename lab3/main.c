#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*  x y 
	x y 
	x y 
������ ����� - ������ i, �������� x, y - ������� j */

//������� ���������� ���������� �������� ���������
void RAN (float A [1000][2], int n)
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
	int i,j;
	for (i=1;i<=n;i++)
	for (j=1;j<=2;j++)
	A[i][j]=a+rand()%(b-a+1);
}

//������� ������� ���������� �������� X � Y
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
void FLAGS(float A [1000][2], int n, float R)
{
	printf("\n�����, ���������� � �������:\n");
	int i;
	for(i=1;i<=n;i++)
		if (FLAG(A[i][1],A[i][2],R)==1)
		printf("(%.1f ; %.1f)\n",A[i][1],A[i][2]);
	printf("�����,  �� ���������� � �������:\n");
	for(i=1;i<=n;i++)
		if (FLAG(A[i][1],A[i][2],R)==0)
		printf("(%.1f ; %.1f)\n",A[i][1],A[i][2]);
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
	printf("������� 1 - ��� ��������� �������� x � y;\n����� ������ ����� - ������ ���� �������� x � y:\n");
	scanf("%d",&key);
	if (key==1) RAN(A,n); else RUCH(A,n);
//������� ��� �����
	printf("\n�������� ��������:\n");
	printf("         X            Y\n");
	int i,j;
	for (i=1;i<=n;i++)
	{for (j=1;j<=2;j++)
	printf("%*.1f   ",10,A[i][j]);
	printf("\n");
	}	
//������� �������� � �� �������� �����
	FLAGS(A,n,R);
}

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
	������: ������������ ��������� ������ �������� � ������� ��� �� �����. 
	��������� ������� ������ ���� �x�, ��������� ���� ������������ �������� 
	������ � � �, �������� �-�.
*/

//�������� �������� ��������������
const int rangeLow = 2;
const int rangeHigh = 50;


//�������� �� val � �������� [min...max]
bool inline inRange(int val, int min, int max)
{
	return val >= min && val <= max;
}

//����������� ������� ��������� �������, ���� ����� ������������ ����������
//����� ���������� ����� �� ���������
void fillArray(char [][50], int, int);
void printArray(const char [][50], int, int);

int main() 
{
	char arr[50][50];
	int sizeX,sizeY;
	
	//������������� ��������� ��� ������� ��������
//	SetConsoleCP(1251); 
//	SetConsoleOutputCP(1251);
    system("chcp 1251");
	
	//���� � �������� ������
	do
	{
		printf("������� ������ � ������ �������������� � ��������� [%d...%d]:\n", rangeLow, rangeHigh);
		scanf("%d%d", &sizeX,&sizeY);
		
		if(inRange(sizeX,rangeLow,rangeHigh) && inRange(sizeY,rangeLow,rangeHigh))
		{
			break;
		}
		else
			printf("������! ������� ��� ���!\n"); 
	}while(true);
	
	//��������� ������ ��������
	fillArray(arr, sizeX, sizeY);
	
	//������� �������������
	printArray(arr, sizeX, sizeY);
		
	return 0;
}


//�������� �� x,y �� ������� �������������� ��������� �������
bool inline isBorder(int x, int y, int sizeX, int sizeY)
{
	return x==0 || x==sizeX || y==0 || y==sizeY;
}

//������ �� �����
bool inline isEven(int val)
{
	return val % 2 == 0;
}

// ��������� ��������� ������ � ����������� � �������. ������ ����������� ������� ������� ����
void fillArray(char arr[][50], int sizeX, int sizeY)
{
	int i,j;
	
	for(j = 0; j < sizeY; j++)
		for(i = 0; i < sizeX; i++)
			arr[i][j] = isBorder(i, j, sizeX -1 , sizeY - 1) ? 'x' : (isEven(i * j) ? ' ' : '-');			
}

// ������� ��������� ������ �� �����. �� �������� const!
void printArray(const char arr[][50], int sizeX, int sizeY)
{
	int i,j;

	for(j = 0; j < sizeY; j++)
	{
		for(i = 0; i < sizeX; i++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}

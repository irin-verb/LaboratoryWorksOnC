#include <stdio.h>


// ���������� ����������
int a;

// ���������� � ������������� ���������� ����������
int b = 2 , c = 3;

// ���������� ���������
const int numStudents = 30; 


/*****************************************************/


//���������� ����������
int i = 1; 

int getI() 
{
	return i;
}

int getLocalI() 
{
	//��������� ���������� �������
	int i = 2; 
	
	return i;
}

int main() 
{
	int i = 3; //��������� ����������
	printf("i = %d\n", i); // i = 3
	
	{
		int i = 4; //��������� ����������
		printf("i = %d\n", i); // i = 4
	}
	
	printf("i = %d\n", getI()); // i = 1
	printf("i = %d\n", getLocalI()); // i = 2
	
	return 0;
}






#include <stdio.h>
#include <math.h>


// ������ ���������� n! ������� ���������� ��������
int fact1(unsigned int n) 
{
	if(n == 0)
		return 1; // ������������ ��������
	else
		return n * fact1(n - 1); // ����������� �����
}

// ������ ���������� n! ������� ���������� ��������, w - ������� ��������
int fact2(unsigned int n, unsigned int w) 
{
	if(n == 0)
		return w; // ������������ ��������
	else
		return fact2(n - 1, w * n); // ����������� �����
}

int main() 
{
	system("chcp 1251");
	
	int n = 5;
	printf("���������� ��������: %d! = %d\n", n, fact1(n));
	printf("���������� ��������: %d! = %d\n", n, fact2(n, 1));
	
	return 0;
}



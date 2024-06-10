#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
	�������� ��������:
 	���������� ��� ���� ����������� ����� �� ��������� �������:
 	���� m �������� ������ ��������� n, �� ��� = m, � ��������� 
	������ ����� ����� ������� ��� �� m � �� ������� ������� n �� m
*/
int NOD(unsigned int n,unsigned int m)
{
	if(m > n)
		return NOD(m, n); // ����������� �����
	else
		if(m == 0)
			return n; // ������������ �����
		else
			return NOD(m, n % m); // ����������� �����
}

/* 
	����������� ��������:
   	��������� n-� ���� ���� ��������� F(0) = 0, F(1) = 1, F(N) = F(N-1) + F(N-2)
*/
int fibo(unsigned int n)
{
	if(n == 0)
		return 0; // ������������ �����
	else
		if(n == 1)
			return 1; // ������������ �����
		else
			return fibo(n - 1) + fibo(n - 2); // ����������� �����
		
}

/*
	�������� ��������:
	��������� �������� �� ����� ������ ��� �������� (������ ������������� � �������������)
*/
bool isOdd(unsigned int n);
bool isEven(unsigned int n) 
{
  if (n == 0) 
	return true;
  else 
	return isOdd(n - 1); // �������� ����������� �����
}

bool isOdd(unsigned int n) 
{
  if(n == 0) 
	return false;
  else 
	return isEven(n - 1); // �������� ����������� �����
}


/*
	�������� ����� �������� �������:
	���������� ������� ��������� ��� m � n
	A(m, n) = n+1			��� m = 0;
	A(m, n) = A(m-1, 1)		��� n = 0;
	A(m, n) = A(m-1, A(m, n-1))	� ��������� �������.
*/
int ackerman(unsigned int m, unsigned int n)
{
	if(m == 0)
		return n + 1;
	else
		if(n == 0)
			return ackerman(m - 1, 1);
		else
			return ackerman(m - 1, ackerman(m, n - 1));
}

int main() 
{
	system("chcp 1251");
	
	int i = 42, j = 12;
	printf("���������� ����� �������� ��� %d � %d: %d\n", i, j, NOD(i, j));
	
	int f = 15;
	printf("����� ���������� ��� %d-�� �����: %d\n",f, fibo(f));
	
	int d = 13;
	printf("����� %d ������: %s\n", d, isEven(d)? "��" : "���");
	printf("����� %d ��������: %s\n", d, isOdd(d)? "��" : "���");
	
	int n = 3, m = 4;
	printf("������� ��������� ��� %d � %d : %d", n, m, ackerman(n,m));

	return 0;
}



#include <stdio.h>


int main()
{
	int a=5, b=10;
	int* pointer=&a; //���� ����� ���������� �
	
	printf("%d\n", *pointer); //pointer ��������� �� a: 5
	
	pointer=&b; //���� ����� ���������� b
	printf("%d\n", *pointer); //pointer ��������� �� b: 10
	
	printf("%p\n", pointer); //����� ���������: 22fe2c
	
	//��������� ����� ��������� � ������� ��� ����� ��������� pointer
	int* pointer2=pointer;
	printf("%d\n", *pointer2 * a); // pointer2 ��������� �� b, b * a = 50
	
	return 0;
}

#include <stdio.h>

int main(int argc, char** argv) 
{
	
	//��������� ����� ��� ����
	typedef unsigned int UInt;
	
	//������ ��� ����� ������������ ��� ����� ������ ���
	UInt a = 5 + 2;
	printf("%d", a); // 7
	
	//����� ���������� ��� ���� ��� ���������
	typedef int* IntPtr;
	IntPtr ptr; //� ��������� ��������� ������� ����
	
	//����� ��������� ���������� ���� ��� ���������� �� �������
	typedef float (*MathFunc)(float);
	MathFunc funcPtr; //��������� �� �������
	
	//��� ���������� ��� ���� ��� �������
	typedef int IntArr[6];
	IntArr arr = {1,2,3,4,5,6};

	
	return 0;
}

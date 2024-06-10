#include <stdio.h>

// ��� ��������� �������� ���������� - ����������:
/*
void func(int* ptr, const int* ptrToConst, int* const constPtr, const int* const constPtrToConst)
{
    *ptr = 0; //OK: ������ ������ �� ���������.
    ptr = NULL; //OK: ������ ���������.
    
    *ptrToConst = 0; //������! ������ ������ ������ �� ���������.
    ptrToConst = NULL; //OK: ������ ���������.
    
    *constPtr = 0; //OK: ������ ������ �� ���������.
    constPtr  = NULL; //������! ������ ������ ���������.
    
    *constPtrToConst = 0; //������! ������ ������ ������ �� ���������.
    constPtrToConst  = NULL; //������! ������ ������ ���������.
}
//*/

int main()
{
	//������������ const ����� ������ ����� ���������� � ��������������� ���� ��������� ��� const:
	
	const int a = 3;
	
	// ...
	
	int *ptr1 = &a; // Warning!
	int *ptr2 = (int*) &a; // No warning!
	
	// ...
	
	*ptr1 += 2;
	*ptr2 *= 10;
	
	printf("%d", *ptr2); // 50
	
	return 0;
}

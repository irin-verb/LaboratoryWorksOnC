#include <stdio.h>


#define DEBUG
#define VERSION 4

int main()
{
	system("chcp 1251"); 

	#if VERSION < 3
		puts("���������� ����� ������ ������ ���������! ���������� ��������� ������!\n");
		exit(1);
	#elif VERSION < 5
		puts("�������� ����� ����������, ������������� �������� ���������...\n");
	#endif
	
	// �������� ���������� DEBUG
	//#undef DEBUG
	
	#ifdef DEBUG
		puts("���������� ������ ���������.\n");
	#else
		puts("�������� ������ ���������.\n");
	#endif

  return 0;
}

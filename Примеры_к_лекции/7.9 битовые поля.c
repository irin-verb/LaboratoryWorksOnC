#include <stdio.h>

/*
� ������� ���� � ��������� ���������� �������� ������, ������������ ����� ����������� 
� ����� ����� ��������, � ���������� ������ ��������� ����� �������� � ����� 1 ����: 
*/

typedef struct  //typedef ��������� �� ������ struct � ����������
{
	unsigned char isReady; //���������� ������ ������ ���
	unsigned char isError; //���������� ������ ������ ���
	unsigned char processId; //���������� ������ ������ 6 ��� (�.�. �������� �������� [0...63])
} State;

int main() 
{
	State state={1,0,7};

	printf("[%d bytes] ready=%d err=%d proc=%d",sizeof(State), 
												state.isReady, 
												state.isError, 
												state.processId);
	
	//[1 bytes] ready=1 err=0 proc=7
	
	return 0;
}


#include <stdio.h>


int main() 
{
	int i = 0;
	if(i) // ��������� ��������, ������������ � ��������������
		printf("i!=0\n");
	else
		printf("i==0\n");
		
	i = 5;
	// ���� �� ������� break ����� ��������� ��� ��������� �� ���������� break
	// � case ��� ������� ���������� ���������� ��������� �������� �� ���������
	switch(i)
	{
		case 5:
			printf("5! ");
			break;
		case 6:
			printf("6! ");
			break;
		case 7:
			printf("7! ");
			break;
		default:
			printf("default!");
	}
	printf("\n");
		
	return 0;
}


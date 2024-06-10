#include <stdio.h>

//�������� ��� ������ ������ ���������� �����
//������ ��� �� ������� ������ �����������
unsigned int getUniqID()
{
	//����������� ���������� ������ ���� ��������
	//����� �������� �������
	static unsigned int id = 1;
	return id++;
}

int main() 
{
	printf("%d\n", getUniqID()); // 1
	printf("%d\n", getUniqID()); // 2
	printf("%d\n", getUniqID()); // 3
	
	return 0;
}





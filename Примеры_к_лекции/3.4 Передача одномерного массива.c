#include <stdio.h>
#include <math.h>

// ������� ������ ���������� �� ������, ������� �� ��������
// ����� ���� �������� ������ �������
void doubleElems(int array[], int len) 
{
	int i;
	
	for(i = 0; i < len; ++i)
		array[i] *= array[i];
}

// ���� �������������� ������ ������ ���������, ������
// ������� ���������� ��� ����������� ��������
float getAvgValue(const int array[], int len) 
{
	int i, sum = 0;
	
	for(i = 0; i < len; ++i)
		sum += array[i];
		
	return (float) sum / len;
}

// ���� ����������� �������� �� ����� ������, ��� �����
// ������� � ����������� ������������ ������ �������.
void print(const int array[], int len) 
{
	int i;
	
	for(i = 0; i < len; ++i)
		printf("%d ", array[i]);
		
	printf("\n");
}

int main() 
{
	system("chcp 1251");
	
	int array[]={1,5,-4,6,9};
	
	print(array, 5);
	doubleElems(array, 5); // ������ �������������� � ������ �������
	print(array, 5);
	printf("������� ��������: %f", getAvgValue(array,5)); // 31.7999

	return 0;
}



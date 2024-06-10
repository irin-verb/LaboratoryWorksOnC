#include <stdlib.h>
#include <stdio.h>
#include <mem.h>

int* createDynArray(int size);
void printDynArray(const int* array, int size);

#define ARR_SIZE 10

int main() 
{
	//������ ��� ������������ ������� �� 10 ���������
	int *a = createDynArray(ARR_SIZE), *b = createDynArray(ARR_SIZE);
	
	if(!a || !b) printf("Error!"), exit(1);
	
	//��������� �������
	int i;
	for(i = 0; i < ARR_SIZE; i++) 
		a[i] = b[ARR_SIZE - 1 - i] = i * i;
	
	//������� �������
	printDynArray(a, ARR_SIZE);
	printDynArray(b, ARR_SIZE);	
	printf("\n");
	
	const int arrSizeHalf = ARR_SIZE / 2;
	//�������� ��������� 5 ��������� �� ������� a � ������ 5 ��������� ������� b
	memcpy(b, a + arrSizeHalf, arrSizeHalf * sizeof(int));
	
	//�������� ������ 5 ��������� �� ������� a � ��������� 5 ��������� ������� b
	memset(a, 0, arrSizeHalf * sizeof(int));	
	memset(b + arrSizeHalf, 0, arrSizeHalf * sizeof(int));
	
	//������� �������
	printDynArray(a,ARR_SIZE);
	printDynArray(b,ARR_SIZE);	
	
	//�� �������� ���������� ������
	free(a); 
	free(b); 
	a = b = NULL;
	
	return 0;
}



//������� ���������� ��������� �� ������������ ������ ������� size ���������
int* createDynArray(int size)
{	
	//�������� �� ���������� ������
	if(size < 1) return NULL;
	
	//�������� ������ ��� size ���������
	int* p = (int*)calloc(size, sizeof(int));
	
	//���� ������ �� ���������� - ���������� ������� ���������
	if(!p) return NULL;
	
	//���������� ��������� �� ������ ������� �������
	return p;
}

//����� ������� �� �����
void printDynArray(const int* array, int size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("\t%d", array[i]);	
	printf("\n");
}

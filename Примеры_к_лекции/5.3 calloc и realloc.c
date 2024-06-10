#include <stdlib.h>
#include <stdio.h>

//������� ���������� ��������� �� ������������ ������ ������� size ���������
float* createDynArray(int size)
{	
	//�������� �� ���������� ������
	if(size < 1) return NULL;
	
	//�������� ������ ��� size ���������
	float* p = (float*)calloc(size, sizeof(float));
	
	//���� ������ �� ���������� - ���������� ������� ���������
	if(!p) return NULL;
	
	//���������� ��������� �� ������ ������� �������
	return p;
}

//������� ��������� ������� ������� �� newsize ���������
float* resizeDynArray(float* array, int newsize)
{
	//�������� �� ���������� ������
	if(newsize < 1) return NULL;
		
	//��������� ����� ������
	float* p = (float*)realloc(array, newsize * sizeof(float));
	
	//���� �� ������� - ���������� NULL
	if(!p) return NULL;
	
	//���������� ��������� �� ������ ������� �������, �.�.
	//����� ��� ����������!
	return p;
}

//����� ������� �� �����
void printDynArray(const float* array, int size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("%f ", array[i]);	
	printf("\n");
}

int main() 
{
	//������ ������������ ������ �� 5 ���������
	float* array = createDynArray(5);
	if(!array) printf("Error!"), exit(1);
	
	//������� �������� �������
	printDynArray(array, 5);
		
	//����������� ������ ������������� �������
	array = resizeDynArray(array, 15);
	if(!array) printf("Error!"), exit(1);
	
	//������� ����� �������� �������
	printDynArray(array, 15); //c��������� ����������� ����� ������ �� ����������, 
							 //������� ����� ���������� �����
		
	free(array); //�� �������� ���������� ������
	array = NULL;
	
	return 0;
}


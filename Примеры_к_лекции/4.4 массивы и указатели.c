#include <stdio.h>

void sum(int num, const float array1[], const float array2[], float arrayRes[]);
void print(int rows, int cols, const float array[][cols]);

main()
{
	// ���������� �������:
	// ������� ��� ������ �������� � �������� �������
	
	int a[]={1, 2, 3, 4, 5};

	// ������ ������� � ������ sizeof(a) 
	// ������������� �� ����� ����������
	unsigned int count = sizeof(a) / sizeof(a[0]); 

	// ��������� �� ��������� �������
	int *a_end = a + count - 1; 
	
	//������� ��� ������ �������� � �������� �������
	int *ptr;
	for (ptr = a_end; ptr >= a; ptr--) 
	    if(*ptr % 2 == 0) 
			printf("%d ", *ptr); // 4 2
	printf("\n");		
			
			
			
	// ��������� �������:
	// ������� ��� �������
	#define ROWS 3
	#define COLS 2
	int i,j;
	float mat1[ROWS][COLS] = {1, 2, 3, 4, 5, 6};
	float mat2[ROWS][COLS] = {7, 8, 9, 10, 11, 12};
	float mat3[ROWS][COLS];
	
	//  mat1: 1.0        2.0	mat2: 7.0        8.0
	//        3.0        4.0  	      9.0        10.0
	//        5.0        6.0  	      11.0       12.0
	
	// � ������ � ��������� �������� ��� ��� ����� ��������� �� ��� ������
	// �������, �� � ������ ������ ��� �������� �������� ����������� ���������
	// (�.�. ��������� ������ ��� ���������� ������ �� ��������� ���������� ����������� ���������)
	
	for(j = 0; j < COLS; j++)
		printf("%f ",(*(mat1 + 1))[j]); // ������� 2-� ������ ������� mat1
	printf("\n");
	for(j = 0; j < COLS; j++)
		printf("%f ",*(*(mat1 + 2) + j)); // ������� 3-� ������ ������� mat1
	printf("\n");
	
	
	// ������� � ������� ���������� �������, �.�. ������� ��-�������
	for(i=0; i<ROWS;i++)
			sum(COLS, *(mat1 + i), *(mat2 + i), *(mat3 + i)); 
			
	printf("mat3:\n");		
	print(ROWS, COLS, mat3);
	
	//  mat3: 8.0        10.0
	//        12.0       14.0
	//        16.0       18.0	
	
	// ������ �� "���������" ������� (array flatten) �� ���������� � ����������
	// "��������" (flatten) ������� - ��� ���������� ����������� �������
	float* p1 = (float*) mat1; //���� ��������� �� ������� mat1[0][0]
	float* p2 = (float*) mat2; //���� ��������� �� ������� mat2[0][0]
	float* p3 = (float*) mat3; //���� ��������� �� ������� mat3[0][0]
	unsigned int size = ROWS * COLS; //���-�� ��������� � ��������
	
	
	for(i = 0; i < size; i++)
		*p3++ = *p1++ + *p2++; //���������� �������� � �������� ���������


	printf("mat3:\n");
	print(ROWS,COLS,mat3);
	
	//  mat3: 8.0        10.0
	//        12.0       14.0
	//        16.0       18.0	

}

void sum(int num, const float array1[], const float array2[], float arrayRes[])
{
	int i;
	for(i = 0; i < num; ++i)
		arrayRes[i] = array1[i] + array2[i];
}

void print(int rows, int cols, const float array[][cols])
{
	int i,j;

	for(i=0; i<rows;i++)
	{
		for(j=0; j<cols;j++)
			printf("\t%f",array[i][j]);
		printf("\n");
	}
}

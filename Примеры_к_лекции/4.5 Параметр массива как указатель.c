#include <stdio.h>

void print(const int* array,int len) //���������� const int array[]
{
	int i;
	for(i=0; i<len;i++)
		printf("%d ",*(array+i)); //���������� array[i]
	printf("\n");
}

void inline swap(int* a, int* b) //�������� �������� �������
{
	int temp= *a;
	*a = *b;
	*b = temp;
}

void reverse(int* array, int len) //���������� int array[]
{
  int start = 0, end = len - 1;
  
  while (start < end)  
	swap((array + start++), (array + end--));
}


// �������� �������� �������� �� 1 ���� ����� �������� ������,
// � �� -1 - ���� ��������
float calcOddEven(int* array, unsigned int rows, unsigned int cols)
{
	int i,j;
	
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
		{
			int* elem = (array + i * cols + j); // array2d[imax][jmax] => array1d[i * jmax + j]
			*elem = (i + j) % 2 == 0 ? 1 : -1;
		}
}

int main() 
{
	int a[] = {1, 2, 3, 4, 5};
	
	reverse(a, 5); // ��� 1d ������� - ��������� �� ��� ������ �������
	print(a, 5); // 5, 4, 3, 2, 1
	
	
	#define ROWS 3
	#define COLS 2
	int mat[ROWS][COLS];
							
	calcOddEven((int*)mat, ROWS, COLS);  //��� ����� ���������� ���� �� ����� Warning

	print((int*)mat, ROWS * COLS); // ��� �������� 2d ������� ����� ������������ ������� ��� 1d �������

	/* mat =  1 -1 
			 -1  1 
			  1 -1
	*/
	
	/*  ����� ������� ��� � 1d ������� ��� ��� ��������� �� ������ ������� int*
		� �� ����� ��� � 2d ������� ��� ��� ��������� �� 1d ������ int(*)[]
	*/
	
	return 0;
}

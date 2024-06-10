#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
 
int main() 
{
	int i, j;
	
	//������ ������ ���������� �������� SIZE
    int** A = (int**) malloc(SIZE * sizeof(int*));
 
 	//��� ������� ��������-��������� ������ ���� ������
 	//������ �������� ������������� � 1 �� SIZE
    for (i = 0; i < SIZE; ++i)
        A[i] = (int*) malloc((i + 1) * sizeof(int));
 
 	//��������� ��������� ����������� ������
 	int c = 1;
    for (i = 0; i < SIZE; ++i) 
        for (j = 0; j < i + 1; ++j) 
            A[i][j] = c++;
        
    
 	//������� ��������� ����������� ������
    for (i = 0; i < SIZE; ++i) 
    {
        for (j = 0; j < i + 1; ++j) 
            printf("\t%d", A[i][j]);
        printf("\n");
    }
    /*
        1
        2       3
        4       5       6
        7       8       9       10
        11      12      13      14      15
    */

	//������� ������� ���-�������
    for (i = 0; i < SIZE; ++i)  
		free(A[i]);
    
    //����� ������� �������� ������
	free(A); 
	A = NULL;
     
	return 0;
}

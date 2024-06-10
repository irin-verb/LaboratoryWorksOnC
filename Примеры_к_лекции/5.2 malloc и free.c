#include <stdio.h>
#include <stdlib.h>

int main() 
{

	int* p; //��������� �� ������������ ����������
	p = (int*)malloc(sizeof(int));  //�������� ������ ������� int
	
	//�����: ���� C ������������ ������� ���������� �� void* � 
	//       ������ ����� ���������� (� ����� ������ � int*). 
	//		 C++ ��������� ���.
	
    //���� ������ ������������, �� malloc ������ ������� ���������
    //����������� ������� ��������� ��������
    if(!p) 
    {
    	printf("Out of memory!");
		//������� exit ���������� ��������� ������ ���������
    	// � �������� ����� ������������ ��� ������
    	exit(1); 
	}
	
	*p = 42; //���������� ��������
	
	printf("%d\n",*p); //42
	
	free(p); //����������� ������, ������ p �����������
	
	p = NULL; //����� �������� ��������� �� ������� ������, �������� ��� NULL
	
	
	
	// -----------------------------------------------------
	// ������� ������������ ������:
	
	const int maxSize = 100;
    int* arr = NULL; //��������� �� ������������ ������
    int i, size;
 
 	//���������� � ������������ ������ ������������� �������
    do 
	{
        printf("Enter array size in range [1...%d]: ", maxSize);
        scanf("%d", &size);
        //��������� ������� ������ �������
        if (size > 0 && size <= maxSize) 
			break;	
		else
			printf("Error!\n");
    } while (1);
 
 	//�������� ��� ������� ������ � size ���������
    arr = (int*)malloc(size * sizeof(int));
    
    //��������� �������� ���������
    if(!arr) printf("Out of memory!"), exit(1); 
 
 	//����������� �������� ���������
    for (i = 0; i < size; i++) 
        arr[i] = i*i;
    
 	//������� �������� �� �����
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    
    //����������� ������ �������
    free(arr);
    arr = NULL;
	
    
    return 0;
}

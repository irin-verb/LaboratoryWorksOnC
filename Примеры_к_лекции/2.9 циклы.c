#include <stdio.h>


int main() 
{
	int i = 0;
	
	// ���� � ������������:
	while(i < 5)
		printf("%d ",++i);
	printf("\n");	

	i = 0;
	// ���� � ������������:
	do
		printf("%d ",i++);
	while(i < 5);
	printf("\n");
	
	
	// ���� � ���������� (����� �����������):
	int x, y;
	for(x = 5, y = 0; x > 0 && y < 10; --x, ++y) 
		printf("[%d, %d]", x, y);
	printf("\n");
	
	
	
	return 0;
}


#include <stdio.h>

int main(int argc, char** argv)
{
	system("chcp 1251"); 
	
	printf("������ ����: %s\n", argv[0]);
	
	if(argc > 1)
	{
		int i;
		for(i = 1; i < argc; ++i)
			printf("�������� �%d = \"%s\"\n", i, argv[i]);
	}
	else
		puts("��� ����������");
		
	return 0;
}

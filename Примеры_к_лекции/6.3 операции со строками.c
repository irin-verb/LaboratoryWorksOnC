#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int main() 
{
	system("chcp 1251"); 
	
	char* name = (char*) malloc(10); // �������� ������ ��� 10 ��������
	puts("������� ���:");
	scanf("%9s", name); // %9s ��������� ���� ������� 9 ���������, 10 ����� '\0'
	printf("���� ��� %s\n", name);
	free(name);
	name = NULL;
	
	// ����� scanf � ����� ����������� �� ������ ����� ����� fgets
	// ����� �������� ����� stdin, ����� ���� ����� ������� ������ '\n'
	// � ���� ����� fgets ����� ��������
	fflush(stdin);
	
	// -----------------------------------------------------------------
	// ������ ������ � ������ ��������� �� ������ ���������
	// -----------------------------------------------------------------
	char s1[20], s2[20], text[2000]; 

	puts("������� �����:");
	fgets(text, 100, stdin); //�������� �����

	if(strlen(text) < 5) 
		puts("������� ����� ������ 5 ��������"), exit(1);
	
	puts("������� ��� ������������������ �������� ��� ������ \"����\" �� \"���\" ����� ������:");
	scanf("%19s %19s", s1, s2); //�������� ������ ������
	

	int s1Len = strlen(s1), 
		s2Len = strlen(s2), 
		textLen = strlen(text);
	
	if(!s1Len || !s2Len) 
		puts("������� ���� �� �� 1 ������� ������"), exit(1);
	
	int i=0;
	int offset = s2Len - s1Len;
	while(i != strlen(text)) //� ����� �������� ��� ������� text
	{
		if(strncmp(text + i, s1, s1Len) == 0) //� ���� ����� ����������
		{
			if(offset != 0) // ������ ������ �� ��������� �� �������
			{
				int from = offset > 0 ? strlen(text) : (i + s2Len);
				int to = offset > 0 ? i : (strlen(text) + 1);
				int mod = offset > 0 ? -1 : 1;
				
				int j;
				for(j = from; j != to; j += mod)
					text[j + offset] = text[j];
			}

			memcpy(text + i, s2, s2Len * sizeof(char)); //�������� ��������� � ������
			i += s2Len;

			continue;
		}
		i++;
	}
	
	puts(text);

	return 0;
}

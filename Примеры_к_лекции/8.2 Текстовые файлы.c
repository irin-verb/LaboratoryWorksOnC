#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
 
const char* fileName = "8.2 test.txt";
const char* ErrorOpen = "���������� ������� ����.";
const char* ErrorClose = "������ �������� �����.";

int main()
{
	system("chcp 1251");
	
	//��������� ���� �� ������
	FILE *file = fopen(fileName, "w"); 
	if (!file) 
		puts(ErrorOpen), exit(1);
	
	fputs("������ ������\n������ ������", file); //���������� ��� ������
	fputs(" � ��� �����\n", file); //���������� �� ������ ������
	
	//���������� ��������������� ������
	fprintf(file, "������: [%d] [%f]\n����� ������!", 42, 1.32f);
	
	//��������� ����
	if(fclose(file)) 
		puts(ErrorClose), exit(1);
	
	//-------------------------------------------
	
	//��������� ���� �� ����������
	if (!(file = fopen(fileName, "a"))) 
		puts(ErrorOpen), exit(1);
	
	fputc('\n', file);  //������� �� ����� ������
	fputs("��������� ������", file); //���������� ������
	fputc('!', file); //���������� ��������� ������
	
	//��������� ����
	if(fclose(file)) 
		puts(ErrorClose), exit(1);	
	
	//-------------------------------------------
	
	//��������� ���� �� ������
	if (!(file = fopen(fileName, "r"))) 
		puts(ErrorOpen), exit(1);
	
	char line1[50], line2[50], str[20];
	int intVar;
	float floatVar;
	
	//��������� ������ ������ 3� �����
	fgets(line1, 50, file);
	fgets(line2, 50, file);
	fscanf(file,"%19s [%d] [%f]",str, &intVar, &floatVar);
	
	//������� �������� � ����� �����
	line1[strlen(line1) - 1] = line2[strlen(line2) - 1] = '\0';
	
	//��������� ����
	if(fclose(file)) 
		puts(ErrorClose), exit(1);	
	
	printf("���������� �����:\n%s\n%s\n%f\n%d\n%s\n",
					line1, line2, floatVar, intVar, str);
	
	
	return 0;
}

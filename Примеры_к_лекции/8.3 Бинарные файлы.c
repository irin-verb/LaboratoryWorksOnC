#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <locale.h>
 
const char* fileName = "8.3 test.bin";
const char* ErrorOpen = "���������� ������� ����.";
const char* ErrorClose = "������ �������� �����.";

int main()
{
	system("chcp 1251");
	
	typedef struct
	{
		char surname[30];
		unsigned char age;
		unsigned int salary;
		float tax;
	} Person;
	
	Person persons[4]={
						{"������", 38, 34000, 0.13},
						{"������", 27, 27000, 0.13},
						{"������", 55, 55000, 0.06},
						{"�������", 40, 32000, 0.0},
					  };
	
	
	
	//��������� ���� �� ������
	FILE *file = fopen(fileName, "wb"); 
	if (!file) 
		puts(ErrorOpen), exit(1);
	
	//���������� ������ � ���� 
	fwrite(persons, sizeof(Person), 4, file);
	
	//��������� ����
	if(fclose(file)) 
		puts(ErrorClose), exit(1);	
	
	
	//----------------------------------
	
	//��������� ���� �� ������
	if (!(file=fopen(fileName, "rb"))) 
		puts(ErrorOpen), exit(1);
	
	puts("������� ������� ��������, ������� ���������� �����:");
	char findName[30];
	scanf("%29s",findName);
	
	//�������� �������� �������
	int i, len = strlen(findName);
	if(len<2) puts("������� �������!"), exit(1);
	
	//��� ����� tolower �� ����� �������� ��� ������� ����, ��������� � locale.h
	setlocale(LC_ALL, "rus"); 
	//����������� ��� ����� � ��������
	for(i = 0; i < len; ++i) 
		findName[i] = tolower(findName[i]);
	
	char buff[30];
	while(1) //��������� ��� ������, � ������� ������ (������ ������������ feof)
	{
		//��������� ��������� ���
		if(fread(buff, sizeof(char), 30, file) != 30) 
			break; //�������� ����� �����
		
		if(strcmp(findName, buff) == 0) //���� ��� ��������� � �������
		{
			Person person;
			fseek(file, -30 * sizeof(char), SEEK_CUR); //������������ � ������ ������
			
			//��������� ��� ������ ������� � person
			if(!fread(&person, sizeof(Person), 1, file)) 
			{ 
				puts("���� ���������!"); 
				break; 
			}
			
			//������� �������� ���������� � ��������
			printf("%s ����� ������� %d � �������� %d ������ � ����� �������.\n", 
											person.surname, person.age,
											(int)round(person.salary * (1.0 - person.tax)));
		}
		else
			//���������� �������� ��������� �� ������ ����� ������
			fseek(file, sizeof(Person) - 30 * sizeof(char), SEEK_CUR);
	}
	
	if(fclose(file)) 
		puts(ErrorClose), exit(1); 	//��������� ����
	
	return 0;
}

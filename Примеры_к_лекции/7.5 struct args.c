#include <stdio.h>


struct Person 
{
	char name[20];
	char surname[20];
	unsigned int yearBirth;
}; 

typedef struct Person Person; //��������� �� ������ � ���������� struct

void printPersonVal(Person person)
{
	printf("%s %s ������� � %d ����.\n", person.name, person.surname, person.yearBirth);
	person.yearBirth = 999;
}

void printPersonPtr(Person *person)
{
	printf("%s %s ������� � %d ����.\n", person->name, person->surname, person->yearBirth);
	person->yearBirth = 999;
}

int main() 
{
	system("chcp 1251");
	
	Person person={"����", "������", 1995};
	
	printPersonVal(person); //1995
	printPersonVal(person); //1995
	
	printPersonPtr(&person); //1995
	printPersonPtr(&person); //999	
	
	return 0;
}


#include <stdio.h>
#include <string.h>

struct Person //���������� ���������
{
	char name[20];
	char surname[20];
	unsigned int yearBirth;
}; // ; �����������!

int main() 
{
	system("chcp 1251");	
	
	struct Person person; 
	 
	puts("������� ���, ������� � ��� ��������:");
	
	do //���� � �������� ����� ���������
	{
		scanf("%19s%19s%d", person.name, person.surname, &person.yearBirth);
		if(strlen(person.name)>1 && strlen(person.surname)>1 && 
			person.yearBirth>1900 && person.yearBirth<2099)
				break;
		else
			puts("������!");
	} while(1);
	
	//����� ����� ���������
	printf("%s %s ������� � %d ����.\n", person.name, person.surname, person.yearBirth);
	
	
	// -------------------------
	
    struct   //���������� ���������� ���� ��������� ��������� � �� �������������
	{
        char dim[2];
        float x;
        float y;
        float z;
    } point1 = {"3d", 1.0f, 2.0f, 5.0f}, point2 = {"2d", 4.0f, 3.0f}; 
    
    point1 = point2; //  �������� ���������� ����������� ������
    				 //  memcpy(&point1, &point2, sizeof(point1));
    
    printf("%s %f %f\n", point1.dim, point1.x, point1.y); //2d 4.0 3.0
    printf("%s %f %f\n", point2.dim, point2.x, point2.y); //2d 4.0 3.0
    
    
    // -------------------------
    
    // �������� ������������ �������������:
    struct Person person2 = {"����", "������", 1995};
    
	struct Person* p = &person2; //������ p ��������� �� �����������
								//���������� person2
								
	printf("���: %d\n", p->yearBirth); // 1995
	
	// �������� -> ���������� ������������� (*p).yearBirth
	p->yearBirth = 2000;
	printf("���: %d\n", p->yearBirth); // 2000
	
	(*p).yearBirth = 1990;
	printf("���: %d\n", p->yearBirth); // 1990
	
	return 0;
}



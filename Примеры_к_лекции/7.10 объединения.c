#include <stdio.h>

 

  
int main()
{
	/*
		������ ����, ��� � ������� ����������� ����� ������������ � ������
		����� ���� � �� �� ������� ������ � ��� int � ��� float
	*/
	
	union 
	{
		int i;
		float f;
	} myUnion; //���������� ���������� ���� ��������� �����������
	
	myUnion.i = 5;
	printf("%d\n",myUnion.i); // 5
	
	myUnion.f = -0.5f;
	printf("%f\n",myUnion.f); // -0.5
	
	
	printf("%d\n",myUnion.i); // -1090519040 (������!)
  
  
	// -------------------------------

	/*
		� ������ ������� ������������, ��� � ������� �����������
		������ ���������� � ������ ���������� ���� int �����
		������ char[4]
	*/
	
	union typeInt //���������� ����������� (����� ������������ typedef ��� � �� struct)
	{
	  int i;
	  unsigned char b[4];
	};
	
	union typeInt value; 
  
	
	printf("N = ");
	scanf("%d", &value.i);
	
	//������� int ��-������ � 16-������ �����
	printf("%d = %x %x %x %x\n", value.i, value.b[3], value.b[2], value.b[1], value.b[0]);
  
  return 0;
}

#include <stdio.h>


void doubleInt(void* x);
void doubleFloat(void* x);
void map(void* arr, int num, size_t size, void (*fun)(void *));


float doSum(float a, float b) 
{
    return a + b;
}

float doSub(float a, float b) 
{
    return a - b;
}

int main() 
{
	//���������� func ���� ��������� �� ������� ���� float (float, float)
	float (*func)(float, float) = NULL; 
	
	//����������� ��������� �������� - ����� �������
    //��� ������ �� ������ � ��������: �������� ������ ������ ������������ �� �����
	func = doSum;
	printf("%f \n", func(1.5f, 0.2f)); //1.7
	func = doSub;
	printf("%f \n", func(1.5f, 0.2f)); //1.3
	
	
	// -----------------------------------------------------
	
	/*	
		��� void* ����� �����������, ����� �� ����� ���������� ���������
		�� �������, ��������� �������� � ������� ������ ������ � �������� ���������
	*/
	
    int a[] = {1, 2, 3, 4};
    float b[] = {1.1f, 2.2f, 3.3f, 4.4f};
    
    map(a,4,sizeof(int),doubleInt); //��������� �������� ������� a
    map(b,4,sizeof(float),doubleFloat); //��������� �������� ������� b
    
	//������� �������� ��������
    int i;
    for(i = 0; i < 4; ++i)
    	printf("%d %f \n",a[i],b[i]);
 
	// 2 2.2
	// 4 4.4
	// 6 6.6
	// 8 8.8
}


//������ �������� int ����������
void doubleInt(void* x) 
{
	*((int*) x) *= 2;
}

//������ �������� float ����������
void doubleFloat(void* x) 
{
    *((float*) x) *= 2.0f;
}

//������� ��������� ������, ��� ������, ������ ������ �������� � ��������� �� �������,
//������� ����� ����������� �� ���� ��������� �������
void map(void* arr, int num, size_t size, void (*fun)(void *)) 
{
    int i;
    char* p = arr; // �������� ��������� � ���� char* (�.�. �������� ������ � ������)
    for (i = 0; i < num; ++i) 
		//�������� ������� � ������� ����� ���������� �������� �������
		fun(p + i * size); 
}

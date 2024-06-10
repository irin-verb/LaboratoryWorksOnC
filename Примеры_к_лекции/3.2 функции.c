#include <stdio.h>
#include <math.h>

// ����� ��������� ��������������� ����������, �.�. distance ��������
// ���� ��� ������� ������
//float distance(float x1, float y1, float x2, float y2);

// ��� void ����� ������� ������� �� ���������� �������� (���������)
// �\��� �� ��������� ������� ����������
void printBeginTitle(void)
{
	printf("--------------------------\n");
	printf("������ �� ��������\n");
	printf("--------------------------\n");	
}

printEndTitle() // void � ���������� ����� ��������
{
	printf("--------------------------\n");
	printf("����� ������� �� ��������\n");
	printf("--------------------------\n");	
	
	return 0; // ��-��������� ��� ������������� �������� - int
}

int main() 
{
	system("chcp 1251");
	
	printBeginTitle();
	
	// ����� distance ������������ � ���������� - ������ ��������� ��������������� ����������!
	printf("����������: %f\n", distance(1.0f, 0.0f, 5.0f, 0.0f)); //  4.0
	
	printEndTitle();
	
	return 0;
}

// inline ������������ �����������, ��� ������ ������� �������
// �������� � ������ ����� ������, ������� ����� �� � ������
inline float sub(float a, float b)
{
	return a - b;
}

inline float distance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(sub(x1, x2), 2.0f) + pow(sub(y1, y2), 2.0f));
}

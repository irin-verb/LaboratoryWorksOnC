#include <stdio.h>

// ������� ������������ � ������� Direction
//enum Direction {RIGHT, LEFT, DOWN, UP};

// ������� ��� ������������ � ������� Direction ����� �� ������ enum
typedef enum {RIGHT, LEFT, DOWN, UP} Direction;

// ������� ���������� dir � ������������ ����� Direction
Direction dir;



//	enum Direction
//    {
//      RIGHT,  // �� ��������� = 0
//      LEFT,   // = 1
//      DOWN,   // = 2
//      UP      // = 3
//    };
  

  
//    enum Direction
//    {
//      RIGHT,    // �� ��������� = 0
//      LEFT = 4, // = 4
//      DOWN,     // = 5
//      UP        // = 6
//    };
  

  
//    enum Direction 
//    {
//      RIGHT = 8,  // = 8
//      LEFT,       // = 9
//      DOWN = 100, // = 100
//      UP          // = 101
//    };
  
    
int main() 
{
	system("chcp 1251");
	

    // ����������� ���������� dir ��������� UP
    dir = UP;
    
    //����� ����������� ��������� � �����������
    if(dir == UP) 
		puts("�����!");
	

    // ������� ���������� dir � ������������ ����� Direction
    Direction dir2 = DOWN;
    
    if(dir != dir2) 
		puts("����������� ������!");
    
    
	return 0;
}


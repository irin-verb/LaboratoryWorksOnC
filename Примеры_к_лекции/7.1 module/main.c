//main.c
#include "testlib.h"

/*
	� ������ ������� � �����main.c��� ������������ �����������stdio.h, 
	���� �� � ������������ � ������testlib.c, �.�. ������� ���� ��stdio.h�
	�� ����� ��� ���������� ��������� ���������� testlib.h, �������������� 
	�main.c��� ����� ����������.

	���� �� ��� ���� �� ���, �� ���������� ������ ���� �� ���� �������� �� � 
	testlib.c, � � testlib.h, ����� �� ���� ������, ��� ������������ ������ 
	testlib, � ��� ������ ��� ������������ ����� ���������� �������������.
*/

int WinMain()
{
    sayHello();
    return 0;
}



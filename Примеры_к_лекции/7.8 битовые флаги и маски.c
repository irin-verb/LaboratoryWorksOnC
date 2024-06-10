#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) 
{
	
	char flags = 0; // 00000000
	
	const char flag1 = 1; // 00000001
	const char flag2 = 2; // 00000010
	const char flag3 = 4; // 00000100
	
	//��������� �����
	flags = flags | flag1; 	// 00000001
	flags |= flag3; 		// 00000101
	
	//�������� �����
	bool isSet = flags & flag1; // !=0, true
	isSet = flags & flag2; // ==0, false
	
	//����� ����
	flags &= ~flag1; // 00000100
	
	//�������� (������������) ������
	flags = flags ^ flag2; // 00000110
	flags ^= flag2; // 00000100
	
	//�������� ��� �����
	flags = 0; // 00000000
	
	// -------------------
	
	// ������ � �������:
	
	//��������� ������ �� �����
	char mask = flag1 | flag2;  	// 00000011
	flags |= flag3; 				// 00000100
	flags |= mask; 					// 00000111
	
	//�������� ������ �� �����
	isSet = flags & mask == mask; // true, flag1 � flag2 �����������

	//������ ������ �� �����
	flags = flags & ~mask; //����� ����� flag1 � flag2, 00000100
	
	//�������� (������������) ������ �� ��������������� �� �����
	mask = flag2 | flag3; // 00000110
	flags = 0xff; //�������� ��� �����, 11111111
	flags = flags ^ mask; //����������� ����� �� �����: 11111001  
	flags = flags ^ mask; //����������� ����� �� �����: 11111111  
	
	// -------------------
	
	// ����� ������ ������������ ������ � ��������������:
	
	//������������ ���� ������������
	enum Rights
	{
		NONE = 0,
		READ = 1,
		WRITE = 2,
		EXECUTE = 4
	};
	
	enum Rights userRights = READ | EXECUTE; //��������� ���� �� ������ � ����������
	
	if(userRights & EXECUTE)
		printf("user can execute!");  
		
	return 0;
	
}

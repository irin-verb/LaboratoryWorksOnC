#include <stdio.h>


int main()
{
	int a=5, b=10;
	int* pointer=&a; //берЄм адрес переменной а
	
	printf("%d\n", *pointer); //pointer указывает на a: 5
	
	pointer=&b; //берЄм адрес переменной b
	printf("%d\n", *pointer); //pointer указывает на b: 10
	
	printf("%p\n", pointer); //јдрес указател€: 22fe2c
	
	//объ€вл€ем новый указатель и передаЄм ему адрес указател€ pointer
	int* pointer2=pointer;
	printf("%d\n", *pointer2 * a); // pointer2 указывает на b, b * a = 50
	
	return 0;
}

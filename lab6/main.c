#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <mem.h>
#include <ctype.h>
#include <string.h>
//функция, возвращающая ноль, если символ является маркером начала/конца слова/числа
int Marker(char S){
	int N=1;
	if ((S==' ')||(S=='.')||(S==',')||(S==';')||(S=='!')||(S=='?')||(S==':')||(S=='\"')||(S=='\0')) N=0;
	return N;}
//функция, возвращающая ноль, если последовательность является числом (целым положительным)
int Number(const char* S) {		
	int i,N;
	N=0;
	for (i=0; i<strlen(S);i++)
		if (isdigit(*(S+i))==0){
			N=1;
		}
	if (N==0)
		if (atoi(S)==0) N=1;
	return N;}
//функция, возвращающая номером заданную команду
int Command(const char* S) {
	int C=0;
	if (strcmp(S,"-info")==0) C=1;
	if (strcmp(S,"-create")==0) C=2;
	if (strcmp(S,"-delete")==0) C=3;
	return C;}
/*int info(const char* S) {	
	int k=0; //счетчик длины слова
	int MX=0; //максимальная длина
	int i;
	for (i=0; i<strlen(S); i++){
		if (isalpha(*(S+i))==0) { //при каждой встречей с не-буквой идет обнуление счетчика и проверка на максимум
			if (k>MX) MX=k;	
			k=0;
		}
		else {	//с каждой буквой счетчик увеличивается
			k++;
			if (i==strlen(S)-1 && k>MX) MX=k;}}
	return MX;}*/
//ФУНКЦИЯ, ВОЗВРАЩАЮЩАЯ МАКСИМАЛЬНУЮ ДЛИНУ СЛОВА, ВСТРЕЧАЮЩУЮСЯ В ТЕКСТЕ
int Info(const char* S) {	
	int n=0; //счетчик длины слова
	int MX=0; //максимальная длина
	int i;
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //если маркер границы слова
		if ((n!=0)&&(n>MX)) MX=n; //если до этого шло слово и его длина больше максимума
		n=0;
	}
	else {
		if (isalpha(*(S+i))!=0)
			if (n==0) {
				if (i==0) n++;
				else if (Marker(*(S+i-1))==0) n++;
					else n=0;
			}
			else {
				n++;	
			}
		else n=0; //не буква - счетчик обнуляется
	}
	return MX;
}
/*int create(const char* S, int* A, int M) {
	int i,j;
	int k=0; //количетво цифр
	int n=0; //длина цифры
	//char B[strlen(S)]; 
	char *B = (char*) malloc(strlen(S) * sizeof(char));
	for (i=0;i<strlen(S);i++)
		if (isdigit(*(S+i))==0) { //если не цифра
			if (n!=0) {
				for (j=0;j<n;j++)
					*(B+j)=*(S+i-n+j);
				*(B+n)='\0';
				if (atoi(B)<M) {
					k++;
					*(A+k)=atoi(B);}}
			n=0;}
		else { n++;
			if (i==strlen(S)-1) {
				for (j=0;j<n;j++)
					*(B+j)=*(S+i-n+j+1);
				*(B+n)='\0';
				if (atoi(B)<M) {
					k++;
					*(A+k)=atoi(B);}}}
	*A=k;
	A = (int*)realloc(A,(k+1) * sizeof(int));
	free(B);
	B=NULL;}*/
//ПОДПРОГРАММА, СОЗДАЮЩАЯ МАССИВ ЧИСЕЛ, МЕНЬШИХ ЧЕМ М
int Create(const char* S, int* A, int M) {
	int i,j;
	int k=0; //количетво цифр
	int n=0; //длина цифры
	char *B = (char*) malloc(strlen(S) * sizeof(char));// массив под текущую цифру
	if(!B) printf("Ошибка: недостаточно памяти"), exit(1);//
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //если маркер границы числа
		if (n!=0){
			for (j=0;j<n;j++)
				*(B+j)=*(S+i-n+j);
			*(B+n)='\0';
			if (atoi(B)<M){
				k++;
				*(A+k)=atoi(B);
				}
			}
		n=0;
	}
	else {
		if (isdigit(*(S+i))!=0)
			if (n==0) {
				if (i==0) n++;
				else if (Marker(*(S+i-1))==0) n++;
					else n=0;
			}
			else n++;	
		else n=0; //не цифра - счетчик обнуляется
	}
	*A=k;
	A = (int*)realloc(A,(k+1) * sizeof(int));//
	free(B); B=NULL;//
}
/*int delet(char* S, int M) {
	int i,j;
	int n=0; //счетчик длины текущего слова
	int k=0; //счетчик количества слов
	for (i=0;i<strlen(S);i++) {
		if (isalpha(*(S+i))==0) { //не буква
			if (n!=0) {
				k++;
				if (k%M==0)
				for (j=0;j<n;j++)
					*(S+i+j-n)=' ';	}
			n=0;}
		else {n++;
			if (i==strlen(S)-1) {
				k++;
				if (k%M==0)
				for (j=0;j<n;j++)
					*(S+i+j-n+1)=' ';
	}	}	}	}*/
//ПОДПРОГРАММА УДАЛЕНИЯ КАЖДОГО K-ОГО СЛОВА В СТРОКЕ
int Delet(char* S, int M){
	int i,j;
	char* C=S; //дополнительная строчка, хранящая исходную
	int n=0; //длина текущего слова
	int k=0; //номер слова
	int Begin[strlen(S)]; //массив координат начал участков копирования в новую строку
	int End[strlen(S)]; //массив окончаний координат участков
	int w=0; //текущий элемент массивов координат
	Begin[0]=0;
	//пробегаемся по строке запоминая все вхождения
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //если маркер границы слова
		if (n!=0){ //если до этого шло слово
			k++;
			if (k%M==0){
				End[w]=i-n-1; //номер символа перед началом слова и конец участка копирования
				w++;
				Begin[w]=i; //конец слова и начало нового участка копирования
			}
		}	
		n=0;
	}
	else {
		if (isdigit(*(S+i))!=0)
			if (n==0) {
				if (i==0) n++;
				else if (Marker(*(S+i-1))==0) n++;
					else n=0;
			}
			else n++;	
		else n=0; 
	}
	End[w]=strlen(S); w++;
	k=0;
	for (i=0;i<w;i++)
		for (j=Begin[i];j<End[i];j++){
			*(S+k)=*(C+j);
			k++;
		}
	*(S+k)='\0';				
}
//ОСНОВНАЯ ПРОГРАММА
int main(int argc, char** argv) {	
	system("chcp 1251");
	if (argc==1) {
		printf("Ошибка: вы не задали входных параметров\n");
		exit(1);
	}
	char* S = argv[1];
	if (strlen(S)==0) {
		printf("Ошибка: заданная строка - пустая\n");
		exit(1);
	}
	printf("ИСХОДНЫЙ ТЕКСТ: \"%s\"\n", S);
	if (argc==2) {
		printf("Ошибка: вы не ввели команду вторым аргументом\n");
		exit(1);
	}
	char* C = argv[2];
	int i;
	for (i=0; i<strlen(C); i++)
		*(C+i)=tolower(*(C+i));
	
	switch (Command(C)) {
			case 1: {
				printf("КОМАНДА: Информация\n");
				printf("РЕЗУЛЬТАТ: Максимальная длина слова, встречающаяся в тексте: %d\n",Info(S));
			} break;
			case 2: {
				printf("КОМАНДА: Создание\n");
				if (argc==3) {
					printf("Ошибка: вы не ввели число третьим аргументом\n");
					exit(1);
				}
				char* M = argv[3];
				if (Number(M)==0) {
					printf("РЕЗУЛЬТАТ: Массив чисел, меньших чем %d:\n",atoi(M));
					int *A = (int*) malloc(strlen(S) * sizeof(int)); //
					if(!A) printf("Ошибка: недостаточно памяти"), exit(1);//
					Create(S,A,atoi(M));
					for (i=1;i<=*A;i++)
						printf("%*d\t",4,*(A+i));
					free(A); A = NULL; //
				}
				else {
					printf("Ошибка: заданный третий аргумент - не целое положительное число\n");
					exit(1);
		 		}
			} break;
			case 3: {
				printf("КОМАНДА: Удаление\n");
				if (argc==3) {
					printf("Ошибка: вы не ввели число третьим аргументом\n");
					exit(1);
				}
				char* M = argv[3];
				if (Number(M)==0) {
					printf("РЕЗУЛЬТАТ: Текст с каждым %d-м удалённым в нем числом:\n",atoi(M));
					Delet(S,atoi(M));
					printf("\"%s\"\n", S);
				}
				else {
					printf("Ошибка: заданный третий аргумент - не целое положительное число\n");
					exit(1);
		 		}
			} break;
			case 0: {
				printf("Ошибка: такой заданной  команды не существует\n");
				exit(1);
			} break;		
	}
	return 0;
}

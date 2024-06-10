#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <mem.h>
#include <ctype.h>
#include <string.h>
//�������, ������������ ����, ���� ������ �������� �������� ������/����� �����/�����
int Marker(char S){
	int N=1;
	if ((S==' ')||(S=='.')||(S==',')||(S==';')||(S=='!')||(S=='?')||(S==':')||(S=='\"')||(S=='\0')) N=0;
	return N;}
//�������, ������������ ����, ���� ������������������ �������� ������ (����� �������������)
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
//�������, ������������ ������� �������� �������
int Command(const char* S) {
	int C=0;
	if (strcmp(S,"-info")==0) C=1;
	if (strcmp(S,"-create")==0) C=2;
	if (strcmp(S,"-delete")==0) C=3;
	return C;}
/*int info(const char* S) {	
	int k=0; //������� ����� �����
	int MX=0; //������������ �����
	int i;
	for (i=0; i<strlen(S); i++){
		if (isalpha(*(S+i))==0) { //��� ������ �������� � ��-������ ���� ��������� �������� � �������� �� ��������
			if (k>MX) MX=k;	
			k=0;
		}
		else {	//� ������ ������ ������� �������������
			k++;
			if (i==strlen(S)-1 && k>MX) MX=k;}}
	return MX;}*/
//�������, ������������ ������������ ����� �����, ������������� � ������
int Info(const char* S) {	
	int n=0; //������� ����� �����
	int MX=0; //������������ �����
	int i;
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //���� ������ ������� �����
		if ((n!=0)&&(n>MX)) MX=n; //���� �� ����� ��� ����� � ��� ����� ������ ���������
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
		else n=0; //�� ����� - ������� ����������
	}
	return MX;
}
/*int create(const char* S, int* A, int M) {
	int i,j;
	int k=0; //��������� ����
	int n=0; //����� �����
	//char B[strlen(S)]; 
	char *B = (char*) malloc(strlen(S) * sizeof(char));
	for (i=0;i<strlen(S);i++)
		if (isdigit(*(S+i))==0) { //���� �� �����
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
//������������, ��������� ������ �����, ������� ��� �
int Create(const char* S, int* A, int M) {
	int i,j;
	int k=0; //��������� ����
	int n=0; //����� �����
	char *B = (char*) malloc(strlen(S) * sizeof(char));// ������ ��� ������� �����
	if(!B) printf("������: ������������ ������"), exit(1);//
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //���� ������ ������� �����
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
		else n=0; //�� ����� - ������� ����������
	}
	*A=k;
	A = (int*)realloc(A,(k+1) * sizeof(int));//
	free(B); B=NULL;//
}
/*int delet(char* S, int M) {
	int i,j;
	int n=0; //������� ����� �������� �����
	int k=0; //������� ���������� ����
	for (i=0;i<strlen(S);i++) {
		if (isalpha(*(S+i))==0) { //�� �����
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
//������������ �������� ������� K-��� ����� � ������
int Delet(char* S, int M){
	int i,j;
	char* C=S; //�������������� �������, �������� ��������
	int n=0; //����� �������� �����
	int k=0; //����� �����
	int Begin[strlen(S)]; //������ ��������� ����� �������� ����������� � ����� ������
	int End[strlen(S)]; //������ ��������� ��������� ��������
	int w=0; //������� ������� �������� ���������
	Begin[0]=0;
	//����������� �� ������ ��������� ��� ���������
	for (i=0; i<=strlen(S); i++)
	if (Marker(*(S+i))==0){ //���� ������ ������� �����
		if (n!=0){ //���� �� ����� ��� �����
			k++;
			if (k%M==0){
				End[w]=i-n-1; //����� ������� ����� ������� ����� � ����� ������� �����������
				w++;
				Begin[w]=i; //����� ����� � ������ ������ ������� �����������
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
//�������� ���������
int main(int argc, char** argv) {	
	system("chcp 1251");
	if (argc==1) {
		printf("������: �� �� ������ ������� ����������\n");
		exit(1);
	}
	char* S = argv[1];
	if (strlen(S)==0) {
		printf("������: �������� ������ - ������\n");
		exit(1);
	}
	printf("�������� �����: \"%s\"\n", S);
	if (argc==2) {
		printf("������: �� �� ����� ������� ������ ����������\n");
		exit(1);
	}
	char* C = argv[2];
	int i;
	for (i=0; i<strlen(C); i++)
		*(C+i)=tolower(*(C+i));
	
	switch (Command(C)) {
			case 1: {
				printf("�������: ����������\n");
				printf("���������: ������������ ����� �����, ������������� � ������: %d\n",Info(S));
			} break;
			case 2: {
				printf("�������: ��������\n");
				if (argc==3) {
					printf("������: �� �� ����� ����� ������� ����������\n");
					exit(1);
				}
				char* M = argv[3];
				if (Number(M)==0) {
					printf("���������: ������ �����, ������� ��� %d:\n",atoi(M));
					int *A = (int*) malloc(strlen(S) * sizeof(int)); //
					if(!A) printf("������: ������������ ������"), exit(1);//
					Create(S,A,atoi(M));
					for (i=1;i<=*A;i++)
						printf("%*d\t",4,*(A+i));
					free(A); A = NULL; //
				}
				else {
					printf("������: �������� ������ �������� - �� ����� ������������� �����\n");
					exit(1);
		 		}
			} break;
			case 3: {
				printf("�������: ��������\n");
				if (argc==3) {
					printf("������: �� �� ����� ����� ������� ����������\n");
					exit(1);
				}
				char* M = argv[3];
				if (Number(M)==0) {
					printf("���������: ����� � ������ %d-� �������� � ��� ������:\n",atoi(M));
					Delet(S,atoi(M));
					printf("\"%s\"\n", S);
				}
				else {
					printf("������: �������� ������ �������� - �� ����� ������������� �����\n");
					exit(1);
		 		}
			} break;
			case 0: {
				printf("������: ����� ��������  ������� �� ����������\n");
				exit(1);
			} break;		
	}
	return 0;
}

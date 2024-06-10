#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	system("chcp 1251");	
	int A,B,C,D,E,F,S;
	printf("Введите целые переменные\n");	
	printf("A=");
	scanf("%d",&A);
	printf("B=");
	scanf("%d",&B);
	printf("C=");
	scanf("%d",&C);
	printf("D=");
	scanf("%d",&D);
	printf("E=");
	scanf("%d",&E);
	printf("F=");
	scanf("%d",&F);
  	asm("movl %0, %%ebx;"::"r" (A):"%ebx"); /* A -> ebx */
  	asm("addl %0, %%ebx;"::"r" (D):"%ebx"); /* D + ebx -> ebx *//* A+D */
  	asm("movl %0, %%ecx;"::"r" (D):"%ecx"); /* D -> ecx */
  	asm("movl %0, %%eax;"::"r" (A):"%eax"); /* A -> eax */
  	asm("imull %%ecx;":::"%ecx");           /* ecx * eax -> eax *//* A*D */
  	asm("cdq;":::"%eax", "%edx");           /* расширяем eax -> edx:eax */
  	asm("idivl %%ebx;":::"%ebx");           /* edx:eax / ebx -> eax */
  	asm("movl %%eax, %%ecx;":::"%eax", "%ecx"); /* eax -> ECX */
  	asm("movl %0, %%edx;"::"r" (E):"%edx");     /* E -> edx */
  	asm("movl %0, %%ebx;"::"r" (B):"%ebx");     /* B -> ebx */
  	asm("subl %%edx, %%ebx;":::"%ebx", "%edx"); /* ebx - edx -> ebx */
  	asm("movl %0, %%eax;"::"r" (F):"%eax");     /* F -> eax */
  	asm("cdq;":::"%eax", "%edx");               /* расширяем eax -> edx:eax */
  	asm("idivl %%ebx;":::"%ebx");               /* edx:eax / ebx -> EAX */
  	asm("subl %%eax, %%ecx;":::"%eax", "%ecx"); /* ECX - EAX -> ECX */
  	asm("movl %0, %%eax;"::"r" (C):"%eax");     /* C -> EAX */
  	asm("addl %%ecx, %%eax;":::"%eax", "%ecx"); /* ECX + EAX -> EAX */
  	asm("movl %%eax, %0;":"=r" (S)::"%eax");    /* EAX -> S */
	printf("1 Выражение %d*%d/(%d+%d)-%d/(%d-%d)+%d=%d",D,A,D,A,F,B,E,C,S);
	S=D*A/(A+D)-F/(B-E)+C;
	printf("2 Выражение %d*%d/(%d+%d)-%d/(%d-%d)+%d=%d",D,A,D,A,F,B,E,C,S);
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//������� ��� X<=A
float F1 (float x, float y, float n)
	{
	float S; S=0;
	float i;
	for (i=1;i<=n;++i) 
		S=S+(i+powf((3*x+y),i+2)/(i+1));
	S=x/2*S;
	return S;
	}
	
//������� ��� X>A
float F2 (float x, float y, float n)
	{
	float S; S=0; 
	float i;
	for (i=1;i<=n;++i) {
		S=S+powf(x,i)/(i*y+3*x);	
	}
	return S;
	}
	
//�������� ���������																									  
int main()
{
	//���� �, NM1, NM2
	system("chcp 1251");        
	float A; printf("A="); scanf("%f",&A);
	int G=A>=0?100:-100;
	printf("%d\n",G);
	int NM1;
	printf("������� ����� NM1 � ��������� [2,6], NM1=");
	do {	
		scanf("%d",&NM1);
		if ((NM1>6) || (NM1<2)) 
			printf("������: ������� NM1 � ��������� [2,6], NM1=");
		} while ((NM1>6) || (NM1<2));
	int NM2;
	printf("������� ����� NM2 � ��������� [2,6], NM2=");
	do {	
		scanf("%d",&NM2);
		if ((NM2>6) || (NM2<2)) 
			printf("������: ������� NM2 � ��������� [2,6], NM2=");
		} while ((NM2>6) || (NM2<2));									
	float N1,N2; N1=NM1; N2=NM2;
	
	//���� X0,XH,XN,Y0,YH,YN										   
	float X0;
	printf("������� ��������� �������� x, X0="); 
	scanf("%f",&X0);
	float XH;
	printf("������� ��� x, XH=");
	do {
		scanf("%f",&XH);
		if (XH<=0) 
			printf("������: ��� ������ ���� ������ ����, XH=");	
		} while (XH<=0);
	float XN;
	printf("������� �������� �������� y, XN=");
	do {
		scanf("%f",&XN);
		if (XN<=X0) 
			printf("������: �������� �������� ������ ���� ������ ����������, XN=");
		} while (XN<=X0);
	float Y0;
	printf("������� ��������� �������� y, Y0="); 
	scanf("%f",&Y0);
	float YH;
	printf("������� ��� y, YH=");
	do {
		scanf("%f",&YH);
		if (YH<=0) 
			printf("������: ��� ������ ���� ������ ����, YH=");	
		} while (YH<=0);
	float YN;
	printf("������� �������� �������� y, YN=");
	do {
		scanf("%f",&YN);
		if (YN<=Y0) 
			printf("������: �������� �������� ������ ���� ������ ����������, YN=");
		} while (YN<=Y0);
		
	//��������� � ����� ������������ � ����������� �������� �������
	float i,k;
	float YMAX,YMIN; 
	YMAX=-1.5*pow(10,-44) ; 
	YMIN=3.4*(10,37);
	float X,Y;
	for (Y=Y0;Y<=YN+YH/2;Y+=YH) 
	{
		for (X=X0;X<=XN+XH/2;X+=XH) 
		{
		if (X<=A) {
			if (F1(X,Y,N1)<YMIN) YMIN=F1(X,Y,N1);
			if (F1(X,Y,N1)>YMAX) YMAX=F1(X,Y,N1);
			printf("F(%.2f,%.2f)=%.3f\n",X,Y,F1(X,Y,N1));
			}
		else {
			k=1;                                        //
			for (i=1;i<=N2;++i)                         //�������� �� ���
				k=k*(Y*i+3*X);						    //(����������� �� ������
			if (k==0) {						  			//���� ����� ����)
			printf("F(%.2f,%.2f) �� ����������\n",X,Y);     //
			continue;}                                  //
			if (F2(X,Y,N2)<YMIN) YMIN=F2(X,Y,N2);
			if (F2(X,Y,N2)>YMAX) YMAX=F2(X,Y,N2);
			printf("F(%.2f,%.2f)=%.3f\n",X,Y,F2(X,Y,N2));
			}	
		}
	}
	printf("����������� �������� �������: %.3f\n",YMIN);
	printf("������������ �������� �������: %.3f",YMAX);
	
	
	
}


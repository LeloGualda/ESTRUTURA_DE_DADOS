#include <stdio.h>
#include <stdlib.h>
#define N 100

void imprimir();
void sortear();
int  aondeDividir();
//int ary[N] = {230,11,232,35,4,51,63,72};
int ary[N];
//int ini = 0,fim = N;
//int pivo = 0; 

int main()
{	 sortear();
	 pivo =	ary[N/2];
}

int aondeDividir(int * matriz, int ini,int fim)
{
	int pivo = matriz[fim],i,j=ini,tmp;
	
}
void imprimir()
{
	for (int i = 0; i<N;i++)
	{
		printf("%d \t",ary[i]);
	}
	printf("\n");
} 

void sortear()
{
	for (int i = 0; i<N;i++){
			ary[i] =rand() % 10 + 1;
	}
}
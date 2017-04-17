#include <stdio.h>
#include <stdlib.h>
#define N 100

void imprimir();

//int ary[N] = {230,11,232,35,4,51,63,72};
int ary[N];
void sortear();
int main()
{	
	int tmp,k=N;
	sortear();
	int qnt; 
	for (int i = 0; i<N;i++)
	{
		for (int j=1;j<k;j++)
		{imprimir();
			if(ary[i] < ary[j])
			{ qnt++;
				tmp = ary[j];
				ary[j] =  ary[i];
				ary[i] = tmp;	
				
			}
		}
		k--;
	}
	
	printf("%d",qnt);	
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
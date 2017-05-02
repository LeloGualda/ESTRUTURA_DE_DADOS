#include "stdlib.h"
#include "stdio.h"                    
#include "time.h"
#define n 8 	  //limite do vetor                    

void imprimir(int *,int);
void random(int *,int,int);
int main()
{
		
}


void imprimir(int * v,int q)
	{
		q <(n)?printf("pos %d valor: %d  \n",q,v[q++]),imprimir(v,(q)): NULL;
	}  
void random(int * v,int q,int x)
{	int a,b,c,d;
	a	=	(x*x);
	b 	=	x++;
	c	=	x-b;
	d 	=  (b*b) -(4*a*c);
	d 	= d/c;
	srand(time(NULL)-d);	
	int	r = rand()%100;	
	q <(n)?v[q++] =r,random(v,q,x):NULL;
}
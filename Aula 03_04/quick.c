#include "stdlib.h"
#include "stdio.h"                    
#include "time.h"
#define n 9 	  //limite do vetor                    
//mapa de kohonen - sort radix
/*PROTOTIPOS*/
int 	separar 	(int *,int,int);    //devolve aposicao do valor de um vetor de maneira ordenada.
void 	quickS		(int * ,int,int);  //separa e encontra a posicao atual assim ordenando 
void 	imprimir	(int *,int);
void 	random 		(int *,int,int);
/*GLOBAL*/
int contador = 0;

int main()
		{	
			int vetor[n];  				  							   //= {45,54,15,223,1,2,7,4,23} /*Exemplo:*/
			random(vetor,0,0);			                              //define vetor principal,
		//	printf("\n-Valores iniciais \n"),imprimir(vetor,0);	   	 //valor inicial
			quickS(vetor,0,n);		   								//fazer quickSorte		
			printf("\n-Resultado final \n"),imprimir(vetor,0);	   //mostrar resultado
			printf("\n-Quantidade de trocas %d \n",contador);
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
	srand(time(NULL));
	
	int	r = rand()%1000;	
	q <(n)?v[q++] =r,random(v,q,x):NULL;
}
//v:vetor, p:valor apontado,u:qnt valores a percorrer
int separar(int*v,int p,int u)
{ 
	int a = v[p],i=(p+1),t;//a:Atual|i:percorra|t:temporaria
	while(i<=u) 
	{   if(v[i]<= a)
		{
			++i;
		} 		 		 //valor atual é maior do que o percorrido então some i ++
		else if (a < v[u])
		{
			--u;
		}		//valor atual é menor que ultimo valor, ultimo u-- 
		else						   //se não substitua valor percorrido pelo ultimo valor
		{		t = v[i];
				v[i] = v[u];
				v[u] = t;
				++i;
				--u;
				contador++;
		} 
	
	}								  // continue somando i e subtraia o ultimo valor  
	v[p] = v[u], v[u] = a;           // colocando o  atual em sua devida posicao;
	contador++;
	return u;					   //  retorne a posicao do valor atual
} 					  
//v:vetor, p:valor apontado,u: qnt valores a percorrer
void quickS(int v[n], int p, int u)
{	while(p < u)
			{   int s = separar(v,p,u); // pos do valor atual
					if((s-p)<(u-s))
						{
							quickS(v,p,s-1);
							p=(s+1);
						}
					else
						{
							quickS(v,p,u);
							u=(s-1);
						}
			}
}/*(atual - separado) é < que o (ultimo - separado), quickS em separado-1, senão QuickS no ultimo.*/
#include "stdlib.h"
#include "stdio.h"
#define n 5  //limite do vetor                    
int 	separa 		(int *,int,int);  //devolve aposicao do valor de um vetor de maneira ordenada.
void 	quickS		(int * v,int,int); //separa e encontra a posicao atual assim ordenando 
void 	imprimir	(int *,int);

int main(){	int vetor[n] = {23,1,32,2,4};  // define vetor principal
				quickS(vetor,0,n-1);		 //fazer quickSorte
				imprimir(vetor,0);} 	    //mostrar resultado
	
void imprimir(int * v,int q){q <(n)?printf("pos %d com valor: %d \n",q,v[q++]),imprimir(v,(q)): NULL;}  

//v:vetor, p:valor apontado,u:qnt valores a percorrer
int separar(int*v,int p,int u){ int a = v[p],i=(p+1),t;//a:Atual|i:percorra|t:temporaria
	while(i<=u) 
	{   if 		(v[i]<= a)	++i	; 		 //valor atual é maior do que o percorrido então some i ++
		else if (a < v[u]) 	--u	;		//valor atual é menor que ultimo valor, ultimo u-- 
		else						   //se não substitua valor percorrido pelo ultimo valor
		{		t = v[i], v[i] = v[u], v[u] = t;
				++i; --u;} 		     // continue somando i e subtraia o ultimo valor  
	}
	v[p] = v[u], v[u] = a;         // colocando o  atual em sua devida posicao;
	return u;} 					  //  retorne a posicao do valor atual
//v:vetor, p:valor apontado,u: qnt valores a percorrer
void quickS(int * v, int p, int u)
{	while(p < u){   int s = separar(v,p,u); // pos do valor atual
					(s-p)<(u-s)?quickS(v,p,s-1),p=(s+1):quickS(v,p,u),u=s-1;}
}//(atual - separado) é < que o (ultimo - separado), quickS em separado-1, senão QuickS no ultimo.

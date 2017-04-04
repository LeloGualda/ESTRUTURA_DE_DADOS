#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/* 
Objetivo 
	Criar uma calculadora de pilha  	
*/ 


//Constantes 

#define QNT 10
 
// Estruturas 
 
 typedef enum sinal
 {	
	 mult 	= -6,	// 		*
	 divsor = -1,	// 		/
	 soma 	= -5,	//		+
	 subs 	= -3	//		-
 } sinal;
 
 typedef struct
 {	 
	 char string[QNT];
 }String;
 
typedef struct
{
	float 	n1;
	float 	n2;
	float 	r;
	sinal 	s;	
}operacao;

// Global

char 	resolva			[QNT];
char 	char_nunAtual	[QNT];
int  	numeros			[QNT];
int  	operador		[QNT];

operacao ops[5];

//Prototipo
void Inicializar();
void Resposta(operacao *);

int main(void)
{ 
Inicializar();	
/*
	operacao op1;
		op1.n1 = 2; 
		op1.n2 = 3;
		op1.s = -6;
	Resposta(&op1);
 	
	printf("%f",op1.r);

	int n = 1;
do{
	

	 n = resolva[0]  - '0';
	printf("%d",n);
} while(!n == 0);
	
	*/

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

		char aux_resolva[QNT];


//	printf("\n Digita a conta \n");
	//scanf("%s",&resolva);
		
		strcpy(resolva,"(22-2)*3+333+22");
	//	strcpy(aux_resolva,resolva);
		
		int vrf_numero;
		int qntNum = 0, numIni =0;
		
		
		for(int i = 0; i < QNT; i++)
		{
			
			vrf_numero 	= 	resolva[i]  - '0';
			

					
			if(vrf_numero < 0 ||   9 < vrf_numero)
			{
				if(qntNum >0)
				{
					
					int valRel = atoi(char_nunAtual);
					printf("%d",valRel);
					qntNum = 0;
					for(int k = 0; k < QNT; k++)char_nunAtual[k] = '0';
					
				}
						
			/*	if(qntNum >0)
				{
					for(int k = 0; k < qntNum; k++)
					{
						char_nunAtual[k] = resolva[(numIni-1)+k];
						
						printf("\n %c",resolva[(numIni-1)+k]);
					}
						printf("\n qntNum %d",qntNum);
						printf("\t numIni %d",(numIni-1));
						printf("\n %s",char_nunAtual);
									}
			*/
					
			}
			else
			{
				char_nunAtual[qntNum] = resolva[i];
				qntNum++;
				printf("\n %d",vrf_numero);
				//printf("\n %d",vrf_numero);
				// @@@@@@@@@@@@@@@@@ fazer a lista de numeros para amarzenas na pilha de operacoes
				
			}
			
		}
		

	
	return(0);
}


void Inicializar()
{
	for(int i = 0; i < QNT; i++)
		{
//			resolva[i]  = ' ';
		}
}
void Resposta(operacao * op)
{
	float aux;
	switch(op->s)
	{
		case mult: 		op->r = op->n1 * op->n2;
			break;
		case divsor:	op->r = op->n1 / op->n2;
			break;
		case soma:		op->r = op->n1 + op->n2;
			break;
		case subs:		op->r = op->n1 - op->n2;
			break;
	}
}
String Separa(char criterio)
{
	String c;
	strcpy (c.string,"");
	for(int i = 0; i < QNT; i++) 
		{	
			if(resolva[i] == criterio)
			{	
				char aux_resolva[QNT];
				for(int k = (i+1); k < QNT; k++)
				{
					if(resolva[k] == criterio) k = QNT;
					else
					{
						aux_resolva[(k-i-1)] = resolva[k];
					}					
				}
				strcpy (c.string,aux_resolva);
			}
		}
	return (c);
}


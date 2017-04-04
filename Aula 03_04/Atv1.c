#include <stdio.h>
#include <stdlib.h>
#define N 10


//global
int 	MinhaLista[N],u=0,p=0,cheio=0;

//prototipo
void 	Inserir();
void 	Consumir();
void 	Imprimir();
int 	menu();
int 	DigiteValor();

int main()
{	

	for(int i=0;i<N;i++)MinhaLista[i] =	0;
	
	int opcao;
	
	do { 	opcao = menu();
	
			switch (opcao) 
			{
				case 0:
						return(0);				
					break;				
				case 1:
						Inserir();
					break;
				case 2:
						Consumir();
				break;
				case 3:
						Imprimir();
				break;				
				default: printf ("Invalido");
			}
		} while (opcao != 0);

		}

int 	DigiteValor()
{		int opc = 0; 
		printf("\n *------------- \t DIGITE O VALOR \t -------------* \n\n");			
		scanf("%d",&opc);
		return opc;
}
int 	menu() 
{
	printf("\n *------------- \t SUAS OPCOES \t\t -------------* \n");
	printf("\n\n\t 1 \t INSERIR");
	printf("\n\t 2 \t COMSUMIR ");
	printf("\n\t 3 \t IMPRIMIR \n");
	return DigiteValor();
}


void 	Inserir()
{
	printf("\n *------------- \t VAMOS ISERIR \t\t -------------* \n");
	if(cheio == 1) {printf("\n CHEIO \n");return;}
	 MinhaLista[u++] = DigiteValor();
		u = u % N;
		cheio = u == p ? 1:0;
		Imprimir();
	
}

void 	Consumir()
{
	MinhaLista[p++] = 0;
	p = p % N;
	printf("\n\n *------------- \t VALOR CONSUMIDO! \t\t -------------* \n\n");
	Imprimir();
}

void	Imprimir()
{			printf("\n\n *------------- \t  - - - - - - - - \t\t -------------* \n\n");
		for(int i=0;i<N;i++)printf("%d \t",MinhaLista[i]);
		printf("\n");
		for(int i=0;i<u;i++)printf("- \t");
		printf("u \n");
		for(int i=0;i<p;i++)printf("- \t");
		printf("p");
			printf("\n\n *------------- \t  - - - - - - - - \t\t -------------* \n\n");
}
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
/* 
 
Criar banco de dados
	Com o numero da conta automatico
	deposito
	sacar
	imprimir
	apagar conta
	sair
	
*/

#define N 5

typedef struct  
{
		int cod;
		char nome[32];
		float saldo;
}conta;
//prototipo de funcao

	int menu();
	conta * Buscar();

	void Imprimir (conta *); 
	void Reajustar(conta *, float);
	void Sacar(conta*);
	void Deposito(conta*);
	void ApagarConta(conta *);
	void Criar();
	void Inicializar();
	void Consultar(conta *);
	void Listar();

// GLOBAL
	conta cs[N];
	int proxCod = 1;

int main (void)
{	

int opcao;
conta *contAtual;
Inicializar();

	do { 	opcao = menu();
	system ("CLS");
			switch (opcao) 
			{
				case 0:
						return(0);				
					break;
				
				case 1:
						Criar();
					break;
				case 2:
				
					contAtual =	Buscar();
					
					if(contAtual == NULL) break;			
					else Consultar(contAtual);
					break;
					
				case 3: 
					
					Listar();
					
					break;
					
				case 4:
					contAtual =	Buscar();
					
					if(contAtual == NULL) break;			
					else ApagarConta(contAtual);
					
					break;
					
				case 5:
					contAtual =	Buscar();
					
					if(contAtual == NULL) break;			
					else Deposito(contAtual);
					
					break;
				
				case 6:
					contAtual =	Buscar();
					
					if(contAtual == NULL) break;			
					else Sacar(contAtual);
					
					break;
				
				default: printf ("Invalido");
			}
		} while (opcao != 0);

	return(0);
}

int menu() 
{
	int opc = 0; 
	printf("\n *------------- \t Digite a operacao que deseja realizar \t -------------* \n");			
	printf("\n\n\t 1 \t Criar");
	printf("\n\t 2 \t Consultar");
	printf("\n\t 3 \t Listar");
	printf("\n\t 4 \t Apagar");
	printf("\n\t 5 \t Depositar");
	printf("\n\t 6 \t Sacar");
	printf("\n\t 0 \t Sair \n");

	scanf("%d",&opc);
	return opc;
}
void  Inicializar()
{
	for(int i = 0; i < N; i++) 
	{
		cs[i].cod = -1;
	}
} 

void Criar()
{
	for(int i = 0; i < N; i++) 
		{
			
			if (cs[i].cod == -1) 	
			{
					cs[i].cod = proxCod++;
					printf("\n *------------- \t Digite o nome do cliente \t -------------* \n");
					char nomeCliente[32];
					scanf("%s", &nomeCliente);
					strcpy(cs[i].nome,nomeCliente);
					cs[i].saldo = 0.0;
					//criado com sucesso! 
					printf("\n *------------- \t Conta criada com sucesso. \t -------------* \n");
					Imprimir(&cs[i]);
					
				return;
			}
		}
	printf("\n *------------------- \t Ja tem 5 usuarios. \t\t ---------------* \n");
}

void Consultar(conta * c)
{
	printf("\n *------------------- \t Conta consultada. \t\t ---------------* \n");
	Imprimir(c);

}
void Imprimir (conta * c) 
{
	printf("\n Nome: %s \t", c->nome);
	printf("\n Saldo: %0.2f \t", c->saldo);
	printf("\n Codigo: %d \t", c->cod);

}

void Reajustar(conta * c, float taxa)
{
	c->saldo = c->saldo * taxa;
}

void Sacar(conta * c)
{
	float v;
	printf("\n *------------- \t Digite o valor a sacar \t -------------* \n");
	scanf("%f",&v);
	if((c->saldo - v) <0) printf("\n *------------- \t Nao tem saldo o suficiente \t -------------* \n");
	else {
		c->saldo = c->saldo - v;
		printf("\n *------------- \t Saque realizado com sucesso! \t -------------* \n");
	}
}
void Deposito(conta * c)
{
	float v;
	printf("\n *------------- \t Digite o valor do depoisito \t -------------* \n");
	scanf("%f",&v);
	c->saldo = c->saldo + v;
	printf("\n *------------- \t Deposito realizado com sucesso! \t -------------* \n");
}
void ApagarConta(conta * c)
{
	int q=0;
	do{
		system("CLS");
		printf("\n *------------- \t Deseja mesmo apagar esta conta? \t -------------* \n");
		Imprimir(c);
		printf("\n\n *------------- \t ------------------  \t\t -------------*");
		printf("\n \t 1\t Para cancelar a operacao.");
		printf("\n \t 2\t Para apagar a conta.\n");
		scanf("%d",&q);
		
		switch(q)
		{
			case 1:
				
				printf("\n *------------- \t Operacao cancelada com sucesso! \t -------------* \n");
				
				break;
				
			case 2:
					c->cod = -1;
					c->saldo = 0.0;
					strcpy (c->nome, "");
					printf("\n *------------- \t Conta apagada com sucesso! \t -------------* \n");
				
				break;
			default:
				q = 0;
//				printf("\n *------------- \t Opcao invalida! \t -------------* \n");
			
			break;
		}
	} while (q == 0);	
}

conta * Buscar() 
{
	int i,codi;
	
	printf("\n *------------------- \t Digite o codigo da conta: \t ---------------* \n");
		scanf("%d",&codi);
	for(i = 0; i < N; i++) 
	{
		if(cs[i].cod == codi)
		{
			return &cs[i];
		}
	}
	printf("\n *------------- \t Conta nao encontrada!  \t -------------*");

	
	return NULL;
}

void Listar()
{
	int  auxQNT = 0;
	
	printf("\n *------------- \t Sua lista de cliente(s): \t -------------* \n");

	for(int i = 0; i < N; i++) 
	{
		if(cs[i].cod > 0)
		{
			auxQNT++;
			printf("\n\n *------------- \t ------------------  \t\t -------------*");
			Imprimir(&cs[i]);
			
		}
	}
	if(auxQNT == 0)	printf("\n *------------- \t Nenhum cliente encontrado. \t -------------* \n");
	else printf("\n *------------- \t Encontrado(S) %d clientes \t -------------* \n",auxQNT);
	
}
 
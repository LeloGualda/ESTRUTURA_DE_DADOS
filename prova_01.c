#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* 
	Elabora em Sistema eletrônico bancário
	
	Onde o cliente possua as 
		opções: 
				-saque 
				-depósito 
				-compra de ações
				-emprestimo pessoal 10%
				-consultar o saldo 
	
		gerentes:
				-Relatório por saldo
				-Consulta por cliente
	
	Para acessar o sistema o menu
				-Nome do Cliente
				-Senha Alfanumérica (5 posições)
		caso errar 3 tentativas, o cliente não poderá ter acesso ao sistema.
	
		- O cliente pode acessar o menu quantas vezes for chamado. 
		- Ao final de cada operação monstrar o saldo do cliente. 
		- com sistem aberto qualquer cliente  pode  fazer uso
		- As opções de relatório só poderam ter acesso ao gerente
		
		- RELATÓRIO POR CLIENTE: Ordenação por ordem Alfabética, utilizando método Shell
		- RELATÓRIO POR SALDO: Ordenação  decrescente, utilizando método de Inserção
		- CONSULTA POR  CLIENTE: Ordenação método de pesquisa Sequencial 
		
*/

// estruturas

typedef struct 
{
  char  nome[30];
  float saldo;
  char  senha[5];
  int   tentativas;
  int   gerente;
}cliente;

//global
cliente clientes[5];
char  usario[30];
cliente * logado;

//prototipo
void inicio();
int logar();
cliente * BuscaCliente(char[]);
void menu(int);
void imprimir();
int Menu();
void Sacar(float);
void Deposito(float);
void ComprAcao();
void Emprestimo();
void Relatorio_Saldo();	
void Relatorio_Clientes();
void Rel_BuscaCliente();

int main()
{
  inicio();
  int  operando = 1;
  int l=0;
  int op=0;
  do
  {
    if(l==0)l=logar();
    else if(l == 2)operando=0;
	else
    {   
	   printf("\n LOGADO: %s \n \n",logado->nome);
       op = Menu();
      if(logado->gerente == 1)
      {
        
        switch(op)
        { 
			case 0:l = 0;
				break;
			case 1:Relatorio_Saldo();
				 break;
			case 2:Relatorio_Clientes();
				break;
			case 3:  Rel_BuscaCliente();
				break;
			  default: printf("Opcao invalida");
		  break;
		}  
        
      }
      else
      {
        
        switch(op)
        { 
          case 0:l = 0;
            break;
          case 1:Sacar(0);
            break;
          case 2:Deposito(0);
            break;
          case 3:ComprAcao();
            break;
          case 4:Emprestimo();
            break;
          case 5:printf("Saldo atual: %f \n",logado->saldo);
            break;
		  default: printf("Opcao invalida");
		  break;
        }
        printf("Saldo atual: %f \n",logado->saldo);
      }
    }
	
  }while(operando != 0);
	return(0);
}

void imprimir()
{
  for(int i = 0; i<6;i++){
  printf("Nome: %s \t Tipo: %d  \t Saldo: %s \n  " ,clientes[i].nome,clientes[i].gerente,clientes[i].senha);
  }
}

void Sacar(float v)
{
if(v ==0){
  if(logado->saldo <= 0)
  {
    printf("saldo insuficiente! \n"); 
    return;
  }
  
  printf("DIGITE O VALOR A SACAR \n");
  scanf("%f",&v);
}  
  if(logado->saldo <= v)
  {
    printf("saldo insuficiente! \n"); 
    return;
  }
     logado->saldo = (logado->saldo -v);
     return;
  
   
}

void Deposito(float v)
{

if(v == 0){
  printf("DIGITE O VALOR A DEPOSITAR \n");
  scanf("%f",&v);
  
  if(v <= 0)
  {
    printf("Valor indevido \n"); 
    return;
  }
}
     logado->saldo = (logado->saldo +v);
     return;
}

int logar()
{     
      cliente * atual;  
      char senhaUser[5];
	  
		printf("PARA ENCERRAR A OPERACÃO DO CAIXA DIGITE 0 \n");
  
    	
		printf("ENTRAR NA SUA CONTA:: \n");
    	printf("DIGITE SEU NOME: \n \n");
    	printf("deve ter a primeira letra Maiuscula! \n \n");
		
		
    	scanf("%s",&usario);
		if(strcmp(usario,"0") ==0)
		{	printf("CAIXA DESLIGANDO...");
			return(2);
		};
		atual =	BuscaCliente(usario);
      
    	if(atual == NULL)
    	{
    	  	printf("Usario nao encontrado \n"); 
    	  	return (0);
    	}
    	else if(atual->tentativas < 1)
    	{
    	  printf("PROCURAR SUA ARGENCIA PARA REGURALIZAR. \n");
    	  return (0);
    	  
    	}
    	else
    	{
    	  printf("DIGITA A SENHA: \n");
    	  scanf("%s",&senhaUser);
    	  
    	  if(strcmp(senhaUser,atual->senha) != 0)
    	  {
    	    printf("Senha invalida\n");
    	    atual->tentativas --;
    	    printf("restam %d tentativas \n",atual->tentativas);
    	    return (0);
    	  }
    	  else
    	  {   
    	    cliente * aux;
    	    aux = logado; 
    	    logado = atual;
    	    atual = aux;
    	      return(1);
    	  }
    	}
}

int Menu()
{ int r;
  if(logado->gerente ==1)
  {
    printf("DIGITE:: \n");
    printf("1  \t RELATORIO SALDO  \n");
    printf("2  \t RELATORIO CLIENTE   \n");
    printf("3  \t BUSCA DE CLIENTE  \n");
    printf("0  \t SAIR  \n");
  }
  else
  { 
    printf("DIGITE:: \n");
    printf("1  \t SAQUE  \n");
    printf("2  \t DEPOSITO  \n");
    printf("3  \t COMPRA DE ACAO  \n");
    printf("4  \t EMPRESTIMO PESSOAL  \n");
    printf("5  \t SALDO  \n");
    printf("0  \t SAIR  \n");
  }
  scanf("%d",&r);
  return(r);
}


cliente * BuscaCliente(char nome[30])
{
  for(int i = 0; i<=5 ; i++)
  {
    if(strcmp(nome,clientes[i].nome)== 0)
    { 
      return &clientes[i];
    }
  }
  return (NULL);
}

void ComprAcao()
{
  float v;
  printf("DIGITE O VALOR DA ACAO \n");
  scanf("%f",&v);
  Sacar(v);
  printf("ACAO COMPRADA! \n");
}
void Emprestimo()
{
  float v;
  float j;
  printf("DIGITE O VALOR DO EMPRESTIMO \n");
  scanf("%f",&v);
  j = v * 0.1;
  v = (v - j);
  Deposito(v);
  printf("EMPRESTIMO REALIZADO JUROS DE 10 pnt \n");
}

void inicio()
{
  strcpy (clientes[0].senha,"50005"); 
  strcpy (clientes[1].senha,"x111x");
  strcpy (clientes[2].senha,"s222s");
  strcpy (clientes[3].senha,"c333c");
  strcpy (clientes[4].senha,"a444a");
  strcpy (clientes[5].senha,"e555e");
  
  clientes[0].saldo = 00;
  clientes[1].saldo = 5000;
  clientes[2].saldo = 2350;
  clientes[3].saldo = 10200;
  clientes[4].saldo = 7350;
  clientes[5].saldo = -2500;
 
  clientes[0].gerente = 1;
  clientes[0].tentativas = 3; 
 
  for(int i = 0; i < 6;i++)
  {
    clientes[i].tentativas = 3;
//    clientes[i].acoes = NULL;
//    clientes[i].emprestimo = NULL;
  }
   
  strcpy (clientes[0].nome,"Soul");
  strcpy (clientes[1].nome,"Xavier");
  strcpy (clientes[2].nome,"Silvia");
  strcpy (clientes[3].nome,"Celio");
  strcpy (clientes[4].nome,"Adao");
  strcpy (clientes[5].nome,"Ester");

}

void Relatorio_Saldo()
{
	int t=6,i,j,min;
	cliente aux;
	
  for(i =0; i<t;i++)
  { min = i;
    for(j=(i+1); j<t;j++)
    {
      if(clientes[j].saldo < clientes[min].saldo)
      {
        min = j;
      }
    }
    if(min != i)
    {
      aux = clientes[i];
      clientes[i] = clientes[min];
      clientes[min] = aux;
     
    }
  }
  
	logado = BuscaCliente("Soul");
	
	printf(" ****** RELATORIO DOS SALDOS ***** \n");
	for(int k = 0; k<6;k++)
	{	if(clientes[k].gerente !=1)printf("Nome: %s \t Saldo: %f \n" ,clientes[k].nome,clientes[k].saldo);
	}
}
void Rel_BuscaCliente()
{	char nome[30];
	cliente * atual;
	printf("DIGITE O NOME DO CLIENTE \n");
	
	scanf("%s",&nome);
	
	atual =	BuscaCliente(nome);
      
    	if(atual == NULL)
    	{
    	  	printf("Usario nao encontrado \n"); 
    	  	return;
    	}
		else
		{	printf(" ****** DADOS DO CLIENTE ***** \n");
			printf("Nome: %s \n",atual->nome);
			printf("Saldo: %f \n",atual->saldo);
			printf("tentativas para logar : %d \n",atual->tentativas);
			
		}
}
void Relatorio_Clientes()
{
		int i , j, h = 6;
    cliente aux,aux2;
    do
    {
        h = h / 2;
        for (i = h; i < 6; i++)
        {
            j = i;
            aux = clientes[i];
		
				while ((j >= h) && (strcmp(clientes[j-h].nome, aux.nome) > 0))
				{	
					
					clientes[j] = clientes[j-h];
					j = j - h;
				}
				clientes[j] = aux;
			
		}
    }while (h > 1);
	
	logado = BuscaCliente("Soul");
	printf(" ****** RELATORIO DE CLIENTES ***** \n");
	for(int k = 0; k<6;k++)
	{	if(clientes[k].gerente !=1)printf("Nome: %s \t Saldo: %f \n" ,clientes[k].nome,clientes[k].saldo);
	}
}

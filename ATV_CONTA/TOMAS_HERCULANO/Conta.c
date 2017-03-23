#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//definiçao da estrutura conta com lista
typedef struct
{
    int codigo;
    char nome[30];
    float saldo;
    float limite;

    //ponteiro para o proximo elemento
    struct conta * proximo;

} conta;

//global
conta * cabecalho = NULL;
int prox_cod = 1;

//prototipo das funções
int menu();
void criar();
void listar();
void imprimir(conta * c);
void buscar();
void depositar();
void sacar();
void excluir();

int main()
{
    int opcao, aux=0;

    do{
        opcao = menu();
        switch(opcao)
        {
            //sair
            case 0:
                system("cls");
                printf("\nAte mais!");
                return 0;
                break;

            //criar
            case 1:
                criar();
                break;

           //depositar
            case 2:
                depositar();
                break;

            //sacar
            case 3:
                sacar();
                break;

            //excluir
            case 4:
                excluir();
                break;

            //buscar
            case 5:
                buscar();
                break;

            //listar
            case 6:
                listar();
                break;

            //opcao invalida
            default:
                system("cls");
                printf("\nOpcao invalida!");
        }
    }while(aux==0);
}

//funcao menu
int menu()
{
    int op;

    printf("\n...:::MENU:::...\n");
    printf("\n0 - SAIR");
    printf("\n1 - Criar");
    printf("\n2 - Depositar");
    printf("\n3 - Sacar");
    printf("\n4 - Excluir ");
    printf("\n5 - Buscar");
    printf("\n6 - Listar \n");
    scanf("%d", &op);

    return op;
}

//funcao criar
void criar()
{
    //1. aloca um espaço na memoria do tamanho de uma conta
    //2. o sistema operacional volta um ponteiro, e fazemos a conversao deste espaco em ponteiro de conta (CAST)
    conta * novo = (conta *)malloc(sizeof(conta));
    novo->codigo = prox_cod;
    novo->saldo = 0.0;
    novo->limite = 100;
    printf("\nNome: ");
    scanf("%s", &novo->nome);
    prox_cod +=1;
    novo->proximo = NULL;

    if(cabecalho == NULL)
    {
        cabecalho = novo;
    }
    else
    {
        conta * atual = cabecalho;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;


    }
    printf("\nCodigo: %d\nInserido com sucesso!", novo->codigo);
    getch();
    system("cls");
}


//funcao buscar
void buscar()
{
    int cod = 0, aux = 0;
    printf("Codigo: ");
    scanf("%d", &cod);

    conta * atual = cabecalho;

    while (atual != NULL)
    {
        if (atual->codigo == cod)
        {
            imprimir(atual);
            aux = 1;
        }
        atual = atual->proximo;
    }

    //conta nao existe
    if (aux == 0)
    {
        printf("\nConta nao existe\n");
    }
    getch();
    system("cls");
}


//funcao imprimir
void imprimir(conta * c)
{
    if (c == NULL)
	{
		printf("\nConta nao existe\n");
	}
	else
    {
        printf("\ncodigo: %d", c->codigo);
        printf("\nnome..: %s", c->nome);
        printf("\nsaldo.: %0.2f\n", c->saldo);
    }
}


//funcao listar
void listar()
{
    conta * atual = cabecalho;
    while (atual != NULL)
    {
        imprimir(atual);
        atual = atual->proximo;
    }
    getch();
    system("cls");
}



//funcao excluir
void excluir()
{
    int cod = 0, aux = 0;
    printf("Codigo: ");
    scanf("%d", &cod);

    conta * anterior = NULL;
    conta * atual = cabecalho;

    //liberando o espaco da memoria
    while (atual != NULL)
    {
        if ((atual == cabecalho) && (atual->codigo == cod))
        {
            printf("Exclusao realizada com sucesso!");
            cabecalho = atual->proximo;
            free(atual);
            atual = NULL;
            aux = 1;
        }
        else
        {
            if (atual->codigo == cod)
            {
                printf("Exclusao realizada com sucesso!");
                anterior->proximo = atual->proximo;
                free(atual);
                atual = NULL;
                aux = 1;
                break;
            }

            if (aux == 0)
            {
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }

    //conta nao existe
    if (aux == 0)
    {
        printf("\nConta nao existe\n");
    }
    getch();
    system("cls");


}

//funcao depositar
void depositar()
{
   int cod = 0, aux = 0;
   float valor_dep;
   printf("\nCodigo: ");
   scanf("%d", &cod);
   printf("\nValor: ");
   scanf("%f", &valor_dep);

   conta * atual = cabecalho;

    while (atual != NULL)
    {
        if (atual->codigo == cod)
        {
            printf("Deposito efetuado com sucesso!");
            atual->saldo += valor_dep;
            aux = 1;
        }
        atual = atual->proximo;
    }

    //conta nao existe
    if (aux == 0)
    {
        printf("\nConta nao existe\n");
    }
    getch();
    system("cls");
}

//funcao sacar
void sacar()
{
    int cod = 0, aux = 0;
    float valor_saq;
    printf("\nCodigo: ");
    scanf("%d", &cod);
    printf("\nValor: ");
    scanf("%f", &valor_saq);

    conta * atual = cabecalho;

    while (atual != NULL)
    {
        if (atual->codigo == cod)
        {
            if (((atual->saldo)+(atual->limite)) >= valor_saq)
            {
                printf("Saque efetuado com sucesso!");
                atual->saldo -= valor_saq;
                aux = 1;
            }
            else
            {
                printf("Saldo insuficiente!");
                aux = 1;
            }
        }
        atual = atual->proximo;
    }

    //conta nao existe
    if (aux == 0)
    {
        printf("\nConta nao existe\n");
    }
    getch();
    system("cls");
}

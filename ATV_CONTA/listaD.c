#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct conta {
    int codigo;
    char nome[30];
    float saldo;
    float limite;
 
    struct conta * anterior;
    struct conta * proximo;
} conta;
 
 
conta * cabecalho = NULL;
int proximoCodigo = 1;
 
int menu();
void criar();
void listar();
conta * buscar();
void imprimir(conta * c);
void apagar();
 
int main()
{
    int opcao = 0;
    do
    {
        opcao = menu();
        conta * tmp;
        switch(opcao) {
            case 0: break;
            case 1:
                criar();
                break;
            case 2:
                imprimir(buscar());
                break;
            case 3:
                listar();
                break;
            case 4:
                apagar();
                break;
            case 5:
            case 6:
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}
 
int menu()
{
    int opc = 0;
    printf("\n\nIBTA");
    printf("\n--------");
    printf("\n1. Criar");
    printf("\n2. Consultar");
    printf("\n3. Listar");
    printf("\n4. Apagar");
    printf("\n5. Depositar");
    printf("\n6. Sacar");
    printf("\n0. Sair");
    printf("\nDigite a opcao: ");
    scanf("%d", &opc);
    return opc;
}
 
conta * buscar()
{
    int cod = 0;
    printf("Digite o codigo: ");
    scanf("%d", &cod);
     
    conta * atual = cabecalho;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
 
void imprimir(conta * c)
{
    if (c == NULL)
    {
        printf("\nConta nao existe\n");
        return;
    }
    printf("\ncodigo.: %d", c->codigo);
    printf("\nnome...: %s", c->nome);
    printf("\nsaldo..: %f", c->saldo);
    printf("\nlimite.: %f", c->limite);
}
 
void criar()
{
 
    // 1. aloca um espaco na memoria de tamanho conta
    // 2. volta um ponteiro, e fazemos a conversao deste espaco em ponteiro de conta (CAST)
//ime usp pilha
    conta * novo = (conta *) malloc(sizeof(conta));
    novo->codigo = proximoCodigo++;
    novo->saldo = 0.0;
    novo->limite = 100;
 
    printf("Nome: ");
    scanf("%s", novo->nome);
    novo->anterior = NULL;
    novo->proximo = NULL;
 
    if (cabecalho == NULL)
    {
        cabecalho = novo;
    } else {
        conta * atual = cabecalho;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->anterior = atual;
    }
    printf("Inserido com sucesso! Codigo: %d\n", novo->codigo);
}
 
void listar()
{
    conta * atual = cabecalho;
    while (atual != NULL)
    {
        imprimir(atual);
        atual = atual->proximo;
    }
}
 
void apagar()
{
    int cod = 0;
    printf("Digite o codigo: ");
    scanf("%d", &cod);
     
    conta * atual = cabecalho;
    if (atual != NULL && atual->codigo == cod)
    {
        // para o caso de ser o primeiro
        cabecalho = atual->proximo;
		cabecalho->anterior = NULL;
        free(atual);
        return;
    }
    while (atual != NULL && atual->proximo != NULL)
    {
        conta * analisado = atual->proximo;
        if (analisado->codigo == cod) 
        {
            // encontrei o elemento
            atual->proximo = analisado->proximo;
			atual->anterior = analisado->anterior;
            free(analisado);
            return;
        }
        atual = atual->proximo;
    }
    printf("Conta nao encontrada!");
}
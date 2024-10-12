#include <stdlib.h>
#include <stdio.h>

void teste();

#define MAX 10

typedef struct Pilha
{
    int data;
    struct Pilha *next;
} Pilha;

int main()
{
    int x = 42;
    teste();
    return 0;
}

void teste()
{
    Pilha *top = NULL;        // Ponteiro que aponta para o topo da pilha, inicialmente nulo
    char inteiro[] = "%d\n"; // array de caracteres para formar a string
    

    if (top == NULL || (top != NULL && top->data < MAX))
    {
        int value = 1;

        // Cria um novo nó e aloca memória para ele
        Pilha *newPilha = (Pilha *)malloc(sizeof(Pilha));
        newPilha->data = value; // Armazena o valor no novo nó
        newPilha->next = top;   // Faz o novo nó apontar para o antigo topo
        top = newPilha;         // Atualiza o topo para o novo nó

        // Mensagem de sucesso
        printf(inteiro, value);
    }
    else
    {
        // Mensagem se a pilha estiver cheia
        printf("Pilha cheia!\n");
    }
}
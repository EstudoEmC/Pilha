#include <stdio.h>
#include <stdlib.h>

// Define o tamanho máximo da pilha (não utilizado aqui, mas pode ser útil)
#define MAX 10

// Estrutura que representa um nó da pilha
typedef struct Node {
    int data;           // Valor armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

int main() {
    Node* top = NULL; // Ponteiro que aponta para o topo da pilha, inicialmente nulo
    int choice, value; // Variáveis para armazenar a escolha do usuário e o valor a ser empilhado

    // Loop principal do programa
    while (1) {
        // Exibe o menu de opções
        printf("1. Empilhar\n2. Desempilhar\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &choice); // Lê a escolha do usuário

        switch (choice) {
            case 1: // Opção para empilhar
                // Verifica se a pilha está cheia (condição simples, pode ser expandida)
                if (top == NULL || (top != NULL && top->data < MAX)) {
                    printf("Digite o valor a ser empilhado: ");
                    scanf("%d", &value); // Lê o valor a ser empilhado

                    // Cria um novo nó e aloca memória para ele
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = value; // Armazena o valor no novo nó
                    newNode->next = top;   // Faz o novo nó apontar para o antigo topo
                    top = newNode;         // Atualiza o topo para o novo nó

                    // Mensagem de sucesso
                    printf("Valor %d empilhado.\n", value);
                } else {
                    // Mensagem se a pilha estiver cheia
                    printf("Pilha cheia!\n");
                }
                break;

            case 2: // Opção para desempilhar
                // Verifica se a pilha não está vazia
                if (top != NULL) {
                    // Armazena o nó do topo em uma variável temporária
                    Node* temp = top;
                    top = top->next; // Atualiza o topo para o próximo nó

                    // Mensagem mostrando o valor desempilhado
                    printf("Valor %d desempilhado.\n", temp->data);
                    free(temp); // Libera a memória do nó desempilhado
                } else {
                    // Mensagem se a pilha estiver vazia
                    printf("Pilha vazia!\n");
                }
                break;

            case 3: // Opção para sair do programa
                printf("Saindo...\n");
                return 0; // Termina o programa

            default: // Opção inválida
                printf("Opção inválida!\n");
        }
    }

    return 0; // Retorno padrão da função main
}

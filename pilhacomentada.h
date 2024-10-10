// pilhaE.h - TAD que implementa uma pilha estatica (didatica)

#include <stdio.h>
#include <stdlib.h>

// DDA - 18.01.2024

// Definição da estrutura que representa a pilha
typedef struct PILHA {
    int data[42];  // Array que armazena os elementos da pilha, com capacidade para 42 elementos
    int topo;      // Índice do topo da pilha (quantidade de elementos na pilha)
    int max;       // Capacidade máxima da pilha (42)
} PILHA;

// Função para criação da estrutura da pilha
PILHA *criaPilha() {
    PILHA *p = (PILHA*) malloc(sizeof(PILHA));  // Aloca memória para uma nova pilha
    // Testa se a alocação foi bem sucedida
    if (p == NULL) {
        printf("Nao foi possivel alocar a ED");  // Mensagem de erro se a alocação falhar
        // exit(1); // (Comentado) Poderia encerrar o programa se a alocação falhar
    }
    p->topo = 0;  // Inicializa o topo da pilha como 0 (vazia)
    p->max = 42;  // Define a capacidade máxima da pilha
    return p;     // Retorna o ponteiro para a nova pilha
}

// Função para empilhar um elemento na pilha
int empilhar(int d, PILHA *p) {
    int status = 0;  // Variável para indicar o status da operação
    // Testa se a pilha não está cheia
    if (p->topo < p->max) {
        p->data[p->topo] = d;  // Adiciona o elemento no topo da pilha
        p->topo = p->topo + 1;  // Atualiza o índice do topo
        status = 1;  // Define status como 1 (sucesso)
    }
    return status;  // Retorna o status da operação (0 se falhou, 1 se sucesso)
}

// Função para desempilhar um elemento da pilha
int desempilhar(PILHA *p, int *status) {
    int ret = 0;  // Variável para armazenar o valor desempilhado
    *status = 0;  // Inicializa o status como 0 (falha)
    // Verifica se a pilha não está vazia
    if (p->topo > 0) {
        *status = 1;  // Define status como 1 (sucesso)
        p->topo = p->topo - 1;  // Decrementa o índice do topo
        ret = p->data[p->topo];  // Armazena o valor do topo antes de removê-lo
    }
    return ret;  // Retorna o valor desempilhado
}

// Função para testar se a pilha está vazia
char pilhaVazia(PILHA *p) {
    int status = 0;  // Inicializa status como 0 (não está vazia)
    // Verifica se o topo é 0 (indicando que a pilha está vazia)
    if (p->topo == 0) {
        status = 1;  // Define status como 1 (a pilha está vazia)
    }
    return status;  // Retorna o status da pilha (0 se não estiver vazia, 1 se estiver)
}

// Função para liberar a memória alocada para a pilha
void liberaPilha(PILHA *p) {
    free(p);  // Libera a memória alocada para a pilha
}

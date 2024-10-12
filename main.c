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
    
}
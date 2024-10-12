//pilhaE.h - TAD que implementa uma pilha estatica (didatica)

#include <stdio.h>
#include <stdlib.h>

//DDA - 18.01.2024

//ED representando a pilha
typedef struct PILHA{
    int data[42];
    int topo;
    int max;
} PILHA;

//funcao para criacao da ED
PILHA *criaPilha( )
{
    PILHA *p = ( PILHA* ) malloc( sizeof( PILHA ) );
    //testa se a alocacao foi bem sucedida
    if ( p == NULL )
    {
        printf("Nao foi possivel alocar a ED");
        //exit(1);
    }
    p->topo = 0;
    p->max = 42;
    return p;
}

//funcao para empilhamento
int empilhar( int d, PILHA *p )
{
    int status = 0;
    //testa se a pilha nao esta cheia
    if( p->topo < p->max )
    {
        p->data[p->topo] = d;
        p->topo = p->topo + 1;
        status = 1;
    }
    return status;
}

//funcao para remocao
int desempilhar( PILHA *p, int *status )
{
    int ret = 0;
    *status = 0;
    if( p->topo > 0 )
    {
        *status = 1; // deu certo a remocao
        p->topo = p->topo - 1;    
        ret = p->data[p->topo];        
    }
    return ret;
}

//funcao para testar se a pilha estah vazia
char pilhaVazia( PILHA *p )
{
    int status = 0;    
    if( p->topo == 0 )
    {
        status = 1;
    }
    return status;
}

//funcao para liberacao da memoria da ED
void liberaPilha( PILHA *p )
{
    free( p );
}
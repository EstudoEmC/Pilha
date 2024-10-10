//pilhaD.h - TAD que implementa uma pilha dinâmica (didatica)

#include <stdio.h>
#include <stdlib.h>

//DDA - 18.01.2024

//ED representando um elemento dinamico da pilha
typedef struct ELEM{
    int data;
    struct ELEM *a;
} ELEM;

//ED representando a pilha
typedef struct PILHAD{
    ELEM    *topo;
    int     quantidade;
} PILHAD;

//funcao para criacao da ED
PILHAD *criaPilha( )
{
    PILHAD *p = ( PILHAD* ) malloc( sizeof( PILHAD ) );
    //testa se a alocacao foi bem sucedida
    if ( p == NULL )
    {
        printf("Nao foi possivel alocar a ED");
        //exit(1);
    }
    p->topo = NULL;
    p->quantidade = 0;
    return p;
}
//cria um elemento com o inteiro passado como argumento
ELEM *criaElemento( int d )
{
    ELEM *te = (ELEM*) malloc( sizeof( ELEM ) );
    if(te != NULL)
    {
        te->data = d;
        te->a = NULL;
    }
    return te;

}


//funcao para empilhamento (PUSH)
int empilhar( ELEM *e, PILHAD *p )
{
    int status = 0;
    if( ( e != NULL) && ( p != NULL) )// garante que sao ponteiros validos
    {
        e->a = p->topo;
        p->topo = e;
        p->quantidade++;
        //printf("%d", p->topo->data);
        status = 1;
    }

    return status;
}

//desempilha o elemento localizado no topo da pilha (POP)
ELEM *desempilha( PILHAD *p )
{
    ELEM *te = p->topo;
    p->topo = te->a;
    return te;
}

void liberaElem( ELEM *e )
{
    free( e );
}

int desempilhaDado( PILHAD *p )
{
    ELEM *te = desempilha( p );
    int tmp = te->data;
    free( te );
    return tmp;
}
//testes automaticos da ED
void testePilha()
{

    /*ELEM *e = (ELEM*) malloc( sizeof( ELEM ) );
    if(e != NULL)
    {
        e->data = 42;
        e->a = NULL;
        printf( "%d", e->data );
    }*/
    ELEM *e = criaElemento( 42 );
    PILHAD *p = criaPilha();
    //PILHAD *p = (PILHAD*) malloc( sizeof( PILHAD ) );
    if(p != NULL)
    {
        if( empilhar( e, p ) == 1 )
        {
            printf("\n e empilhado com sucesso!");
            printf("\n dado:%d", p->topo->data );
            printf("\n topo:%x", p->topo);
            printf("\n ant:%d", p->topo->a);
            
        }
    }
}
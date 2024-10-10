#include "pilhaEstatica.h"
#include <stdlib.h>

void teste( );

int main( ){
    int x = 42; 
    teste(); // Corrigido para chamar a função correta
    return 0;
}

void teste( ){
    PILHA *f1 = criaPilha( );

    for( int i = 0; i < 10; i++ ){
       empilhar(i, f1);
    }
    for( int i = 0; i < 10; i++ ){
        int stat;
       printf( "%d, ", desempilhar( f1, &stat ) );     
    }

    liberaPilha( f1 );
}
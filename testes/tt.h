//funcao para empilhamento
//int empilhar( int d, PILHA *p )
{
    //função recebe um inteiro d e um ponteiro
    int status = 0;
    //testa se a pilha nao esta cheia
    if( p->topo < p->max ) //se p que aponta pra topo for menor que p que aponta pra max
    {
        p->data[p->topo] = d; //armazena o valor d na posição atual do topo da pilha
        p->topo = p->topo + 1; //p que aponta para topo recebe p que aponta para topo +1 - incrementa o topo para a próxima posição
        status = 1; //status recebe 1 - para indicar sucesso na operação
    }
    return status; //retorna status para indicar se a operação foi bem-sucedida
}

//verificar se a pilha está cheia
//armazenar o valor de d na posição atual do topo da pilha
//incrementa o topo para a próxima posição
//retorna variavel pra dizer que teve sucesso na operação
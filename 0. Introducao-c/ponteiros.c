#include <stdio.h>

// função principal
int main(){
    // variável normal
    int num = 10;

    // ponteiro
    int *pNum = &num;
    // escrever um "*" entre o tipo e o nome da variável numa declaração cria um ponteiro.
    // escrever um "&" antes do nome de uma variável normal retorna a locação em memória dessa variável.

    // para acessar o valor para o qual um ponteiro aponta é preciso escrever um "*" antes do nome do ponteiro
    printf("valor do ponteiro pNum: %d\n", *pNum);
    // acessar um valor é "dereferenciar um ponteiro"

    // para mudar o valor para o qual um ponteiro aponta é a mesma coisa
    *pNum = 777;
    printf("valor do ponteiro pNum: %d\n", *pNum);


    // detalhe sobre declarações de multiplos ponteiros:
    // isso cria 3 ponteiros:
    int *a1, *a2, *a3;

    // isso cria 1 ponteiro e duas variáveis normais:
    int *b1, b2, b3;

    return 0;
}


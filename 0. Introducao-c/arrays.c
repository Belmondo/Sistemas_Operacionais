#include <stdio.h>

// função principal
int main() {
    // declara um array de tamanho 5.
    // o ultimo elemento é collectionInt[4].
    int collectionInt[5] = {1, 3, 5, 7, 9};

    // maneira rápida de inicializar todos os elementos para 0.
    int elementos[10] = { 0 };
    //                    ^
    //                    |
    //                    |
    // mudar o valor disso   só modifica o primeiro elemento do array, o resto vai ser 0.

    // arrays em c são pequenas abstrações em cima de ponteiros.
    // exemplo disso é que é possível dereferenciar um valor de um array igual um array.
    printf("valor de indice 2 de collectionInt %d\n", *(collectionInt + 2));
    printf("valor de indice 2 de collectionInt %d\n", collectionInt[2]);

    // declarar um array sem tamanho especifico é quase a mesma coisa que declarar um ponteiro.
    char carlos[] = "Abacaxi";
    char *joao = "Abacaxi";

    for (int i = 0; i < 7; i++) {
        printf("carlos %d: %c\n", i, carlos[i]);
        printf("joao   %d: %c\n", i, joao[i]); // a sintaxe de arrays é válida para ponteiros.
    }


    // acessar valores maiores que o tamanho especificado na declaração pode retornar valores imprevisíveis (undefined behaviour).
}


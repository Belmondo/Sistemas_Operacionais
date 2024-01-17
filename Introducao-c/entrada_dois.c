#include <stdio.h>
//função principal
int main(){
    int primeiroValor;
    int segundoValor;
    int valorMultiplicado;
    printf("Digite um valor inteiro\n");
    scanf("%d", &primeiroValor);

    printf("Digite um segundo valor inteiro\n");
    scanf("%d", &segundoValor);

    valorMultiplicado = primeiroValor*segundoValor;

    printf("Multiplicacao: %d\n", valorMultiplicado);

}


#include <stdio.h>
//função principal
int main(){
    int valorUsuario;
    char inicialUsuario;
    printf("Digite um valor inteiro\n");
    scanf("%d", &valorUsuario);

    printf("Digite a inicial do seu nome\n");
    scanf(" %c", &inicialUsuario);
    // esse espaço antes o %c é necessário para remover a nova linha do buffer
    // a nova linha seria capturada pois ela é uma "letra"

    printf("Ola %c, voce digitou o numero: %d\n", inicialUsuario, valorUsuario);
    return 0;
}


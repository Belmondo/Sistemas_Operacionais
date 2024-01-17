#include <stdio.h>
//função principal
int main(){
    int valorUsuario;
    char inicialUsuario;
    printf("Digite um valor inteiro\n");
    scanf("%d", &valorUsuario);

    printf("Digite a inicial do seu nome\n");
    scanf("%s", &inicialUsuario);

    printf("Ola %c, voce digitou o numero: %d\n", inicialUsuario, valorUsuario);

}


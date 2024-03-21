#include <stdio.h>

//função principal
int main(){
    //4 bytes
   int idade = 42;
    //1 byte
   char letra = 'a';
    //4 bytes
   float saldo = 1234.56;
    //8 bytes
   double saldoDois = 0.12345678;

   printf("Imprimindo uma variavel %d \n", idade);
   printf("Imprimindo outra variavel %c\n", letra);
   // detalhe: acessar variáveis sem valores atribuídos pode retornar valores imprevisíveis (undefined behaviour).
}

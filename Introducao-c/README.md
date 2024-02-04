# Introdução
C é uma linguagem compilada que é estaticamente e fracamente tipada.

## Como assim?
Vamos entender estes termos.

1. "Linguagem compilada": Isso quer dizer que a compilação do código fonte para linguagem de máquina acontece antes da execução do programa.
2. "Estaticamente (tipada)": Todas as variáveis tem um tipo definido que não vai mudar.
3. "Fracamente tipada": Não existem restrições em relação a conversões implícitas de variáveis de um tipo para outro (Ex: de long para short).

## Como compilar
Existem inúmeros compiladores para C, esta introdução assume que você está em sistema linux e vá usar o "gcc" (GNU C Compiler).

Mas não se preocupe porque a maioria dos compiladores seguem esta mesma lógica

### Sintaxe:
```
gcc [lista de código fonte] [flags de compilação]
```
(Existem muitas outras funcionalidades que serão omitidos por motivos didáticos)

#### Exemplo de uso:

```
gcc fibonacci.c main.c -o calculadora -std=c99 -Werror -Wall -Wextra -Wpedantic
```
- fibonacci.c main.c : código fonte
- -o: flag    Especificando o nome do binário final
- -std=c99:   Especifica que o padrão "c99" vai ser usado
- -Werror:    Todos os warnings são tratados como erros de compilação
- -Wall:      Abilita vários warnings
- -Wextra:    Abilita warnings adicionais não abilitados pelo "-Wall"
- -Wpedantic: Mostra warnings caso o programa não siga o padrão ISO

#### !!! lembrando que flags são opcionais !!!
##### main.c:
```c
#include <stdio.h> // inclui os headers de input e output (significa "standard input-output")
#include "fibonacci.h"

int main() {
    int n;
    printf("Digite o enésimo número desejado da sequência de fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Só é aceito números positivos\n");
        return 0;
    }

    int resultado = fibonacci(n);
    printf("Número: %d\n", resultado);

    return 0;
}
```

##### fibonacci.c:
```c
int fibonacci(int n) {
    if (n < 0) return -1;

    int num[] = {0, 1, 1};

    switch (n) {
        case 0:
            return num[0];

        case 1: case 2:
            return num[1];

        default:
            for (int i = 0; i < n - 1; i++) {
                num[2] = num[1] + num[0];
                num[0] = num[1];
                num[1] = num[2];
            }
    }
    return num[2];
}
```

##### fibonacci.h:
```c
#ifndef FIBONACCI_H
#define FIBONACCI_H

int fibonacci(int n);

#endif /* FIBONACCI_H */
```

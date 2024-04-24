#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 4 // Número de páginas na memória
#define NUM_REFERENCES 8 // Número de referências de página

// Função para inicializar a memória
void initializeMemory(int memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i] = -1; // -1 indica que a página está vazia
    }
}

// Função para verificar se uma página está na memória
int isInMemory(int memory[], int size, int page) {
    for (int i = 0; i < size; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Função para substituir a página mais antiga na memória
void replacePage(int memory[], int size, int page) {
    for (int i = 0; i < size - 1; i++) {
        memory[i] = memory[i + 1]; // Desloca as páginas uma posição para a esquerda
    }
    memory[size - 1] = page; // Insere a nova página na última posição
}

// Função principal
int main() {
    int memory[NUM_PAGES]; // Memória
    int references[] = {1, 2, 3,3, 4,4, 1, 2}; // Referências de página

    initializeMemory(memory, NUM_PAGES); // Inicializa a memória

    printf("Referências de página:\n");
    for (int i = 0; i < NUM_REFERENCES; i++) {
        int page = references[i];
        printf("Referência %d: Página %d\n", i + 1, page);

        if (!isInMemory(memory, NUM_PAGES, page)) {
            printf("Página %d não está na memória. Substituindo...\n", page);
            replacePage(memory, NUM_PAGES, page);
        } else {
            printf("Página %d está na memória.\n", page);
        }

        printf("Estado atual da memória: [ ");
        for (int j = 0; j < NUM_PAGES; j++) {
            printf("%d ", memory[j]);
        }
        printf("]\n\n");
    }

    return 0;
}

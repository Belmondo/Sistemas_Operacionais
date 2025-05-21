#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES 4               // Número de frames disponíveis
#define NUM_PAGES 12               // Número total de páginas referenciadas

typedef struct {
    int pageNumber;               // Número da página
    int referenceBit;            // Bit de referência (0 ou 1)
} PageFrame;

int main() {
    int pageReferences[NUM_PAGES] = {1, 2, 3, 1, 4, 5, 1, 2, 3, 4, 6, 7};
    PageFrame memory[NUM_FRAMES];

    int pointer = 0;  // Ponteiro do "relógio"
    int i, j;
    int pageFaults = 0;

    // Inicializa os frames da memória
    for (i = 0; i < NUM_FRAMES; i++) {
        memory[i].pageNumber = -1;     // -1 indica que está vazio
        memory[i].referenceBit = 0;
    }

    // Percorre cada página referenciada
    for (i = 0; i < NUM_PAGES; i++) {
        int currentPage = pageReferences[i];
        int found = 0;

        // Verifica se a página já está na memória
        for (j = 0; j < NUM_FRAMES; j++) {
            if (memory[j].pageNumber == currentPage) {
                memory[j].referenceBit = 1; // Atualiza o bit de referência
                found = 1;
                break;
            }
        }

        if (!found) {
            // Page fault ocorreu, usa o algoritmo Clock
            while (1) {
                if (memory[pointer].referenceBit == 0) {
                    // Substitui a página
                    memory[pointer].pageNumber = currentPage;
                    memory[pointer].referenceBit = 1;
                    pointer = (pointer + 1) % NUM_FRAMES;
                    pageFaults++;
                    break;
                } else {
                    // Dá uma segunda chance (zera o bit e avança)
                    memory[pointer].referenceBit = 0;
                    pointer = (pointer + 1) % NUM_FRAMES;
                }
            }
        }

        // Estado atual da memória
        printf("Referência %2d: %d -> Memória: [", i + 1, currentPage);
        for (j = 0; j < NUM_FRAMES; j++) {
            if (memory[j].pageNumber == -1)
                printf(" -,");
            else
                printf(" %d,", memory[j].pageNumber);
        }
        printf("]\n");
    }

    printf("\nTotal de page faults: %d\n", pageFaults);

    return 0;
}

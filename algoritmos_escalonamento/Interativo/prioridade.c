#include <stdio.h>

// Estrutura para representar um processo
typedef struct {
    int id;           // Identificador do processo
    int prioridade;   // Prioridade do processo
    int tempo_de_execucao;   // Tempo de execução do processo
}Processo;

// Função para ordenar os processos por prioridade
void ordenarPorPrioridade(Processo processos[], int n) {
    Processo temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processos[j].prioridade < processos[j + 1].prioridade) {
                // Trocar os processos de lugar se a prioridade for maior
                temp = processos[j];
                processos[j] = processos[j + 1];
                processos[j + 1] = temp;
            }
        }
    }
}

// Função para executar os processos usando o escalonamento por prioridade
void escalonamentoPorPrioridade(Processo processos[], int n) {
    // Ordenar os processos por prioridade
    ordenarPorPrioridade(processos, n);

    // Imprimir a ordem de execução dos processos
    printf("Ordem de execucao dos processos:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processos[i].id);
    }
    printf("\n");
}

int main() {
    // Número total de processos
    int n;
    printf("Digite o numero de processos: ");
    scanf("%d", &n);

    // Array para armazenar os detalhes dos processos
    Processo processos[n];

    // Preencher os detalhes dos processos
    for (int i = 0; i < n; i++) {
        processos[i].id = i + 1;
        printf("Digite a prioridade para o processo P%d: ", i + 1);
        scanf("%d", &processos[i].prioridade);
        printf("Digite o tempo de execucao para o processo P%d: ", i + 1);
        scanf("%d", &processos[i].tempo_de_execucao);
    }

    // Executar o escalonamento por prioridade
    escalonamentoPorPrioridade(processos, n);

    return 0;
}

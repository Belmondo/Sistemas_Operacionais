#include <stdio.h>
#include <stdlib.h>

typedef enum {
    PRONTO,
    EM_EXECUCAO,
    BLOQUEADO
} ProcessState;

// Estrutura para representar um processo
typedef struct {
    int id;
    int time_remaining;
    ProcessState state;
} Process;

// Função para encontrar o próximo processo com o menor tempo restante
int encontrarMenorTempoRestante(Process processos[], int n) {
    int menorTempo = 999999; // Um valor grande inicial para comparação
    int indiceMenorTempo = -1;

    for (int i = 0; i < n; i++) {
        if (processos[i].state == PRONTO && processos[i].time_remaining < menorTempo) {
            menorTempo = processos[i].time_remaining;
            indiceMenorTempo = i;
        }
    }

    return indiceMenorTempo;
}

// Função para simular a execução do algoritmo de Tarefa Mais Curta Primeiro (SJN)
void tarefaMaisCurtaPrimeiro(Process processos[], int n) {
    int tempoTotal = 0;

    while (1) {
        int indiceMenorTempo = encontrarMenorTempoRestante(processos, n);

        if (indiceMenorTempo == -1) {
            // Todos os processos foram concluídos
            break;
        }

        // Atualizar o estado para EM_EXECUCAO
        processos[indiceMenorTempo].state = EM_EXECUCAO;
        
         int current_time = 0;

        printf("Tempo %d: Processo %d em execucao\n", current_time, processos[indiceMenorTempo].id);

        // Simular a execução do processo até a conclusão
        while (processos[indiceMenorTempo].time_remaining > 0) {
            current_time++;
            processos[indiceMenorTempo].time_remaining--;

            printf("Tempo %d: Processo %d - Tempo restante: %d\n", current_time, processos[indiceMenorTempo].id, processos[indiceMenorTempo].time_remaining);
        }


        printf("Tempo %d: Processo %d concluido\n", current_time, processos[indiceMenorTempo].id);

        // Simular a execução de um ciclo do processo
        //processos[indiceMenorTempo].time_remaining--;

        tempoTotal++;
    }

    printf("Todos os processos foram concluidos em");
}

int main() {
    // Exemplo com 3 processos
    Process processos[] = {
        {1, 8, PRONTO},
        {2, 4, PRONTO},
        {3, 6, PRONTO}
    };

    int n = sizeof(processos) / sizeof(processos[0]);

    // Executar o algoritmo de Tarefa Mais Curta Primeiro
    tarefaMaisCurtaPrimeiro(processos, n);

    return 0;
}

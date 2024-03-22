#include <stdio.h>
#include <stdlib.h>

typedef enum {
    PRONTO,
    EM_EXECUCAO,
    BLOQUEADO,
    CONCLUIDO
} ProcessState;

// Estrutura para representar um processo
typedef struct {
    int id;
    int time_remaining;
    ProcessState state;
} Process;

// Função para escalonar processos usando o algoritmo FCFS
void fcfs(Process processes[], int num_processes) {
    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        // Mudar o estado do processo para EM_EXECUCAO
        processes[i].state = EM_EXECUCAO;

        printf("Tempo %d: Processo %d em execucao\n", current_time, processes[i].id);

        // Simular a execução do processo até a conclusão
        while (processes[i].time_remaining > 0) {
            current_time++;
            processes[i].time_remaining--;

            printf("Tempo %d: Processo %d - Tempo restante: %d\n", current_time, processes[i].id, processes[i].time_remaining);
        }

        // Mudar o estado do processo para CONCLUIDO
        processes[i].state = CONCLUIDO;

        printf("Tempo %d: Processo %d concluido\n", current_time, processes[i].id);
    }
}

int main() {
    // Exemplo de utilização
    Process processes[] = {
        {1, 5, PRONTO},
        {2, 3, PRONTO},
        {3, 7, PRONTO}
        // Adicione mais processos conforme necessário
    };

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    // Chamar a função de escalonamento FCFS
    fcfs(processes, num_processes);

    // Exibir o estado final dos processos
    printf("Estado final dos processos:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Processo %d: Estado %d\n", processes[i].id, processes[i].state);
    }

    return 0;
}

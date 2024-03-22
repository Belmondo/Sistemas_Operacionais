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

// Função para criar um novo processo
Process* create_process(int id, int time_remaining) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->time_remaining = time_remaining;
    process->state = PRONTO;
    return process;
}

// Função para simular a execução de um processo
void execute_process(Process* process) {
    if (process->state == PRONTO) {
        process->state = EM_EXECUCAO;
        printf("Process %d is now in execution (Time remaining: %d)\n", process->id, process->time_remaining);
        printf("Executing process %d (Time remaining: %d)\n", process->id, process->time_remaining);
        //sleep(1); // Simula o tempo de execução
        process->time_remaining--;
        process->state = PRONTO;
        if (process->time_remaining == 0) {
            process->state = CONCLUIDO;
            printf("Process %d completed.\n", process->id);
        }
        
    } else if (process->state == BLOQUEADO) {
    }
}

// Função principal de simulação
int main() {
    // Criação de alguns processos para a fila
    Process* process1 = create_process(1, 5);
    Process* process2 = create_process(2, 3);
    Process* process3 = create_process(3, 8);

    // Fila de processos
    Process* process_queue[] = {process1, process2, process3};
    int num_processes = sizeof(process_queue) / sizeof(process_queue[0]);

    // Simulação de execução
    for (int time_slice = 0; ; time_slice++) {
        printf("\nTime Slice: %d\n", time_slice);

        // Executa cada processo na fila
        for (int i = 0; i < num_processes; i++) {
            if (process_queue[i]->time_remaining > 0) {
                execute_process(process_queue[i]);
            } else {
                printf("Process %d completed.\n", process_queue[i]->id);
            }
        }

        // Verifica se todos os processos foram concluídos
        int all_processes_completed = 1;
        for (int i = 0; i < num_processes; i++) {
            if (process_queue[i]->time_remaining > 0) {
                all_processes_completed = 0;
                break;
            }
        }

        // Se todos os processos foram concluídos, encerra a simulação
        if (all_processes_completed) {
            printf("\nAll processes completed. Simulation finished.\n");
            break;
        }
    }

    // Libera a memória alocada para os processos
    for (int i = 0; i < num_processes; i++) {
        free(process_queue[i]);
    }

    return 0;
}
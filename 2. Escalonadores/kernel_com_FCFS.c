#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Definição dos estados do processo
typedef enum {
    PRONTO,
    EM_EXECUCAO,
    BLOQUEADO,
    CONCLUIDO
} ProcessState;

// Estrutura para representar um processo (PCB)
typedef struct Process {
    int id;
    int time_remaining;
    ProcessState state;
    struct Process* next;
} Process;

// Cabeça da lista de processos
Process* process_list = NULL;
int next_process_id = 1;  // Identificador único para processos

// Funções auxiliares para manipulação de tela
void terminal_initialize(void);
void terminal_writestring(const char* str);


// Funções do gerenciamento de processos
void create_process(void);
void list_processes(void);
void terminate_process(int id);
void execute_processes_fcfs(void);



// Função principal do kernel
int main(void) {
    int opcao; 
    terminal_initialize();

    // Loop principal do kernel
    while (1) {
        // Verifica processos pendentes antes de continuar
        terminal_writestring("\nKernel Simples\n");
        terminal_writestring("1. Executar Processos (FCFS)\n");
        terminal_writestring("2. Criar Processo\n");
        terminal_writestring("3. Listar Processos\n");
        terminal_writestring("4. Terminar Processo\n");
        terminal_writestring("5. Sair\n");
        terminal_writestring("Escolha uma opção: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                execute_processes_fcfs();
                break;
            case 2:
                create_process();
                break;
            case 3:
                list_processes();
                break;
            case 4:
                terminal_writestring("Digite o ID do processo a ser terminado: ");
                int id;
                if (scanf("%d", &id) == 1) {
                    terminate_process(id);
                }
                break;
            case 5:
                 terminal_writestring("Sistema finalizado.\n");
                exit(0);
                break;
            default:
                terminal_writestring("Opção inválida!\n");
        }

        sleep(1);  // Simula tempo de processamento
    }

    return 0;
}



// Função para criar um novo processo
void create_process(void) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    if (!new_process) {
        terminal_writestring("Erro: Falha ao criar processo!\n");
        return;
    }

    new_process->id = next_process_id++;
    new_process->time_remaining = rand() % 10 + 1; // Tempo aleatório entre 1 e 10 unidades
    new_process->state = PRONTO;
    new_process->next = NULL;

    // Adiciona o processo ao final da fila
    if (!process_list) {
        process_list = new_process;
    } else {
        Process* temp = process_list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_process;
    }

    terminal_writestring("Processo criado com sucesso!\n");
}

// Função para listar os processos ativos
void list_processes(void) {
    Process* current = process_list;
    if (!current) {
        terminal_writestring("Nenhum processo ativo.\n");
        return;
    }

    terminal_writestring("Lista de processos:\n");
    while (current) {
        printf("ID: %d | Estado: %s | Tempo Restante: %d\n",
               current->id,
               (current->state == PRONTO) ? "PRONTO" :
               (current->state == EM_EXECUCAO) ? "EM_EXECUÇÃO" :
               (current->state == BLOQUEADO) ? "BLOQUEADO" :
               "CONCLUÍDO",
               current->time_remaining);
        current = current->next;
    }
}

// Função para terminar um processo
void terminate_process(int id) {
    Process* current = process_list;
    Process* prev = NULL;

    while (current) {
        if (current->id == id) {
            if (prev) {
                prev->next = current->next;
            } else {
                process_list = current->next;
            }
            free(current);
            terminal_writestring("Processo terminado com sucesso!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    terminal_writestring("Erro: Processo não encontrado!\n");
}

// Função de escalonamento FCFS (First-Come, First-Served)
void execute_processes_fcfs(void) {
    if (!process_list) {
        terminal_writestring("Nenhum processo para executar.\n");
        return;
    }

    terminal_writestring("Iniciando escalonamento FCFS...\n");
    Process* current = process_list;
    Process* prev = NULL;
    int current_time = 0;

    while (current) {
        // Mudar o estado para EM_EXECUÇÃO
        current->state = EM_EXECUCAO;
        printf("Tempo %d: Processo %d em execução\n", current_time, current->id);

        // Simular execução até a conclusão
        while (current->time_remaining > 0) {
            sleep(1);
            current_time++;
            current->time_remaining--;
            printf("Tempo %d: Processo %d - Tempo restante: %d\n",
                   current_time, current->id, current->time_remaining);
        }

        // Mudar o estado para CONCLUÍDO
        current->state = CONCLUIDO;
        printf("Tempo %d: Processo %d concluído\n", current_time, current->id);

        // Remover o processo concluído da lista
        if (prev) {
            prev->next = current->next;
        } else {
            process_list = current->next;
        }
        free(current);
        current = (prev) ? prev->next : process_list;
    }

    terminal_writestring("Todos os processos foram executados.\n");
}

// Função para inicializar o terminal
void terminal_initialize(void) {
    terminal_writestring("Inicializando terminal...\n");
}

// Função para escrever no terminal
void terminal_writestring(const char* str) {
    printf("%s", str);
}

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

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

// Funções auxiliares para manipulação de tela
void terminal_initialize(void);
void terminal_writestring(const char* str);

// Definição de chamada de sistema
#define SYSCALL_EXIT 0

// Protótipo da função de chamada de sistema
void syscall(uint32_t syscall_number, ...);

// Função principal do kernel
int main(void) {
    int opcao; 
    // Inicializa a tela
    terminal_initialize();

    // Loop principal do kernel
    while (1) {
        // Exibe o menu de opções
        terminal_writestring("\nKernel Simples\n");
        terminal_writestring("1. Executar Processos\n");
        terminal_writestring("2. Criar Processo\n");
        terminal_writestring("3. Listar Processos\n");
        terminal_writestring("4. Terminar Processo\n");
        terminal_writestring("5. Sair\n");
        terminal_writestring("Escolha uma opção: ");

        // Lê a opção do usuário
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                terminal_writestring("Implementar código...\n"); // Substituir pela chamada da função desejada
                break;
            case 5:
                syscall(SYSCALL_EXIT);
                break;
            default:
                terminal_writestring("Opção inválida!\n");

        }

    }

    return 0;
}

// Implementação da chamada de sistema
void syscall(uint32_t syscall_number, ...) {
    // Ponteiro para a lista de argumentos
    uint32_t* args = &syscall_number + 1;

    // Processa a chamada de sistema
    switch (syscall_number) {
        case SYSCALL_EXIT:
            // Finaliza o sistema
            terminal_writestring("Sistema finalizado.\n");
            exit(0); 
            break;
        default:
            // Chamada de sistema inválida
            terminal_writestring("Erro: chamada de sistema inválida.\n");
            break;
    }
}

// Funções auxiliares para manipulação de tela
void terminal_initialize(void) {
    // Implemente a inicialização da tela aqui
    //printf("Inicializando a tela e o terminal\n");
}

void terminal_writestring(const char* str) {
    printf("%s", str);
    // Implemente a escrita na tela aqui
}
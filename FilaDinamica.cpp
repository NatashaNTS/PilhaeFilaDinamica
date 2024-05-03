#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

struct no {
    int valor;
    struct no *proximo;
};

struct fila {
    struct no *inicio;
    struct no *fim;
};

struct fila minhaFila;

void inicializarFila() {
    minhaFila.inicio = NULL;
    minhaFila.fim = NULL;
}

void enfileirar(int pvalor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->valor = pvalor;
    novo->proximo = NULL;
    
    if (minhaFila.fim == NULL) { // Fila vazia
        minhaFila.inicio = novo;
        minhaFila.fim = novo;
    } else {
        minhaFila.fim->proximo = novo;
        minhaFila.fim = novo;
    }
    
    printf("Elemento %d inserido com sucesso!\n", pvalor);
}

void desenfileirar() {
    if (minhaFila.inicio == NULL) {
        printf("Fila vazia. Nada a remover.\n");
        return;
    }
    
    struct no *temp = minhaFila.inicio;
    printf("Elemento removido: %d\n", temp->valor);
    
    minhaFila.inicio = minhaFila.inicio->proximo;
    free(temp);
    
    if (minhaFila.inicio == NULL) { // Se a fila ficar vazia
        minhaFila.fim = NULL;
    }
}

void mostrarFila() {
    struct no *atual = minhaFila.inicio;
    printf("Conteudo da fila:\n");
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

int main() {
    int valor, opcao;
    inicializarFila();
    
    do {
        printf("\nEscolha uma opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Enfileirar (Inserir)\n");
        printf("2 - Desenfileirar (Remover)\n");
        printf("3 - Mostrar Fila\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor que deseja enfileirar: ");
                scanf("%d", &valor);
                enfileirar(valor);
                break;
            case 2:
                desenfileirar();
                break;
            case 3:
                mostrarFila();
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida. Tente novamente.\n");
                }
        }
    } while (opcao != 0);
    
    // Limpa a fila antes de sair
    while (minhaFila.inicio != NULL) {
        desenfileirar();
    }
    
    return 0;
}

#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

struct no{
	int valor;
	no *anterior;
};
	no *topo;

void pilhavazia(){
	topo=NULL;
}

void empilha(int pvalor){
	no *novo;
	novo= (no*)malloc(sizeof(no));
	novo->valor=pvalor;
	novo->anterior=topo;
	topo=novo;
	printf("Elemento %d inserido com sucesso!",novo->valor);
	getch();
	system("cls");
}

void mostrar(){
	no *aux=topo;
	while(aux!=NULL){
	printf("\n%d",aux->valor);
	aux=aux->anterior;
	}
	getch();
	system("cls");
}

void excluirTudo(){
    no *aux=topo;
    while(aux!=NULL){
        topo=aux->anterior;
        free(aux);
        aux=topo;
    }
    printf("Pilha excluida com sucesso");
    getch();
    system("cls");
}

void excluirTopo(){
    no *aux=topo;
    
        topo=aux->anterior;
        free(aux);
        aux=topo;
    printf("Topo excluido com sucesso");
    getch();
    system("cls");
}

main(){
    int valor,op;
    do{
        printf("Escolha uma opção");
        printf("\n0 - sair");
        printf("\n1 - inserir");
        printf("\n2 - mostrar a pilha");
        printf("\n3 - exibir o valor do topo");
        printf("\n4 - excluir toda pilha");
        printf("\n5 - excluir topo da pilha\n");
        scanf("\n%d",&op);
        
		switch(op){
                case 1: 
                    printf("\nDigite o valor que deseja inserir: ");
                    scanf("%d",&valor);
                    empilha(valor);
                    break;
                case 2:
                    mostrar();
                    break;
                case 3:
                    printf("\n%d",topo->valor);
                    getch();
                    system("cls");
                    break;
                case 4:
                    excluirTudo();
                    break;
                case 5: 
                	excluirTopo();
                	break;
        }
    }while(op!=0);   
}

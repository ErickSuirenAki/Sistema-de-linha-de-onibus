#include "linhas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int verificaAdmin(char senha[]){
    char senhaAdmin[30] = "admin";

    if(strcmp(senha, senhaAdmin) == 0){
        return 1;
    } else {
        return 0;
    }
}

void criarListaLinhas(ListaLinhas *L){
    L->head = NULL;
}

int inserirInicio(ListaLinhas *L, int numero, char companhia[]){
    Linha * novo;
    novo = (Linha *) malloc (sizeof(Linha));
    if(!novo){
        return 0;
    }
    novo->numero = numero;

    strcpy(novo->companhia, companhia);

    novo->paradas = NULL;

    novo->proxima = L->head;
    L->head = novo;
    return 1;

}
Linha* buscarLinha(ListaLinhas *L, int numero){
    Linha * auxiliar;

    auxiliar = L->head;

    while(auxiliar!= NULL){
        if(auxiliar->numero == numero){
            return auxiliar;
        }
        auxiliar = auxiliar->proxima;
    }
    return NULL;
}

int removerLinha(ListaLinhas *L, int numero){
    Linha * atual = L->head;
    Linha * anterior = NULL;
    while(atual != NULL && atual->numero != numero){
        anterior = atual;
        atual = atual->proxima;
    }

    if(atual == NULL){
        return 0;
    }

   // destruirListasParadas(atual);

    if (anterior == NULL){
        L->head = atual->proxima;
    } else {
        anterior->proxima = atual->proxima;
    }

    free(atual);

    return 1;

}
void mostrarLinhas(ListaLinhas *L){
    Linha * auxiliar;

    auxiliar = L->head;

    while(auxiliar!= NULL){
        printf("Numero da linha: %d\n", auxiliar->numero);
        printf("Companhia: %s\n\n", auxiliar->companhia);
        auxiliar = auxiliar->proxima;
    }
}

void inserirParadaNaLinha(ListaLinhas *L){
    int numero, pos;
    tipoParada p;

    printf("\nDigite o numero da linha: ");
    scanf("%d", &numero);

    Linha *ln = buscarLinha(L, numero);
    if(ln == NULL){
        printf("\nLinha não encontrada!\n");
        return;
    }
    if(ln->paradas == NULL){
    ln->paradas = criarListaParadas();
}
    printf("Local da parada: ");
    fflush(stdin);
    gets(p.local);

    printf("Horario de saída (HH:MM): ");
    fflush(stdin);
    gets(p.saida);

    printf("Horario de chegada (HH:MM): ");
    fflush(stdin);
    gets(p.chegada);

    printf("Posição para inserir (1, 2, 3...): ");
    scanf("%d", &pos);

    if(inserirParadaEmPosicao(ln->paradas, p, pos)){
        printf("\nParada inserida com sucesso!\n");
    } else {
        printf("\nErro ao inserir parada!\n");
    }
}


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

    if(atual->paradas != NULL){
        destruirListaParadas(atual->paradas);
    }
   

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
        printf("\nNumero da linha: %d", auxiliar->numero);
        printf("\nCompanhia: %s\n\n", auxiliar->companhia);
        auxiliar = auxiliar->proxima;
    }
}

void inserirParadaNaLinha(ListaLinhas *L, int numero){
    int posicao;
    tipoParada parada;

    Linha *linha = buscarLinha(L, numero);
    if(linha == NULL){
        printf("\nLinha nao encontrada!\n");
        return;
    }
   
    if(linha->paradas == NULL){
        linha->paradas = criarListaParadas();
    }
    else {
        mostrarParadasDaLinha(L, numero);
    }
    
    printf("\nLocal da parada: \n");
    fflush(stdin);
    gets(parada.local);

    printf("\nHorario de saida (HH:MM): \n");
    fflush(stdin);
    gets(parada.saida);

    printf("\nHorario de chegada (HH:MM): \n");
    fflush(stdin);
    gets(parada.chegada);

    printf("\nPosicao para inserir: \n");
    scanf("%d", &posicao);
    posicao++;

    if(inserirParadaEmPosicao(linha->paradas, parada, posicao)){
        printf("\nParada inserida com sucesso!\n");
    } else {
        printf("\nErro ao inserir parada!\n");
    }
}

void alterarParadaNaLinha(ListaLinhas *L, int numero){
    int posicao;
    tipoParada nova;

    Linha *linha = buscarLinha(L, numero);
    if(linha == NULL){
        printf("\nLinha nao encontrada!\n");
        return;
    }

    if(linha->paradas == NULL || listaParadasVazia(linha->paradas)){
        printf("\nEsta linha nao possui paradas!\n");
        return;
    }

    exibirParadas(linha->paradas);

    int quantidade = tamanhoListaParadas(linha->paradas);

    do {
        printf("\nQual parada deseja alterar (1 a %d): ", quantidade);
        scanf("%d", &posicao);
        getchar();
    } while(posicao < 1 || posicao > quantidade);

    printf("\nNovo local: \n");
    fflush(stdin);
    gets(nova.local);
    
    printf("\nNovo horario de chegada (HH:MM): \n");
    fflush(stdin);
    gets(nova.chegada);

    printf("Novo horario de saida (HH:MM): ");
    fflush(stdin);
    gets(nova.saida);

    if(alterarParadaPos(linha->paradas, posicao, nova))
        printf("\nParada alterada com sucesso!\n");
    else
        printf("\nErro ao alterar parada!\n");
}


void removerParadaNaLinha(ListaLinhas *L, int numero){
    int posicao;

    Linha *linha = buscarLinha(L, numero);
    if(linha == NULL){
        printf("\nLinha nao encontrada!\n");
        return;
    }

    if(linha->paradas == NULL || listaParadasVazia(linha->paradas)){
        printf("\nEsta linha nao possui paradas!\n");
        return;
    }

    exibirParadas(linha->paradas);

    int quantidade = tamanhoListaParadas(linha->paradas);

    do {
        printf("\nQual parada deseja remover (1 a %d): ", quantidade);
        scanf("%d", &posicao);
    } while(posicao < 1 || posicao > quantidade);

    if(removerParadaPos(linha->paradas, posicao))
        printf("\nParada removida com sucesso!\n");
    else
        printf("\nErro ao remover parada!\n");
}

void mostrarParadasDaLinha(ListaLinhas *L, int numero){

    Linha *linha = buscarLinha(L, numero);

    if(linha == NULL){
        printf("\nLinha nao encontrada!\n");
        return;
    }

    if(linha->paradas == NULL){
        printf("\nEsta linha ainda nao possui paradas.\n");
        return;
    }

    exibirParadas(linha->paradas);
}




#include "parada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ListaP* criarListaParadas(){
    ListaP* lp = (ListaP*) malloc(sizeof(ListaP));
    if(lp != NULL)
        lp->head = NULL;
    return lp;
}

int listaParadasVazia(ListaP *lp){
    if(lp == NULL) return 1;       
    if(lp->head == NULL) return 1;
    return 0;        
}

int tamanhoListaParadas(ListaP *lp){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

    No *aux = lp->head;
    int tamanho = 1;

    while(aux->prox != lp->head){
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}

int inserirParadaEmPosicao(ListaP *lp, tipoParada parada, int posicao) {
    if(lp == NULL) return 0;

    int tam = tamanhoListaParadas(lp);

    // posição válida: 1 .. tam+1
    if(posicao < 1 || posicao > tam + 1) {
        return 0;
    }

    // criar novo nó
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL) return 0;
    novo->infos = parada;

    // caso lista vazia (tam == 0). posicao só pode ser 1 aqui
    if(tam == 0){
        novo->prox = novo;
        novo->ant  = novo;
        lp->head = novo;
        return 1;
    }

    // inserir na primeira posição (antes do head)
    if(posicao == 1) {
        No *ultimo = lp->head->ant;
        novo->prox = lp->head;
        novo->ant  = ultimo;
        ultimo->prox = novo;
        lp->head->ant = novo;
        lp->head = novo;
        return 1;
    }

    // inserir no fim (posicao == tam + 1)
    if(posicao == tam + 1){
        No *ultimo = lp->head->ant;
        novo->prox = lp->head;
        novo->ant  = ultimo;
        ultimo->prox = novo;
        lp->head->ant = novo;
        return 1;
    }

    // inserir no meio (1 < posicao <= tam)
    No *atual = lp->head;
    int i = 1;
    while(i < posicao){
        atual = atual->prox;
        i++;
    }
    // agora 'atual' é o nó que estava na posição 'posicao'
    No *ant = atual->ant;
    novo->prox = atual;
    novo->ant  = ant;
    ant->prox = novo;
    atual->ant = novo;

    return 1;
}

int alterarParadaPos(ListaP *lp, int pos, tipoParada novaParada){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

    int tamanho = tamanhoListaParadas(lp);
    if(pos < 1 || pos > tamanho) return 0;

    No *atual = lp->head;
    int i = 1;

    while(i < pos){
        atual = atual->prox;
        i++;
    }

    strcpy(atual->infos.local,   novaParada.local);
    strcpy(atual->infos.chegada, novaParada.chegada);
    strcpy(atual->infos.saida,   novaParada.saida);

    return 1;
}

int removerParadaPos(ListaP *lp, int pos){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

    int tamanho = tamanhoListaParadas(lp);
    if(pos < 1 || pos > tamanho) return 0;

    No *atual = lp->head;
    int i = 1;

    //n� unico, quando removo, lista fica nula
    if(atual->prox == atual){
        free(atual);
        lp->head = NULL;
        return 1;
    }

    while(i < pos){
        atual = atual->prox;
        i++;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;

    //atualizar o head, caso seja ele que for removido
    if(atual == lp->head){
        lp->head = atual->prox;
    }
    free(atual);

    return 1;
}

void exibirParadas(ListaP *lp){
    if(lp == NULL){
        printf("\nLista inexistente.\n");
        return;
    }

    if(listaParadasVazia(lp)){
        printf("\nLista vazia: nao ha paradas cadastradas!");
        return;
    }

    No *atual = lp->head;
    int pos = 1;

    printf("\n----Lista de Paradas----\n");
    do{
        printf("%d) local: %s\tHorario Chegada: %s\tHorario Saida: %s\n",
               pos, atual->infos.local, atual->infos.chegada, atual->infos.saida);

        atual = atual->prox;
        pos++;
    } while(atual != lp->head);

    printf("\n-------------------------\n");
}

No* buscaParadaLocal(ListaP *lp, char destino[]){
    if(lp == NULL) return NULL;
    if(listaParadasVazia(lp)) return NULL;

    No *atual = lp->head;

    do{
        if(strcmp(atual->infos.local, destino) == 0){
            return atual;
        }
        atual = atual->prox;
    } while(atual != lp->head);

    return NULL;
}

void destruirListaParadas(ListaP *lp) {
    if(lp == NULL) return;

    if (lp->head == NULL) {
        return;
    }

    No *atual = lp->head;
    No *prox;

    do {
        prox = atual->prox;
        free(atual);
        atual = prox;
    } while (atual != lp->head);

    lp->head = NULL;
}



No* buscarDestinoHorario(ListaP *lp, char destino[], char horario[]){
    if(lp == NULL || lp->head == NULL) return NULL;

    No *atual = lp->head;

    do{
        if(strcmp(atual->infos.local, destino) == 0){
            if(strcmp(atual->infos.chegada, horario) >= 0){
                return atual;
            }
        }
        atual = atual->prox;
    }while(atual != lp->head);

    return NULL;
}
No* acharHorarioSaida(No* destinoEncontrado){
    if(destinoEncontrado == NULL){
        return NULL;
    }
    return destinoEncontrado->ant;
}









#include "parada.h"

ListaP* criarListaParadas(){
    ListaP* lp = (ListaP*) malloc(sizeof(ListaP));
    if(lp != NULL)
        lp->head = NULL;
    return lp;
}

int listaParadasVazia(ListaP *lp){
    if(lp == NULL) return 1;
    if((*li) == NULL) return 1;
    return 0;
}

int inserirParadaEmPosicao(ListaParadas *lp, tipoParada p, int posicao) {
    if(lp == NULL) return 0;
    No *no = (No*) malloc(sizeof(No));
    if(no == NULL) return 0;

    no->infos = p;

    if(listaParadasVazia(lp)) {
        lp->head = no;
        no->prox = no;
        no->ant = no;
        return 1;
    }
    // verificar se é uma posição válida - acho que é melhor no main
    // tipo exibir quantas paradas tem e suas respectivas posições
    // pergunta qual a posição a ser inserida
    // verifica se ela é válida (não dá pra adicionar na pos 4 se só tem 2 paradas, nem se for um valor negativo)
    No *atual = lp->head;
    No *ant = NULL;
    int i = 1;

    while(i < posicao) {
        ant = atual;
        atual = atual->prox;
        i++;

        //pra manter a lista circular, no caso se for igual a cabeça, voltou pro inicio;
        if(atual == lp->head) break;
    }

    //inserção no início
    if(posicao == 1) {
        No *ultimo = lp->head->ant;
        no->prox = lp->head;
        no->ant = ultimo;
        ultimo->prox = no;
        lp->head->ant = no;
        lp->head = no;
        return 1;
    }

    no->prox = atual;
    no->ant = ant;
    ant->prox = no;
    atual->ant = no;

    return 1;
}

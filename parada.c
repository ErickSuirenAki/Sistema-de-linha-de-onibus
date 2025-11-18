#include "parada.h"
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

int inserirParadaEmPosicao(ListaP *lp, tipoParada p, int posicao) {
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
    // verificar se � uma posi��o v�lida - acho que � melhor no main
    // tipo exibir quantas paradas tem e suas respectivas posi��es
    // pergunta qual a posi��o a ser inserida
    // verifica se ela � v�lida (n�o d� pra adicionar na pos 4 se s� tem 2 paradas, nem se for um valor negativo)
    No *atual = lp->head;
    No *ant = NULL;
    int i = 1;

    while(i < posicao) {
        ant = atual;
        atual = atual->prox;
        i++;

        //pra manter a lista circular, no caso se for igual a cabe�a, voltou pro inicio;
        if(atual == lp->head) break;
    }

    //inser��o no in�cio
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

int alterarParadaPos(ListaP *lp, int pos, tipoParada novaParada){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

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

No* buscarDestinoHorario(ListaP *lp, char destino[], char horario[]){}
No* acharHorarioSaida(No* destinoEncontrado){}








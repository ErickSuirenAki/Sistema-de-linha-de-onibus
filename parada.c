/*
Trabalho de Estrutura de Dados 1
2º período de Ciência da Computação
Professora: Carolina Yukari Veludo Watanabe

Desenvolvido por:
-Erick Batista dos Santos
-Anna Julia Oliveira de Sousa
*/

#include "parada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criação e manipulação da lista de paradas
ListaP* criarListaParadas(){
    ListaP* lp = (ListaP*) malloc(sizeof(ListaP));
    if(lp != NULL)
        lp->head = NULL;
    return lp;
}

//verifica se a lista de paradas está vazia
int listaParadasVazia(ListaP *lp){
    if(lp == NULL) return 1;       
    if(lp->head == NULL) return 1;
    return 0;        
}

//função que retorna o tamanho da lista de paradas
int tamanhoListaParadas(ListaP *lp){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

    No *aux = lp->head;
    int tamanho = 1;

    while(aux->prox != lp->head){ // percorre até voltar ao head
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}


//insere uma nova parada em uma posição específica da lista
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


//altera os dados de uma parada em uma posição específica da lista
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
    // atual agora aponta para o nó na posição 'pos'
    strcpy(atual->infos.local,   novaParada.local);
    strcpy(atual->infos.chegada, novaParada.chegada);
    strcpy(atual->infos.saida,   novaParada.saida);

    return 1;
}

//remove uma parada em uma posição específica da lista
int removerParadaPos(ListaP *lp, int pos){
    if(lp == NULL) return 0;
    if(listaParadasVazia(lp)) return 0;

    int tamanho = tamanhoListaParadas(lp);
    if(pos < 1 || pos > tamanho) return 0;

    No *atual = lp->head;
    int i = 1;

    //no unico, quando removo, lista fica nula
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


//exibe todas as paradas da lista
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

//busca uma parada pelo local

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


//destrói a lista de paradas, liberando toda a memória alocada
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
    } while (atual != lp->head); // percorre toda a lista circular

    lp->head = NULL;
}


//busca uma parada pelo local e horário mínimo de chegada
No* buscarDestinoHorario(ListaP *lp, char destino[], char horario[]){
    if(lp == NULL || lp->head == NULL) return NULL;

    No *atual = lp->head;

    do{
        if(strcmp(atual->infos.local, destino) == 0){ // local compatível
            if(strcmp(atual->infos.chegada, horario) >= 0){ // horário compatível
                return atual;
            }
        }
        atual = atual->prox;
    }while(atual != lp->head);

    return NULL;
}

//busca a parada anterior ao destino encontrado (horário de saída)
No* acharHorarioSaida(No* destinoEncontrado){
    // se não encontrou destino, retorna NULL
    if(destinoEncontrado == NULL){
        return NULL;
    }
    // retorna o nó anterior ao destino encontrado
    return destinoEncontrado->ant;
}









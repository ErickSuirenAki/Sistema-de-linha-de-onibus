/*
Trabalho de Estrutura de Dados 1
2º período de Ciência da Computação
Professora: Carolina Yukari Veludo Watanabe

Desenvolvido por:
-Erick Batista dos Santos
-Anna Julia Oliveira de Sousa
*/

#include "linhas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
    verifica se a senha informada é igual à senha do administrador.
    retorna 1 se correta, 0 caso contrário.
*/


int verificaAdmin(char senha[]){
    char senhaAdmin[30] = "admin";

    if(strcmp(senha, senhaAdmin) == 0){
        return 1;
    } else {
        return 0;
    }
}


/*
    inicializa a lista de linhas.
    a lista começa vazia, apontando para NULL.
*/

void criarListaLinhas(ListaLinhas *L){
    L->head = NULL;
}

/*
    insere uma nova linha no início da lista encadeada.
    cria a linha, define o número, companhia e inicia o ponteiro de paradas como NULL.
*/

int inserirInicio(ListaLinhas *L, int numero, char companhia[]){
    Linha * novo;
    novo = (Linha *) malloc (sizeof(Linha));
    if(!novo){
        return 0;
    }
    novo->numero = numero;

    strcpy(novo->companhia, companhia);

    // no momento da criação, a linha ainda não possui paradas
    novo->paradas = NULL;

    // insere no início da lista de linhas
    novo->proxima = L->head;
    L->head = novo;
    return 1;

}

/*
    busca uma linha pelo número.
    retorna um ponteiro para a linha encontrada ou NULL caso não exista.
*/
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

/*
    remove uma linha específica pelo número.
    também libera todas as paradas associadas à linha.
*/

int removerLinha(ListaLinhas *L, int numero){
    Linha * atual = L->head;
    Linha * anterior = NULL;

    // procura a linha desejada
    while(atual != NULL && atual->numero != numero){
        anterior = atual;
        atual = atual->proxima;
    }

    // linha não encontrada
    if(atual == NULL){
        return 0;
    }

    // remove as paradas antes de remover a linha
    if(atual->paradas != NULL){
        destruirListaParadas(atual->paradas);
    }
   
    // ajusta ponteiros da lista encadeada
    if (anterior == NULL){   // removendo a primeira linha
        L->head = atual->proxima;
    } else {
        anterior->proxima = atual->proxima;
    }

    free(atual); // remove a linha da memoria

    return 1;

}



// exibe todas as linhas cadastradas no sistema.

void mostrarLinhas(ListaLinhas *L){
    Linha * auxiliar;

    auxiliar = L->head;

    if(auxiliar == NULL){
        printf("\nNenhuma linha cadastrada.\n");
        return;
    }

    while(auxiliar!= NULL){
        printf("\nNumero da linha: %d", auxiliar->numero);
        printf("\nCompanhia: %s\n\n", auxiliar->companhia);
        auxiliar = auxiliar->proxima;
    }
}


/*
    insere uma nova parada em uma linha específica.
    se a linha ainda não possuir lista de paradas, ela é criada aqui.
*/
void inserirParadaNaLinha(ListaLinhas *L, int numero){
    int posicao;
    tipoParada parada;

    Linha *linha = buscarLinha(L, numero);
    if(linha == NULL){
        printf("\nLinha nao encontrada!\n");
        return;
    }

    // se ainda não existe lista de paradas, cria
   
    if(linha->paradas == NULL){
        linha->paradas = criarListaParadas();
    }
    else {
        // caso já existam paradas, exibe para auxiliar escolha da posição
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
    posicao++; // ajuste porque a lista é circular

    //tenta inserir a parada na posição desejada
    if(inserirParadaEmPosicao(linha->paradas, parada, posicao)){
        printf("\nParada inserida com sucesso!\n");
    } else {
        printf("\nErro ao inserir parada!\n");
    }
}


// Permite alterar os valores de uma parada existente em uma linha
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

    //exibe todas as paradas para que o usuário escolha qual alterar
    exibirParadas(linha->paradas);

    int quantidade = tamanhoListaParadas(linha->paradas);

    do {
        // validação da posição
        printf("\nQual parada deseja alterar (1 a %d): ", quantidade);
        scanf("%d", &posicao);
        getchar();
    } while(posicao < 1 || posicao > quantidade);

     // leitura dos novos valores
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

//remove uma parada específica dentro de uma linha.
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

//mostra todas as paradas cadastradas em uma linha específica

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

/*
    busca a melhor linha considerando destino e horário desejados.
    critério de desempate: menor horário de chegada disponível.
*/
void buscarMelhorLinha(ListaLinhas *L, char destino[], char horario[]){
    if(L->head == NULL){
        printf("\nNenhuma linha encontrada!\n");
        return;
    }

    Linha *atualLinha = L->head;
    Linha *melhorLinha = NULL;
    No *melhorDestino = NULL;

    // percorre todas as linhas
    while(atualLinha != NULL){
        
        if(atualLinha->paradas != NULL){   
            // busca parada compativel com destino e horário
            No *destinoHorario = buscarDestinoHorario(atualLinha->paradas, destino, horario);

            if(destinoHorario != NULL){
                // primeira linha encontrad
                if(melhorLinha == NULL){
                    melhorLinha = atualLinha;
                    melhorDestino = destinoHorario;  
                }
                else{
                     // Compara horários para decidir qual é a melhor
                    if(strcmp(destinoHorario->infos.chegada, melhorDestino->infos.chegada) < 0){
                        melhorLinha = atualLinha;
                        melhorDestino = destinoHorario;  
                    }
                }
            }
        }

        atualLinha = atualLinha->proxima;
    }
    //exibe o resultado da busca
    if(melhorLinha == NULL){
        printf("\nNenhuma linha atende esse destino e horario\n");
    } else {
        printf("\nMELHOR LINHA ENCONTRADA\n");
        printf("Linha: %d | Companhia: %s\n", melhorLinha->numero, melhorLinha->companhia);
        printf("Destino encontrado: %s\n", melhorDestino->infos.local);
        printf("Horario de chegada: %s\n", melhorDestino->infos.chegada);

        //exibe a parada anterior ao destino
        No *saida = acharHorarioSaida(melhorDestino);
        if(saida != NULL){
            printf("ultima parada antes do destino: %s\n", saida->infos.local);
            printf("Horario de saida anterior: %s\n", saida->infos.saida);
        }
    }
}

/*
Trabalho de Estrutura de Dados 1
2º período de Ciência da Computação
Professora: Carolina Yukari Veludo Watanabe

Desenvolvido por:
-Erick Batista dos Santos
-Anna Julia Oliveira de Sousa
*/

#include "parada.h"


/*
    Estrutura que representa uma linha de ônibus
    Cada linha possui:
    - número identificador
    - nome da companhia
    - ponteiro para a lista de paradas (lista circular duplamente encadeada)
    - ponteiro para a próxima linha na lista encadeada simples
*/

typedef struct Linha {
    int numero;
    char companhia[50];
    ListaP *paradas;
    struct Linha *proxima;
}Linha;


/*
    Estrutura que representa a lista de linhas de ônibus.
    É simplesmente uma lista encadeada com ponteiro para o primeiro elemento.
*/

typedef struct {
    Linha *head;
} ListaLinhas;

/* 
   Verifica se a senha digitada corresponde à senha do administrador.
   Retorna 1 se correta ou 0 se incorreta.
*/
int verificaAdmin(char senha[]); //ok

// Inicializa a lista de linhas com head = NULL.
void criarListaLinhas(ListaLinhas *L); //ok


/*
   Insere uma nova linha no início da lista.
   Recebe número da linha e companhia.
*/
int inserirInicio(ListaLinhas *L, int numero, char companhia[]); //ok
/*
   Busca uma linha pelo número.
   Retorna ponteiro para a linha ou NULL se não encontrada.
*/
Linha* buscarLinha(ListaLinhas *L, int numero); //ok

/*
   Remove uma linha específica pelo número.
   Também libera todas as paradas associadas à linha.
*/
int removerLinha(ListaLinhas *L, int numero); //ok

//Exibe todas as linhas cadastradas no sistema.
void mostrarLinhas(ListaLinhas *L); //ok

// Insere uma nova parada em uma linha específica.
void inserirParadaNaLinha(ListaLinhas *L, int numero); //ok

// Permite alterar os valores de uma parada existente em uma linha
void alterarParadaNaLinha(ListaLinhas *L, int numero); //ok

//remove uma parada específica dentro de uma linha.
void removerParadaNaLinha(ListaLinhas *L, int numero); //ok

//mostra todas as paradas cadastradas em uma linha específica
void mostrarParadasDaLinha(ListaLinhas *L, int numero); //ok

// busca a melhor linha considerando destino e horário desejados.
void buscarMelhorLinha(ListaLinhas *L, char destino[], char horario[]);



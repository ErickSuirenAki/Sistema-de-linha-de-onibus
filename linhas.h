#include "parada.h"

typedef struct Linha {
    int numero;
    char companhia[50];
    //Parada *paradas;
    struct Linha *proxima;
}Linha;


int verificaAdmin(char senha[]);
void procurarLinha(char destino[], char horario[]);
void incluirLinha();
void incluirParada();
void alterarParada();
void excluirParada();
void excluirLinha();
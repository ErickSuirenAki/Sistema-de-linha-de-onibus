#include "parada.h"

typedef struct Linha {
    int numero;
    char companhia[50];
    tipoParada *paradas;
    struct Linha *proxima;
}Linha;


typedef struct {
    Linha *head;
} ListaLinhas;

int verificaAdmin(char senha[]); //ok
void criarListaLinhas(ListaLinhas *L); //ok
int inserirInicio(ListaLinhas *L, int numero, char companhia[]); //ok
Linha* buscarLinha(ListaLinhas *L, int numero); //ok
int removerLinha(ListaLinhas *L, int numero); //ok
void mostrarLinhas(ListaLinhas *L);
void inserirParadaNaLinha(ListaLinhas *L);
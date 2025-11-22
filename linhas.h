#include "parada.h"

typedef struct Linha {
    int numero;
    char companhia[50];
    ListaP *paradas;
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
void mostrarLinhas(ListaLinhas *L); //ok
void inserirParadaNaLinha(ListaLinhas *L, int numero); //ok
void alterarParadaNaLinha(ListaLinhas *L, int numero); //ok
void removerParadaNaLinha(ListaLinhas *L, int numero); //ok
void mostrarParadasDaLinha(ListaLinhas *L, int numero); //ok
void buscarMelhorLinha(ListaLinhas *L, char destino[], char horario[]);



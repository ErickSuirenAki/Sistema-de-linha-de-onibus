typedef struct{
    char local[40];
    char chegada[6];
    char saida[6];
}tipoParada;

typedef struct no{
    tipoParada infos;
    struct no *prox;
    struct no *ant;
}No;

typedef struct{
    No *head;
}ListaP;

ListaP* criarListaParadas();
int listaParadasVazia(ListaP *lp);
int inserirParadaEmPosicao(ListaP *lp, tipoParada p, int posicao);

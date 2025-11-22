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
int alterarParadaPos(ListaP *lp, int pos, tipoParada novaParada);
int removerParadaPos(ListaP *lp, int pos);
void exibirParadas(ListaP *lp);
No* buscaParadaLocal(ListaP *lp, char destino[]);
void destruirListaParadas(ListaP *lp);
No* buscarDestinoHorario(ListaP *lp, char destino[], char horario[]);
No* acharHorarioSaida(No* destinoEncontrado);

int tamanhoListaParadas(ListaP *lp);





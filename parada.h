/*
Trabalho de Estrutura de Dados 1
2º período de Ciência da Computação
Professora: Carolina Yukari Veludo Watanabe

Desenvolvido por:
-Erick Batista dos Santos
-Anna Julia Oliveira de Sousa
*/

/* 
    Estrutura que representa uma parada de ônibus.
    Cada parada possui:
    - local (nome do ponto de parada)
    - horário de chegada
    - horário de saída
*/
typedef struct{
    char local[40];
    char chegada[6];
    char saida[6];
}tipoParada;

/*
    Estrutura que representa um nó na lista de paradas.
    Cada nó possui:
    - informações da parada (tipoParada)
    - ponteiro para o próximo nó
    - ponteiro para o nó anterior
*/

typedef struct no{
    tipoParada infos;
    struct no *prox;
    struct no *ant;
}No;

/*
    Estrutura que representa a lista de paradas.
    A lista é circular e duplamente encadeada, com ponteiro para o nó head (primeira parada).
*/

typedef struct{
    No *head;
}ListaP;

//criação e manipulação da lista de paradas
ListaP* criarListaParadas();

//verifica se a lista de paradas está vazia
int listaParadasVazia(ListaP *lp);

//função que retorna o tamanho da lista de paradas
int tamanhoListaParadas(ListaP *lp);

//insere uma nova parada em uma posição específica da lista
int inserirParadaEmPosicao(ListaP *lp, tipoParada p, int posicao);

//altera os dados de uma parada em uma posição específica da lista
int alterarParadaPos(ListaP *lp, int pos, tipoParada novaParada);

//remove uma parada em uma posição específica da lista
int removerParadaPos(ListaP *lp, int pos);

//exibe todas as paradas da lista
void exibirParadas(ListaP *lp);

//busca uma parada pelo local
No* buscaParadaLocal(ListaP *lp, char destino[]);

//destrói a lista de paradas, liberando toda a memória alocada
void destruirListaParadas(ListaP *lp);

//busca uma parada que corresponda ao destino e horário desejados
No* buscarDestinoHorario(ListaP *lp, char destino[], char horario[]);

//acha o horário de saída da parada encontrada
No* acharHorarioSaida(No* destinoEncontrado);






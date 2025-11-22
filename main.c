#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linhas.h"


int main() {

    ListaLinhas L;
    criarListaLinhas(&L);

    int opcaoPrincipal = -1;
    int opcaoAdmin = -1;
    char destino[40];
    char horario[6];
    char senhaAdmin[30];
    int numero;
    char companhia[50];

    do {
        printf("\n===== MENU PRINCIPAL =====");
        printf("\n1 - Procurar linha de onibus");
        printf("\n2 - Manutencao do programa");
        printf("\n0 - Sair");
        printf("\nEscolha sua opcao: ");
        scanf("%d", &opcaoPrincipal);
        getchar();

        switch(opcaoPrincipal) {

            case 1:
                printf("\nDigite o destino da sua viagem: ");
                fflush(stdin);
                gets(destino);

                printf("Digite o horário aproximado (HH:MM): ");
                fflush(stdin);
                gets(horario);

                //buscarLinha(&L, destino, horario);
            break;

            case 2:
                printf("\nDigite a senha de administrador: ");
                fflush(stdin);
                gets(senhaAdmin);

                if(verificaAdmin(senhaAdmin)) {

                    do {
                        printf("\n===== MENU ADMIN =====");
                        printf("\n1 - Inserir nova linha");
                        printf("\n2 - Inserir parada");
                        printf("\n3 - Alterar parada");
                        printf("\n4 - Excluir parada");
                        printf("\n5 - Excluir linha");
                        printf("\n6 - Mostrar linhas");
                        printf("\n0 - Voltar");
                        printf("\nEscolha sua opcao: ");

                        scanf("%d", &opcaoAdmin);
                        getchar();

                        switch(opcaoAdmin) {
                            case 1:
                                printf("\nDigite o numero da linha: ");
                                scanf("%d", &numero);
                                printf("\nDigite a companhia da linha: ");
                                fflush(stdin);
                                gets(companhia);
                                if(inserirInicio(&L, numero, companhia)){
                                    printf("\nLinha inserida com sucesso!");
                                } else {
                                    printf("\nErro ao inserir linha!");
                                }
                                break;

                            case 2:
                                inserirParadaNaLinha(&L);
                                break;

                            case 3:
                                mostrarLinhas(&L);
                                printf("\nDigite o numero da linha para alterar a parada: ");
                                scanf("%d", &numero); 
                                break;

                            case 4:
                                mostrarLinhas(&L);
                                printf("\nDigite o numero da linha para excluir a parada: ");
                                scanf("%d", &numero);
                                
                                break;

                            case 5:
                                mostrarLinhas(&L);
                                printf("\nDigite o numero da linha a ser excluida: ");
                                scanf("%d", &numero);
                                if(removerLinha(&L, numero)){
                                    printf("\nLinha removida com sucesso!");
                                } else {
                                    printf("\nErro ao remover linha! Linha nao encontrada.");
                                }
                                break;

                            case 0: 
                            break;
                            default: printf("\nOpção invalida!\n");
                        }

                    } while (opcaoAdmin != 0);
                }
                else {
                    printf("\nSenha incorreta! Acesso negado.\n");
                }

            break;

            case 0:
                printf("\nEncerrando sistema\n");
            break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcaoPrincipal != 0);

    return 0;
}

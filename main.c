#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificaAdmin(char senha[]);
void procurarLinha(char destino[], char horario[]);
void incluirLinha();
void incluirParada();
void alterarParada();
void excluirParada();
void excluirLinha();

int main() {

    int opcaoPrincipal = -1;
    int opcaoAdmin = -1;
    char destino[50];
    char horario[6];
    char senhaAdmin[30];

    do {
        printf("\n===== MENU PRINCIPAL =====");
        printf("\n1 - Procurar linha de ônibus");
        printf("\n2 - Manutenção do programa");
        printf("\n0 - Sair");
        printf("\nEscolha sua opção: ");
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
                procurarLinha(destino, horario);
            break;

            case 2:
                printf("\nDigite a senha de administrador: ");
                fgets(senhaAdmin, 30, stdin);
                senhaAdmin[strcspn(senhaAdmin, "\n")] = 0;

                if(verificaAdmin(senhaAdmin)) {

                    do {
                        printf("\n===== MENU ADMIN =====");
                        printf("\n1 - Incluir nova linha");
                        printf("\n2 - Incluir parada");
                        printf("\n3 - Alterar parada");
                        printf("\n4 - Excluir parada");
                        printf("\n5 - Excluir linha");
                        printf("\n0 - Voltar");
                        printf("\nEscolha sua opção: ");

                        scanf("%d", &opcaoAdmin);
                        getchar();

                        switch(opcaoAdmin) {
                            case 1: incluirLinha(); break;
                            case 2: incluirParada(); break;
                            case 3: alterarParada(); break;
                            case 4: excluirParada(); break;
                            case 5: excluirLinha(); break;
                            case 0: break;
                            default: printf("\nOpção inválida!\n");
                        }

                    } while (opcaoAdmin != 0);
                }
                else {
                    printf("\nSenha incorreta!\n");
                }

            break;

            case 0:
                printf("\nEncerrando sistema\n");
            break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcaoPrincipal != 0);

    return 0;
}

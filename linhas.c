#include "linhas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int verificaAdmin(char senha[]){
    char senhaAdmin[30] = "admin";

    if(strcmp(senha, senhaAdmin) == 0){
        return 1;
    } else {
        return 0;
    }
}

void procurarLinha(char destino[], char horario[]){
    // Implementação da função para procurar linha de ônibus
}
void incluirLinha(){
    // Implementação da função para incluir nova linha
} 

void incluirParada(){
    // Implementação da função para incluir parada
}

void alterarParada(){
    // Implementação da função para alterar parada
}

void excluirParada(){
    // Implementação da função para excluir parada
}

void excluirLinha(){
    // Implementação da função para excluir linha
}


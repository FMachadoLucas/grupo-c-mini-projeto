#include <stdio.h>
#include <stdlib.h>
#include "terrenos.h"

int main (int argc, char * argv[]){
    //verifica os parametros da main
    if(argc < 2){
        printf("Erro: Nome do arquivo de dados nao informado.\n");
        return 0;
    }
    char * nomeArquivo = argv[1];

    //vetor de ponteiros
    Terrenos * meusTerrenos[100];

    int opcao;
    do{
        //codigo de menu (printf e switch case)
        //chama as funcoes

        //printf menu
        scanf("&d, &opcao");
        if(opcao == 1) criarTerreno(meusTerrenos);
        
    }while (opcao != 0);

    return 0

}
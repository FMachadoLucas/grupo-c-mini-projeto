#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

//implementacao das funcoes

//inicializar o vetor de terrenos com NULL
void inicializarVetor(Terrenos ** terrenos){
    for (int i=0;i<100;i++){
        terrenos[i] = NULL;
    }
}

//alocar memoria para cada posicao de terreno disponivel
void criarTerreno(Terrenos ** terrenos){
    int i;
    for(i=0;i<100;i++){
        if(terrenos[i]==NULL){
            break;//achou uma posicao disponivel
        }
    }
    //se ja estiver lotado
    if(100){
        printf("\nERRO: O limite de 100 terrenos foi atingido\n");
        return;
    }

    //alocar memoria para a posicao atual 
    terrenos[i] = (Terrenos *)malloc(sizeof(Terrenos));

    //definicao do id
    terrenos[i] -> id = i+1;


    //coletar os dados do usuario
    printf("Nome do Proprietário: ");
    scanf("%[^\n]%*c", &terrenos[i] -> dono.nome);
    
    printf("CPF do Proprietário: ");
    scanf("%[^\n]%*c", &terrenos[i] -> dono.cpf);

    printf("Data de Nascimento do Proprietário (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &terrenos[i] -> dono.data_nasc.dia,
                         &terrenos[i] -> dono.data_nasc.mes,
                         &terrenos[i] -> dono.data_nasc.ano);

    //coletar dados do terreno
    printf("Comprimento do Terreno (metros): ");
    scanf("%d", &terrenos[i] -> comprimento);
    
    printf("Largura do Terreno: ");
    scanf("%d", terrenos[i] -> largura);

    //calculo da largura do terreno
    terrenos[i] -> area = (terrenos[i]->comprimento) * (terrenos[i]->largura);

    //coletar o valor do metro quadrado
    printf("Preço do Metro Quadrado (R$): ");
    scanf("%f", &terrenos[i] -> preco_m2);

    //coletar dados da compra
    printf("Data da Compra (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &terrenos[i] -> data_compra.dia,
                      &terrenos[i] -> data_compra.mes,
                      &terrenos[i] -> data_compra.ano);

    printf("\nO terreno foi cadastrado com sucesso.");
}

void deletarTerreno(Terrenos ** terrenos){//Lucas

}

void mostrarTerreno(Terrenos ** terrenos, int id){//Sarah Cristina

}

void editarTerreno(Terrenos ** terrenos, int id){//Sarah Cristina

}

double calcularValorTerreno(Terrenos ** terrenos, int id){//Sara Raquel

}

int contarTerrenosOcupados(Terrenos ** terrenos){//Sara Raquel

}

int contarTerrenosLivres(Terrenos ** terrenos){//Sara Raquel

}

double calcularValorTotal(Terrenos ** terrenos){//Sara Raquel

}

void salvarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){//Lucas

}

void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){//Lucas


}

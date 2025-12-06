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
    int i;
    int encontrado = 0; // Variável para verificar se o terreno foi localizado

    // Percorre o vetor de 100 posições
    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL && terrenos[i]->id == id) {     //se o terreno for encontrado, exibe as seguintes informacoes:

            encontrado = 1;
            printf("--- INFORMAÇÕES DO TERRENO (ID %d) ---\n", terrenos[i]->id);
            printf("Nome do Proprietário: %s\n", terrenos[i]->dono.nome);
            printf("CPF do Proprietário: %s\n", terrenos[i]->dono.cpf);
            printf("Data de Nascimento: %02d/%02d/%d\n", terrenos[i]->dono.data_nasc.dia, terrenos[i]->dono.data_nasc.mes, terrenos[i]->dono.data_nasc.ano);
            printf("Comprimento do Terreno (m): %.2f\n", terrenos[i]->comprimento);
            printf("Largura do Terreno (m): %.2f\n", terrenos[i]->largura);
            printf("Área Total (m²): %.2f\n", terrenos[i]->area);
            printf("Preço do Metro Quadrado (R$): %.2f\n", terrenos[i]->preco_m2);
            printf("Data da Compra: %02d/%02d/%d\n", terrenos[i]->data_compra.dia, terrenos[i]->data_compra.mes, terrenos[i]->data_compra.ano);
            break;
        }
    }
    if (!encontrado) {      //se o terreno não foi encontrado, exibe o seguinte erro:
        printf("\nERRO: Terreno com ID %d não encontrado ou posição vazia.\n", id);
    }
}

void editarTerreno(Terrenos ** terrenos, int id){//Sarah Cristina
    int i;
    int encontrado = 0;

    for (i = 0; i < 100; i++) {     //verifica se a posição do terreno e sse o ID sao validos
        if (terrenos[i] != NULL && terrenos[i]->id == id) {     //se for encontrado, exibe a seguinte mensagem:
            encontrado = 1;

            printf("--- EDIÇÃO DO TERRENO (ID %d) ---\n", id);
            printf("Insira os novos dados para o terreno com ID %d.\n", id);
            
            //aqui coletamos os novos dados do proprietário:
            printf("Novo Nome do Proprietário: ");
            scanf(" %[^\n]%*c", terrenos[i]->dono.nome);

            printf("Novo CPF do Proprietário: ");
            scanf(" %[^\n]%*c", terrenos[i]->dono.cpf);
            
            printf("Novo Telefone do Proprietário: ");
            scanf(" %[^\n]%*c", terrenos[i]->dono.telefone); 
            printf("Nova Data de Nascimento do Proprietário (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &terrenos[i]->dono.data_nasc.dia, &terrenos[i]->dono.data_nasc.mes, &terrenos[i]->dono.data_nasc.ano);
            
            //aqui coletamos os novos dados do terreno
            printf("Novo Comprimento do Terreno (metros): ");
            scanf("%f", &terrenos[i]->comprimento);
            printf("Nova Largura do Terreno (metros): ");
            scanf("%f", &terrenos[i]->largura);

            //recalculamos a area (a area do terreno é dada pelo comprimento * largura):
            terrenos[i]->area = terrenos[i]->comprimento * terrenos[i]->largura;
            
            printf("Área Total Recalculada (m²): %.2f\n", terrenos[i]->area); 
            printf("Novo Preço do Metro Quadrado (R$): ");
            scanf("%f", &terrenos[i]->preco_m2);

            //nova data da compra:
            printf("Nova Data da Compra (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &terrenos[i]->data_compra.dia, &terrenos[i]->data_compra.mes, &terrenos[i]->data_compra.ano);
            
            //limpa o buffer caso ele exista
            while (getchar() != '\n'); 
            
            printf("\nO terreno com ID %d foi editado com sucesso!\n", id);
            
            break;
        }
    }
    if (!encontrado) {      //se o terreno nao foi encontrado, exibe o seguinte erro:
        printf("\nERRO: Terreno com ID %d não encontrado ou posição vazia.\n", id);
    }
}

double calcularValorTerreno(Terrenos ** terrenos, int id){//Sara Raquel
    int indice = id - 1;
    
    if (indice < 0 || indice > 99) 
        return 0;
    
    if (terrenos[indice] == NULL)
    return 0;

    double valor = terrenos[indice]->area * terrenos[indice]->preco_m2;
    return valor;
}

int contarTerrenosOcupados(Terrenos ** terrenos){//Sara Raquel
    int i;
    int contador = 0;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            contador++;
        }
    }
    return contador;
}

int contarTerrenosLivres(Terrenos ** terrenos){//Sara Raquel
    int i;
    int contador = 0;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] == NULL) {
            contador++;
        }
    }
    return contador;
}

double calcularValorTotal(Terrenos ** terrenos){//Sara Raquel
    double total = 0;
    int i;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            total += calcularValorTerreno(terrenos, terrenos[i]->id);
        }
    }
    return total;
}

void salvarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){//Lucas

}

void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){//Lucas


}

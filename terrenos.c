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
    if(i==100){
        printf("\n[ERRO]: O limite de 100 terrenos foi atingido\n");
        return;
    }

    //alocar memoria para a posicao atual 
    terrenos[i] = (Terrenos *)malloc(sizeof(Terrenos));

    //definicao do id
    terrenos[i] -> id = i+1;


    //coletar os dados do usuario
    printf("Nome do Proprietário: ");
    scanf("%[^\n]%*c", terrenos[i] -> dono.nome);
    
    printf("CPF do Proprietário: ");
    scanf("%[^\n]%*c", terrenos[i] -> dono.cpf);

    printf("Data de Nascimento do Proprietário (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &terrenos[i] -> dono.data_nasc.dia,
                      &terrenos[i] -> dono.data_nasc.mes,
                      &terrenos[i] -> dono.data_nasc.ano);

    //coletar dados do terreno
    printf("Digite o comprimento do Terreno (metros): ");
    scanf("%f", &terrenos[i] -> comprimento);
    
    printf("Digite a largura do Terreno: ");
    scanf("%f", &terrenos[i] -> largura);

    //calculo da largura do terreno
    terrenos[i] -> area = (terrenos[i]->comprimento) * (terrenos[i]->largura);

    //coletar o valor do metro quadrado
    printf("Digite o preço do Metro Quadrado (R$): ");
    scanf("%f", &terrenos[i] -> preco_m2);

    //coletar dados da compra
    printf("Digite e data de Compra do lote (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &terrenos[i] -> data_compra.dia,
                      &terrenos[i] -> data_compra.mes,
                      &terrenos[i] -> data_compra.ano);

    printf("\nO terreno com id [%d] foi cadastrado com sucesso.", terrenos[i] -> id);
}

void deletarTerreno(Terrenos ** terrenos){//Lucas
    int id_requerido;
    int opcao;
    int indice;

    printf("Qual a id do lote você gostaria de apagar do banco de dados?\n");
    printf("(1) Digitar a id\n");
    printf("(2) Não sei a id. Mostrar todos os lotes existentes no banco de dados\n");
    scanf("%d", &opcao);
    if(opcao==2){
        id_requerido = mTerreno_ordenado(terrenos);
    }else{
        printf("Digite o ID do lote que deseja apagar: ");
        scanf("%d", &id_requerido);
    }

    //verificacoes de seguranca
    if(id_requerido == -1){//o usuario desistiu
        printf("Operacao cancelada.\n");
        return;
    }

    if(id_requerido<1 || id_requerido>100){
        printf("[ERRO]: ID invalida!\n");
        return;
    }
    
    indice = id_requerido - 1;

    //verificar se tem terreno nessa posicao
    if(terrenos[indice] == NULL){
        printf("[ERRO]: Nao existe um terreno com a ID %d.\n", id_requerido);
        return;
    }

    //liberar memoria e marcar NULL
    free(terrenos[indice]);
    terrenos[indice] = NULL;

    printf("Terreno de ID %d foi apagado com sucesso!\n", id_requerido);
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
    FILE * arquivo = fopen(nomeArquivo, "w");
    int qtdd_terrenos_salvos=0;

    //verificacao se der erro
    if(arquivo == NULL){
        printf("[ERRO]: Não foi possível criar ou abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    for(int i=0;i<100;i++){
        if(terrenos[i]!=NULL){
            //ID
            fprintf(arquivo, "%d\n", terrenos[i]->id);

            //strings
            fprintf(arquivo, "%s\n", terrenos[i]->dono.nome);
            fprintf(arquivo, "%s\n", terrenos[i]->dono.cpf);

            //data de nascimento
            fprintf(arquivo, "%d %d %d\n", terrenos[i]->dono.data_nasc.dia,
                                           terrenos[i]->dono.data_nasc.mes,
                                           terrenos[i]->dono.data_nasc.ano);

            //dimensoes e preco
            fprintf(arquivo, "%f\n", terrenos[i]->comprimento);
            fprintf(arquivo, "%f\n", terrenos[i]->largura);
            fprintf(arquivo, "%f\n", terrenos[i]->area);
            fprintf(arquivo, "%f\n", terrenos[i]->preco_m2);

            //data de compra
            fprintf(arquivo, "%d %d %d\n", terrenos[i]->data_compra.dia,
                                           terrenos[i]->data_compra.mes,
                                           terrenos[i]->data_compra.ano);

            qtdd_terrenos_salvos++;
        }
    }
    fclose(arquivo);

    printf("\nConcluido: %d terrenos foram salvos no arquivo '%s'.\n", qtdd_terrenos_salvos, nomeArquivo);
}

void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){//Lucas
    FILE * arquivo = fopen(nomeArquivo, "r");

    //verificacao
    if(arquivo == NULL){
        printf("[ERRO]: Arquivo '%s' nao encontrado!\n", nomeArquivo);
        return;
    }
    int i=0;
    int id_aux;

    //verificar se tem terreno naquela posicao
    while(fscanf(arquivo, "%d\n", &id_aux) == 1){
        //procira proximo lote vazio
        while(i<100 && terrenos[i]!=NULL){
            i++;
        }
        //caso o vetor de lotes fique cheio
        if(i==100){
            printf("[AVISO]: Capacidade máxima de 100 lotes salvos atingida.\n");
        }
        terrenos[i] = (Terrenos *)malloc(sizeof(Terrenos));

        //preenchimento dos dados

        terrenos[i]->id = id_aux;

        //strings
        fscanf(arquivo, "%[^\n]%*c", terrenos[i]->dono.nome);
        fscanf(arquivo, "%[^\n]%*c", terrenos[i]->dono.cpf);

        //data de nascimento
        fscanf(arquivo, "%d %d %d\n",  &terrenos[i]->dono.data_nasc.dia,
                                       &terrenos[i]->dono.data_nasc.mes,
                                       &terrenos[i]->dono.data_nasc.ano);

        //medidas e precos
        fscanf(arquivo, "%f\n", &terrenos[i]->comprimento);
        fscanf(arquivo, "%f\n", &terrenos[i]->largura);
        fscanf(arquivo, "%f\n", &terrenos[i]->area);
        fscanf(arquivo, "%f\n", &terrenos[i]->preco_m2);

        //data da compra
        fscanf(arquivo, "%d %d %d\n", &terrenos[i]->data_compra.dia,
                                      &terrenos[i]->data_compra.mes,
                                      &terrenos[i]->data_compra.ano);

        i++;
    }
    //fechar
    fclose(arquivo);
    printf("Sistema inicializado com sucesso! %d terrenos foram recuperados do arquivo de texto.\n", i);
}

//funcao extra
int mTerreno_ordenado(Terrenos **terrenos){//Lucas
    int id_escolhida=0;//verifica se ja escolheu a id
    int sem_terrenos = 1;//verifica se tem terrenos cadastrados

    printf("\n Procurando terreno para apagar.\n");

    // do{ 
    //     mostrarTerreno(terrenos, id_ordem_crescente);
    //     printf("\nDeseja apagar esse lote de id %d?\n", id_ordem_crescente);
    //     printf("(1) SIM.\n");
    //     printf("(2) NÃO.\n");
    //     scanf("%d", &id_escolhida);
    //     if(id_escolhida==1){
    //         return id_ordem_crescente;
    //     }else{
    //         printf("Próximo lote...\n\n");
    //         id_ordem_crescente++;
    //     }
    // }while(id_escolhida==2);

    for(int i=0; i<100;i++){
        if(terrenos[i]!=NULL){
            sem_terrenos = 0;//encontrou algum terrenos cadastrado

            mostrarTerreno(terrenos, terrenos[i]->id);

            printf("\nDeseja apagar esse lote (ID: %d)?\n", terrenos[i]->id);
            printf("(1) Sim, apagar este lote.\n");
            printf("(2) Não, mostrar o próximo lote.\n");
            printf("(0) Cancelar operacao.\n");
            printf("Escolha: ");
            scanf("%d", &id_escolhida);

            if(id_escolhida == 1){
                return terrenos[i]->id;
            }else if(id_escolhida == 0){
                return -1;
            }//se for 2, continua o loop
        }
    }

    if(sem_terrenos == 1){
        printf("Nenhum terreno encontrado na lista para apagar.\n");
    }else{
        printf("\nFim da lista. Nenhum terreno foi escolhido.\n");
    }
    //percorreu todos os terrenos e não escolheu nenhum
    return -1;
}

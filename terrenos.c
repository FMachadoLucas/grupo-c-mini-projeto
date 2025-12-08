#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "terrenos.h"

void inicializarVetor(Terrenos ** terrenos){
    for (int i=0;i<100;i++){
        terrenos[i] = NULL;
    }
}

int buscarIndicePorId(Terrenos ** terrenos, int id){
    for(int i=0;i<100;i++){
        if(terrenos[i] != NULL && terrenos[i] -> id == id){
            return i;
        }
    }
    return -1;//caso nao ache o id
}

void criarTerreno(Terrenos ** terrenos){
    int i;
    int opcaoId, novoId, idValido=0;

    //procurar uma vaga livre para o terreno
    for(i=0;i<100;i++){
        if(terrenos[i] == NULL) break;
    }

    //verifica se ja esta lotado
    if(i==100){
        printf("\n[ERRO]: O limite de 100 terrenos foi atingido\n");
        return;
    }

    //alocar memoria para a posicao atual
    terrenos[i] = (Terrenos *)malloc(sizeof(Terrenos));

    //verifica a alocacao
    if(terrenos[i] == NULL){
        printf("[ERRO] Falha ao alocar memoria RAM.\n");
    }

    //definir ID
    do{
        printf("\nComo deseja definir o ID deste terreno?\n");
        printf("[1] Gerar um ID Aleatorio (automatico)\n");
        printf("[2] Digitar o ID pretendido\n");
        printf("Escolha: ");
        scanf("%d%*c", &opcaoId);

        if(opcaoId == 1){
            //gerar ID aleatorio, de 1000 a 9999
            novoId = 1000 + (rand()%9000);
            printf(">> ID Gerado Automaticamente: %d\n", novoId);
        }else if(opcaoId == 2){
            printf("Digite o ID Desejado (numero inteiro de 1000 a 9999): ");
            do{
                scanf("%d%*c", &novoId);
            }while(novoId<1000 || novoId>9999);
        }else{
            printf("[ERRO] Opcao invalida.\n");
            continue;
        }

        //verificar se o id ja existe
        if(buscarIndicePorId(terrenos, novoId) != -1){
            printf("[ERRO] O ID %d ja existe! Tente outro numero.\n", novoId);
            idValido = 0;
        }else{
            idValido = 1;
        }

    }while(!idValido);

    //definicao do id
    terrenos[i] -> id = novoId;

    //coletar os dados do usuario

    printf("\n--- Preenchendo os dados do Terreno (ID: %d) ---\n", terrenos[i]->id);
    printf("Nome do Proprietario: ");
    scanf(" %[^\n]%*c", terrenos[i] -> dono.nome);
    
    printf("CPF do Proprietario (11 digitos): ");
    do {
        scanf(" %[^\n]%*c", terrenos[i] -> dono.cpf);
        if (validarCPF(terrenos[i]->dono.cpf) == 0) {
            printf("CPF invalido! Digite novamente: ");
        }
    } while (validarCPF(terrenos[i]->dono.cpf) == 0);

    printf("Telefone do Proprietario (inclua o DDD): ");
    do {
        scanf(" %[^\n]%*c", terrenos[i] -> dono.telefone);
        if (validarTelefone(terrenos[i]->dono.telefone) == 0) {
            printf("Telefone invalido! Digite novamente: ");
        }
    } while (validarTelefone(terrenos[i]->dono.telefone) == 0);
    
    printf("Data de Nascimento do Proprietário (dd/mm/aaaa): ");
    do {
        scanf("%d/%d/%d", &terrenos[i] -> dono.data_nasc.dia,
                          &terrenos[i] -> dono.data_nasc.mes,
                          &terrenos[i] -> dono.data_nasc.ano);
        if (validarData(terrenos[i]->dono.data_nasc.dia,
                        terrenos[i]->dono.data_nasc.mes,
                        terrenos[i]->dono.data_nasc.ano) == 0) {
            printf("Data inválida! Digite novamente: ");
        }
    } while (validarData(terrenos[i]->dono.data_nasc.dia,
            terrenos[i]->dono.data_nasc.mes,
            terrenos[i]->dono.data_nasc.ano) == 0);

    //coletar dados do terreno
    printf("Digite o comprimento do Terreno (m): ");
    scanf("%f", &terrenos[i] -> comprimento);
    
    printf("Digite a largura do Terreno: ");
    scanf("%f", &terrenos[i] -> largura);

    //calculo da largura do terreno
    terrenos[i] -> area = (terrenos[i]->comprimento) * (terrenos[i]->largura);

    //coletar o valor do metro quadrado
    printf("Digite o preço do Metro Quadrado (R$): ");
    scanf("%f", &terrenos[i] -> preco_m2);

    //coletar dados da compra
    printf("Digite a data de Compra do lote (dd/mm/aaaa): ");
    do {
        scanf("%d/%d/%d", &terrenos[i] -> data_compra.dia,
                          &terrenos[i] -> data_compra.mes,
                          &terrenos[i] -> data_compra.ano);
        if (validarDataCompra(terrenos[i]->data_compra.dia,
                              terrenos[i]->data_compra.mes,
                              terrenos[i]->data_compra.ano) == 0) {
            printf("Data inválida! Digite novamente: ");
        }
    } while (validarDataCompra(terrenos[i]->data_compra.dia,
                               terrenos[i]->data_compra.mes,
                               terrenos[i]->data_compra.ano) == 0);
    printf("\nO terreno com ID [%d] foi cadastrado com sucesso.", terrenos[i] -> id);
}
int validarCPF(char cpf[]) {
    int i;
    int contador = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            contador++;
        }
    }
    if (contador == 11) {
        return 1;
    }
    else {
        return 0;
    }
}

int validarTelefone(char tel[]) {
    int i;
    int contador = 0;

    for (i = 0; tel[i] != '\0'; i++) {
        if (isdigit(tel[i])) {
            contador++;
        }
    }
    if (contador == 11) {
        return 1;
    }
    else {
        return 0;
    }
}

int validarData(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) {
        return 0;
    }
    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (ano < 1920 || ano > 2024) {
        return 0;
    }
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0;
    }
    return 1;
}

int validarDataCompra(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) {
        return 0;
    }
    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (ano < 1920 || ano > 2025) {
        return 0;
    }
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0;
    }
    return 1;
}

void deletarTerreno(Terrenos ** terrenos){
    int id_requerido;
    int opcao;
    int indice;

    printf("\n--- DELETAR TERRENO ---\n");
    printf("Como deseja selecionar o terreno?\n");
    printf("(1) Digitar o ID manualmente\n");
    printf("(2) Procurar na lista (Nao sei o ID)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    //validacao
    while(opcao!=1 && opcao!=2){
        printf("[ERRO]: Opcao invalida. Digite [1] ou [2]: ");
        scanf("%d", &opcao);
    }

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
    
    indice = buscarIndicePorId(terrenos, id_requerido);

    if(indice == -1){
        printf("[ERRO] Nao existe um terreno com a ID %d.\n", id_requerido);
        return;
    }

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

void mostrarTerreno(Terrenos ** terrenos, int id){
    int i;
    int encontrado = 0; //verifica se o terreno foi localizado

    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL && terrenos[i]->id == id) { //se o terreno for encontrado
            encontrado = 1;

            printf("\n--- INFORMAÇÕES DO TERRENO (ID %d) ---\n", terrenos[i]->id);
            printf("Nome do Proprietario: %s\n", terrenos[i] -> dono.nome);
            printf("CPF do Proprietario: %s\n", terrenos[i] -> dono.cpf);
            printf("Telefone do Proprietario: %s\n", terrenos[i] -> dono.telefone);
            printf("Data de Nascimento: %02d/%02d/%d\n", terrenos[i]->dono.data_nasc.dia,
                                                         terrenos[i]->dono.data_nasc.mes,
                                                         terrenos[i]->dono.data_nasc.ano);
            printf(" --------------------------------\n");                                         
            printf("Comprimento do Terreno (m): %.2f\n", terrenos[i]->comprimento);
            printf("Largura do Terreno (m): %.2f\n", terrenos[i]->largura);
            printf("Área Total (m2): %.2f\n", terrenos[i]->area);
            printf("Preço do Metro Quadrado (R$): %.2f\n", terrenos[i]->preco_m2);
            printf("Data da Compra: %02d/%02d/%d\n", terrenos[i]->data_compra.dia,
                                                     terrenos[i]->data_compra.mes,
                                                     terrenos[i]->data_compra.ano);
            break;
        }
    }
    if (!encontrado) { //terreno nao encontrado
        printf("\n[ERRO]: Terreno com ID %d não encontrado.\n", id);
    }
}

void editarTerreno(Terrenos ** terrenos, int id){
    int i;
    int encontrado = 0;

    for (i = 0; i < 100; i++) {     //verifica se a posição do terreno e sse o ID sao validos
        if (terrenos[i] != NULL && terrenos[i]->id == id) {     //se for encontrado, exibe a seguinte mensagem:
            encontrado = 1;

            //limeza de buffer
            while(getchar() != '\n');

            printf("\n--- EDITANDO TERRENO (ID %d) ---\n\n", id);

            printf("Insira os novos dados para o terreno com ID %d.\n", id);
            
            //coleta dos novos dados:
            printf("Novo Nome do Proprietário: ");
            scanf(" %[^\n]%*c", terrenos[i]->dono.nome);

            printf("Novo CPF do Proprietário: (11 digitos)");
            do {
                scanf(" %[^\n]%*c", terrenos[i] -> dono.cpf);
                if (validarCPF(terrenos[i]->dono.cpf) == 0) {
                    printf("CPF invalido! Digite novamente: ");
                }
            } while (validarCPF(terrenos[i]->dono.cpf) == 0);

            printf("Novo Telefone do Proprietário: (inclua o DDD)");
            do {
                scanf(" %[^\n]%*c", terrenos[i] -> dono.telefone);
                if (validarTelefone(terrenos[i]->dono.telefone) == 0) {
                    printf("Telefone invalido! Digite novamente: ");
                }
            } while (validarTelefone(terrenos[i]->dono.telefone) == 0);

            printf("Nova Data de Nascimento do Proprietário (dd/mm/aaaa): ");
            do {
                scanf("%d/%d/%d", &terrenos[i] -> dono.data_nasc.dia,
                                  &terrenos[i] -> dono.data_nasc.mes,
                                  &terrenos[i] -> dono.data_nasc.ano);
                if (validarData(terrenos[i]->dono.data_nasc.dia,
                                terrenos[i]->dono.data_nasc.mes,
                                terrenos[i]->dono.data_nasc.ano) == 0) {
                    printf("Data inválida! Digite novamente: ");
                }
            } while (validarData(terrenos[i]->dono.data_nasc.dia,
                                 terrenos[i]->dono.data_nasc.mes,
                                 terrenos[i]->dono.data_nasc.ano) == 0);
            
            //coleta dos novos dados dos terrenos
            printf("Novo Comprimento do Terreno (m): ");
            scanf("%f", &terrenos[i]->comprimento);

            printf("Nova Largura do Terreno (m): ");
            scanf("%f", &terrenos[i]->largura);

            //recalculando a area
            terrenos[i]->area = (terrenos[i] -> comprimento) * (terrenos[i] -> largura);
            printf("Área Total Recalculada (m²): %.2f\n", terrenos[i]->area); 

            //novo preco do m2
            printf("Novo Preço do Metro Quadrado (R$): ");
            scanf("%f", &terrenos[i]->preco_m2);

            //nova data da compra:
            printf("Nova Data da Compra (dd/mm/aaaa): ");
            do {
            scanf("%d/%d/%d", &terrenos[i] -> data_compra.dia,
                              &terrenos[i] -> data_compra.mes,
                              &terrenos[i] -> data_compra.ano);
            if (validarDataCompra(terrenos[i]->data_compra.dia,
                                  terrenos[i]->data_compra.mes,
                                  terrenos[i]->data_compra.mes) == 0) {
                    printf("Data inválida! Digite novamente: ");
                }
            } while (validarDataCompra(terrenos[i]->data_compra.dia,
                                       terrenos[i]->data_compra.mes,
                                       terrenos[i]->data_compra.mes) == 0);
            
            //limpa o buffer caso ele exista
            while (getchar() != '\n'); 
            
            printf("\n>> Sucesso! Terreno com ID %d atualizado.\n", id);
            break;
        }
    }
    if (!encontrado) {//se o terreno nao foi encontrado
        printf("\nERRO: Terreno com ID %d não encontrado ou posição vazia.\n", id);
    }
}

double calcularValorTerreno(Terrenos ** terrenos, int id){
    int indice = buscarIndicePorId(terrenos, id);
    double valor;
    
    if (indice < 0 || indice > 99) return 0;
    
    //verificacoes
    if(indice == -1) return 0;//nao achou
    if(terrenos[indice] == NULL) return 0;

    valor = (terrenos[indice] -> area) * (terrenos[indice] -> preco_m2);
    
    return valor;
}

int contarTerrenosOcupados(Terrenos ** terrenos){
    int i;
    int contador = 0;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            contador++;
        }
    }
    return contador;
}

int contarTerrenosLivres(Terrenos ** terrenos){
    int i;
    int contador = 0;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] == NULL) {
            contador++;
        }
    }
    return contador;
}

double calcularValorTotal(Terrenos ** terrenos){
    double total = 0;
    int i;

    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            total += calcularValorTerreno(terrenos, terrenos[i]->id);
        }
    }
    return total;
}

void salvarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){
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
            fprintf(arquivo, "%s\n", terrenos[i] -> dono.nome);
            fprintf(arquivo, "%s\n", terrenos[i] -> dono.cpf);
            fprintf(arquivo, "%s\n", terrenos[i] -> dono.telefone);

            //data de nascimento
            fprintf(arquivo, "%02d %02d %02d\n", terrenos[i]->dono.data_nasc.dia,
                                                 terrenos[i]->dono.data_nasc.mes,
                                                 terrenos[i]->dono.data_nasc.ano);

            //dimensoes e preco
            fprintf(arquivo, "%f\n", terrenos[i]->comprimento);
            fprintf(arquivo, "%f\n", terrenos[i]->largura);
            fprintf(arquivo, "%f\n", terrenos[i]->area);
            fprintf(arquivo, "%f\n", terrenos[i]->preco_m2);

            //data de compra
            fprintf(arquivo, "%02d %02d %02d\n", terrenos[i]->data_compra.dia,
                                                 terrenos[i]->data_compra.mes,
                                                 terrenos[i]->data_compra.ano);

            qtdd_terrenos_salvos++;
        }
    }
    fclose(arquivo);

    printf("\nConcluido: %d terreno(s) salvo(s) no arquivo '%s'.\n", qtdd_terrenos_salvos, nomeArquivo);
}

void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo){
    FILE * arquivo = fopen(nomeArquivo, "r");

    //verificacao do malloc
    if(arquivo == NULL){
        printf("[AVISO] Arquivo '%s' nao encontrado. Iniciando base vazia.\n", nomeArquivo);
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
            break;
        }
        terrenos[i] = (Terrenos *)malloc(sizeof(Terrenos));

        //verificacao do malloc
        if(terrenos[i] == NULL){
            printf("[ERRO] Falha ao alocar memoria RAM. Carregamento interrompido.\n");
            break;
        }

        //preenchimento dos dados

        terrenos[i]->id = id_aux;

        //strings
        fscanf(arquivo, "%[^\n]%*c", terrenos[i] -> dono.nome);
        fscanf(arquivo, "%[^\n]%*c", terrenos[i] -> dono.cpf);
        fscanf(arquivo, "%[^\n]%*c", terrenos[i] -> dono.telefone);

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
    printf(">> Sistema inicializado com sucesso! %d terrenos foram recuperados do arquivo de texto.\n", i);
}

int mTerreno_ordenado(Terrenos **terrenos){
    int id_escolhida=0;//verifica se ja escolheu a id
    int sem_terrenos = 1;//verifica se tem terrenos cadastrados

    printf("\n--- PROCURANDO TERRENO PARA APAGAR ---\n");

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
        printf("[AVISO] Nenhum terreno encontrado na lista para apagar.\n");
    }else{
        printf("\n[FIM DA LISTA] Nenhum terreno foi selecionado.\n");
    }
    //percorreu todos os terrenos e não escolheu nenhum
    return -1;
}

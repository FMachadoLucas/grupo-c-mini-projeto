#include <stdio.h>
#include <stdlib.h>
#include "terrenos.h"

int main (int argc, char * argv[]){
    int opcao;
    int id;
    double valorTerreno;
    int dadosAlterados=0;//case 0
    int opcaoSalvar;//case 0

    //verifica os parametros da main
    if(argc < 2){
        printf("Erro: Nome do arquivo de dados nao informado.\n");
        printf("Execute da seguinte forma: ./nome_do_programa nome_do_arquivo_de_texto.txt\n");
        return 0;
    }

    //salva o nome do arquivo informado pelo usuario
    char * nomeArquivo = argv[1];

    //vetor de ponteiros
    Terrenos *meusTerrenos[100];

    //NULL em todas as posicoes do vetor
    inicializarVetor(meusTerrenos);

    //verifica se ja existem dados no arquivo
    carregarTerrenos(meusTerrenos, nomeArquivo);

    do{

        //menu
        printf("================= MENU DO SISTEMA DE LOTEAMENTO =================\n\n");
        printf("Qual ação você deseja executar?\n");
        printf("(Digite o numero em parenteses para a seguinte opcao requerida)\n\n");
        printf("(0) SAIR (fecha o programa);\n");
        printf("(1) Criar um novo terreno\n");
        printf("(2) Apagar um terreno existente;\n");
        printf("(3) Mostrar as informações de um terreno;\n");
        printf("(4) Editar as informações de um terreno existente;\n");
        printf("(5) Verificar o valor de determinado terreno;\n");
        printf("(6) Verificar a quantidade de terrenos ocupados no momento;\n");
        printf("(7) Verificar a quantidade de terrrenos disponiveis no momento;\n");
        printf("(8) Calcular o valor de todos os terrenos ocupados somados;\n");
        printf("(9) SALVAR os dados de todos os terrenos.\n\n");
        printf("=================================================================\n");

        //leitura da opcao do usuario
        scanf("%d%*c", &opcao);

        //verificar a opcao do usuario
        switch (opcao){
            case 0: {//sair do programa
                if(dadosAlterados == 1){
                    printf("[ATENCAO]: Existem alteracoes nos loteamentos que nao foram salvas.\n");
                    printf("Deseja salvar antes de sair?\n");
                    printf("(1) SIM. Salvar e sair.\n");
                    printf("(2) NAO. Sair sem salvar (CUIDADO: as alteracoes mais recentes serao perdidas!\n)");
                    printf("Escolha: ");
                    scanf("%d", &opcaoSalvar);
    
                    while(opcao!=1 && opcaoSalvar!=2){
                        printf("[ERRO]: Opcao invalida! Digite 1 para SIM ou (2) para NAO: ");
                        scanf("%d", &opcaoSalvar);
                    }

                    if(opcaoSalvar==1){
                        salvarTerrenos(meusTerrenos, nomeArquivo);
                        printf("Dados Salvos. Encerrando...\n");
                    }else printf("Encerrando sem salvar...\n");

                }else printf("Saindo do sistema...\n");

                break;
            }
            case 1: {
                criarTerreno(meusTerrenos);
                dadosAlterados = 1;
                break;
            }
            case 2: {
                deletarTerreno(meusTerrenos);
                dadosAlterados = 1;
                break;
            }
            case 3: {
                printf("Digite o ID para visualizar o terreno: ");
                scanf("%d", &id);
                mostrarTerreno(meusTerrenos, id);
                break;
            }
            case 4: {
                printf("Digite a ID para EDITAR o terreno: ");
                scanf("%d", &id);
                editarTerreno(meusTerrenos, id);
                dadosAlterados = 1;
                break;   
            }
            case 5: {
                printf("Digite a ID para calcular o valor do terreno: ");
                scanf("%d", &id);
                valorTerreno = calcularValorTerreno(meusTerrenos, id);
                if(valorTerreno > 0){
                    printf(">> Valor de Venda do Terreno %d: R$ %.2lf\n", id, valorTerreno);
                }else{
                    printf(">> Terreno nao encontrado ou invalido\n");
                }
                break;
            }
            case 6: {
                printf(">> Terrenos Ocupados: %d\n", contarTerrenosOcupados(meusTerrenos));
                break;
            }
            case 7: {
                printf(">> Terrenos Disponiveis: %d\n", contarTerrenosLivres(meusTerrenos));
                break;
            }
            case 8: {
                printf(">> Valor Total do Loteamento: R$ %.2lf\n", calcularValorTotal(meusTerrenos));
                break;
            }
            case 9: {
                salvarTerrenos(meusTerrenos, nomeArquivo);
                dadosAlterados = 1;
                break;
            }
            default:
                printf("[ERRO]: Opção Inválida! Digite outra opção.\n");
        }
    }while (opcao != 0);



    return 0;

}

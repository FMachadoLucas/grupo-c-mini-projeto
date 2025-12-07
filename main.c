#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terrenos.h"

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

int main (int argc, char * argv[]){
    int opcao;
    int id;
    double valorTerreno;
    int dadosAlterados=0;//case 0
    int opcaoSalvar;//case 0

    srand(time(0));

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
        //limpar a tela
        limparTela();

        //menu

        printf("\n================ SISTEMA GERENCIADOR DE BAIRROS ================\n");
        if(dadosAlterados != 0) printf("[!] ATENCAO: Existem alteracoes nao salvas.\n");
        printf("----------------------------------------------------------------\n");
        printf("\nQual acao voce deseja executar?\n\n");
        printf("[1] Criar Novo Terreno\n");
        printf("[2] Apagar Terreno\n");
        printf("[3] Mostrar Detalhes do Terreno\n");
        printf("[4] Editar Terreno\n");
        printf("[5] Consultar o Valor de Venda de UM Terreno\n");
        printf("[6] RELATORIO: Quantidade de Lotes Ocupados\n");
        printf("[7] RELATORIO: Quantidade de Lotes Disponiveis\n");
        printf("[8] RELATORIO: Valor TOTAL do Loteamento\n");
        printf("[9] SALVAR DADOS\n");
        printf("[0] SAIR (fechar o programa);\n");
        printf("=================================================================\n");
        printf("Escolha uma opcao: ");

        if(scanf("%d%*c", &opcao) != 1){
            printf("Entrada INVALIDA. Reinicie o programa.\n");
            return 0;
        }
        printf("\n");

        //verificar a opcao do usuario
        switch (opcao){
            case 0: {//sair do programa
                if(dadosAlterados == 1){
                    printf("[!] ATENCAO: Existem alteracoes nao salvas.\n");
                    printf("Deseja salvar antes de sair?\n");
                    printf("[1] SIM. Salvar e sair.\n");
                    printf("[2] NAO. Sair sem salvar (CUIDADO: as alteracoes mais recentes serao perdidas!\n)");
                    printf("Escolha: ");
                    scanf("%d", &opcaoSalvar);
    
                    while(opcaoSalvar != 1 && opcaoSalvar != 2){
                        printf("[ERRO]: Opcao invalida! Digite 1 para SIM ou (2) para NAO: ");
                        scanf("%d", &opcaoSalvar);
                    }

                    if(opcaoSalvar == 1){
                        salvarTerrenos(meusTerrenos, nomeArquivo);
                        printf(">> Dados Salvos. Encerrando...\n");
                    }else printf(">> Encerrando sem salvar...\n");

                }else printf(">> Saindo do sistema...\n");

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
        //pausa
        if(opcao != 0){
            printf("\n\n------------------------------------------------");
            printf("\n[Pressione ENTER para voltar ao menu principal]");
        }

        //consumir lixo
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        getchar();

    }while (opcao != 0);

    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include "terrenos.h"

int main (int argc, char * argv[]){
    int opcao;
    int id;

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
                break;
            }
            case 1: {
                criarTerreno(meusTerrenos);
                break;
            }
            case 2: {
                deletarTerreno(meusTerrenos);
                break;
            }
            case 3: {
                //verificar depois sobre a id
                printf("Digite o número do id: ");
                scanf("%d", &id);
                mostrarTerreno(meusTerrenos, id);
                break;
            }
            case 4: {
                mostrarTerreno(meusTerrenos, id);
                break;   
            }
            case 5: {
                editarTerreno(meusTerrenos, id);
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            default:
                printf("ERRO: Opção Inválida! Digite outra opção.\n");
        }
    }while (opcao != 0);



    return 0;

}

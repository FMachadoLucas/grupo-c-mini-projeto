#ifndef TERRENOS_H
#define TERRENOS_H

//definicao das structs

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[100];
    char cpf[20];
    Data data_nasc;
    char telefone[20];
}Pessoa;

typedef struct{
    int id;
    Pessoa dono;
    Data data_compra;
    float largura, comprimento, area, preco_m2;
}Terrenos;

//funcoes

/**
 * @brief Inicializa o vetor de ponteiros para a struct Terrenos com NULL
 * 
 * @param terrenos Vetor de ponteiros para struct Terrenos
 */
void inicializarVetor(Terrenos ** terrenos);
/**
 * @brief Aloca memoria, coleta dados do usuario e cria um novo terreno
 * 
 * @param terrenos vetor de ponteiros para a manipulacao de dados dos terrenos
 */
void criarTerreno(Terrenos ** terrenos);
/**
 * @brief Busca um terreno (por ID ou lista), libera sua memoria e remova do vetor
 * 
 * @param terrenos Vetor de ponteiros para os terrenos
 */
void deletarTerreno(Terrenos ** terrenos);
/**
 * @brief Exibe todas as informacoes de um terreno especifico
 * 
 * @param terrenos Vetor de ponteiro para os terrenos
 * @param id Identificador unico do terreno a ser exibido
 */
void mostrarTerreno(Terrenos ** terrenos, int id);
/**
 * @brief Permite ao usiario alterar os dados de um terreno existente.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @param id Identificador unico do terreno que sera editado.
 */
void editarTerreno(Terrenos ** terrenos, int id);
/**
 * @brief Calcula o valor de venda de um terreno especifico a partir da area e do preco do m2 informado.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @param id Identificador unico do terreno para o calculo do valor de venda.
 * @return double Valor total do terreno.
 */
double calcularValorTerreno(Terrenos ** terrenos, int id);
/**
 * @brief Conta quantos terrenos estao cadastrados.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @return int Quantidade de terrenos ocupados.
 */
int contarTerrenosOcupados(Terrenos ** terrenos);
/**
 * @brief Conta quantas vagas estao disponiveis no vetor terrenos.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @return int Quantidade de vagas livres.
 */
int contarTerrenosLivres(Terrenos ** terrenos);
/**
 * @brief Calcula a soma do valor de venda de todos os terrenos cadastrados.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @return double Valor total de venda de todos os terrenos.
 */
double calcularValorTotal(Terrenos ** terrenos);
/**
 * @brief Salva todos os dados da memoria em um arquivo de texto.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @param nomeArquivo Nome do arquivo onde os dados serao salvos.
 */
void salvarTerrenos(Terrenos ** terrenos, const char *nomeArquivo);
/**
 * @brief Le um arquivo de texto contendo as informacoes do terrenos e reconstroi as structs na memoria ram.
 * 
 * @param terrenos Vetor de ponteiros onde os dados serao carregados.
 * @param nomeArquivo Nome do arquivo que sera lido
 */
void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo);
/**
 * @brief Funcao auxiliar para listar os terrenos e permitir a selecao pelo usuario.
 * 
 * @param terrenos Vetor de ponteiros para os terrenos.
 * @return int Retorna a ID escolhida pelo usuario ou -1 se cancelar.
 */
int mTerreno_ordenado(Terrenos **terrenos);

#endif

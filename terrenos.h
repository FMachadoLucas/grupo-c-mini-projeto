#ifndef TERRENOS_H
#define TERRENOS_H
#include <time.h>

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
 * @brief Busca a posicao (indice) de um terreno no vetor pelo seu id
 * 
 * @param terrenos vetor de ponteiros para os terrenos
 * @param id O ID que estamos procurando
 * @return int Retorna o indice ou -1 se nao encontrar
 */
int buscarIndicePorId(Terrenos ** terrenos, int id);
/**
 * @brief Aloca memoria, coleta dados do usuario e cria um novo terreno
 * 
 * @param terrenos vetor de ponteiros para a manipulacao de dados dos terrenos
 */
void criarTerreno(Terrenos ** terrenos);
/**
 * @brief Analisa se o cpf contem apenas numeros e se contem 11 digitos
 * 
 * @param cpf String contendo o cpf a ser validado
 * @return int int Retorna 1 se o cpf for valido e 0 se nao for valido
 */
int validarNome(char nome[]);
/**
 * @brief Analisa se o nome contem apenas espaços ou se contem numeros
 * 
 * @param nome String contendo o nome a ser validado
 * @return int int Retorna 1 se o nome vor valido e 0 se nao for valido
 */
int validarCPF(char cpf[]);
/**
 * @brief Analisa se o numero de telefone contem apenas numeros e se contem 11 digitos (com o DDD)
 * 
 * @param tel String contendo o telefone a ser validado
 * @return int int Retorna 1 se o telefone vor valido e 0 se nao for valido
 */
int validarTelefone(char tel[]);
/**
 * @brief Analisa se a data fornecida (dia mes e ano) eh valida
 * 
 * @param dia dia da data
 * @param mes mes da data
 * @param ano ano da data
 * @return int Retorna 1 se a data for valida e 0 se nao
 */
int validarData(int dia, int mes, int ano);
/**
 * @brief Analisa se a data de compra fornecida (dia mes e ano) eh valida
 * 
 * @param dia dia da data
 * @param mes mes da data
 * @param ano ano da data
 * @return int Retorna 1 se a data for valida e 0 nao
 */
int validarDataCompra(int dia, int mes, int ano);
/**
 * @brief Busca um terreno (por ID ou lista), libera sua memoria e remova do vetor
 * 
 * @param terrenos terrenos Vetor de ponteiros para os terrenos
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

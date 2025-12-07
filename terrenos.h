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
 * @param terrenos struct contendo as informacoes de cada terreno
 */
void inicializarVetor(Terrenos ** terrenos);
void criarTerreno(Terrenos ** terrenos);
void deletarTerreno(Terrenos ** terrenos);
void mostrarTerreno(Terrenos ** terrenos, int id);
void editarTerreno(Terrenos ** terrenos, int id);
double calcularValorTerreno(Terrenos ** terrenos, int id);
int contarTerrenosOcupados(Terrenos ** terrenos);
int contarTerrenosLivres(Terrenos ** terrenos);
double calcularValorTotal(Terrenos ** terrenos);
void salvarTerrenos(Terrenos ** terrenos, const char *nomeArquivo);
void carregarTerrenos(Terrenos ** terrenos, const char *nomeArquivo);
/**
 * @brief Mostrar os terrenos em ordem crescente de ids
 * 
 * @param terrenos struct de terrenos
 * @return int retorna a id que o usuário deseja
 */
int mTerreno_ordenado(Terrenos **terrenos);
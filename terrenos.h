//definicao das structs

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct pessoa{
    char nome[128];
    char cpf[15];
    Data data_nasc;
    char telefone[20];
}Pessoa;

typedef struct terrenos{
    int id;
    Pessoa dono;
    Data data_compra;
    float largura, comprimento, area, preco_m2;
}Terrenos;

//funcoes
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
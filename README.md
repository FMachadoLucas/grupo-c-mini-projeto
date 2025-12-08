# Mini Projeto - Sistema Gerenciador de Bairros

Este projeto foi desenvolvido como atividade avaliativa da disciplina de Introdução à Programação. O objetivo foi criar um sistema completo para gerenciamento de terrenos e lotes imobiliários em linguagem C, utilizando conceitos avançados como alocação dinâmica de memória, manipulação de arquivos (persistência de dados) e estruturação de dados complexos.

O desenvolvimento seguiu as instruções de manipular um vetor de ponteiros para estruturas (structs), garantindo otimização de memória e organização modular do código.

🎥 Vídeo de apresentação:

👥 Integrantes do Grupo

Alunos:

    Lucas Fernandes Machado

    Sara Raquel Lima Montelo

    Sarah Cristina de Oliveira

🚀 Como Compilar e Executar

O projeto está modularizado em três arquivos principais: main.c, terrenos.c e terrenos.h. Além disso, o programa exige que o nome do arquivo de banco de dados seja passado como argumento via linha de comando.

1. Compilação

Abra o terminal na pasta do projeto e execute o comando abaixo para compilar todos os módulos juntos:
Bash

gcc main.c terrenos.c -o main

2. Execução

Para rodar, você deve informar o nome do arquivo .txt onde os dados serão salvos/lidos.

No Linux/Mac:
Bash

./main dados_terrenos.txt

No Windows:
DOS

gerenciador.exe dados_terrenos.txt

    Nota: Se o arquivo dados_terrenos.txt não existir, o programa criará um novo automaticamente ao salvar. Se já existir, ele carregará os dados automaticamente ao iniciar.

📖 Instruções de Uso

O sistema funciona através de um menu interativo no console. O fluxo de utilização segue a lógica de CRUD (Create, Read, Update, Delete):

    Menu Principal: Ao iniciar, o sistema carrega os dados do arquivo (se houver) e exibe as opções de gerenciamento.

    Identificação: Cada terreno é identificado unicamente por um ID (gerado aleatoriamente ou inserido manualmente).

Entrada de Dados: Ao cadastrar proprietários ou datas, siga os formatos solicitados (ex: datas no formato dd/mm/aaaa). O sistema possui validações para CPF, Telefone e Datas.

Persistência: Lembre-se de utilizar a opção [9] SALVAR DADOS antes de fechar o programa para garantir que as alterações sejam gravadas no arquivo de texto.

## 🛠️ Funcionalidades Implementadas

O sistema suporta até 100 terrenos simultâneos e oferece as seguintes operações:

| Opção | Funcionalidade | Descrição |
|:---:|:--- |:--- |
| **1** | **Criar Novo Terreno** | Aloca memória dinamicamente, valida CPF/Datas e cadastra um novo lote. |
| **2** | **Apagar Terreno** | Remove um lote do sistema e libera a memória associada (Free). |
| **3** | **Mostrar Detalhes** | Exibe proprietário, dimensões, preços e datas de um ID específico. |
| **4** | **Editar Terreno** | Permite alterar dados do proprietário ou dimensões do lote existente. |
| **5** | **Consultar Valor** | Calcula o preço de venda de um terreno específico (Área * Preço m²). |
| **6** | **Relatório: Ocupados** | Exibe quantos lotes estão cadastrados atualmente. |
| **7** | **Relatório: Livres** | Exibe quantas vagas ainda existem no vetor (de 100 totais). |
| **8** | **Relatório: Total** | Calcula o valor somado de todos os imóveis cadastrados no bairro. |
| **9** | **Salvar Dados** | Escreve todos os dados da memória RAM para o arquivo `.txt`. |
| **0** | **Sair** | Encerra o programa (com alerta caso haja dados não salvos). |

⚙️ Detalhes da Implementação Técnica

Para atender aos requisitos acadêmicos e técnicos do projeto:

    Estruturas de Dados (Structs): Foram utilizadas três estruturas interligadas para organizar os dados:

    Data: Armazena dia, mês e ano.

    Pessoa: Armazena nome, CPF, telefone e a struct Data (nascimento).

    Terrenos: Armazena ID, dimensões, preço, a struct Pessoa (dono) e a struct Data (compra).

Alocação Dinâmica: O sistema não ocupa memória desnecessária. O vetor principal (Terrenos *meusTerrenos[100]) armazena apenas ponteiros. A memória real da struct é alocada com malloc apenas quando um terreno é criado e liberada com free quando deletado.

Manipulação de Arquivos: A persistência é feita lendo e escrevendo em arquivo de texto plano, permitindo que os dados sejam recuperados mesmo após fechar o programa.

Validações: Foram implementadas funções auxiliares para garantir a integridade dos dados:

    validarCPF: Verifica se possui 11 dígitos numéricos.

    validarData: Verifica dias, meses e anos válidos.
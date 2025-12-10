# Mini Projeto - Sistema Gerenciador de Bairros

Este projeto foi desenvolvido como atividade avaliativa da disciplina de Introdução à Programação. O objetivo foi criar um sistema completo para gerenciamento de terrenos e lotes imobiliários em linguagem C, utilizando conceitos avançados como alocação dinâmica de memória, manipulação de arquivos (persistência de dados) e estruturação de dados complexos.

O desenvolvimento seguiu as instruções de manipular um vetor de ponteiros para estruturas (structs), garantindo otimização de memória e organização modular do código.

🎥 Vídeo de apresentação:

## 🔗 Link do Repositório

Você pode encontrar o código-fonte completo e o histórico de commits no GitHub:
**[https://github.com/FMachadoLucas/grupo-c-mini-projeto](https://github.com/FMachadoLucas/grupo-c-mini-projeto)**

## 👥 Integrantes do Grupo

**Alunos:**
* Lucas Fernandes Machado
* Sara Raquel Lima Montelo
* Sarah Cristina de Oliveira

## 🚀 Como Compilar e Executar

O projeto está modularizado em três arquivos principais: `main.c`, `terrenos.c` e `terrenos.h`. Além disso, o programa **exige** que o nome do arquivo de banco de dados seja passado como argumento.

### 1. Compilação
Abra o terminal na pasta do projeto e execute o seguinte comando:

**gcc main.c terrenos.c -o gerenciador**

### 2. Execução
Para rodar, você deve informar o nome do arquivo `.txt` onde os dados serão salvos.

* **No Linux/Mac:** Digite **./gerenciador dados_terrenos.txt**
* **No Windows:** Digite **gerenciador.exe dados_terrenos.txt**

> **Nota:** Se o arquivo `dados_terrenos.txt` não existir, o programa criará um novo automaticamente ao salvar.

## 📖 Instruções de Uso

O sistema funciona através de um menu interativo no console. O fluxo de utilização segue a lógica de CRUD (Create, Read, Update, Delete):

1. **Menu Principal:** Ao iniciar, o sistema carrega os dados do arquivo (se houver) e exibe as opções de gerenciamento.
2. **Identificação:** Cada terreno é identificado unicamente por um **ID** (gerado aleatoriamente ou inserido manualmente).
3. **Entrada de Dados:** Ao cadastrar proprietários ou datas, siga os formatos solicitados (ex: datas no formato `dd/mm/aaaa`). O sistema possui validações automáticas.
4. **Persistência:** Lembre-se de utilizar a opção **Salvar Dados** antes de fechar o programa para garantir que as alterações sejam gravadas no arquivo.

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

## ⚙️ Detalhes da Implementação Técnica

Para atender aos requisitos acadêmicos e técnicos do projeto:

* **Estruturas de Dados (Structs):** Foram utilizadas três estruturas interligadas para organizar os dados:
    * `Data`: Armazena dia, mês e ano.
    * `Pessoa`: Armazena nome, CPF, telefone e a struct `Data` (nascimento).
    * `Terrenos`: Armazena ID, dimensões, preço, a struct `Pessoa` (dono) e a struct `Data` (compra).

* **Alocação Dinâmica:** O sistema otimiza o uso da memória RAM. O vetor principal (`Terrenos *meusTerrenos[100]`) armazena apenas ponteiros. A memória real da struct é alocada com `malloc` apenas quando um terreno é criado e liberada com `free` quando deletado.

* **Manipulação de Arquivos:** A persistência é feita lendo e escrevendo em arquivo de texto, permitindo que os dados sejam recuperados mesmo após fechar o programa.

### Validações Implementadas
Para garantir a integridade dos dados, foram criadas funções específicas:
* **Validação de CPF:** Verifica se o CPF inserido possui 11 dígitos numéricos e aplica a lógica de verificação.
* **Validação de Data:** Impede o cadastro de datas inexistentes (como dia 32 ou mês 13).
* **Validação de Nome:** Impede a inserção de números ou caracteres inválidos no nome do proprietário, aceitando apenas letras.
* **Validação de Telefone:** Verifica a quantidade de dígitos (DDD + número) e aplica a verificação de dígitos repetidos (ex: (11) 1111-1111).

### Recursos de Interface e Usabilidade
Para melhorar a experiência do usuário, o código conta com:
* **Proteção de saída:** O sistema monitora alterações não salvas (flag dadosAlterados). Se o usuário tentar sair sem salvar, um alerta é exibido perguntando se deseja salvar antes de encerrar.
* **Busca Visual para Exclusão:** Na opção de apagar terreno, caso o usuário não saiba o ID, o sistema oferece um modo de visualização (mTerreno_ordenado) que exibe os terrenos um a um, permitindo a exclusão interativa.
* **Tratamento de Buffer:** Uso estratégico de limpeza de buffer (%*c e loops getchar) para evitar erros de leitura e "pulos" de tela indesejados.
* **Portabilidade:** A função limparTela foi implementada com diretivas de pré-processador (#ifdef _WIN32), funcionando corretamente tanto em Windows (cls) quanto em Linux/macOS (clear).

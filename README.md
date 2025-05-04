# 🌳 Trabalho de Árvores e Grafos em C

## 🎯 Objetivo

Implementar e comparar o desempenho das operações básicas em três tipos de árvores binárias:

- **ABB** (Árvore Binária de Busca)
- **AVL** (Árvore AVL)
- **RB** (Árvore Rubro-Negra)

## ⚙️ Operações Avaliadas

Cada tipo de árvore deverá ser testado nas seguintes operações:

- Inclusão
- Busca
- Remoção

O desempenho será medido em **milissegundos**, e os resultados deverão ser comparados em uma tabela.

## 📊 Benchmark

As árvores devem ser testadas com diferentes quantidades de chaves:

- **1.000**
- **10.000**
- **100.000**
- **1.000.000**

### 🧪 Tabela de Resultados Esperada

| Qtde de chaves | ABB Inserção | ABB Exclusão | ABB Busca | AVL Inserção | AVL Exclusão | AVL Busca | RB Inserção | RB Exclusão | RB Busca |
|----------------|--------------|--------------|-----------|--------------|--------------|-----------|-------------|-------------|----------|
| 1.000          | ms           | ms           | ms        | ms           | ms           | ms        | ms          | ms          | ms       |
| 10.000         | ms           | ms           | ms        | ms           | ms           | ms        | ms          | ms          | ms       |
| 100.000        | ms           | ms           | ms        | ms           | ms           | ms        | ms          | ms          | ms       |
| 1.000.000      | ms           | ms           | ms        | ms           | ms           | ms        | ms          | ms          | ms       |

## 🛠️ Requisitos Técnicos

- As **três bibliotecas de árvores** devem ser integradas em **um único programa**.
- O programa deve ser capaz de:
  - Inserir uma grande quantidade de chaves automaticamente.
  - Medir o tempo de execução de cada operação.
  - Exibir os resultados organizados para análise.

## 💻 Linguagem

- **C (ANSI C)**

## 📦 Entrega no Moodle UTFPR

- Código-fonte comentado.
- Arquivo `README.md` com essa especificação.
- Saída com os tempos em milissegundos no terminal ou exportados em um arquivo `.csv` ou `.txt`.

## 📁 Estrutura do Projeto

### 1. `benchmark/`

Contém ferramentas para avaliação de desempenho das árvores:

- `benchmark.h`: Funções para cronometrar operações de inserção, busca e exclusão nas árvores ABB, AVL e RB.
- `bm_gerador_dados.c`: Gera arquivos de dados para testes, criando vetores com diferentes tamanhos (1K, 10K, 100K, 1M) para operações de inserção, busca e exclusão.
- Arquivos `.txt`: Dados gerados pelo `bm_gerador_dados.c`, utilizados nos testes de benchmarking.

### 2. `dados/`

Responsável pela criação e manipulação dos arquivos de dados:

- `embaralhador.c`: Gera arquivos `.txt` com dados embaralhados utilizando o algoritmo de Fisher-Yates. Também salva vetores ordenados para testes específicos com árvores AVL de 100K e 1M de elementos.

### 3. `operacoes/`

Contém as implementações das estruturas de árvores:

- Árvores ABB, AVL e RB: Implementações completas com funções de inserção, busca, exclusão e balanceamento.
- Função específica para AVL: Criação de uma árvore AVL balanceada a partir de vetores ordenados, otimizando a inserção de grandes volumes de dados.

### Arquivos na Raiz do Projeto

- `main.c`: Ponto de entrada do programa, onde são chamadas as funções de criação das árvores e execução dos benchmarks.
- `arvores.h`: Agrega os `#includes` das bibliotecas necessárias para o `main.c`.
- `TAD_arvore.h`: Define as assinaturas das funções e estruturas (`structs`) utilizadas nas árvores. As estruturas de nós são compartilhadas entre ABB e AVL, com uma estrutura distinta para a RB.
- `utils.h`: Funções auxiliares utilizadas em todo o projeto, como `comparaInt`, `ler_arquivo_para_vetor`, `formatarMilhar`, entre outras.

## 🚀 Como Executar

1. Compile o projeto utilizando um compilador C de sua preferência.
2. Execute o programa principal (`main.c`) para criar as árvores e realizar os benchmarks.
3. Utilize os arquivos de dados gerados em `dados/` para testar diferentes cenários e volumes de dados.

## 📝 Observações

- Os arquivos de dados gerados são essenciais para os testes de desempenho. Certifique-se de executá-los antes de iniciar os benchmarks.
- A função de criação de árvore AVL balanceada é especialmente útil para grandes volumes de dados, como 100K e 1M de elementos, garantindo melhor desempenho nas operações.


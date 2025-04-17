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

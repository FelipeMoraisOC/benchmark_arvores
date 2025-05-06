#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Utils.h"
#include "Arvores.h"


#define T1K   1000
#define T10K  10000
#define T100K 100000
#define T1M   1000000

int main() {
    //Vetores de criação de arvores
    int* vetor1k   = ler_arquivo_para_vetor("dados/1k.txt",   T1K);
    int* vetor10k  = ler_arquivo_para_vetor("dados/10k.txt",  T10K);
    int* vetor100k = ler_arquivo_para_vetor("dados/100k.txt", T100K);
    int* vetor1m   = ler_arquivo_para_vetor("dados/1m.txt",   T1M);
    //Ordenados para criar AVL 100k e 1M
    int* vetor_ordenado100k = ler_arquivo_para_vetor("dados/ordenado_100k.txt", T100K);
    int* vetor_ordenado1m = ler_arquivo_para_vetor("dados/ordenado_1m.txt", T1M);

    //Vetores de benchmark de busca
    int* vetor_busca_1k     = ler_arquivo_para_vetor("benchmark/busca_1k.txt",   100);
    int* vetor_busca_10k    = ler_arquivo_para_vetor("benchmark/busca_10k.txt",  T1K);
    int* vetor_busca_100k   = ler_arquivo_para_vetor("benchmark/busca_100k.txt", T10K);
    int* vetor_busca_1m     = ler_arquivo_para_vetor("benchmark/busca_1m.txt",   T100K);

    //Vetores de benchmark de inclusão
    int* vetor_inclusao_1k   = ler_arquivo_para_vetor("benchmark/inclusao_1k.txt",   100);
    int* vetor_inclusao_10k  = ler_arquivo_para_vetor("benchmark/inclusao_10k.txt",  T1K);
    int* vetor_inclusao_100k = ler_arquivo_para_vetor("benchmark/inclusao_100k.txt", T10K);
    int* vetor_inclusao_1m   = ler_arquivo_para_vetor("benchmark/inclusao_1m.txt",   T100K);
    
     //Vetores de benchmark de exclusao
     int* vetor_exclusao_1k   = ler_arquivo_para_vetor("benchmark/exclusao_1k.txt",   100);
     int* vetor_exclusao_10k  = ler_arquivo_para_vetor("benchmark/exclusao_10k.txt",  T1K);
     int* vetor_exclusao_100k = ler_arquivo_para_vetor("benchmark/exclusao_100k.txt", T10K);
     int* vetor_exclusao_1m   = ler_arquivo_para_vetor("benchmark/exclusao_1m.txt",   T100K);

    //Verificação vetores
    if (!vetor1k           || !vetor10k           || !vetor100k           || !vetor1m)           return EXIT_FAILURE;
    if (!vetor_busca_1k    || !vetor_busca_10k    || !vetor_busca_100k    || !vetor_busca_1m)    return EXIT_FAILURE;
    if (!vetor_inclusao_1k || !vetor_inclusao_10k || !vetor_inclusao_100k || !vetor_inclusao_1m) return EXIT_FAILURE;
    if (!vetor_exclusao_1k || !vetor_exclusao_10k || !vetor_exclusao_100k || !vetor_exclusao_1m) return EXIT_FAILURE;
    if (!vetor_ordenado100k || !vetor_ordenado1m) return EXIT_FAILURE;

    //Salvar os resultados do benchmark
    int tamanhos[] = {T1K, T10K, T100K, T1M};
    BenchmarkResultados resultados[4];
    //----------------------------------------------------------------------------------------//
    //                                    Benchmark Árvores ABB                               //
    //----------------------------------------------------------------------------------------//
    //Criando arvores ABB
    printf("-------Criação ABB----\n");
    pDArvore arvoreABB1k       = criarArvoreBinaria(vetor1k,   T1K);
    pDArvore arvoreABB10k      = criarArvoreBinaria(vetor10k,  T10K);
    pDArvore arvoreABB100k     = criarArvoreBinaria(vetor100k, T100K);
    pDArvore arvoreABB1m       = criarArvoreBinaria(vetor1m,   T1M);
    pDArvore exc_arvoreABB1k   = criarArvoreBinaria(vetor1k,   T1K);
    pDArvore exc_arvoreABB10k  = criarArvoreBinaria(vetor10k,  T10K);
    pDArvore exc_arvoreABB100k = criarArvoreBinaria(vetor100k, T100K);
    pDArvore exc_arvoreABB1m   = criarArvoreBinaria(vetor1m,   T1M);
    printf("-------Busca ABB------\n");
    resultados[0].abb_busca    = benchmarkOperacaoBuscaABBVL(arvoreABB1k,   buscarInfo, vetor_busca_1k,   100,   "ABB");
    resultados[1].abb_busca    = benchmarkOperacaoBuscaABBVL(arvoreABB10k,  buscarInfo, vetor_busca_10k,  T1K,   "ABB");
    resultados[2].abb_busca    = benchmarkOperacaoBuscaABBVL(arvoreABB100k, buscarInfo, vetor_busca_100k, T10K,  "ABB");
    resultados[3].abb_busca    = benchmarkOperacaoBuscaABBVL(arvoreABB1m,   buscarInfo, vetor_busca_1m,   T100K, "ABB");
    printf("-------Inclusão ABB---\n");
    resultados[0].abb_insercao = benchmarkOperacaoInclusaoABBVL(arvoreABB1k,   incluirInfo, vetor_inclusao_1k,   100,   "ABB", 0);
    resultados[1].abb_insercao = benchmarkOperacaoInclusaoABBVL(arvoreABB10k,  incluirInfo, vetor_inclusao_10k,  T1K,   "ABB", 0);
    resultados[2].abb_insercao = benchmarkOperacaoInclusaoABBVL(arvoreABB100k, incluirInfo, vetor_inclusao_100k, T10K,  "ABB", 0);
    resultados[3].abb_insercao = benchmarkOperacaoInclusaoABBVL(arvoreABB1m,   incluirInfo, vetor_inclusao_1m,   T100K, "ABB", 0);
    printf("-------Exclusão ABB---\n");
    resultados[0].abb_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreABB1k,   excluirInfo, vetor_exclusao_1k,   100,   "ABB");
    resultados[1].abb_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreABB10k,  excluirInfo, vetor_exclusao_10k,  T1K,   "ABB");
    resultados[2].abb_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreABB100k, excluirInfo, vetor_exclusao_100k, T10K,  "ABB");
    resultados[3].abb_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreABB1m,   excluirInfo, vetor_exclusao_1m,   T100K, "ABB");
    //Free ABB
    {
        free(arvoreABB1k);
        free(arvoreABB10k);
        free(arvoreABB100k);
        free(arvoreABB1m);
        free(exc_arvoreABB1k);
        free(exc_arvoreABB10k);
        free(exc_arvoreABB100k);
        free(exc_arvoreABB1m);
    }
    //----------------------------------------------------------------------------------------//
    //                                    Benchmark Árvores AVL                               //
    //----------------------------------------------------------------------------------------//
    //Criando arvores AVL
    printf("-------Criação AVL----\n");
    pDArvore arvoreAVL1k       = criarArvoreAVL(vetor1k,   T1K);
    pDArvore arvoreAVL10k      = criarArvoreAVL(vetor10k,  T10K);
    pDArvore exc_arvoreAVL1k   = criarArvoreAVL(vetor1k,   T1K);
    pDArvore exc_arvoreAVL10k  = criarArvoreAVL(vetor10k,  T10K);

    pDArvore arvoreAVL100k     = criarArvoreAVLBalanceada(vetor_ordenado100k, T100K);
    pDArvore arvoreAVL1m       = criarArvoreAVLBalanceada(vetor_ordenado1m,   T1M);
    pDArvore exc_arvoreAVL100k = criarArvoreAVLBalanceada(vetor_ordenado100k, T100K);
    pDArvore exc_arvoreAVL1m   = criarArvoreAVLBalanceada(vetor_ordenado1m,   T1M);
    printf("-------Busca AVL------\n");
    resultados[0].avl_busca    = benchmarkOperacaoBuscaABBVL(arvoreAVL1k,   buscarInfoAVL, vetor_busca_1k,   100,   "AVL");
    resultados[1].avl_busca    = benchmarkOperacaoBuscaABBVL(arvoreAVL10k,  buscarInfoAVL, vetor_busca_10k,  T1K,   "AVL");
    resultados[2].avl_busca    = benchmarkOperacaoBuscaABBVL(arvoreAVL100k, buscarInfoAVL, vetor_busca_100k, T10K,  "AVL");
    resultados[3].avl_busca    = benchmarkOperacaoBuscaABBVL(arvoreAVL1m,   buscarInfoAVL, vetor_busca_1m,   T100K, "AVL");
    printf("-------Inclusão AVL---\n");
    resultados[0].avl_insercao = benchmarkOperacaoInclusaoABBVL(arvoreAVL1k,   incluirInfoAVL, vetor_inclusao_1k,   100,   "AVL", 0);
    resultados[1].avl_insercao = benchmarkOperacaoInclusaoABBVL(arvoreAVL10k,  incluirInfoAVL, vetor_inclusao_10k,  T1K,   "AVL", 0);
    resultados[2].avl_insercao = benchmarkOperacaoInclusaoABBVL(arvoreAVL100k, incluirInfoAVL, vetor_inclusao_100k, T1K,  "AVL", 1);
    resultados[3].avl_insercao = benchmarkOperacaoInclusaoABBVL(arvoreAVL1m,   incluirInfoAVL, vetor_inclusao_1m,   T1K, "AVL", 1);
    printf("-------Exclusão AVL---\n");
    resultados[0].avl_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL1k,   excluirInfoAVL, vetor_exclusao_1k,   100,   "AVL");
    resultados[1].avl_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL10k,  excluirInfoAVL, vetor_exclusao_10k,  T1K,   "AVL");
    resultados[2].avl_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL100k, excluirInfoAVL, vetor_exclusao_100k, T1K,  "AVL");
    resultados[3].avl_exclusao = benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL1m,   excluirInfoAVL, vetor_exclusao_1m,   T1K, "AVL");
    //Free ABB
    {
        free(arvoreAVL1k);
        free(arvoreAVL10k);
        free(arvoreAVL100k);
        free(arvoreAVL1m);
        free(exc_arvoreAVL1k);
        free(exc_arvoreAVL10k);
        free(exc_arvoreAVL100k);
        free(exc_arvoreAVL1m);
    }
    //----------------------------------------------------------------------------------------//
    //                                    Benchmark Árvores RB                                //
    //----------------------------------------------------------------------------------------//
    //Criando arvores RB
    printf("-------Criação RB-----\n");
    pDArvoreRb arvoreRB1k       = criarArvoreRb(vetor1k,   T1K);
    pDArvoreRb arvoreRB10k      = criarArvoreRb(vetor10k,  T10K);
    pDArvoreRb arvoreRB100k     = criarArvoreRb(vetor100k, T100K);
    pDArvoreRb arvoreRB1m       = criarArvoreRb(vetor1m,   T1M);
    pDArvoreRb exc_arvoreRB1k   = criarArvoreRb(vetor1k,   T1K);
    pDArvoreRb exc_arvoreRB10k  = criarArvoreRb(vetor10k,  T10K);
    pDArvoreRb exc_arvoreRB100k = criarArvoreRb(vetor100k, T100K);
    pDArvoreRb exc_arvoreRB1m   = criarArvoreRb(vetor1m,   T1M);
    printf("-------Busca RB------\n");
    resultados[0].rb_busca      = benchmarkOperacaoBuscaRB(arvoreRB1k,   buscarInfoRb, vetor_busca_1k,   100);
    resultados[1].rb_busca      = benchmarkOperacaoBuscaRB(arvoreRB10k,  buscarInfoRb, vetor_busca_10k,  T1K);
    resultados[2].rb_busca      = benchmarkOperacaoBuscaRB(arvoreRB100k, buscarInfoRb, vetor_busca_100k, T10K);
    resultados[3].rb_busca      = benchmarkOperacaoBuscaRB(arvoreRB1m,   buscarInfoRb, vetor_busca_1m,   T100K);
    printf("-------Inclusão RB---\n");
    resultados[0].rb_insercao   = benchmarkOperacaoInclusaoRB(arvoreRB1k,   incluirInfoRb, vetor_inclusao_1k,   100);
    resultados[1].rb_insercao   = benchmarkOperacaoInclusaoRB(arvoreRB10k,  incluirInfoRb, vetor_inclusao_10k,  T1K);
    resultados[2].rb_insercao   = benchmarkOperacaoInclusaoRB(arvoreRB100k, incluirInfoRb, vetor_inclusao_100k, T10K);
    resultados[3].rb_insercao   = benchmarkOperacaoInclusaoRB(arvoreRB1m,   incluirInfoRb, vetor_inclusao_1m,   T100K);
    // printf("-------Exclusão RB---\n");
    // resultados[0].rb_exclusao = benchmarkOperacaoExclusaoRB(exc_arvoreRB1k,   excluirInfoRb, vetor_exclusao_1k,   100);
    // resultados[1].rb_exclusao = benchmarkOperacaoExclusaoRB(exc_arvoreRB10k,  excluirInfoRb, vetor_exclusao_10k,  T1K);
    // resultados[2].rb_exclusao = benchmarkOperacaoExclusaoRB(exc_arvoreRB100k, excluirInfoRb, vetor_exclusao_100k, T10K);
    // resultados[3].rb_exclusao = benchmarkOperacaoExclusaoRB(exc_arvoreRB1m,   excluirInfoRb, vetor_exclusao_1m,   T100K);

    {
        free(arvoreRB1k);
        free(arvoreRB10k);
        free(arvoreRB100k);
        free(arvoreRB1m);
        free(exc_arvoreRB1k);
        free(exc_arvoreRB10k);
        free(exc_arvoreRB100k);
        free(exc_arvoreRB1m);
    }

    //---------------------------------------------------------------------------------------------------//
    //                                    Gerando o arquivo de resultados                                //
    //---------------------------------------------------------------------------------------------------//

    gerarTabelaMarkdown(resultados, tamanhos, 4);

    free(vetor1k);
    free(vetor10k);
    free(vetor100k);
    free(vetor1m);

    free(vetor_inclusao_1k);
    free(vetor_inclusao_10k);
    free(vetor_inclusao_100k);
    free(vetor_inclusao_1m);

    return EXIT_SUCCESS;
}

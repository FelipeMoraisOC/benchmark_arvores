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
    
    // //----------------------------------------------------------------------------------------//
    // //                                    Benchmark Árvores ABB                               //
    // //----------------------------------------------------------------------------------------//
    // //Criando arvores ABB
    // printf("-------Criação ABB----\n");
    // pDArvore arvoreABB1k   = criarArvoreBinaria(vetor1k,   T1K);
    // pDArvore arvoreABB10k  = criarArvoreBinaria(vetor10k,  T10K);
    // pDArvore arvoreABB100k = criarArvoreBinaria(vetor100k, T100K);
    // pDArvore arvoreABB1m   = criarArvoreBinaria(vetor1m,   T1M);
    // pDArvore exc_arvoreABB1k   = criarArvoreBinaria(vetor1k,   T1K);
    // pDArvore exc_arvoreABB10k  = criarArvoreBinaria(vetor10k,  T10K);
    // pDArvore exc_arvoreABB100k = criarArvoreBinaria(vetor100k, T100K);
    // pDArvore exc_arvoreABB1m   = criarArvoreBinaria(vetor1m,   T1M);
    // printf("-------Busca ABB------\n");
    // benchmarkOperacaoBuscaABBVL(arvoreABB1k,   buscarInfo, vetor_busca_1k,   100,   "ABB");
    // benchmarkOperacaoBuscaABBVL(arvoreABB10k,  buscarInfo, vetor_busca_10k,  T1K,   "ABB");
    // benchmarkOperacaoBuscaABBVL(arvoreABB100k, buscarInfo, vetor_busca_100k, T10K,  "ABB");
    // benchmarkOperacaoBuscaABBVL(arvoreABB1m,   buscarInfo, vetor_busca_1m,   T100K, "ABB");
    // printf("-------Inclusão ABB---\n");
    // benchmarkOperacaoInclusaoABBVL(arvoreABB1k,   incluirInfo, vetor_inclusao_1k,   100,   "ABB");
    // benchmarkOperacaoInclusaoABBVL(arvoreABB10k,  incluirInfo, vetor_inclusao_10k,  T1K,   "ABB");
    // benchmarkOperacaoInclusaoABBVL(arvoreABB100k, incluirInfo, vetor_inclusao_100k, T10K,  "ABB");
    // benchmarkOperacaoInclusaoABBVL(arvoreABB1m,   incluirInfo, vetor_inclusao_1m,   T100K, "ABB");
    // printf("-------Exclusão ABB---\n");
    // benchmarkOperacaoExclusaoABBVL(exc_arvoreABB1k,   excluirInfo, vetor_exclusao_1k,   100,   "ABB");
    // benchmarkOperacaoExclusaoABBVL(exc_arvoreABB10k,  excluirInfo, vetor_exclusao_10k,  T1K,   "ABB");
    // benchmarkOperacaoExclusaoABBVL(exc_arvoreABB100k, excluirInfo, vetor_exclusao_100k, T10K,  "ABB");
    // benchmarkOperacaoExclusaoABBVL(exc_arvoreABB1m,   excluirInfo, vetor_exclusao_1m,   T100K, "ABB");
    // //Free ABB
    // {
    //     free(arvoreABB1k);
    //     free(arvoreABB10k);
    //     free(arvoreABB100k);
    //     free(arvoreABB1m);
    //     free(exc_arvoreABB1k);
    //     free(exc_arvoreABB10k);
    //     free(exc_arvoreABB100k);
    //     free(exc_arvoreABB1m);
    // }
//     //----------------------------------------------------------------------------------------//
//     //                                    Benchmark Árvores AVL                               //
//     //----------------------------------------------------------------------------------------//
//     //Criando arvores AVL
//     printf("-------Criação AVL----\n");
//     pDArvore arvoreAVL1k   = criarArvoreAVL(vetor1k,   T1K);
//     pDArvore arvoreAVL10k  = criarArvoreAVL(vetor10k,  T10K);
//    // pDArvore arvoreAVL100k = criarArvoreAVL(vetor100k, T100K);
//    // pDArvore arvoreAVL1m   = criarArvoreAVL(vetor1m,   T1M);
//     pDArvore exc_arvoreAVL1k   = criarArvoreAVL(vetor1k,   T1K);
//     pDArvore exc_arvoreAVL10k  = criarArvoreAVL(vetor10k,  T10K);
//     //pDArvore exc_arvoreAVL100k = criarArvoreAVL(vetor100k, T100K);
//     //pDArvore exc_arvoreAVL1m   = criarArvoreAVL(vetor1m,   T1M);
//     printf("-------Busca AVL------\n");
//     benchmarkOperacaoBuscaABBVL(arvoreAVL1k,   buscarInfoAVL, vetor_busca_1k,   100,   "AVL");
//     benchmarkOperacaoBuscaABBVL(arvoreAVL10k,  buscarInfoAVL, vetor_busca_10k,  T1K,   "AVL");
//     //benchmarkOperacaoBuscaABBVL(arvoreAVL100k, buscarInfoAVL, vetor_busca_100k, T10K,  "AVL");
//     //benchmarkOperacaoBuscaABBVL(arvoreAVL1m,   buscarInfoAVL, vetor_busca_1m,   T100K, "AVL");
//     printf("-------Inclusão AVL---\n");
//     benchmarkOperacaoInclusaoABBVL(arvoreAVL1k,   incluirInfoAVL, vetor_inclusao_1k,   100,   "AVL");
//     benchmarkOperacaoInclusaoABBVL(arvoreAVL10k,  incluirInfoAVL, vetor_inclusao_10k,  T1K,   "AVL");
//     //benchmarkOperacaoInclusaoABBVL(arvoreAVL100k, incluirInfoAVL, vetor_inclusao_100k, T10K,  "AVL");
//     //benchmarkOperacaoInclusaoABBVL(arvoreAVL1m,   incluirInfoAVL, vetor_inclusao_1m,   T100K, "AVL");
//     printf("-------Exclusão AVL---\n");
//     benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL1k,   excluirInfoAVL, vetor_exclusao_1k,   100,   "AVL");
//     benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL10k,  excluirInfoAVL, vetor_exclusao_10k,  T1K,   "AVL");
//     benchmarkOperacaoBuscaABBVL(exc_arvoreAVL10k, buscarInfoAVL, vetor_exclusao_10k, T1K,   "AVL");
//     //benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL100k, excluirInfoAVL, vetor_exclusao_100k, T10K,  "AVL");
//     //benchmarkOperacaoExclusaoABBVL(exc_arvoreAVL1m,   excluirInfoAVL, vetor_exclusao_1m,   T100K, "AVL");
//     //Free ABB
//     {
//         free(arvoreAVL1k);
//         free(arvoreAVL10k);
//         // free(arvoreAVL100k);
//         // free(arvoreAVL1m);
//         free(exc_arvoreAVL1k);
//         free(exc_arvoreAVL10k);
//         // free(exc_arvoreAVL100k);
//         // free(exc_arvoreAVL1m);
//     }
    //Criando arvores ABB
    printf("-------Criação RB-----\n");
    pDArvoreRb arvoreRB1k   = criarArvoreRb(vetor1k,   T1K);
    pDArvoreRb arvoreRB10k  = criarArvoreRb(vetor10k,  T10K);
    pDArvoreRb arvoreRB100k = criarArvoreRb(vetor100k, T100K);
    pDArvoreRb arvoreRB1m   = criarArvoreRb(vetor1m,   T1M);
    pDArvoreRb exc_arvoreRB1k   = criarArvoreRb(vetor1k,   T1K);
    pDArvoreRb exc_arvoreRB10k  = criarArvoreRb(vetor10k,  T10K);
    pDArvoreRb exc_arvoreRB100k = criarArvoreRb(vetor100k, T100K);
    pDArvoreRb exc_arvoreRB1m   = criarArvoreRb(vetor1m,   T1M);
    printf("-------Busca RB------\n");
    benchmarkOperacaoBuscaABBVL(arvoreRB1k,   buscarInfoRb, vetor_busca_1k,   100,   "RB");
    benchmarkOperacaoBuscaABBVL(arvoreRB10k,  buscarInfoRb, vetor_busca_10k,  T1K,   "RB");
    benchmarkOperacaoBuscaABBVL(arvoreRB100k, buscarInfoRb, vetor_busca_100k, T10K,  "RB");
    benchmarkOperacaoBuscaABBVL(arvoreRB1m,   buscarInfoRb, vetor_busca_1m,   T100K, "RB");
    printf("-------Inclusão RB---\n");
    benchmarkOperacaoInclusaoABBVL(arvoreRB1k,   incluirInfoRb, vetor_inclusao_1k,   100,   "RB");
    benchmarkOperacaoInclusaoABBVL(arvoreRB10k,  incluirInfoRb, vetor_inclusao_10k,  T1K,   "RB");
    benchmarkOperacaoInclusaoABBVL(arvoreRB100k, incluirInfoRb, vetor_inclusao_100k, T10K,  "RB");
    benchmarkOperacaoInclusaoABBVL(arvoreRB1m,   incluirInfoRb, vetor_inclusao_1m,   T100K, "RB");
    printf("-------Exclusão ABB---\n");
    benchmarkOperacaoExclusaoABBVL(exc_arvoreRB1k,   excluirInfoRb, vetor_exclusao_1k,   100,   "RB");
    benchmarkOperacaoExclusaoABBVL(exc_arvoreRB10k,  excluirInfoRb, vetor_exclusao_10k,  T1K,   "RB");
    benchmarkOperacaoExclusaoABBVL(exc_arvoreRB100k, excluirInfoRb, vetor_exclusao_100k, T10K,  "RB");
    benchmarkOperacaoExclusaoABBVL(exc_arvoreRB1m,   excluirInfoRb, vetor_exclusao_1m,   T100K, "RB");


    // free(arvoreAVL1k);
    // free(arvoreAVL10k);
    // //free(arvoreAVL100k);
    // //free(arvoreAVL1m);

    // free(arvoreRB1k);
    // free(arvoreRB10k);
    // free(arvoreRB100k);
    // //free(arvoreRB1m);

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

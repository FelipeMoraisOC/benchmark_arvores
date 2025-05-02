#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utils.h"
#include "Arvores.h"


#define T1K   1000
#define T10K  10000
#define T100K 100000
#define T1M   1000000

int main() {
    //Vetores de criação de arvores
    int* vetor1k   = ler_arquivo_para_vetor("dados/1k.txt",     T1K);
    int* vetor10k  = ler_arquivo_para_vetor("dados/10k.txt",   T10K);
    int* vetor100k = ler_arquivo_para_vetor("dados/100k.txt", T100K);
    int* vetor1m   = ler_arquivo_para_vetor("dados/1m.txt",     T1M);

    //Vetores de benchmark de inclusão
    int* vetor_inclusao_1k   = ler_arquivo_para_vetor("benchmark/inclusao_1k.txt",   100);
    int* vetor_inclusao_10k  = ler_arquivo_para_vetor("benchmark/inclusao_10k.txt",  T1K);
    int* vetor_inclusao_100k = ler_arquivo_para_vetor("benchmark/inclusao_100k.txt", T10K);
    int* vetor_inclusao_1m   = ler_arquivo_para_vetor("benchmark/inclusao_1m.txt",   T100K);
    
    
    if (!vetor1k || !vetor10k || !vetor100k || !vetor1m) {
        return EXIT_FAILURE;
    }

    if (!vetor_inclusao_1k || !vetor_inclusao_10k || !vetor_inclusao_100k || !vetor_inclusao_1m) {
        return EXIT_FAILURE;
    }

    //Criando arvores ABB
    pDArvore arvoreABB1k = criarArvoreBinaria();
    for (size_t i = 0; i < T1K; i++) {
        incluirInfo(arvoreABB1k, alocaInt(vetor1k[i]), comparaInt);
        
    }
    printf("Arvore ABB 1K Criada!\n");

    pDArvore arvoreABB10k = criarArvoreBinaria();
    for (size_t i = 0; i < T10K; i++) {
        incluirInfo(arvoreABB10k, alocaInt(vetor10k[i]), comparaInt);
    }
    printf("Arvore ABB 10K Criada!\n");


    pDArvore arvoreABB100k = criarArvoreBinaria();
    for (size_t i = 0; i < T100K; i++) {
        incluirInfo(arvoreABB100k, alocaInt(vetor100k[i]), comparaInt);
    }
    printf("Arvore ABB 100K Criada!\n");


    pDArvore arvoreABB1m = criarArvoreBinaria();
    for (size_t i = 0; i < T1M; i++) {
        incluirInfo(arvoreABB1m, alocaInt(vetor1m[i]), comparaInt);
    }
    printf("Arvore ABB 1M Criada!\n");

    //Fim criação arvores ABB

    //Criando arvores AVL
    pDArvore arvoreAVL1k = criarArvoreAVL();
    for (size_t i = 0; i < T1K; i++) {
        incluirInfoAVL(arvoreAVL1k, alocaInt(vetor1k[i]), comparaInt);
    }
    printf("Arvore AVL 1K Criada!\n");


    pDArvore arvoreAVL10k = criarArvoreAVL();
    for (size_t i = 0; i < T10K; i++) {
        incluirInfoAVL(arvoreAVL10k, alocaInt(vetor10k[i]), comparaInt);
    }
    printf("Arvore AVL 10K Criada!\n");

    //Demorando Minutos para criar
    // pDArvore arvoreAVL100k = criarArvoreAVL();
    // for (size_t i = 0; i < T100K; i++) {
    //     incluirInfoAVL(arvoreAVL100k, alocaInt(vetor100k[i]), comparaInt);
    //     printf("\e[1;1H\e[2J");
    //     printf("Inserindo [%d]\n", i);
    // }
    // printf("Arvore AVL 100K Criada!\n");


    // pDArvore arvoreAVL1m = criarArvoreAVL();
    // for (size_t i = 0; i < T1M; i++) {
    //     incluirInfoAVL(arvoreAVL1m, alocaInt(vetor1m[i]), comparaInt);
    // }
    // printf("Arvore AVL 1M Criada!\n");

    //Fim criação arvores AVL
    
    //Criacao Arvores Rubro Negra
    pDArvoreRb arvoreRB1k = criarArvoreRb();
    for (size_t i = 0; i < T1K; i++) {
        incluirInfoRb(arvoreRB1k, alocaInt(vetor1k[i]), comparaInt);
    }
    printf("Arvore RB 1K Criada!\n");

    pDArvoreRb arvoreRB10k = criarArvoreRb();
    for (size_t i = 0; i < T1K; i++) {
        incluirInfoRb(arvoreRB10k, alocaInt(vetor10k[i]), comparaInt);
    }
    printf("Arvore RB 10K Criada!\n");

    pDArvoreRb arvoreRB100k = criarArvoreRb();
    for (size_t i = 0; i < T1K; i++) {
        incluirInfoRb(arvoreRB100k, alocaInt(vetor100k[i]), comparaInt);
    }
    printf("Arvore RB 100K Criada!\n");

    pDArvoreRb arvoreRB1m = criarArvoreRb();
    for (size_t i = 0; i < T1M; i++) {
        incluirInfoRb(arvoreRB1m, alocaInt(vetor1m[i]), comparaInt);
    }
    printf("Arvore RB 1M Criada!\n");


    //Benchmark arvores ABB
    clock_t inicio_abb = clock();
    printf("O tempo para incluir ABB 1K --- foi: [%lf]segundos\n", benchmarkInclusaoABB(arvoreABB1k,   vetor_inclusao_1k,   100));
    printf("O tempo para incluir ABB 10K -- foi: [%lf]segundos\n", benchmarkInclusaoABB(arvoreABB10k,  vetor_inclusao_10k,  T1K));
    printf("O tempo para incluir ABB 100K - foi: [%lf]segundos\n", benchmarkInclusaoABB(arvoreABB100k, vetor_inclusao_100k, T10K));
    printf("O tempo para incluir ABB 1M --- foi: [%lf]segundos\n", benchmarkInclusaoABB(arvoreABB1m,   vetor_inclusao_1m,   T100K));

    clock_t fim_abb = clock();
    double tempo_total_abb = ((double)(fim_abb - inicio_abb)) / CLOCKS_PER_SEC;
    printf("Tempo total das operações de inclusão ABB: [%lf]ms\n", tempo_total_abb);


    //Benchmark arvores AVL
    clock_t inicio_avl = clock();
    printf("O tempo para incluir AVL 1K --- foi: [%lf]segundos\n", benchmarkInclusaoAVL(arvoreAVL1k,   vetor_inclusao_1k,   100));
    printf("O tempo para incluir AVL 10K -- foi: [%lf]segundos\n", benchmarkInclusaoAVL(arvoreAVL10k,  vetor_inclusao_10k,  T1K));
    //printf("O tempo para incluir AVL 100K - foi: [%lf]segundos\n", benchmarkInclusaoAVL(arvoreAVL100k, vetor_inclusao_100k, T10K));
    //printf("O tempo para incluir AVL 1M --- foi: [%lf]segundos\n", benchmarkInclusaoAVL(arvoreAVL1m,   vetor_inclusao_1m,   T100K));

    clock_t fim_avl = clock();
    double tempo_total_avl = ((double)(fim_avl - inicio_avl)) / CLOCKS_PER_SEC;
    printf("Tempo total das operações de inclusão AVL: [%lf]ms\n", tempo_total_avl);

    //Benchmark arvores RB
    clock_t inicio_rb = clock();
    printf("O tempo para incluir RB 1K --- foi: [%lf]segundos\n", benchmarkInclusaoRB(arvoreRB1k,   vetor_inclusao_1k,   100));
    printf("O tempo para incluir RB 10K -- foi: [%lf]segundos\n", benchmarkInclusaoRB(arvoreRB10k,  vetor_inclusao_10k,  T1K));
    printf("O tempo para incluir RB 100K - foi: [%lf]segundos\n", benchmarkInclusaoRB(arvoreRB100k, vetor_inclusao_100k, T10K));
    printf("O tempo para incluir RB 1M --- foi: [%lf]segundos\n", benchmarkInclusaoRB(arvoreRB1m,   vetor_inclusao_1m,   T100K));

    clock_t fim_rb = clock();
    double tempo_total_rb = ((double)(fim_rb - inicio_rb)) / CLOCKS_PER_SEC;
    printf("Tempo total das operações de inclusão RB: [%lf]ms\n", tempo_total_rb);
    


    //Liberando espaço dos vetores
    free(arvoreABB1k);
    free(arvoreABB10k);
    free(arvoreABB100k);
    free(arvoreABB1m);

    free(arvoreAVL1k);
    free(arvoreAVL10k);
    //free(arvoreAVL100k);
    //free(arvoreAVL1m);

    free(arvoreRB1k);
    free(arvoreRB10k);
    free(arvoreRB100k);
    //free(arvoreRB1m);

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

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
    int* vetor10k = ler_arquivo_para_vetor("dados/10k.txt", T10K);
    
    if (!vetor10k) {
        return EXIT_FAILURE;
    }
    //ABB
    pDArvore arvoreABB10k = criarArvoreBinaria();
    for (size_t i = 0; i < T10K; i++) {
        incluirInfoAVL(arvoreABB10k, alocaInt(vetor10k[i]), comparaInt);
    }
    desenhaArvore(arvoreABB10k, imprimeInt);
    
    //AVL
    pDArvore arvoreAVL1k = criarArvoreAVL();
    for (size_t i = 0; i < T10K; i++) {
        incluirInfoAVL(arvoreAVL1k, alocaInt(vetor10k[i]), comparaInt);
    }
    //desenhaArvoreAVL(arvoreAVL1k, imprimeInt);


    //Rubro Negra
    pDArvoreRb arvoreRb1k = criarArvoreRb();
    for (size_t i = 0; i < 1000; i++) {
        incluirInfoRb(arvoreRb1k, alocaInt(vetor10k[i]), comparaInt);
    }
    //desenhaArvoreRb(arvoreRb1k, imprimeInt);

    free(vetor10k);
    free(arvoreAVL1k);
    free(arvoreRb1k);
    free(arvoreABB10k);
    

    return EXIT_SUCCESS;
}

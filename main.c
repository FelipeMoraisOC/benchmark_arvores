#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Arvores.h"



int main() {

    int* vetor = ler_arquivo_para_vetor("dados/1k.txt", 1000);
    
    if (!vetor) {
        return EXIT_FAILURE;
    }

    pDArvoreRb arvoreRb1k = criarArvoreRb();
    for (size_t i = 0; i < 1000; i++) {
        incluirInfoRb(arvoreRb1k, alocaInt(vetor[i]), comparaInt);
    }
    desenhaArvoreRb(arvoreRb1k, imprimeInt);

    free(vetor);
    return EXIT_SUCCESS;
}

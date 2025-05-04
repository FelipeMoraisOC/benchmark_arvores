#ifndef CRIAR_ARVORE_RB_H
#define CRIAR_ARVORE_RB_H

/* --------------------------*/
pDArvoreRb criarArvoreRb(int* vetor_inclusao, size_t tamanho){
    pDArvoreRb desc      = malloc(sizeof(DArvoreRb));
    desc->raiz           = NULL;
    desc->quantidadeNohs = 0;
    // sentinela
    desc->sentinela      = malloc(sizeof(NohArvoreRb));
    desc->sentinela->cor = BLACK;

    if(!vetor_inclusao) return desc;

    for (size_t i = 0; i < tamanho; i++) {
        incluirInfoRb(desc, alocaInt(vetor_inclusao[i]), comparaInt);
    }
    printf("Arvore RB com %s dados criada!\n", formatarMilhar(tamanho));

    return desc;
};

#endif

#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvoreRb criarArvoreRb(){
    pDArvoreRb dArvore      = malloc(sizeof(DArvoreRb));
    dArvore->raiz           = NULL;
    dArvore->quantidadeNohs = 0;
    // sentinela
    dArvore->sentinela      = malloc(sizeof(NohArvoreRb));
    dArvore->sentinela->cor = BLACK;

    return dArvore;
};

#endif

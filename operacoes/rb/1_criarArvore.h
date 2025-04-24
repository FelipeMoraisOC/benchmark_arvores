#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvoreRubroNegra(){
    pDArvore dArvore = malloc(sizeof(DArvore));
    dArvore->raiz           = NULL;
    dArvore->quantidadeNohs = 0;
    // sentinela
    dArvore->sentinela      = malloc(sizeof(NohArvore));
    dArvore->sentinela->cor = BLACK;

    return dArvore;
};

#endif

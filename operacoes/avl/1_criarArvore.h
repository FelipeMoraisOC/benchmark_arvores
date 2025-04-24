#ifndef CRIAR_ARVORE_AVL_H
#define CRIAR_ARVORE_AVL_H

/* --------------------------*/
pDArvore criarArvoreAVL(){

    pDArvore desc = malloc(sizeof(DArvore));
    desc->raiz           = NULL;
    desc->quantidadeNohs = 0;

    return desc;
};


#endif

#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvoreBinaria(){

    pDArvore descritor = malloc(sizeof(DArvore)); //Cria o descritor
    descritor->raiz = NULL;
    descritor->quantidadeNohs = 0;

    
    return descritor;
};

#endif

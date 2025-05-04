#ifndef CRIAR_ARVORE_AVL_H
#define CRIAR_ARVORE_AVL_H

/* --------------------------*/
pDArvore criarArvoreAVL(int* vetor_inclusao, size_t tamanho){

    pDArvore desc = malloc(sizeof(DArvore));
    desc->raiz           = NULL;
    desc->quantidadeNohs = 0;
    
    if(!vetor_inclusao) return desc;

    for (size_t i = 0; i < tamanho; i++) {
        incluirInfoAVL(desc, alocaInt(vetor_inclusao[i]), comparaInt);
    }
    printf("Arvore AVL com %s dados criada!\n", formatarMilhar(tamanho));

    return desc;
};

#endif

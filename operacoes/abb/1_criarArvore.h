#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvoreBinaria(int* vetor_inclusao, size_t tamanho){

    pDArvore descritor = malloc(sizeof(DArvore)); //Cria o descritor
    descritor->raiz = NULL;
    descritor->quantidadeNohs = 0;

    if(!vetor_inclusao) return descritor;

    for (size_t i = 0; i < tamanho; i++) {
        incluirInfo(descritor, alocaInt(vetor_inclusao[i]), comparaInt);
    }
    printf("Arvore ABB com %s dados criada!\n", formatarMilhar(tamanho));
    return descritor;
};

#endif

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

        if ((i + 1) % 10000 == 0) {
            printf("Inseridos %s dados na AVL %s...\n", formatarMilhar(i + 1), formatarMilhar(tamanho));
            fflush(stdout); // Garante que a saída seja exibida imediatamente
        }
    }
    printf("Arvore AVL com %s dados criada!\n", formatarMilhar(tamanho));

    return desc;
};

int calcularFatorBalanceamento(pNohArvore noh) {
    if (noh == NULL)
        return 0;
    int alturaEsquerda = alturaRecursivo(noh->esquerda);
    int alturaDireita = alturaRecursivo(noh->direita);
    return alturaEsquerda - alturaDireita;
}

pNohArvore construirAVLBalanceada(int* vetor, int inicio, int fim) {
    if (inicio > fim) return NULL;

    int meio = (inicio + fim) / 2;
    pNohArvore noh = malloc(sizeof(NohArvore));
    noh->info = alocaInt(vetor[meio]);
    noh->esquerda = construirAVLBalanceada(vetor, inicio, meio - 1);
    noh->direita  = construirAVLBalanceada(vetor, meio + 1, fim);
    noh->fb = calcularFatorBalanceamento(noh); // Implementar conforme sua estrutura

    return noh;
}

pDArvore criarArvoreAVLBalanceada(int* vetor_inclusao, size_t tamanho) {
    pDArvore desc = malloc(sizeof(DArvore));
    desc->raiz = construirAVLBalanceada(vetor_inclusao, 0, tamanho - 1);
    desc->quantidadeNohs = tamanho;

    printf("Árvore AVL com %s dados criada!\n", formatarMilhar(tamanho));
    return desc;
}

#endif

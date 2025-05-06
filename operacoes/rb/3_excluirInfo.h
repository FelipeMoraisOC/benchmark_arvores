#ifndef EXCLUIRINFO_ARVORE_RB_H
#define EXCLUIRINFO_ARVORE_RB__H

/* --------------------------*/
pNohArvoreRb excluirInfoRecursivoRb(pNohArvoreRb raiz, pNohArvoreRb sentinela, void *info, FuncaoComparacao pfc){

  // caso base
    if (raiz == sentinela){
        return sentinela;
    }

    // caso base: achou a chave
    if (pfc(info, raiz->info) == 0){

        pNohArvoreRb filho;
         if (raiz->esquerda != sentinela)
            filho = raiz->esquerda;
         else
            filho = raiz->direita;

        // achou a chave, remover
        // --------------------------------------------------------
        // caso 1: verifica se um dos dois, a raiz e o filho, � RED
        // --------------------------------------------------------
        if (raiz->cor == RED || filho->cor == RED){
             filho->cor = BLACK;
             return filho;
        }

        // ----------------------------------------------
        // Caso 2: ambos raiz e filho s�o BLACK
        // S�o 4 possibilidades:
        if (raiz->cor == BLACK && filho->cor == BLACK){

              filho->cor = DOUBLEBLACK;

              // parei aqui ----------------------------

              pNohArvoreRb novaRaiz;

              if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) {
                  // caso 2.1 - Left-Left
                  novaRaiz = rotacaoDireita(filho);

              } else if (raiz->direita == filho && raiz->pai->esquerda == raiz){
                        // caso 2.2 - Left-Right
                        novaRaiz = rotacaoEsquerdaDireita(filho);

              } else if (raiz->direita == filho && raiz->pai->direita == raiz){
                        // caso 2.3 - Right-Right
                        novaRaiz = rotacaoEsquerda(filho);

              } else if (raiz->esquerda == filho && raiz->pai->direita == raiz){
                        // caso 2.4 - Left-Right
                        novaRaiz = rotacaoDireitaEsquerda(filho);
              }
              return novaRaiz;
            }

    }
    else{
        pNohArvoreRb filho;
       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){
           filho = Rb(raiz->esquerda, sentinela, info, pfc);
           if (filho->direita == raiz){
               // houve rota��o a direita, n�o precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
              raiz = filho;
           } else {
              filho->pai     = raiz;
            raiz->esquerda = filho;
           }

        }
        else {
           filho = incluirInfoRecursivoRb(raiz->direita, sentinela, info, pfc);
           if (filho->esquerda == raiz){
               // houve rota��o a esquerda, n�o precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
              raiz = filho;
           } else {
              filho->pai    = raiz;
           raiz->direita = filho;
           }
        }

        if (raiz->pai == NULL){
            // � a raiz da �rvore, tem que ser BLACK
            raiz->cor = BLACK;
            return raiz;
        }

        // verifica a cor do pai
        if (raiz->cor == BLACK ||
            (raiz->cor == RED && filho->cor == BLACK)){
            // n�o precisa fazer nada, n�o tem como violar alguma das regras
             return raiz;
        }
        
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfoRb(pDArvoreRb arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Excluindo info: %d ---\n", *((int*)info));
    pNohArvoreRb novaRaiz;
    novaRaiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    if (novaRaiz != NULL){
        arvore->raiz      = novaRaiz;
        arvore->raiz->cor = BLACK;
        arvore->quantidadeNohs--;
    }
    else
        printf("\n --> Chave n�o encontrada! <--");

    printf("\n -----------------------------------------");
    char path[255] = {};
    desenhaArvore(arvore, imprimeInt);
    printf("\n ----------------------------------------- \n");
}

#endif

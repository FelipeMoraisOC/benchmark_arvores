#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

//----------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz){

    raiz->pai->esquerda = raiz->direita;
    raiz->direita       = raiz->pai;

    // ajustar as cores
    raiz->pai->cor = RED;
    raiz->cor      = BLACK;

    // ajustar os pais
    pNohArvore avo = raiz->pai->pai;
    raiz->pai->pai = raiz;
    raiz->pai      = avo;

    return raiz;
}

//----------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz){

    raiz->pai->direita = raiz->esquerda;
    raiz->esquerda     = raiz->pai;

    // ajustar as cores
    raiz->pai->cor = RED;
    raiz->cor      = BLACK;

    // ajustar os pais
    pNohArvore avo = raiz->pai->pai;
    raiz->pai->pai = raiz;
    raiz->pai      = avo;

    return raiz;
}


//----------------------------------
pNohArvore rotacaoDuplaEsquerda(pNohArvore raiz){

    pNohArvore filho = raiz->esquerda;
    raiz->esquerda    = filho->direita;
    filho->direita  = raiz;

    if (raiz->esquerda != NULL)
        raiz->esquerda->pai = raiz;

    filho->pai = raiz->pai;
    raiz->pai  = filho;

    return rotacaoEsquerda(filho);
}

//----------------------------------
pNohArvore rotacaoDuplaDireita(pNohArvore raiz){

    pNohArvore filho = raiz->direita;
    raiz->direita    = filho->esquerda;
    filho->esquerda  = raiz;

    if (raiz->direita != NULL)
        raiz->direita->pai = raiz;

    filho->pai = raiz->pai;
    raiz->pai  = filho;

    return rotacaoDireita(filho);
}

//=================================
pNohArvore tio(pNohArvore filho){

    if(filho->pai->pai->esquerda == filho->pai)
       return filho->pai->pai->direita;
    else
       return filho->pai->pai->esquerda;

}

/* ---------------------------------------------------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc){


    // caso base
    if (raiz == NULL || raiz == sentinela){

        pNohArvore novo = malloc(sizeof(NohArvore));
        novo->info     = info;
        novo->cor      = RED;
        novo->esquerda = sentinela;
        novo->direita  = sentinela;
        novo->pai      = NULL; // nao tem como fazer
       return novo;


    }
    else{
       pNohArvore filho;
       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){

           filho = incluirInfoRecursivo(raiz->esquerda, sentinela, info, pfc);
           // verifica se houve rota��o
           if(filho->direita == raiz){
              raiz = filho;
           }
           else {
              filho->pai     = raiz;
              raiz->esquerda = filho;
           }

        }
        else {
           filho = incluirInfoRecursivo(raiz->direita, sentinela, info, pfc);
           // verifica se houve rota��o
           if(filho->esquerda == raiz){
              raiz = filho;
           }
           else{
              filho->pai    = raiz;
              raiz->direita = filho;
           }
        }

        // garante que a raiz principal da �rvore seja sempre BLAcK
        if (raiz!= NULL && raiz->pai == NULL){
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

         // ----------------------------------------------
        // caso 1: verifica se ambos o pai e o tio s�o RED,
        //         muda a cor de ambos para BLACK e a cor do
        //         av� para RED
        // ----------------------------------------------
        if (raiz->cor == RED && tio(filho)->cor == RED){
            tio(filho)->cor = BLACK;
            raiz->cor       = BLACK;
            raiz->pai->cor  = RED;
            return raiz;
        }

        // ----------------------------------------------
        // Caso 2: pai e tio com cores diferentes
            // S�o 4 possibilidades:
        pNohArvore novaRaiz;
        if (tio(filho)==NULL || tio(filho)->cor == BLACK){

            // rota��o simples a direita
            if (filho == raiz->esquerda){

                if(raiz->pai->esquerda == raiz)
                {
                   // precisa fazer rota�ao simples a direita
                   novaRaiz = rotacaoDireita(raiz);
                } else{
                   novaRaiz = rotacaoDuplaEsquerda(raiz);
                }
            }

            if (filho == raiz->direita){

                // decidir se precisa fazer rota�ao simples ou dupla
                if (raiz->pai->direita == raiz) {
                    // precisa fazer rota�ao simples a esquerda
                    novaRaiz = rotacaoEsquerda(raiz);
                } else{
                    novaRaiz = rotacaoDuplaDireita(raiz);
                }
            }
            //printf("Nova raiz %d", *((int*)novaRaiz->info));
            return novaRaiz;
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Incluindo info: %d ---\n", *((int*)info));
    arvore->raiz = incluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;
    desenhaArvore(arvore, imprimeInt);
}

#endif


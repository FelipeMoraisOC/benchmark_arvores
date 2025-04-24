#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

//----------------------------------
pNohArvoreRb rotacaoDireitaRb(pNohArvoreRb raiz){

    raiz->pai->esquerda = raiz->direita;
    raiz->direita       = raiz->pai;

    // ajustar as cores
    raiz->pai->cor = RED;
    raiz->cor      = BLACK;

    // ajustar os pais
    pNohArvoreRb avo = raiz->pai->pai;
    raiz->pai->pai = raiz;
    raiz->pai      = avo;

    return raiz;
}

//----------------------------------
pNohArvoreRb rotacaoEsquerdaRb(pNohArvoreRb raiz){

    raiz->pai->direita = raiz->esquerda;
    raiz->esquerda     = raiz->pai;

    // ajustar as cores
    raiz->pai->cor = RED;
    raiz->cor      = BLACK;

    // ajustar os pais
    pNohArvoreRb avo = raiz->pai->pai;
    raiz->pai->pai = raiz;
    raiz->pai      = avo;

    return raiz;
}


//----------------------------------
pNohArvoreRb rotacaoDuplaEsquerdaRb(pNohArvoreRb raiz){

    pNohArvoreRb filho = raiz->esquerda;
    raiz->esquerda    = filho->direita;
    filho->direita  = raiz;

    if (raiz->esquerda != NULL)
        raiz->esquerda->pai = raiz;

    filho->pai = raiz->pai;
    raiz->pai  = filho;

    return rotacaoEsquerdaRb(filho);
}

//----------------------------------
pNohArvoreRb rotacaoDuplaDireitaRb(pNohArvoreRb raiz){

    pNohArvoreRb filho = raiz->direita;
    raiz->direita    = filho->esquerda;
    filho->esquerda  = raiz;

    if (raiz->direita != NULL)
        raiz->direita->pai = raiz;

    filho->pai = raiz->pai;
    raiz->pai  = filho;

    return rotacaoDireitaRb(filho);
}

//=================================
pNohArvoreRb tio(pNohArvoreRb filho){

    if(filho->pai->pai->esquerda == filho->pai)
       return filho->pai->pai->direita;
    else
       return filho->pai->pai->esquerda;

}

/* ---------------------------------------------------------------------*/
pNohArvoreRb incluirInfoRbRecursivo(pNohArvoreRb raiz, pNohArvoreRb sentinela, void *info, FuncaoComparacao pfc){


    // caso base
    if (raiz == NULL || raiz == sentinela){

        pNohArvoreRb novo = malloc(sizeof(NohArvoreRb));
        novo->info     = info;
        novo->cor      = RED;
        novo->esquerda = sentinela;
        novo->direita  = sentinela;
        novo->pai      = NULL; // nao tem como fazer
       return novo;


    }
    else{
        pNohArvoreRb filho;
       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){

           filho = incluirInfoRbRecursivo(raiz->esquerda, sentinela, info, pfc);
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
           filho = incluirInfoRbRecursivo(raiz->direita, sentinela, info, pfc);
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
        pNohArvoreRb novaRaiz;
        if (tio(filho)==NULL || tio(filho)->cor == BLACK){

            // rota��o simples a direita
            if (filho == raiz->esquerda){

                if(raiz->pai->esquerda == raiz)
                {
                   // precisa fazer rota�ao simples a direita
                   novaRaiz = rotacaoDireitaRb(raiz);
                } else{
                   novaRaiz = rotacaoDuplaEsquerdaRb(raiz);
                }
            }

            if (filho == raiz->direita){

                // decidir se precisa fazer rota�ao simples ou dupla
                if (raiz->pai->direita == raiz) {
                    // precisa fazer rota�ao simples a esquerda
                    novaRaiz = rotacaoEsquerdaRb(raiz);
                } else{
                    novaRaiz = rotacaoDuplaDireitaRb(raiz);
                }
            }
            //printf("Nova raiz %d", *((int*)novaRaiz->info));
            return novaRaiz;
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfoRb(pDArvoreRb arvore, void *info, FuncaoComparacao pfc)
{
    arvore->raiz = incluirInfoRbRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;
}

#endif


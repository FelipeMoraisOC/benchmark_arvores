#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* ------------------------------------------------------------*/
pNohArvore paiFolhaMaisAEsquerda(pNohArvore raiz){
    if (raiz->esquerda != NULL)
    {
        if (raiz->esquerda->esquerda == NULL) return raiz;

        return paiFolhaMaisAEsquerda(raiz->esquerda);
    }
    return raiz;
}

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc, int *removido){

    if (raiz != NULL){
        if (fc(raiz->info, info) == 0) {
            *removido = 1;
            /* caso base */

            /* antes de liberar a memoria do noh, salva a esquerda e a direita */
            pNohArvore auxEsquerda = raiz->esquerda;
            pNohArvore auxDireita  = raiz->direita;
            free(raiz);

            /* caso 1 - remover noh folha */
            if (auxEsquerda == NULL && auxDireita == NULL){
            return NULL;
            }

            /* caso 3 - remover noh interno com 2 filhos */
            if (auxEsquerda != NULL && auxDireita != NULL){

                if(auxDireita->esquerda != NULL ) 
                {
                    pNohArvore paiFolhaEsquerda;
                    paiFolhaEsquerda = paiFolhaMaisAEsquerda(auxDireita);
        
                    pNohArvore folhaMaisEsquerda = paiFolhaEsquerda->esquerda;
                    folhaMaisEsquerda->esquerda = auxEsquerda;
                    folhaMaisEsquerda->direita  = auxDireita;
        
                    paiFolhaEsquerda->esquerda = NULL;
        
                    return folhaMaisEsquerda;
                }
                if(auxDireita->esquerda == NULL && auxDireita->direita != NULL || auxDireita->esquerda == NULL && auxDireita->direita == NULL)
                {
                    auxDireita->esquerda = auxEsquerda;
                    return auxDireita;
                }
            }
            else{
            /* caso 2 - remover noh interno com 1 filho*/
            if (auxEsquerda != NULL)
                return auxEsquerda;

            return auxDireita;
            }
        }
        /* caso recursivo */
        else if (fc(raiz->info, info) < 0)
            raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc, removido);
        else
            raiz->direita  = excluirInfoRecursivo(raiz->direita, info, fc, removido);
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
    int removido = 0;
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc, &removido);
    if (removido)
        arvore->quantidadeNohs--;
    return removido;
}

#endif

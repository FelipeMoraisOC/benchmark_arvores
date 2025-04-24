#ifndef EXCLUIRINFO_ARVORE_AVL_H
#define EXCLUIRINFO_ARVORE_AVL_H

/* ------------------------------------------------------------*/
pNohArvore paiFolhaMaisAEsquerda(pNohArvore raiz){

    if (raiz->esquerda != NULL)
    {
        if (raiz->esquerda->esquerda == NULL)
            return raiz;
    }
    return paiFolhaMaisAEsquerda(raiz->esquerda);
}

/* --------------------------*/
pNohArvore excluirInfoAVLRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    /*Caso A*/
    /*Nó com FB -2 e filho com FB = -1 ou 0        */
    /*-> rotação do nó com FB -2p/direita          */
  
    /*Caso B*/  
    /*Nó com FB -2 e filho com FB = +1 ou 0        */
    /* -> rotação do nó FB = +1 p/esquerda,        */
    /*    e rotação do nó com FB = -2 p/direita    */

    /*Caso C*/
    /*Remoção de nó intermediário                  */
    /*Substituir pelo nó de Maior chave, seguir ABB*/


    if(raiz == NULL) return NULL;
    
    int comparacao = pfc(info, raiz->info);

    //Casos recursivos
    if(comparacao > 0) 
        raiz->esquerda = excluirInfoAVLRecursivo(raiz->esquerda, info, pfc);
    if(comparacao < 0)
        raiz->direita = excluirInfoAVLRecursivo(raiz->direita, info, pfc);

    //Caso Base
    if(comparacao == 0 )
    {
        pNohArvore auxRaiz;

        //Caso base excluir folha
        if(raiz->direita == NULL && raiz->esquerda == NULL)
        {
            free(raiz);
            return NULL;
        }
        //Caso base nós com um filho
        if(raiz->direita != NULL && raiz->esquerda == NULL)
        {
            auxRaiz = raiz->direita;
            free(raiz);
            return auxRaiz->direita;
        } 
        if(raiz->direita == NULL && raiz->esquerda != NULL )
        {
            auxRaiz = raiz->esquerda;
            free(raiz);
            return auxRaiz->esquerda;
        }

        //Precisa achar o filho mais a direita do filho da esquerda
        auxRaiz = paiFolhaMaisAEsquerda(raiz);
        free(raiz);
        return auxRaiz;    
    } 


    recalcularFBRecursiva(raiz);

    if (raiz->fb == 2 || raiz->fb == -2)
    {   
        pNohArvore novaRaiz;
        if(raiz->fb == 2) // Se é 2 logo devemos analisar os filhos da direita (logo realizar rotação esquerda)
        {
            //Rotação simples
            if(raiz->direita->fb == 1 || raiz->direita->fb == 0)  novaRaiz = rotacaoEsquerdaAVL(raiz); 
            else if(raiz->direita->fb == -1) //Rotação dupla
            {
                novaRaiz = rotacaoDireitaAVL(raiz->direita);
                raiz->direita = novaRaiz;
                novaRaiz = rotacaoEsquerdaAVL(raiz);
                
            }
            
        }

        if(raiz->fb == -2) // Se é -2 logo devemos analisar os filhos da esquerda (logo realizar rotação direita)
        {
            //Rotação Simples
            if(raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0)  novaRaiz = rotacaoDireitaAVL(raiz); 
            //Rotação Dupla
            else if(raiz->esquerda->fb == 1)
            {
                novaRaiz = rotacaoEsquerdaAVL(raiz->esquerda);
                raiz->esquerda = novaRaiz;
                novaRaiz = rotacaoDireitaAVL(raiz);
            }
        }

        //Antes de retornar a nova raiz, 
        //Recalcula o fator de balanceamento dos nós abaixo da nova raiz
        
        recalcularFBRecursiva(novaRaiz);
        return novaRaiz;
    }
    
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfoAVL(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = excluirInfoAVLRecursivo(arvore->raiz, info, pfc);
   /* estah assumindo que sempre excluira */
   arvore->quantidadeNohs--;
   return 1;
}

#endif

#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    pNohArvore nohAux;
    //Caso não encontrou a info
    if(raiz == NULL)
        return NULL;

    //Encontrou a info
    if(pfc(info, raiz->info) == 0)
    {
        //Caso base excluir folha
        if(raiz->direita == NULL && raiz->esquerda == NULL)
        {
            free(raiz);
            return NULL;
        }

        //Caso base noh com um filho
        
        if(raiz->direita != NULL && raiz->esquerda == NULL)
        {
            nohAux = raiz->direita;
            free(raiz);
            return nohAux->direita;
        }
        if(raiz->direita == NULL && raiz->esquerda != NULL)
        {
            nohAux = raiz->esquerda;
            free(raiz);
            return nohAux->esquerda;
        }
        
        //CAso noh com varios filhos 
        
            
    }
    
    //Casos recursivos
    if(pfc(info, raiz->info) > 0)
        raiz->esquerda =  excluirInfoRecursivo(raiz->esquerda, info, pfc);

    if(pfc(info, raiz->info) < 0)
        raiz->direita =  excluirInfoRecursivo(raiz->direita, info, pfc);

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    
    // pNohArvore novaRaiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    // if (novaRaiz != NULL){
    //     // ????
    // }

    //Caso que considera a exclusão de um nó que é folha
    pNohArvore novaRaiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    if(novaRaiz != NULL)
        return 1;



}

#endif

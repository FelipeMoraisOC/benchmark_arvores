#ifndef INCLUIR_INFO_AVL_H
#define INCLUIR_INFO_AVL_H

pNohArvore rotacaoEsquerdaAVL(pNohArvore raiz)
{
    pNohArvore nohDireita = raiz->direita; //Salva Z em nohDireita
    raiz->direita         = nohDireita->esquerda;  //Coloca o T2 na direita do P 
    nohDireita->esquerda  = raiz; //Coloca na esquerda do Z a raiz

    //Devo retornar o Z como nova raiz
    return nohDireita;
}

pNohArvore rotacaoDireitaAVL(pNohArvore raiz)
{
    pNohArvore nohEsquerda = raiz->esquerda;
    raiz->esquerda         = nohEsquerda->direita;
    nohEsquerda->direita   = raiz;

    return nohEsquerda;
}

/* --------------------------*/
pNohArvore incluirInfoAVLRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    // caso base
    if(raiz == NULL)
    {
        pNohArvore novo = malloc(sizeof(NohArvore));
        novo->info = info;
        novo->fb = 0;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    // caso recursivo
    if (pfc(info, raiz->info) > 0)
        raiz->esquerda = incluirInfoAVLRecursivo(raiz->esquerda, info, pfc);
    else
        raiz->direita = incluirInfoAVLRecursivo(raiz->direita, info, pfc);


    raiz->fb = alturaRecursivo(raiz->direita) - alturaRecursivo(raiz->esquerda);


    /*
    ------------Rotação Simples-------------
    Nó com FB = -2 e filho com FB = -1 ou 0:
    ­ rotação do nó com FB = -2 p/ direita

    Nó com FB = +2 e filho com FB = +1 ou 0:
    ­ rotação do nó com FB = +2 p/ esquerda

    ------------Rotação Dupla---------------
    Nó com FB = -2 e filho com FB = +1:
    ­ rotação do nó com FB = +1 p/ esquerda, e
    ­ rotação do nó com FB = -2 p/ direita

    Nó com FB = +2 e filho com FB = -1:
    ­ rotação do nó com FB = -1 p/ direita, e
    ­ rotação do nó com FB = +2 p/ esquerda
    */
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
        // recalcula o fator de balanceamento dos nós abaixo da nova raiz
        recalcularFBRecursiva(novaRaiz);
        
        return novaRaiz;
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfoAVL(pDArvore arvore, void *info, FuncaoComparacao pfc){

    arvore->raiz = incluirInfoAVLRecursivo(arvore->raiz, info, pfc);
}

#endif


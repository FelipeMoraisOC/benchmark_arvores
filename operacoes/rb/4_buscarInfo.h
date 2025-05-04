#ifndef BUSCAR_INFO_RB_H
#define BUSCAR_INFO_RB_H

int buscarInfoRbRecursivo (pNohArvoreRb raiz, void *info, FuncaoComparacao pfc)
{
    if(raiz == NULL) return 0;
   
    if (pfc(info, raiz->info) == 0) return 1;

   // caso recursivo
   if (pfc(info, raiz->info) > 0)
        return buscarInfoRbRecursivo(raiz->esquerda, info, pfc);
    else
        return buscarInfoRbRecursivo(raiz->direita, info, pfc);
}


/* ----------------------------------------------------------*/
int buscarInfoRb (pDArvoreRb arvore, void *info, FuncaoComparacao pfc)
{
    return buscarInfoRbRecursivo(arvore->raiz, info, pfc);
}

#endif


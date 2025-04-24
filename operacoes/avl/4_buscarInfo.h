#ifndef BUSCAR_INFO_AVL_H
#define BUSCAR_INFO_AVL_H

int buscarInfoAVLRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if(raiz == NULL)
   {
       return 0;
   }

    if (pfc(info, raiz->info) == 0)
        return 1;

   // caso recursivo
   if (pfc(info, raiz->info) > 0)
        return buscarInfoAVLRecursivo(raiz->esquerda, info, pfc);
    else
        return buscarInfoAVLRecursivo(raiz->direita, info, pfc);
}


/* ----------------------------------------------------------*/
int buscarInfoAVL (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif


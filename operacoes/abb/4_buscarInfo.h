#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

int buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{

   //Caso base encontrou
   if(raiz == NULL)
      return 0;
      
   if(pfc(info, raiz->info) == 0)   
      return 1;
   
   //Casos recursivos
   if(pfc(info, raiz->info) > 0)
      return buscarInfoRecursivo(raiz->esquerda, info, pfc);
   
   if(pfc(info, raiz->info) < 0)
      return buscarInfoRecursivo(raiz->direita, info, pfc);
}


/* ----------------------------------------------------------*/
int buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif


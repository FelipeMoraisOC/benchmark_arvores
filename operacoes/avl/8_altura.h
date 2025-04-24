#ifndef ALTURA_ARVORE_AVL_H
#define ALTURA_ARVORE_AVL_H

int alturaRecursivo(pNohArvore raiz)
{
   //Caso base 
   if(raiz == NULL) return 0;


   //Caso recursivo
   int altEsq = 1 + alturaRecursivo(raiz->esquerda);
   int altDir = 1 +  alturaRecursivo(raiz->direita);

   if(altEsq > altDir) return altEsq;

   return altDir;
}


int altura(pDArvore arvore)
{
   return alturaRecursivo(arvore->raiz);
}
#endif








#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/

pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){
 
   //Caso Base
   if(raiz == NULL)
   {
      pNohArvore novoNoh = malloc(sizeof(NohArvore));
      novoNoh->info = info;
      //Como o noh é folha os campos esquerda e direita são nulos
      novoNoh->esquerda = NULL; 
      novoNoh->direita = NULL;


      return novoNoh;
   } 
   // caso recursivo
   if(pfc(info, raiz->info) > 0)
      raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);//infor menor
   else 
      raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc); //info maior
   
   return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
   arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif


#ifndef STRUCT_ARVORE_RB_H
#define STRUCT_ARVORE_RB_H

#define RED         'R'
#define BLACK       'B'
#define DOUBLEBLACK 'W'


struct nohArvoreRb{
   void*              info;
   struct nohArvoreRb  *esquerda;
   struct nohArvoreRb  *direita;

   char               cor;
   struct nohArvoreRb  *pai;
};

#endif

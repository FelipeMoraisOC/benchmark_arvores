#ifndef DESENHA_ARVORE_AVL_H
#define DESENHA_ARVORE_AVL_H

#define ESPACO 5

void desenhaArvoreAVLRecursivo(pNohArvore raiz, int depth, char *path, int right, FuncaoImpressao fi) {

    if (raiz == NULL)
        return;

    depth++;

    desenhaArvoreAVLRecursivo(raiz->direita, depth, path, 1, fi);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(raiz->esquerda)
        path[depth-1] = 1;

    printf("\n");
    int i;
    for(i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    fi(raiz->info);
    printf("[%d]", raiz->fb);

    for(i=0; i<depth; i++)
    {
      if(path[i])
          printf(" ");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
          printf(" ");
    }

    desenhaArvoreAVLRecursivo(raiz->esquerda, depth, path, 0, fi);
}

void desenhaAVLArvore(pDArvore arvore, FuncaoImpressao fi) {
    char path[255] = {0};

    desenhaArvoreAVLRecursivo(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}

#endif

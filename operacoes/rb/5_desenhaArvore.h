#ifndef DESENHA_ARVORE_RB_H
#define DESENHA_ARVORE_RB_H

#define ESPACO 5

void desenhaArvoreRbRecursivo(pNohArvoreRb raiz, int depth, char *path, int right, FuncaoImpressao fi, pNohArvoreRb sentinela) {

    if (raiz == NULL || raiz == sentinela)
        return;

    depth++;

    desenhaArvoreRbRecursivo(raiz->direita, depth, path, 1, fi, sentinela);

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
    printf("[%c]", raiz->cor);

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

    desenhaArvoreRbRecursivo(raiz->esquerda, depth, path, 0, fi, sentinela);
}

void desenhaArvoreRb(pDArvoreRb arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRbRecursivo(arvore->raiz, 0, path, 0, fi, arvore->sentinela);
    printf("\n");
}

#endif

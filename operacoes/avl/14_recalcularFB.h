#ifndef RECALCULAR_FB_H
#define RECALCULAR_FB_H

void recalcularFBRecursiva(pNohArvore raiz)
{
    if(raiz == NULL) return;

    raiz->fb = alturaRecursivo(raiz->direita) - alturaRecursivo(raiz->esquerda);

    recalcularFBRecursiva(raiz->esquerda);
    recalcularFBRecursiva(raiz->direita);
}

#endif
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int comparaInt(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;
    return *p2 - *p1;
}
/* ---------------------------------------- */
void imprimeInt(void *info){
   int *pi = (int *) info;
   printf("%d", *pi);
}
/* ---------------------------------------- */
void* alocaInfoInt(void *info){
   int * pi = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi;
}
/* ---------------------------------------- */
int* alocaInt(int n){
   int *pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int          comparaData  (void *info1, void *info2){
    struct Data *p1 = (struct Data *) info1;
    struct Data *p2 = (struct Data *) info2;
    return ((p2->ano - p1->ano)*365) +
           ((p2->mes - p1->mes)*30)  +
            (p2->dia - p1->dia)  ;
}
/* ---------------------------------------- */
void         imprimeData  (void *info){
   struct Data *pd = (struct Data *) info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void*        alocaInfoData(void *info){
   struct Data * pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = ((struct Data*)info)->dia;
   pd->mes = ((struct Data*)info)->mes;
   pd->ano = ((struct Data*)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data* alocaData    (int dia, int mes, int ano){
   struct Data *pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}

int* ler_arquivo_para_vetor(const char* caminho_arquivo, int tamanho) {
    FILE* arquivo = fopen(caminho_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }


    // Alocar memória para o vetor
    int* vetor = (int*) malloc(tamanho * sizeof(int));
    if (!vetor) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    rewind(arquivo);

    // Ler os números e armazená-los no vetor
    int numero;
    size_t i = 0;
    while (fscanf(arquivo, "%d", &numero) == 1) {
        vetor[i++] = numero;
    }

    fclose(arquivo);
    return vetor;
}

#endif /* UTILS_H */

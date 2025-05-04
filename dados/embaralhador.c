#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T1K   1000
#define T10K  10000
#define T100K 100000
#define T1M   1000000

void fisher_yates_shuffle(int *array, size_t n) {
    if (n > 1) {
        for (size_t i = n - 1; i > 0; i--) {
            size_t j = rand() % (i + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

void gerar_e_salvar(const char *nome_arquivo, size_t quantidade) {
    int *vetor = malloc(quantidade * sizeof(int));
    if (!vetor) {
        fprintf(stderr, "Erro ao alocar memória para %zu elementos.\n", quantidade);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        vetor[i] = (int)(i + 1);
    }

    fisher_yates_shuffle(vetor, quantidade);

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        fprintf(stderr, "Erro ao criar o arquivo %s.\n", nome_arquivo);
        free(vetor);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
    free(vetor);
    printf("Arquivo '%s' com %zu numeros gerado com sucesso.\n", nome_arquivo, quantidade);
}
//Para o caso da AVL 100k e 1M
void gerar_e_salvar_ordenado(const char *nome_arquivo, size_t quantidade){
    int *vetor = malloc(quantidade * sizeof(int));
    if (!vetor) {
        fprintf(stderr, "Erro ao alocar memória para %zu elementos.\n", quantidade);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        vetor[i] = (int)(i + 1);
    }

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        fprintf(stderr, "Erro ao criar o arquivo %s.\n", nome_arquivo);
        free(vetor);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
    free(vetor);
    printf("Arquivo '%s' com %zu numeros gerado com sucesso.\n", nome_arquivo, quantidade);
}

int main() {
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios

    gerar_e_salvar("1k.txt",   T1K);
    gerar_e_salvar("10k.txt",  T10K);
    gerar_e_salvar("100k.txt", T100K);
    gerar_e_salvar("1m.txt",   T1M);
    gerar_e_salvar_ordenado("ordenado_100k.txt", T100K);
    gerar_e_salvar_ordenado("ordenado_1m.txt", T1M);

    return 0;
}

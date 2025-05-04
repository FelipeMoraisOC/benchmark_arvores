//Gera dados aleatórios comparado ao limite especificado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T1K   1000
#define T10K  10000
#define T100K 100000
#define T1M   1000000

void bm_gerar_dados(const char *nome_arquivo, size_t quantidade, size_t limite) {

    int *vetor = malloc(quantidade * sizeof(int));
    if (!vetor) {
        fprintf(stderr, "Erro ao alocar memória para %zu elementos.\n", quantidade);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        vetor[i] = rand() % (limite + 1 - 1) + 1;
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
    printf("Arquivo '%s' com %zu numeros gerado com limite de %zu com sucesso.\n", nome_arquivo, quantidade, limite);
}


void bm_gerar_dados_unicos(const char *nome_arquivo, size_t quantidade, size_t limite) {
    if (quantidade > limite) {
        fprintf(stderr, "Quantidade (%zu) maior que o limite de valores únicos (%zu).\n", quantidade, limite);
        exit(EXIT_FAILURE);
    }

    int *numeros = malloc(limite * sizeof(int));
    if (!numeros) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    // Preenche com todos os números possíveis
    for (size_t i = 0; i < limite; i++) {
        numeros[i] = i + 1;
    }

    // Embaralha os primeiros `quantidade` elementos
    for (size_t i = 0; i < quantidade; i++) {
        size_t j = i + rand() % (limite - i);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        free(numeros);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", numeros[i]);
    }

    fclose(arquivo);
    free(numeros);
    printf("Arquivo '%s' com %zu números únicos gerado com sucesso.\n", nome_arquivo, quantidade);
}

int main() {
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios

    bm_gerar_dados_unicos("busca_1k.txt",     100,   T1K); //10%
    bm_gerar_dados_unicos("busca_10k.txt",    T1K,   T10K); //10%
    bm_gerar_dados_unicos("busca_100k.txt",   T10K,  T100K); //10%
    bm_gerar_dados_unicos("busca_1m.txt",     T100K, T1M); //10%

    bm_gerar_dados("inclusao_1k.txt",     100,   T1K); //10%
    bm_gerar_dados("inclusao_10k.txt",    T1K,   T10K); //10%
    bm_gerar_dados("inclusao_100k.txt",   T10K,  T100K); //10%
    bm_gerar_dados("inclusao_1m.txt",     T100K, T1M); //10%


    bm_gerar_dados_unicos("exclusao_1k.txt",    100,   T1K); //10%
    bm_gerar_dados_unicos("exclusao_10k.txt",   T1K,   T10K); //10%
    bm_gerar_dados_unicos("exclusao_100k.txt",  T10K,  T100K); //10%
    bm_gerar_dados_unicos("exclusao_1m.txt",    T100K, T1M); //10%

    return 0;
}

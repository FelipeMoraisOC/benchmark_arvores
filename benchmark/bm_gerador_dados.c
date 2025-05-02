//Gera dados aleatórios comparado ao limite especificado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int *vetor = malloc(quantidade * sizeof(int));
    if (!vetor) {
        fprintf(stderr, "Erro ao alocar memória para %zu elementos.\n", quantidade);
        exit(EXIT_FAILURE);
    }
    //Garantir que não tenham numeros repetidos no arquivo
    for (size_t i = 0; i < quantidade; i++) {
        int n = rand() % (limite + 1 - 1) + 1;
        size_t j = 0;

        while(j < i)
        {
            if(vetor[j] == n)
            {
                j = 0;
                n = rand() % (limite + 1 - 1) + 1;
            } 
            else
            {
                j++;
            }
        }
        vetor[i] = n;
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
    printf("Arquivo '%s' com %zu numeros unicos gerado com limite de %zu com sucesso.\n", nome_arquivo, quantidade, limite);
}

int main() {
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios

    bm_gerar_dados_unicos("busca_1k.txt",     100, 1000); //10%
    bm_gerar_dados_unicos("busca_10k.txt",    1000, 10000); //10%
    bm_gerar_dados_unicos("busca_100k.txt",   10000, 100000); //10%
    bm_gerar_dados_unicos("busca_1m.txt",     10000, 1000000); //1%

    bm_gerar_dados("inclusao_1k.txt",     100,    1000); //10%
    bm_gerar_dados("inclusao_10k.txt",    1000,   10000); //10%
    bm_gerar_dados("inclusao_100k.txt",   10000,  100000); //10%
    bm_gerar_dados("inclusao_1m.txt",     100000, 1000000); //10%


    bm_gerar_dados_unicos("exclusao_1k.txt",    100,   1000); //10%
    bm_gerar_dados_unicos("exclusao_10k.txt",   1000,   10000); //10%
    bm_gerar_dados_unicos("exclusao_100k.txt",  10000,  100000); //10%
    bm_gerar_dados_unicos("exclusao_1m.txt",    10000, 1000000); //1%

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios

    gerar_e_salvar("1k.txt", 1000);
    gerar_e_salvar("10k.txt", 10000);
    gerar_e_salvar("100k.txt", 100000);
    gerar_e_salvar("1m.txt", 1000000);

    return 0;
}

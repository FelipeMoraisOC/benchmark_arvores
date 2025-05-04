#ifndef BENCHMARK_ABB
#define BENCHMARK_ABB

double benchmarkOperacaoInclusaoABBVL(pDArvore arvore, FuncaoInclusao fi, int* vetor_inclusao, size_t tamanho, char* nome_arvore)
{
    int qtd_nohs = arvore->quantidadeNohs;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        fi(arvore, alocaInt(vetor_inclusao[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para incluir %s dados na %s %s foi: [%lf]ms (Tamanho atual: %s)\n", formatarMilhar(tamanho), nome_arvore, formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

double benchmarkOperacaoBuscaABBAVL(pDArvore arvore, FuncaoBusca fb, int* vetor_busca, size_t tamanho, char* nome_arvore)
{
    int qtd_nohs = arvore->quantidadeNohs;
    int qtd_busca_sucesso = 0;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        qtd_busca_sucesso += fb(arvore, alocaInt(vetor_busca[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para buscar  %s dados na %s %s foi: [%lf]ms (Buscas sucedidas: %s)\n", formatarMilhar(tamanho), nome_arvore, formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(qtd_busca_sucesso), formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

double benchmarkOperacaoExclusaoABBAVL(pDArvore arvore, FuncaoExclusao fe, int* vetor_exclusao, size_t tamanho, char* nome_arvore)
{
    int qtd_nohs = arvore->quantidadeNohs;
    int qtd_exclusao_sucesso = 0;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        qtd_exclusao_sucesso += fe(arvore, alocaInt(vetor_exclusao[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para excluir  %s dados na %s %s foi: [%lf]ms (Exclusoes sucedidas: %s | Tamanho Arvore: %s)\n", formatarMilhar(tamanho), nome_arvore, formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(qtd_exclusao_sucesso), formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

double benchmarkOperacaoInclusaoRB(pDArvoreRb arvore, FuncaoInclusaoRB fi, int* vetor_inclusao, size_t tamanho)
{
    int qtd_nohs = arvore->quantidadeNohs;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        fi(arvore, alocaInt(vetor_inclusao[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para incluir %s dados na RB %s foi: [%lf]ms (Tamanho atual: %s)\n", formatarMilhar(tamanho), formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

double benchmarkOperacaoBuscaRB(pDArvoreRb arvore, FuncaoBuscaRB fb, int* vetor_busca, size_t tamanho)
{
    int qtd_nohs = arvore->quantidadeNohs;
    int qtd_busca_sucesso = 0;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        qtd_busca_sucesso += fb(arvore, alocaInt(vetor_busca[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para buscar  %s dados na RB %s foi: [%lf]ms (Buscas sucedidas: %s)\n", formatarMilhar(tamanho), formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(qtd_busca_sucesso), formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

double benchmarkOperacaoExclusaoRB(pDArvoreRb arvore, FuncaoExclusaoRB fe, int* vetor_exclusao, size_t tamanho)
{
    int qtd_nohs = arvore->quantidadeNohs;
    int qtd_exclusao_sucesso = 0;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        qtd_exclusao_sucesso += fe(arvore, alocaInt(vetor_exclusao[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    printf("O tempo para excluir %s dados na RB %s foi: [%lf]ms (Exclusoes sucedidas: %s | Tamanho Arvore: %s)\n", formatarMilhar(tamanho), formatarMilhar(qtd_nohs), tempo_decorrido, formatarMilhar(qtd_exclusao_sucesso), formatarMilhar(arvore->quantidadeNohs));

    return tempo_decorrido;
}

#endif
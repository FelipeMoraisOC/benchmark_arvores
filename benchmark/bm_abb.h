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

double benchmarkOperacaoBuscaABBVL(pDArvore arvore, FuncaoBusca fb, int* vetor_busca, size_t tamanho, char* nome_arvore)
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

double benchmarkOperacaoExclusaoABBVL(pDArvore arvore, FuncaoExclusao fe, int* vetor_exclusao, size_t tamanho, char* nome_arvore)
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

//Benchmark Inserção
double benchmarkInclusaoABB(pDArvore arvore, int* vInclusao, size_t tamanho) {
    struct timeval inicio, fim;

    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        incluirInfo(arvore, alocaInt(vInclusao[i]), comparaInt);
    }

    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos
    printf("O tempo para incluir %zu na ABB %d foi: [%lf]ms\n", tamanho, arvore->quantidadeNohs, tempo_decorrido);
    return tempo_decorrido;
}

//Benchmark Exclusão
double benchmarkExclusaoABB(pDArvore arvore, int* vExclusao, size_t tamanho)
{
    
    struct timeval inicio, fim;

    gettimeofday(&inicio, NULL);

    for (size_t i = 0; i < tamanho; i++) {
        excluirInfo(arvore, alocaInt(vExclusao[i]), comparaInt);
    }
    
    gettimeofday(&fim, NULL);

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) * 1000.0;      // segundos para milissegundos
    tempo_decorrido += (fim.tv_usec - inicio.tv_usec) / 1000.0;          // microssegundos para milissegundos

    return tempo_decorrido;
}
//Benchmark Busca

double benchmarkBuscaABB(pDArvore arvore, int* resultado, int* vBusca, size_t tamanho)
{
    clock_t inicio = clock();
    for (size_t i = 0; i < tamanho; i++) {
        *resultado += buscarInfo(arvore, alocaInt(vBusca[i]), comparaInt);
    }
    
    clock_t fim = clock();
    return (double) fim - inicio; 
}

#endif
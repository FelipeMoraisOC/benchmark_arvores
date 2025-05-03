#ifndef BENCHMARK_ABB
#define BENCHMARK_ABB

//Benchmark Inserção
double benchmarkInclusaoABB(pDArvore arvore, int* vInclusao, size_t tamanho)
{ 
    clock_t inicio = clock();

    for (size_t i = 0; i < tamanho; i++) {
        incluirInfo(arvore, alocaInt(vInclusao[i]), comparaInt);
    }
    
    clock_t fim = clock();
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_total;
}

//Benchmark Exclusão

double benchmarkExclusaoABB(pDArvore arvore, int* vExclusao, size_t tamanho)
{
    clock_t inicio = clock();

    for (size_t i = 0; i < tamanho; i++) {
        excluirInfo(arvore, alocaInt(vExclusao[i]), comparaInt);
    }
    
    clock_t fim = clock();
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_total;
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
#ifndef BENCHMARK_AVL
#define BENCHMARK_AVL

//Benchmark Inserção


double benchmarkExclusaoAVL(pDArvore arvore, int* vExclusao, size_t tamanho)
{
    clock_t inicio = clock();

    for (size_t i = 0; i < tamanho; i++) {
        excluirInfoAVL(arvore, alocaInt(vExclusao[i]), comparaInt);
    }
    
    clock_t fim = clock();
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_total;
}
#endif
#ifndef BENCHMARK_RB
#define BENCHMARK_RB

//Benchmark Inserção
double benchmarkInclusaoRB(pDArvoreRb arvore, int* vInclusao, size_t tamanho)
{ 
    clock_t inicio = clock();
    for (size_t i = 0; i < tamanho; i++) {
        incluirInfoRb(arvore, alocaInt(vInclusao[i]), comparaInt);
    }

    clock_t fim = clock();
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_total;
}
#endif
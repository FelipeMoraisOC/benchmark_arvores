#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

/* estrutura do noh da arvore ABB/AVL */
typedef struct nohArvore  NohArvore;
typedef NohArvore*        pNohArvore;

/* descritor da arvore */
typedef struct dArvore  DArvore;
typedef DArvore*        pDArvore;

/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao) (void*);

typedef void (*FuncaoInclusao)(pDArvore, void*, FuncaoComparacao);
typedef int  (*FuncaoExclusao)(pDArvore, void*, FuncaoComparacao);
typedef int  (*FuncaoBusca)(pDArvore, void*, FuncaoComparacao);



int       grau            (pDArvore);
int       nivel           (pDArvore, void *, FuncaoComparacao);

void desenhaArvore(pDArvore, FuncaoImpressao);



/*------------------------------------------*/
/*             ⏪ BenchMark ⏩             */
/*------------------------------------------*/

pDArvore  criarArvore(int);

void       incluirInfo    (pDArvore, void *, FuncaoComparacao);
int        excluirInfo    (pDArvore, void *, FuncaoComparacao);
int        buscarInfo     (pDArvore, void *, FuncaoComparacao);
int        quantidadeNohs (pDArvore);

/* 🧘‍♂️     AVL     🧘‍♂️*/
pDArvore  criarArvoreAVL();

void       incluirInfoAVL       (pDArvore, void *, FuncaoComparacao);
int        excluirInfoAVL       (pDArvore, void *, FuncaoComparacao);
int        buscarInfoAVL        (pDArvore, void *, FuncaoComparacao);

void      recalcularFBRecursiva (pNohArvore raiz);
int       altura                (pDArvore);
int       alturaRecursivo       (pNohArvore raiz);


/* 🔴 Rubro Negra ⚫*/
typedef struct nohArvoreRb  NohArvoreRb;
typedef NohArvoreRb*        pNohArvoreRb;

typedef struct dArvoreRb  DArvoreRb;
typedef DArvoreRb*        pDArvoreRb;

pDArvoreRb  criarArvoreRb();

void         incluirInfoRb      (pDArvoreRb, void *, FuncaoComparacao);
int          excluirInfoRb      (pDArvoreRb, void *, FuncaoComparacao);
pNohArvoreRb buscarInfoRb       (pDArvoreRb, void *, FuncaoComparacao);

void recolorir(pNohArvoreRb);

void desenhaArvoreRb(pDArvoreRb, FuncaoImpressao);


#endif


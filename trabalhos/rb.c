//bool cor, (1)Black (0)Red

typedef struct no
{
    int chave;                   // chave
    struct Node *esq, *dir, *pai; // ponteiros para as subarvores
    bool cor;                 // cor do no -> true para vermelho e false para preto
} no;

struct arvore {
    no* sentinela;
    int numElementos;
};
//Verifica se houve desbalanceamento na inserção
//Se houve, faz o balanceamento
//Implementação do RB-INSERT-FIXUP(T, z) do Cormen
void balanceamentoInsercao(rb *arv, no *novoNo){
    no* aux = arv->sentinela;
    no* temp = aux;
    no* pai, *avo, *tio;
    pai = novoNo->pai;
    avo = pai->pai;
    

    if(pai->color == 0){
        if(pai->chave >= novoNo->chave){
            if(avo->chave >= pai->chave){
                tio->
                //colorir o pai de preto, se tiver tio vermelho colorir de preto, colorir avo de vermelho, Reavaliar o avô
            }

        }
        

    }
}

abp *criaArvore() {
    abp* arv = (abp*)malloc(sizeof(abp));
    arv->numElementos     = 0;
    arv->sentinela        = (no*)malloc(sizeof(no));
    arv->sentinela->chave = -1000;
    arv->sentinela->esq   =  NULL;
    arv->sentinela->dir   =  NULL;
    arv->sentinela->pai   =  NULL;
    arv->sentinela->cor = 1;
    return arv;
}

int insereNo(abp *arv, int chave) {
    no* aux  = arv->sentinela;
    no* temp = aux;

    while(aux != NULL) {
        temp = aux;
        if(aux->chave > chave) {
            aux = aux->esq;
        } else if(aux->chave <= chave) {
            aux = aux->dir;
        } else {
            return -1;
        }
    }

    if(temp->chave < chave) {
        temp->dir = (no*)malloc(sizeof(no));
        temp->dir->chave = chave;
        temp->dir->dir = NULL;
        temp->dir->esq = NULL;
        temp->dir->pai = temp;
        temp->dir->cor = 0;
        balanceamentoInsercao(arv, temp);
    } else {
        temp->esq = (no*)malloc(sizeof(no));
        temp->esq->chave = chave;
        temp->esq->dir = NULL;
        temp->esq->esq = NULL;
        temp->esq->pai = temp;
        temp->dir->cor = 0;
        balanceamentoInsercao(arv, temp);
    }

    arv->numElementos++;
    return 0;
}


int carregaArvore(abp *arv, char *nomeArquivo) {
    FILE* fp = fopen(nomeArquivo, "r");

    if(fp == NULL) {
        return -1;
    }

    int aux;

    while(fscanf(fp, "%d", &aux) != EOF) {
        if(insereNo(arv, aux) == -1)
            return -1;
    }

    return 0;
}

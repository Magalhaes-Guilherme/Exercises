#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"


//##################################################################

struct tReturn{
    int *vet;
    int tam;
    int error;
};

//##################################################################

void bolha(int *vet, int tam){ //
    int i, j, aux;

    for(i = 0; i< tam; i++){
        for(j = 1; j<tam; j++){
            if(vet[j] < vet[j-1]){
                aux = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

//##################################################################

tReturn* alocatReturn(){
    //tReturn obj;

    tReturn *alocacao = (tReturn*) malloc(sizeof (struct tReturn));
    alocacao->vet = (int*)malloc(1*sizeof(int));
    alocacao->error = 0;
    alocacao->tam = 0;

    return alocacao;
}

//#################################################################
// agora devo ler todo o arquivo e separá-lo do resto.

tReturn* leArquivo(char nomeArquivo[]){
    FILE *arq;
    tReturn* ler;
    int i = 0;
    int tam;
    
    ler = alocatReturn(); //alocar o treturn que iremos utilizar para retornar no lerarquivo
    arq = fopen(nomeArquivo, "r");

    if(NULL == arq){ //arquivo não abriu
        ler->error = 1;
        fclose(arq); 
        return ler;
    }

    if(fscanf(arq,"%d", &ler->tam) == 0){ //leitura com erro
        ler->error = 2;
        fclose(arq); 
        return ler;
    }

    tam = ler->tam;

    if((ler->vet = (int*) malloc(tam * sizeof(int))) == NULL){ //problema de alocamento de memória
        ler->error = 3;
        fclose(arq); 
        return ler;
    }
    
    while(!feof(arq)){
            fscanf(arq, "%d", &ler->vet[i]);
            i++;
    }
    fclose(arq);
    return ler;
}

//##############################################################################

void imprimeVet(int *vet, int tam){
    int i;

    for(i = 0; i< tam; i++){
        printf("%d\n", vet[i]);
    }
}

//###############################################################################

void trataErro(int erro){
    if(erro == 1){
        printf("erro 1 : abertura do arquivo");
    }
    else{
        if(erro == 2){
            printf("erro 2: leitura do arquivo");
        }
        else{
            printf("erro 3 : alocação de memória");
        }
    }
}

//#################################################################################

int *getVet(tReturn *rep){
    int *vetor;
    int tam;
    tam = rep->tam;
    vetor = (int*) malloc (tam*sizeof(int));
    vetor = rep->vet;

    return vetor;
    // return *vetor; Qual será o certo?
}

//############################################################

int getTam(tReturn *rep){
    int tam;

    tam = rep->tam;
    return tam;
}

int getErro(tReturn *rep){
    int error;
    error = rep->error;

    return error;
}


//###########################################################


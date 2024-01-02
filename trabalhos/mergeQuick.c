#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeQuick.h"

int geraAleatorios(char *nomeArquivo, int qtd){

    int i, aux;
    FILE *arq;
    arq = fopen(nomeArquivo, "w"); 
    if (arq == NULL)
        return 1;
    if (qtd > 1000){
        for (i = 0; i < qtd; i++){
            aux = rand() % 1001;
            fprintf(arq, "%d", aux);
        }
    }
    else{
        srand(time(NULL));
        for (i = 0; i < qtd; i++){
            aux = rand() % 1001;
            fprintf(arq, "%d", aux);
        }
    }
    fclose(arq); 
    return 0;
}



int *leArquivo(char *nomeArquivo, int qtd){
    FILE *arq;
    int *vet;
    int i = 0;

    if ((vet = (int *)malloc(qtd * sizeof(int))) == NULL){
        return NULL;
    }

    arq = fopen(nomeArquivo, "r");

    if (NULL == arq){ 
        return NULL;
    }

    while (!feof(arq)){
        fscanf(arq, "%d", &vet[i]);
        i++;
    }
    fclose(arq);
    return vet;
}

void merge(int *vet, int inicio, int meio, int fim) {
	int c1 = inicio, c2 = meio+1, cAux = 0, vetAux[fim-inicio+1];
	while (c1<=meio && c2<=fim){
		if(vet [c1] <= vet[c2]){
			vetAux[cAux] = vet[c1];
		 c1++;
		}
		else{
			vetAux[cAux] = vet[c2];
			c2++; 
		}
			cAux++; 
	}
	while (c1<=meio){ 
		vetAux[cAux] = vet[c1];
		cAux++; 
    c1++; 
	}
 	while(c2<=fim){  
		vetAux[cAux] = vet[c2];
		cAux++;
    c2++; 
	}
	for(cAux=inicio;cAux<=fim;cAux++){ 
		vet[cAux] = vetAux[cAux-inicio];
	}
}

void mergeSort(int *vet, int inicio, int fim){
	int meio;
	if (inicio < fim) {
		meio = (inicio+fim)/2;
		mergeSort(vet, inicio, meio);
		mergeSort(vet, meio+1, fim);
		merge(vet, inicio, meio, fim);
	}
}

void quickSort(int *vet, int inicio, int fim){  
	int pivo;
	if(fim > inicio){
		pivo = particiona(vet, inicio, fim); 
		quickSort(vet, inicio, pivo-1);
		quickSort(vet, pivo+1, fim);
	}
}

int particiona(int *vet, int inicio, int fim){
	int auxini, auxfim, pivo, aux;
	auxini = inicio;
	auxfim = fim;
	pivo = vet[inicio];
	while(auxini < auxfim){
		while(auxini <= fim && vet[auxini] <= pivo){
			auxini++; 
		}
		while(auxfim >= 0 && vet[auxfim] > pivo){
			auxfim--; 
		}
		if(auxini < auxfim){ 
			aux = vet[auxini];
			vet[auxini] = vet[auxfim];
			vet[auxfim] = aux;
		}
	}
	vet[inicio] = vet[auxfim];
	vet[auxfim] = pivo;
	return auxfim;
}

void imprimeVet(int *vet, int tam){ //imprimindo o vetor desejado
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

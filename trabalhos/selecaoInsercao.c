#include <stdio.h>
#include <stdlib.h>
#include "selecaoInsercao.h"
#include <time.h>

int geraAleatorios(char *nomeArquivo, int qtd)
{
    int i, aux;
    // int *vet;
    FILE *arq;

    arq = fopen(nomeArquivo, "w");

    if (arq == NULL)
        return 1;

    if (qtd > 1000)
    {
        for (i = 0; i < qtd; i++)
        {
            aux = rand() % 1001;
            fprintf(arq, "%d", aux);
        }
    }

        else{
            srand(time(NULL));

            for (i = 0; i < qtd; i++)
            {
                aux = rand() % 1001;
                fprintf(arq, "%d", aux);
            }
        }
    fclose(arq);
    return 0;
}

int *leArquivo(char *nomeArquivo, int qtd)
{
    FILE *arq;
    int *vet;
    int i = 0;

    if ((vet = (int *)malloc(qtd * sizeof(int))) == NULL)
    { // problema de alocamento de memória
        return NULL;
    }

    arq = fopen(nomeArquivo, "r");
    if (NULL == arq)
    { // arquivo não abriu
        return NULL;
    }

    while (!feof(arq))
    {
        fscanf(arq, "%d", &vet[i]);
        i++;
    }
    fclose(arq);
    return vet;
}

void troca(int *vet, int selecionado, int marcador){
    int aux;
    aux = vet[marcador];
    vet[marcador] = vet[selecionado];
    vet[selecionado] = aux;
}

void selecao(int *vet, int tam)
{
    int i, marcador;
    int aux, menor;
    for (marcador = 0; marcador < tam - 1; marcador++)
    {
        menor = marcador;
        for (i = marcador + 1; i < tam; i++)
        {
            if (vet[i] < vet[menor])
                menor = i;
        }
        troca(vet, menor, marcador);
    }

    //imprimeVet(vet, tam);
}

void selecaoDecrescente(int *vet, int tam)
{
    int i, marcador;
    int aux, maior;
    for (marcador = 0; marcador < tam - 1; marcador++)
    {
        maior = marcador;
        for (i = marcador + 1; i < tam; i++)
        {
            if (vet[i] > vet[maior])
                maior = i;
        }
        troca(vet, maior, marcador);
    }

    //imprimeVet(vet, tam);
}

void dualSelecao(int *vet, int tam)
{
    int i, marcador, marcador2 = tam -1;
    int aux, maior, menor;
    for (marcador = 0; marcador < tam ; marcador++)
    {
        menor = marcador;
        maior = marcador2;
        if(menor + 1 == maior){
            if (vet[maior] < vet[menor]){
                troca(vet, maior, menor);
            }
        }
        else{
            for (i = marcador + 1; i < marcador2; i++)
            {
                if (vet[i] < vet[menor])
                    menor = i;

                if (vet[i] > vet[maior]){ 
                    if(maior == menor)
                        maior = maior;
                    else{
                        maior = i;        
                    }
                }

            }

        }

        troca(vet, marcador, menor);
        troca(vet, marcador2, maior);
        marcador2 = marcador2 - 1;
    }

    //imprimeVet(vet, tam);
}

void insercao(int *vet, int tam)
{
    int marcador;
    int aux;
    int pos;

    for (marcador = 1; marcador < tam; marcador++)
    {
        pos = marcador - 1;
        aux = vet[marcador];
        while (aux < vet[pos] && (pos >= 0))
        {
            vet[pos + 1] = vet[pos];
            pos = pos - 1;
        }
        vet[pos + 1] = aux;
    }

    //imprimeVet(vet, tam);
}

void imprimeVet(int *vet, int tam){

    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
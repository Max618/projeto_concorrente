#include<stdio.h>
#include<stdlib.h>

# define sizeOfVet 100000 // Test
//# define sizeOfVet 1000000

int* createVet(){
    return malloc(sizeOfVet * sizeof(int));
}

void setVet(int seed, int vet[]){
    srand(seed); // Intializes random number generator

    for(int i=0; i<sizeOfVet; i++){
        vet[i] = rand() % sizeOfVet + 1; // random numbers from 1 to sizeOfVet
    }
}

void printVet(int seed, int vet[], char fileName[], char openfile[]){
    FILE *fp;
    fp = fopen(fileName, openfile);

    for(int i=0; i<sizeOfVet; i++){
        fprintf(fp, "O valor de vet%d[%d]: %d\n", seed, i, vet[i]);
    }

    fclose(fp);
}

void insertionSort(int vet[]){
    int i, key, j;
    for (i=1; i<sizeOfVet; i++){
        key = vet[i];
        j = i-1;

        while ((j>=0) && (vet[j]>key)){
            vet[j+1] = vet[j];
            j = j-1;
        }
        vet[j+1] = key;

        if (i%1000==0){ // Test
            printf("%d\n", i);
        }
    }
}

int main(){
    int *vet1 = createVet();
    int *vet2 = createVet();

    setVet(1, vet1);
    setVet(2, vet2);

    printVet(1, vet1, "vet1_0b.txt", "w");
    printVet(2, vet2, "vet2_0b.txt", "w");

    insertionSort(vet1);
    insertionSort(vet2);

    printVet(1, vet1, "vet1_1a.txt", "w");
    printVet(2, vet2, "vet2_1a.txt", "w");

    return 0;
}
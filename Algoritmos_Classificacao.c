//Programa que compara os tempos de 3 algoritmos de classificação.
//Author: Leandro Almeida

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50000

double bubble_sort() {
    int comp= 0 , troca= 0 , vet[TAM] , i ,j,aux;
    time_t inicio,fim;
    double tempo_t;
    srand(time(NULL));
    inicio = clock();
    for(i=0; i<TAM; i++){
                vet[i]=rand()%5000001;
	}

    for( i=TAM-1; i >= 1; i--) {
        for( j=0; j < i ; j++) {
            comp ++;
            if(vet[j]>vet[j+1]) {
                 aux = vet[j];
                 vet[j] = vet[j+1];
                 vet[j+1] = aux;
                 troca++;
            }
        }
    }
	fim = clock();
	tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
	return tempo_t;
}

double insertionSort() {
    int i, j, eleito, vet[TAM];
    time_t inicio,fim;
    double tempo_t;
    srand(time(NULL));
    inicio = clock();
    for(i=0; i<TAM; i++){
                vet[i]=rand()%5000001;
	}
   for (i = 1; i < TAM; i++){
      eleito = vet[i];
      j = i - 1;
      while ((j>=0) && (eleito < vet[j])) {
         vet[j+1] = vet[j];
         j--;
      }
      vet[j+1] = eleito;
   }
	fim = clock();
	tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
	return tempo_t;
}

double selection_sort() { 
    int i, j, min, aux , vet[TAM];
    time_t inicio,fim;
    double tempo_t;
    srand(time(NULL));
    inicio = clock();
    for(i=0; i<TAM; i++){
                vet[i]=rand()%5000001;
	}
  for (i = 0; i < (TAM-1); i++) 
   {
    min = i;
    for (j = (i+1); j < TAM; j++) {
      if(vet[j] < vet[min]) {
        min = j;
      }
    }
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
	fim = clock();
	tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
	return tempo_t;
} 


int main(int narg , char *argv[]){
	double a,b,c,i;
	for(i=0; i<3; i++){
		a = a + bubble_sort();
		b = b + insertionSort();
		c = c + selection_sort();
	}	
	printf(" Tempo no bubble_sort : %f \n" , a);
	printf(" Tempo no InsertionSort : %f \n" , b);
	printf(" Tempo no selection_sort : %f \n" , c);
	if (a<b && a<c){
		printf(" bubble_sort é o mais eficiente.\n");
	}
	if (b<a && b<c){
		printf(" InsertionSort é o mais eficiente.\n");
	}
	if (c<a && c<b){
		printf(" selection_sort é o mais eficiente.\n");
	}
	return EXIT_SUCCESS;


}

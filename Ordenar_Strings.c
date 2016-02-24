//Programa que ordena um conjunto de strings.
//Author: Leandro Almeida

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

char rand_char()
{

	char c;
	int n;

	n = rand()%52;

	if(n <= 25)   
		n = n + 65;  
	else
		n = n + 97 - 26;  

	c =(char)n;

	return c;

}

int main()
{
	int i, j,x;
	j=0;
	char matriz[MAX][40];
	srand(time(NULL));
      	for(i=0;i<MAX;i++){
          	for(j=0;j<39 ;j++){
			
              		matriz[i][j] = rand_char();
              	}
	matriz[i][39]='\0';
      	}         
	printf("\nVetor de Strings Desordenado: \n");
   	for (i=0;i<MAX; i++){
		printf("%s\n", matriz[i]);
	}

	for(x=0; x<=MAX; x++){

		for(i=0; i<MAX-1; i++){
			
			int j;
			int maior = 0;
			for (j = 0; j < 40; j++) {
				if (matriz[i][j] > matriz[i+1][j]) {
					maior = 1;
					break;
				} else if (matriz[i][j] < matriz[i+1][j]) {
					break;
				}
				printf("\n");

	
			} 	
			
			if(maior){
				int k;

				for (k = 0; k < 40; k++) {
					char c = matriz[i+1][k];
					matriz[i+1][k] = matriz[i][k];
					matriz[i][k] = c;
				}
			}
			
		}
	}
	printf("\n\n\n\n Vetor de Strings Ordenado:\n");
	for (i=0;i<MAX; i++){
		printf("%s\n", matriz[i]);
	}
}
		
			
          


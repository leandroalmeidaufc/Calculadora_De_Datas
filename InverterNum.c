//Programa que inverte inteiros.
//Author: Leandro Almeida

#include <stdio.h>
#include <stdlib.h>

int potencia(int rest, int b){
	int i,pot=1;
	for(i=1;i<=b;i++){
		pot*=10;
	}
	return pot*rest;
}
		
int dividir (int aux){
	int cont=0;
	while(aux%10>=0 && aux>=10){
		aux=aux/10;
		cont ++;
	}
	return cont;
}

int invert(int n)
{
	int rest,valor=0, cont2;
    if(n==0)
      return n;
     else {
	cont2= dividir(n);
	while(n%10>=0 && n!=0){
		rest= n%10;
		n=n/10;
		valor=valor+ potencia(rest, cont2);
		cont2--;
	}
    
    }
	 return valor;
 }

int main(int narg, char *argv[]){
	unsigned int valor2;
	unsigned int k;
	
	if(narg<2){
		printf("Digite um número: \n" 	);
		scanf("%d",&k);
		  }


	else{
		k=atoi(argv[1]);
		}
			
		printf("O inteiro contido eh : %d\n", k);
		valor2=invert(k);
		printf("O numero com a ordem invertida eh : %d\n" , valor2);
		return EXIT_SUCCESS;
}

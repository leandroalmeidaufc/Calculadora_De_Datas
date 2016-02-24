//Programa que calcula numeros primos.
//Author: Leandro Almeida

#include <stdio.h>
#include <stdlib.h>

  int funcPrimo(int a)
{
    int  i,  cont= 0;             
    for (i = 1; i <= a; i++)
    {
        if (a % i == 0)
        cont++;
    }
    if (cont == 2) 
        return a;
    }

int main (){
    int j=1,num,cont =0;
    printf("Digite a quantidade de numeros primos: ");
    scanf("%d",&num);
    while(cont<num){
                       if (funcPrimo(j)==j){
        printf(" %d \n",funcPrimo(j));
        cont++;
    }
    j++;
}
return EXIT_SUCCESS;
}


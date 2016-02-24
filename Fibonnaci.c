//Programa que calcula Fibonacci.
//Autor: Leandro Almeida

#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    int a =0, b =0, auxiliar,i;
    if(n==0)
    	return EXIT_SUCCESS;
    if(n==1)
    	printf("0\n");
    else{
    printf("%d\n", b);
    b=1;
    printf("%d\n", b);
    	
    for (i=1; i<n; i++)
          {
               auxiliar = a + b;
               a = b;
               b = auxiliar;
		if (auxiliar<n){
               		printf("%d\n", auxiliar);
		}
		i=auxiliar;
          }
          }
          }
 
int main()
{
    int num;
    printf("Digite um numero limite da sequencia:");
    scanf("%d", &num);
    fib(num);
    
	return EXIT_SUCCESS;
}



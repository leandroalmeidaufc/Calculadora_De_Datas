//Programa que escreve por extenso um número digitado pelo usuário.
//Author: Leandro Almeida

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *unidades[] = {"zero","um","dois","tres","quatro","cinco","seis","sete","oito","nove"};
char *dezVinte[] = {"","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"};
char *dezenas[] = {"","dez","vinte", "trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa"};
char *centenas[] = {"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"};

char *JuntaString(char *str1, char *str2)
{
  int a,b,f;
  char *buffer;
  a=strlen(str1);
  b=strlen(str2);
  buffer=(char *)malloc(a+b+1);
  for (f=0; f<a+b; f++)
  {
    if (f<a)
      buffer[f]=str1[f];
    else
      buffer[f]=str2[f-a]; 
  }
  return buffer;
}


char *extenso(int num)
{
  char *e = " e ";
  char *nome;
  int cent,dezen,dv,uni; 
  cent=num/100; 
  dezen=num/10-cent*10;
  uni=num-(num/10)*10;
  dv=dezen*10+uni;
  nome=unidades[uni];
  if (num<10)
    return nome;
  
  if ((dv>10) && (dv<20))
    nome=dezVinte[dv-10];
  else
  {    
    if (uni==0)
      nome=dezenas[dezen];
    else
    {
      nome=JuntaString(e,nome);
      nome=JuntaString(dezenas[dezen],nome);
    }
  }
  if (num<100)
    return nome;

  if ((dezen==0)&&(uni==0))
  {
    if (cent==1)
      nome="cem";
    else
      nome=centenas[cent];
  }
  else
  {
    nome=JuntaString(e,nome);
    nome=JuntaString(centenas[cent],nome);
  }
  return nome;
}


int main( int narg, char *argv[])
{
  
  int num,i=0,j;
  char *nome;
  char *numExtenso[1000];
  char opc;
  FILE *arq;
	if (narg<2){	
		do{
  			printf("Entre com um numero 0-999: ");
  			scanf("%d",&num);
 			nome=extenso(num);
  			printf("Numero %d por extenso: %s\n",num,nome);
  			printf("Deseja repetir a operação? S/N ");
  			scanf(" %c", &opc);
  			}while(opc== 'S' || opc == 's');
  			return EXIT_SUCCESS;

	           }

	arq = fopen(argv[1],"r");
	if (arq == NULL){
		printf("Erro ao abrir o arquivo.\n");
		return EXIT_FAILURE;
	}	

	while(!feof(arq)){
		fscanf(arq,"%d ",&num);
		nome=extenso(num);
		numExtenso[i]=nome;
		printf("Numero %d por extenso: %s\n",num,nome);
		i++;
}
	for (j=0; j<i; j++){
		printf("Por extenso(do vetor): %s\n",numExtenso[j]);
}
	

fclose(arq);
return EXIT_SUCCESS;
}

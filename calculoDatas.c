/*Programa que calcula quantos dias existem no intervalo entre duas datas levando em consideração os anos bissextos*/
//Author: Leandro Almeida de Carvalho 

#include <stdio.h>
#include <stdlib.h>

int ano_bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

int tipo_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int num_dias (int DI, int MI, int AI, int DF, int MF, int AF) {
	int i,dias,f_dias,anos, bis;	
	anos=1;
	dias = DI;
	bis = ano_bissexto (AI);
	for (i = MI - 1; i > 0; i--){
		dias += tipo_mes[bis][i];}
		f_dias = DF;
		bis = ano_bissexto (AF);

	for (i= MF-1; i>0; i--)
		f_dias += tipo_mes[bis][i];

	while (AI < AF)
		anos += 365 + ano_bissexto(AI++);

	return anos - dias + f_dias;
}
int main( int narg, char *argv[]) {
	int D1,D2,M1,M2,A1,A2,cont;
	cont=0;
	printf("Lembre que os dias são até 31, meses até 12. E por favor, não digite datas negativas.\n");
	do{
		if (cont>0)
			printf("Data invalida. Tente novamente.\n");
		printf("Qual a data que você nasceu no formato: dd/mm/aa\n");
		scanf("%d/%d/%d", &D1, &M1, &A1);
		printf("Qual a data de hoje no formato: dd/mm/aa\n");
		scanf("%d/%d/%d", &D2,&M2,&A2);
		cont=cont+1;
	} while((D1>31 || D1<1) || (D2>31 || D2<1) || (M1>12 || M1<1) || (M2>12 || M2<1) || (A1<1) || (A2<1) || (A1>A2));
	printf("Numero de dias que voce ja viveu: %d\n", num_dias(D1,M1,A1,D2,M2,A2));
	return EXIT_SUCCESS;
}

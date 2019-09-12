#include <stdio.h>
/* programma che calcola il resto di una divisione tra due numeri interi */
int main()
{
int numero_1, numero_2, risultato, resto;
	printf("introdurre il valore del primo numero \n");
	scanf("%d", &numero_1);
	printf("introdurre il valore del secondo numero \n");
	scanf("%d", &numero_2);
	
	risultato= numero_1 / numero_2 ;
	resto= numero_1 % numero_2 ;
	printf( "la divisione tra %d e %d ha come risultato: %d e resto:%d", numero_1, numero_2, risultato, resto);
	
}

#include <stdio.h>

/* programma che stampa tutti i numeri compresi
 * fra 0 e 99 così che ciascuna decina compare su 
 * una riga diversa. */
int main() {
	int i, j;			// due variabili contatori
	/* la variabile i rappresenta le decine */
	for(i=0;i<=9;i++) {
		/* la variabile j rappresenta le unità */
		for(j=0;j<=9;j++) 
			printf("%2d ", 10*i+j);
		printf("\n");
	}
}

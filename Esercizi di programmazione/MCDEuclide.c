#include <stdio.h>

/* programma che legge due interi ed informa l'utente sul 
 * massimo comun divisore fra i due interi letti; per calcolare
 * il massimo comun divisore viene utilizzato l'algoritmo di 
 * Euclide. */
int main() {
	int x, y;				// gli interi da leggere
	int max, min;		// il più grande ed il più piccolo fra i due
	int resto;			// il resto della divisione fra i numeri

	/* INPUT */
	printf("Caro utente, introduci due interi.\n");
	scanf("%d%d", &x, &y);
	
	/* CALCOLA IL MASSIMO ED IL MINIMO */
	if(x<y) {
		max = y;
		min = x;
	}
	else {
		max = x;
		min = y;
	}
	
	/* CALCOLA IL MCD TRAMITE L'ALGORITMO DI EUCLIDE */
	do {
		resto = max % min;
		max = min; 
		min = resto;
	}
	while(resto!=0); 
	
	/* OUTPUT */
	printf("Il MCD fra %d e %d %c %d.\n", x, y, 138, max);
}

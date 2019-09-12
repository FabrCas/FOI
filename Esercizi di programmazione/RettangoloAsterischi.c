#include <stdio.h>

/* programma che chiede all'utente di inserire due interi da tastiera e 
 * stampa un rettangolo di asterischi la cui base e la cui altezza sono 
 * pari agli interi inseriti dall'utente. */
int main() {
	int i, j;					// due variabili contatori
	int base, altezza;	// dimensioni del rettangolo

	/* INPUT */
	printf("Introduci base ed altezza del rettangolo.\n");
	scanf("%d%d", &base, &altezza);
	
	printf("Ecco il tuo rettangolo.\n\n");
	/* la i rappresenta gli indici di riga */
	for(i=1;i<=altezza;i++) {
	/* la j rappresenta gli indici di colonna */
		for(j=1;j<=base;j++) {
			printf("* ");
		} 
		/* fine riga */
		printf("\n");
	}
}

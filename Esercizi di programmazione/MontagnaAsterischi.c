#include <stdio.h>

/* programma che chiede all'utente di inserire un intero da tastiera 
 * e stampa una montagna di asterischi la cui altezza è pari 
 * all'intero inserito dall'utente. */
int main() {
	int i, j;					// due variabili contatori
	int altezza;				// altezza del rettangolo

	/* INPUT */
	printf("Introduci l'altezza del rettangolo.\n");
	scanf("%d", &altezza);
	
	printf("Ecco il tuo rettangolo.\n\n");
	/* la i rappresenta gli indici di riga */
	for(i=1;i<=altezza;i++) {
	/* la j rappresenta gli indici di colonna */
		for(j=1;j<=altezza*2;j++) {
			/* se sei nelle prime altezza-i posizioni o nelle ultime
				altezza-i posizioni devi lasciare uno spazio, 
				altrimenti devi scrivere un asterisco */
			if(j<=altezza-i || j>=altezza+i+1)
				printf("  ");
			else
				printf("* ");
		} 
		/* fine riga */
		printf("\n");
	}
}

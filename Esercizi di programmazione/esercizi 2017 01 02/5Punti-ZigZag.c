 #include <stdio.h>

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	int indiceS;			// per scandire array da sinistra
	int indiceD;			// per scandire array da destra

	/* INPUT */
	printf("Ciao utente, quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* crea un nuovo array */
	int nuovaSequenza[lunghezza];
	/* il primo carattere che deve essere preso da sinistra nella sequenza ha indice 0 */
	indiceS=0;
	/* il primo carattere che deve essere preso da destra nella sequenza ha indice lunghezza-1 */
	indiceD=lunghezza-1;
	
	/* riempi il nuovo array */
	for(int i=0; i<lunghezza; i++) {
		/* se indice pari devi prendere un carattere da sinistra */
		if(i%2==0) {
			nuovaSequenza[i]=sequenza[indiceS];
			indiceS++;
		}
		/* altrimenti da destra */
		else {
			nuovaSequenza[i]=sequenza[indiceD];
			indiceD--;
		}
	}
			
	/* OUTPUT */
	printf("\nLa nuova sequenza %c: ", 138);
	for(int i=0; i<lunghezza; i++) 
		printf("%d ", nuovaSequenza[i]);
}

 #include <stdio.h>

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	int ultimo;				// ultimo elemento dell'array
	
	/* INPUT */
	printf("Ciao utente, quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* tieni traccia dell'ultimo elemento dell'array */
	ultimo = sequenza[lunghezza-1];
	/* sposta tutti gli elementi verso destra a partire dal penultimo */
	for(int i=lunghezza-2; i>=0; i--) {
		sequenza[i+1]=sequenza[i];
	}
	/* copia il precedentemente ultimo nel primo */
	sequenza[0]=ultimo;
	
	/* OUTPUT */
	printf("\nLa sequenza rotata %c: ", 138);
	for(int i=0; i<lunghezza; i++) 
		printf("%d ", sequenza[i]);
}

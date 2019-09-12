 #include <stdio.h>

/* funzione principale */
int main() {
	int lunghezza;				// numero di elementi dell'array
	int numeroCorrente;		// intero on a run
	int occorrenzeCorrente;	// quante volte è stato visto
	int numeroMassimo;		// il massimo finora trovato
	int occorrenzeMassimo;	// quante volte è stato visto
	
	/* INPUT */
	printf("Ciao utente, quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* inizializzazione */ 
	numeroCorrente = sequenza[0];
	numeroMassimo = sequenza[0];
	occorrenzeCorrente = 1;
	occorrenzeMassimo = 1;
		
	/* cerca il massimo */
	for(int i=1; i<lunghezza; i++) {
		/* inizia una nuova sequenza di numeri uguali? */
		if(sequenza[i]!=numeroCorrente) {
			numeroCorrente = sequenza[i];
			occorrenzeCorrente = 1;
		}
		else {
			/* continua la precedente */
			occorrenzeCorrente++;
			
			/* nuovo massimo? */
			if(occorrenzeCorrente> occorrenzeMassimo) {
				occorrenzeMassimo = occorrenzeCorrente;
				numeroMassimo = numeroCorrente;
			}
		}
	}
			
	/* OUTPUT */
	printf("\nL'intero che ha il maggior numero di occorrenze consecutive ");
	printf("nella sequenza %c %d, che compare %d volte consecutivamente.\n", 138, numeroMassimo, occorrenzeMassimo);
}

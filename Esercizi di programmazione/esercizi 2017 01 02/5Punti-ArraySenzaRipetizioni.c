 #include <stdio.h>

/* funzione che calcola il numero di coppie di elementi consecutivi uguali in un array */
int ripetizioni(int interi[], int lunghezza) {
	int numero;			// il numero di coppie uguali
	numero = 0;			// inizialmente 0
	
	/* guarda tutte le coppie */
	for(int i=0; i<lunghezza-1; i++) {
		/* incrementa la variabile di conteggio se gli interi sono uguali */
		if(interi[i]==interi[i+1])
			numero++;
	}
	return numero;
}

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
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
	int nuovaLunghezza = lunghezza- ripetizioni(sequenza,lunghezza);
	int nuovaSequenza[nuovaLunghezza];
	
	/* riempilo */
	int j=0;			//variabile contatore per nuovo array	
	for(int i=0; i<lunghezza; i++) {
		/* copia il primo elemento */ 
		if(i==0) {
			nuovaSequenza[j]=sequenza[i];
			j++;
		}
		/* copia ciascun altro elemento solo se diverso dal precedente */
		else {
			if(sequenza[i]!=sequenza[i-1]) {
				nuovaSequenza[j]=sequenza[i];
				j++;
			}
		}
	}
			
	/* OUTPUT */
	printf("\nLa nuova sequenza %c: ", 138);
	for(int i=0; i<nuovaLunghezza; i++) 
		printf("%d ", nuovaSequenza[i]);
}

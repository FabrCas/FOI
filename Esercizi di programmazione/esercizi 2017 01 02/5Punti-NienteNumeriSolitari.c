 #include <stdio.h>

/* funzione che dato un array di interi e dato un indice determina se
 * l'intero a quell'indice è solitario */
int solitario(int interi[], int lunghezza, int indice) {
	int solo;				// il valore da restituire

	if(indice>0) {
	/* c'è un intero precedente */
		if(indice<lunghezza-1) {
			/* c'è il successivo */
			if(interi[indice]!= interi[indice-1] && interi[indice]!= interi[indice+1])
				solo = 1;
			else
				solo = 0;
		}
		else {
			/* non c'è il successivo */
			if(interi[indice]!= interi[indice-1])
				solo = 1;
			else
				solo = 0;
		}
	}
	else 	{
		/* non c'è il precedente */
		if(indice<lunghezza-1) {
			/* c'è il successivo */
			if(interi[indice]!= interi[indice+1])
				solo = 1;
			else
				solo = 0;
		}
		else {
			/* array lunghezza 1 */
			solo = 1;
		}
	}
	return solo;
}
 
/* funzione che calcola il numero di interi solitari in un array */
int numeroSolitari(int interi[], int lunghezza) {
	int numero;			// il numero di interi solitari
	numero = 0;			// inizialmente 0
	
	/* guarda tutti gli interi */
	for(int i=0; i<lunghezza; i++) 
		/* incrementa la variabile di conteggio se l'intero è solitario */
		if(solitario(interi, lunghezza,i)) 
			numero++;
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
	int nuovaLunghezza = lunghezza+numeroSolitari(sequenza,lunghezza);
	int nuovaSequenza[nuovaLunghezza];
	
	/* riempi il nuovo array */
	int j=0;			//variabile contatore per nuovo array	
	for(int i=0; i<lunghezza; i++) {
		/* se un elemento è solitario lo dovi copiare due volte */ 
		if(solitario(sequenza, lunghezza, i)) {
			nuovaSequenza[j]=sequenza[i];
			j++;
			nuovaSequenza[j]=sequenza[i];
			j++;
		}
		/* se un elemento non è solitario lo dovi copiare una volta */ 
		else {
			nuovaSequenza[j]=sequenza[i];
			j++;
		}
	}
			
	/* OUTPUT */
	printf("\nLa nuova sequenza %c: ", 138);
	for(int i=0; i<nuovaLunghezza; i++) 
		printf("%d ", nuovaSequenza[i]);
}

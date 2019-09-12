 #include <stdio.h>
 #include <math.h>

/* funzione che calcola il numero di cifre della rappresentazione binaria di un numero */
int numeroCifre(int numero) {
	int res=1;			// il numero da restituire
	
	/* incrementalo fintanto che 2^res-1 è minore del numero */
	while(((int) pow(2,res))-1<numero)
		res++;
	
	return res;
}

/* funzione principale */
int main() {
	int numero;			// il numero da codificare
	int lunghezza;		// numero cifre array
	int potenza;			// potenza attuale
	int residuo;			// numero ancora da rappresentare
	
	/* INPUT */
	printf("Ciao utente, quale intero vuoi convertire? ");
	scanf("%d", &numero);
	
	while(numero<0) {
		printf("\nIl numero deve essere positivo! Prova ancora: ");
		scanf("%d", &numero);
	}

	/* calcola la lunghezza dell'array */
	lunghezza = numeroCifre(numero);
	int binario[lunghezza];
	
	/* adesso riempi l'array */
	residuo = numero;								// devi ancora rappresentare tutto il numero
	potenza = (int) pow(2,lunghezza-1); 	// valore cifra più significativa
	for(int i=0; i<lunghezza; i++) {
		if(potenza<=residuo) { // la potenza attuale ci sta
			binario[i] = 1;
			residuo -= potenza;
			potenza /= 2;
		}
		else {						 // la potenza attuale non ci sta
			binario[i] = 0;
			potenza /= 2;
		}
			
	}
			
	/* OUTPUT */
	printf("\nLa rappresentazione binaria del numero %c: ", 138);
	for(int i=0; i<lunghezza; i++) 
		printf("%d ", binario[i]);
}

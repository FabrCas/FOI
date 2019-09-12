#include <stdio.h>

/* Programma che chiede all'utente di inserire un intero positivo n e
	poi n interi. L'applicazione stampa un messaggio in cui dice all'utente 
	se tutti gli interi inseriti sono positivi oppure no. */
int main() {
	int n;					// numero di interi da leggere
	int numero;		// un intero da leggere
	int tuttiPositivi;	// i numeri sono tutti positivi?
	
	/* QUANTI INTERI? */
	printf("Quanti interi vuoi introdurre?\n");
	scanf("%d", &n);
	
	/* inizialmente tutti i numeri sono positivi */
	tuttiPositivi = 1;
	
	/* leggi n numeri e verifica se sono positivi */
	for(int i=1;i<=n;i++) {
		/* INPUT */
		printf("Introduci un intero, please.\n");
		scanf("%d", &numero);

		if(numero<=0)
			tuttiPositivi = 0;
	}

	/* OUTPUT */
	if(tuttiPositivi)
		printf("\nI numeri sono tutti positivi.");
	else
		printf("\nI numeri non sono tutti positivi.");
}


#include <stdio.h>

/* Programma che chiede all'utente di inserire un numero
 * e ne calcola e stampa il fattoriale */
int main() {
	int numero;			// il numero da leggere
	int fattoriale;			// il valore da calcolare
	int i;						// variabile contatore
	
	/* INPUT */
	printf("Caro utente inserisci un numero!\n");
	scanf("%d", &numero);
	
	/* CALCOLA IL FATTORIALE. Algoritmo: moltiplica la variabile
		fattoriale per ogni numero compreso fra 1 ed n */
	fattoriale = 1;			// valore iniziale
	for(i=1; i<=numero; i++) 
		fattoriale *= i;
		
	/* OUTPUT */
	printf("Il fattoriale di %d %c %d\n", numero, 138, fattoriale);
}

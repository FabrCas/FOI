#include <stdio.h>

/* programma che legge due interi ed informa l'utente sul 
 * massimo comun divisore fra i due interi letti */
int main() {
	int x, y;			// gli interi da leggere
	int risultato;	// il MCD fra i due interi

	/* INPUT */
	printf("Caro utente, introduci due interi.\n");
	scanf("%d%d", &x, &y);
	
	/* CALCOLA IL MCD */
	if(x<y)
		risultato = x;
	else 
		risultato = y;
	while(x%risultato!=0 || y%risultato!=0) 
		risultato--;
	
	/* OUTPUT */
	printf("Il MCD fra %d e %d %c %d.\n", x, y, 138, risultato);
}

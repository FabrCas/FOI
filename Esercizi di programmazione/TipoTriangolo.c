#include <stdio.h>

 /* Applicazione che chiede all'utente di inserire 3 interi 
  * a, b e c da tastiera, li legge e stampa un messaggio 
  * che dice all'utente se il triangolo con lati a, b e c 
  * è equilatero, isoscele o scaleno. */
int main() {
	int lato1, lato2, lato3;		// i lati del triangolo
	
	/* INPUT */
	printf("Caro utente, introduci le lunghezze dei lati di un triangolo\n");
	scanf("%d%d%d", &lato1, &lato2, &lato3);
	
	/* OUTPUT */
	if(lato1==lato2 && lato1==lato3) 
		printf("Il triangolo %c equilatero\n", 138);
	else 
		if(lato1==lato2 || lato1==lato3 || lato2==lato3) 
			printf("Il triangolo %c isoscele\n", 138);
		else
			printf("Il triangolo %c scaleno\n", 138);
}

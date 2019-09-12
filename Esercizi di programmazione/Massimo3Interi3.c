#include <stdio.h>

int main() {
	int x, y, z;				// variabili per memorizzare tre interi
	int massimo;			// il massimo fra i tre
	/* INPUT */
	printf("Introduci tre interi!\n");
	scanf("%d%d%d", &x, &y, &z);
	
	/* CALCOLA IL MASSIMO */
	if(x>y && x>z)
		massimo = x;
	else 
		if(y>z)
			massimo = y;
		else 
			massimo = z;
		
	/* OUTPUT */
	printf("Il massimo valore %c %d", 138, massimo);
}

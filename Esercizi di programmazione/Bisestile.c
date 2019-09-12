#include <stdio.h>

 /* Applicazione che chiede all'utente di inserire un anno 
  * da tastiera, lo legge e stampa un messaggio che dice 
  * all'utente se l'anno è bisestile oppure no. */
int main() {	
	int anno;			// anno da leggere
	
	/* INPUT */
	printf("Caro utente, introduci un anno\n");
	scanf("%d", &anno);

	/* OUTPUT */
	if((anno%400==0)||((anno%4==0)&&(anno%100!=0))) // anno bisestile
		printf("Anno bisestile\n");
	else
		printf("Anno non bisestile\n");
}
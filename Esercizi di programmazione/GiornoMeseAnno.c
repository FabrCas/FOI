#include <stdio.h>

 /* Applicazione che chiede all'utente di inserire 3 interi g, m ed a 
  * da tastiera, li legge e stampa un messaggio che informa l'utente 
  * su quale sia il giorno successivo al giorno g del mese m dell'anno a . */
int main() {
	int g, m, a;		// giorno, mese ed anno
	int g1, m1, a1; 	// giorno, mese ed anno successivi
	
	/* INPUT */
	printf("Caro utente, introduci giorno, mese ed anno\n");
	scanf("%d%d%d", &g, &m, &a);
	
	/* CALCOLA IL PROSSIMO GIORNO MESE ED ANNO */
	if(g==31 && m==12) {	// 31 dicembre
		g1 = 1;
		m1 = 1;
		a1 = a+1;
	}
	else { // non 31 dicembre
		a1 = a;
		/* calcola il mese e il giorno: sono rispettivamente lo stesso e
		 * lo stesso piu' uno a meno che non sei nell'ultimo giorno del mese */
		if(m==1||m==3||m==5||
		   m==7||m==8||m==10||m==12){ // il mese ha 31 giorni
			if(g==31) { 	// fine mese, osserva che mese!=12
				g1 = 1;
				m1 = m+1;		
			}
			else {// non fine mese
				g1 = g+1;
				m1 = m;
			}
		} else {
			if(m==4||m==6||m==9||m==11) { // il mese ha 30 giorni
				if(g==30) { // fine mese
					g1 = 1;
					m1 = m+1;		
				}
				else {// non fine mese
					g1 = g+1;
					m1 = m;
				}
			}
			else { // sei a febbraio
				if(((a%4==0)&&(a%100!=0))||(a%400==0)) {// anno bisestile
					if(g==29) {// fine mese
						g1 = 1;
						m1 = 3;
					}
					else {// non fine mese
						g1=g+1;
						m1=m;
					}
				} 
				else { // anno non bisestile 
					if(g==28) {// fine mese
						g1 = 1;
						m1 = 3;
					}
					else {// non fine mese
						g1 = g+1;
						m1 = m;
					}
				}
			}
		}
	}
		
	/* OUTPUT */
	printf("Il giorno successivo a quello da te inserito %c il %d/%d/%d\n", 138, g1, m1, a1);
}

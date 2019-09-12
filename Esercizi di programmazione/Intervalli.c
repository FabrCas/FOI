/* Realizzare un'applicazione per gestire intervalli. Un intervallo è inteso come una 
 * coppia [a;b] tale che a e b sono interi non negativi con a<=b. Un intervallo può 
 * quindi essere rappresentato da una struttura con due campi di tipo intero, che 
 * corrispondono agli estremi dell'intervallo.
 * 
 * L'applicazione deve permettere all'utente di svolgere le seguenti funzionalità.
 * 
 * - Inserimento di un nuovo intervallo in testa alla lista.
 * - Cancellazione dell'intervallo in fondo alla lista.
 * - Visualizzazione della lista corrente di intervalli; ciascun intervallo può essere 
 * visualizzato rappresentando graficamente la porzione del semiasse positivo 
 * dell'asse delle x che occupa. Ad esempio la lista [2;7], [5;9], [0;3] può essere 
 * rappresentata come:
 *    ------
 *        -----
 * ---- 
 * - Ordinamento della lista di intervalli per valore crescente del loro estremo sinistro 
 *  e, secondariamente, per valore crescente del loro estremo destro.
 * - Calcolo e stampa dell'intersezione fra tutti gli intervalli della lista, se tale intersezione 
 * esiste. 
 * 
 * All'avvio dell'esecuzione l'applicazione deve inizializzare la lista di intervalli con i valori 
 * letti da un file; al termine dell'esecuzione l'applicazione deve salvare i dati della lista 
 * nello stesso file. */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* un intervallo */
struct Intervallo {
    int sinistra;
    int destra;
};

/* per la lista di intervalli */
struct Nodo{
    struct Intervallo intervallo;
    struct Nodo* next;
};

/**********************************************
 ******************** STAMPE ******************
 **********************************************/

/* per stampare un intervallo */
void stampaIntervallo(struct Intervallo intervallo) {
	for(int i = 0; i<intervallo.sinistra; i++)
		printf(" ");
	for(int i = intervallo.sinistra; i<=intervallo.destra; i++)
		printf("-");
	printf("\n");
}

/* per stampare una lista di intervalli */
void stampa(struct Nodo* lista) {
	/* vai avanti fino a che ci sono intervalli */
	lista = lista->next;			// supera il nodo fittizio
	if(lista==NULL)
		printf("La lista %c vuota\n\n", 138);
	else {
		printf("Ecco gli intervalli in lista\n\n");
		while(lista!= NULL) {
			stampaIntervallo(lista->intervallo);
			lista = lista->next;
		}
		printf("\n");
	}
}

/**********************************************
 ************ INSERIMENTO IN TESTA ************
 **********************************************/

/* inserimento di un intervallo in testa alla lista */
void inserisci(struct Nodo* lista, struct Intervallo inter) {
	/* alloca memoria per il nodo */
	struct Nodo* testa = malloc(sizeof(struct Nodo));
	/* riempi il campo dati */
	testa->intervallo = inter;
	
	/* collega il nodo a quello fittizio ed al primo reale */
	testa->next = lista->next;
	lista->next = testa;
}

/* inserimento di un intervallo in lista con lettura */
void nuovoIntervallo(struct Nodo* lista) {
	struct Intervallo inter;		// da inserire

	/* leggi l'intervallo */
	do {
		printf("Caro utente, da quale intero parte l'intervallo? ");
		scanf("%d", &inter.sinistra); 
		if(inter.sinistra<0)
			printf("E' richiesto un intero positivo!\n");
	}
	while(inter.sinistra<0);
	
	do {
	printf("Caro utente, a quale intero finisce l'intervallo? ");
		scanf("%d", &inter.destra); 
		if(inter.destra<inter.sinistra)
			printf("E' richiesto un valore maggiore o uguale a %d!\n",inter.sinistra);
	}
	while(inter.destra<inter.sinistra);
	
	
	/* inserisci l'intervallo in lista */
	inserisci(lista,inter);
	printf("Intervallo inserito!\n\n");
}

/*********************************************************
 *********************** CANCELLAZIONE *******************
 *********************************************************/ 

/* funzione che cancella l'ultimo intervallo della lista */		
void cancellaIntervallo(struct Nodo *lista) {
	
	/* c'è un intervallo da cancellare? */
	if(lista->next == NULL)
		printf("Niente da cancellare!\n\n");
	else {
		/* arriva in fondo alla lista */
		while(lista->next->next!=NULL){
			lista = lista->next;
		}
		/* OK sei in fondo: dealloca l'ultimo nodo ed il penultimo diventa ultimo */
		free(lista->next);
		lista->next = NULL;
		/* stampa messaggio e termina */
		printf("Intervallo cancellato!\n\n");
	}
}

/*********************************************************
 ************************ ORDINAMENTO ********************
 *********************************************************/ 

/* funzione che determina se un intervallo precede un altro */
int precede(struct Intervallo i1, struct Intervallo i2) {
	int prima;			// valore da restituire
	if(i1.sinistra<i2.sinistra || (i1.sinistra==i2.sinistra && i1.destra<i2.destra))
		prima = 1;
	else 
		prima = 0;
	return prima;
}


/* funzione che ordina gli elementi di una lista; implementa selection sort */
void ordina(struct Nodo *lista) {
	struct Nodo *primo;				// primo nodo parte non ordinata
	struct Nodo *minimo;			// minimo corrente
	struct Nodo *nodo;				// nodo corrente
	struct Intervallo inter;			// variabile ausiliaria
	
	/* se la lista è vuota niente da fare */
	if(lista->next != NULL) {
		/* il primo nodo non ordinato è il primo nodo non fittizio della lista */
		primo = lista->next;					
		/* prosegui fino a che la parte ordinata ha almeno due nodi */
		while(primo->next != NULL) {
			/* inizializza il minimo a primo */
			minimo = primo;
			/* guarda tutti i nodi a partire dal successivo a primo e prosegui fino a 
			 * che non li hai visti tutti */
			for(nodo = primo->next; nodo!=NULL; nodo = nodo -> next) 
				/* minore del minimo ? */
				if(precede(nodo->intervallo, minimo->intervallo)) 
					minimo = nodo;

			/* adesso scambia i campi dati del minimo e del primo elemento non ordinato */
			inter = primo->intervallo;
			primo->intervallo = minimo->intervallo;
			minimo->intervallo = inter;
			
			/* fai scorrere il primo elemento non ordinato */
			primo = primo->next;
		}
		printf("Lista ordinata!\n\n");
	}
	else 
		printf("Non c'%c molto da ordinare!\n\n", 138);
}

/*********************************************************
 ************************ INTERSEZIONE ********************
 *********************************************************/ 

/* funzione che verifica se due intervalli hanno intersezione non nulla */
int esisteIntersezioneADue(struct Intervallo i1, struct Intervallo i2) {
	/* due intervalli hanno intersezione vuota se il lato destro di uno dei due
	 * è a sinistra del lato sinistro dell'altro */
	return !(i1.destra <i2.sinistra) && !(i2.destra <i1.sinistra);
}


/* funzione che dati due intervalli ne calcola l'intersezione, assumendo che ci sia */
struct Intervallo intersezioneADue(struct Intervallo i1, struct Intervallo i2) {
	// pre: intersezione non vuota 
	struct Intervallo inter;		// da restituire
	if(i1.sinistra>=i2.sinistra)
		inter.sinistra =i1.sinistra;
	else 
		inter.sinistra =i2.sinistra;
	if(i1.destra<=i2.destra)
		inter.destra =i1.destra;
	else 
		inter.destra =i2.destra;
	return inter;
}

/* funzione calcola e stampa l'intersezione di una lista di intervalli */
void intersezione(struct Nodo* lista) {
	int esiste = 1;						// esiste l'intersezione?
	struct Intervallo inter;			// l'intersezione corrente
	struct Nodo* nodo = lista;		// per scorrere la lista
	
	if(nodo->next == NULL)		// lista vuota
		printf("Non ci sono intervalli\n\n");
	else {	// almeno un intervallo
		nodo = nodo->next;						// supera il nodo fittizio
		inter = nodo->intervallo;		// inizializza al primo intervallo della lista
		while(esiste && nodo->next!=NULL) {
			/* confronta il prossimo intervallo della lista con l'intersezione attuale */  
			nodo = nodo->next;
			if(esisteIntersezioneADue(nodo->intervallo, inter)) 
				inter = intersezioneADue(nodo->intervallo, inter);
			else
				esiste = 0;
		}
		/* se è sopravvissuto un intervallo, stampalo */
		if(esiste) {
			stampa(lista);
			printf("Ed ecco l'intersezione!\n");
			stampaIntervallo(inter);
			printf("\n");
		} 
		else
			printf("L'intersezione degli intervalli nella lista %c vuota!\n\n", 138);
	}
}

/**********************************************
 **************** GESTIONE FILE ****************
 **********************************************/

/* funzione per l'acquisizione di una lista su file, soluzione con nodo fittizio */
void acquisizione(struct Nodo* head) {
	FILE* fp = fopen("intervalli.dat", "rb");				// per la lettura di un file binario

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		int letto;			// lettura OK o no
		struct Nodo* nodo;										// nodo corrente
		struct Intervallo inter;									// un intervallo
	
		/* collega la lista al nodo fittizio */
		nodo = head;				
		/* adesso leggi gli intervalli */
		do {		
			/* leggi un intervallo */
			letto = fread(&inter, sizeof(struct Intervallo), 1, fp);
			if(letto) {		// lo hai effettivamente letto?
				/* memorizza nell'heap il nodo corrispondente */ 
				nodo->next = malloc(sizeof(struct Nodo)) ;			
				nodo->next->intervallo = inter;
				
				/* aggiorna l'ultimo nodo */
				nodo = nodo->next;
			}
			else // il file è terminato, setta il campo next dell'ultimo nodo 
				nodo -> next = NULL;
		}
		while(letto);
	}
	fclose(fp);
}

/* funzione per il salvataggio di una lista su file */
void salvataggio(struct Nodo* lista) {
	FILE* fp = fopen("intervalli.dat", "wb");										// per la scrittura di un file binario
	while(lista!= NULL) {																	// procedi fino a che hai nodi 
		fwrite(&(lista->intervallo), sizeof(struct Intervallo), 1, fp);		// ciò che scrivi è un intervallo
		lista = lista->next;																// passa al prossimo nodo
	} 
	fclose(fp);
}

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* crea la lista con nodo fittizio */
	struct Nodo* lista = malloc(sizeof(struct Intervallo));	
	lista->next = NULL;
	/* acquisisci dati da file */
	acquisizione(lista);
	
	int risposta = -1;			// per interazione con utente
	
	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserisci un intervallo in testa alla lista\n");
		printf("2 -> Cancella l'ultimo intervallo della lista\n");
		printf("3 -> Visualizza la lista di intervalli\n");
		printf("4 -> Ordina la lista di intervalli\n");
		printf("5 -> Calcola l'intersezione fra gli intervalli\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);
		
		/* gestisci le operazioni dell'utente */
		if(risposta==1) {
			nuovoIntervallo(lista);
		}
		else if(risposta==2) {
			cancellaIntervallo(lista);
		}
		else if(risposta==3) {
			stampa(lista);
		}
		else if(risposta==4) {
			ordina(lista);
		}
		else if(risposta==5) {
			intersezione(lista);
		}
		else if(risposta==0) {
			printf("Adios!\n");
		}
		else printf("Selezione non valida!\n\n");
	}
	/* salva la lista sul file, ignorando il nodo fittizio */
	salvataggio(lista->next);
}
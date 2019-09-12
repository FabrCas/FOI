#include <stdio.h>
//*programma che converte un numero binario in input e stampa un valore decimale in output*//
int decodifica(int binario[], int dimensione)  //funzione decodifica
{
    int somma, valore_posizione, i;
    //*Inizializzazioni di somma e valore_posizione*//
    somma=0;
    valore_posizione=1;
    //*ciclo for che calcola il valore somma, leggendo il valore
    //binario da destra verso sinistra e moltiplicando per 
    //l'opportuna potenza di 2*//
    for(i=dimensione-1;i>=0;i--){
       somma=somma+valore_posizione*binario[i];
       valore_posizione*=2;
    }
    return somma;    //valore che viene reastituito nel main
}
int main()
{    //*INPUT*//
    int lunghezza, n[64], decimale;  
    printf("Salve utente, inserire la lunghezza del numero binario da convertire in decimale\n");
    scanf("%d", &lunghezza);
	printf("la lunghezza selezionata %c %d\n", 138, lunghezza);
    printf("Inserire il binario, una cifra per riga\n");
    for(int i=0 ; i<(lunghezza) ; i++){
        scanf("%d", &n[i]);
    }
    decimale=decodifica(n, lunghezza); //richiamo della funzione "decodifica"
    //*OUTPUT*//
    printf("Il numero decimale corrispondente %c %d", 138, decimale);
}

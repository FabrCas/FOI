/*Programma che calcola la somma massima di 3 interi consecutvi in una sequenza lunga almeno 3 interi
 * SPECIFICA
 * Input: Una sequenza s di interi e la sua lunghezza l
 * Pre-condizione: l è la lunghezza di s e l>=3 
 * Output: Un intero somma
 * Post-condizione: somma è pari alla somma massima di tre interi consecutivi in s
 * TIPO DI PROBLEMA: Massimo
 */
#include <stdio.h>

int SommaMassima3Consecutivi(int lunghezza, int sequenza[]){
  int somma;
  somma= sequenza[0]+sequenza[1]+sequenza[2];   //Inizializza la somma a quella dei primi 3 elementi della sequenza
  for(int i=3;i<lunghezza;i++){
      if(sequenza[i-2]+sequenza[i-1]+sequenza[i]>somma)
         somma=sequenza[i-2]+sequenza[i-1]+sequenza[i];
  }
  return somma;
}

int main()
{
    int l, somma;
	printf("Salve utente, introdurre il numero di elementi della sequenza, il numero minimo %c 3\n", 138);
	scanf("%d", &l);
    while(l<3){
        printf("Il numero selezionato %c troppo piccolo\n", 138);
        scanf("%d", &l);
    }
    int i;
    int s[l];
    printf("Ora inserire la sequenza di valori\n");
    for(i=0;i<l;i++){
        printf("Inserire il %d%c numero\n", i+1,167);
        scanf("%d", &s[i]);
    }
    somma=SommaMassima3Consecutivi(l,s);
    printf("La somma massima di 3 consecutivi nella sequenza inserita %c %d", 138, somma);
}

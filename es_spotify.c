#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100
#define SONG 1000
#define TITOLOFILE "playlist.csv"

typedef struct Slista{                                            //struttura necessaria per ogni canzone
    int numero;
    char *titolo, *artista;
    bool ordine;
}lista;

void casuale(lista* playlist, int cont);

int main(){

lista playlist[SONG];
char riga[MAX];
int cont = 0;                                              //inizializzare cont a 0;
FILE *fp = fopen("playlist.csv", "r");

if (fp == NULL)                                                 //ciclo if per verificare se il file viene aperto correttmente
{
    printf("il file non è stato aperto correttamente\n");
    return -1;
} else

printf("file aperto correttamente\n");

while (fgets(riga,MAX,fp))
{
        playlist[cont].numero = atoi(strtok(riga,","));
        playlist[cont].titolo = strdup (strtok(NULL,","));
        playlist[cont].artista = strdup(strtok(NULL,","));
        cont++;
}
    casuale(playlist, cont);
    fclose(fp);
    return 0;
}
void casuale(lista* playlist, int cont)
{
   int ripr, random;
   printf("numero di riproduzioni casuali: ");
   scanf("%d", &ripr);
   for (int a = 0; a < cont; a++)
              {
                  playlist[a].ordine = false;
              }
          for (int n = 0; n < ripr; n++)                               //riproduzioni delle canzoni n volte
          {
              printf("riproduzione numero: %d\n", n+1);
              for (int w = 0; w < cont; w++)                                //per ogni canzone
              {
                  do
                  {
                     random = rand() % cont;
                  } while (playlist[random].ordine);
                  playlist[random].ordine = true;
                  printf("sto riproducendo: %s di %s \n\n", playlist[random].titolo, playlist[random].artista);
              }
              for (int l = 0; l < cont; l++)
              {
                  playlist[l].ordine = false;
              }}}

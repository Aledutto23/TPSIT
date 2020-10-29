#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define TITOLOFILE "playlist.csv"

char string[MAX];

typedef struct lista {
    int N;
    char titolo[MAX], autore[MAX];

}tipolista;

void A(FILE *fp);
void caricamento();
int main(){
    FILE* punt=fopen(TITOLOFILE, "r");

    if (punt == NULL){
        printf ("Errore \n");
        return -1;
    } else {
    printf("OK\n")
    };

    A(punt);
    caricamento();
    fclose (punt);
    return 0;
}
void A(FILE *fp){
    int cont=0;

    while(!feof(fp)){
		fgets(string,MAX,fp);
        printf("%s\n",string);
    }
}

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
int main(){

int A, C, T, G;

    FILE *fp;
    char stringa[MAX];
    fp = fopen ("rna.txt", "r");
    if (fp == NULL)
    {
        printf("impossibile aprire il file\n");
    }
    else
    {
    while(fgets(stringa, MAX, fp))
        {
            int n = 0;
            while(stringa[n] != '\0')
            {
                if (stringa[n] == 'A')
                A++;
            }
            {
                if (stringa[n] == 'T')
                T++;
            }
            {
                if (stringa[n] == 'C')
                C++;
            }
            {
                if (stringa[n] == 'G')
                G++;
            }
        }
        printf("le lettere sono %d, %d, %d, %d", T, A, G, C);
        fclose(fp);

return 0;

    }
}

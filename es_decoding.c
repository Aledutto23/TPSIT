#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGA 100

char* encode(char* src)
{
	int rLen;
	char cont[STRINGA];
	int dim = strlen(src);


	char* dest = (char*)malloc(sizeof(char) * (dim * 2 + 1));

	int i, j = 0, k;

	for (i = 0; i < dim; i++) { // selezionare lettera per lettera

		dest[j++] = src[i];  // copiare la prima occorrenza

		rLen = 1;
		while (i + 1 < dim && src[i] == src[i + 1]) { // conto il numero di occorrenze
			rLen++;
			i++;
		}

		sprintf(cont, "%d", rLen);

		for (k = 0; *(cont + k); k++, j++) {
			dest[j] = cont[k];    // finire la stringa
		}
	}

	dest[j] = '\0';
	return dest;
}

int main()
{
    int stringa;
    printf("inserire la stringa: ");
    scanf("%d\n", stringa);
	char* res = encode(stringaq);
	printf("%s", res);
	getchar();
}

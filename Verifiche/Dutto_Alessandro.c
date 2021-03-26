
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   //libreria tempo


#define MAX 9
#define CARTE 13
#define SIMBOLI 4
#define MAX_CARTE 52

//definisco la struct
struct carta{
  char *pos;
  char suit[MAX];
};
typedef struct carta Carta;


char *ranks[CARTE] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Donna", "Re"}; //dichiaro le carte

char simboli[SIMBOLI][MAX] = {"C", "P", "D", "F"}; //dichiaro i simboli delle carte

void base(Carta []);
void display(const Carta[]);

typedef struct node_t // rappresenta una cella della coda
{
    int value; //Valore
    struct node_t *next; //Puntatore del nodo successivo
}node;

typedef struct queue_t
{
    node* tail; //Puntatore all'ultima cella
    node* head; //Puntatore alla prima cella
}queue;



struct enqueue(queue *q, char CARTE)
{
    node *tmp = NULL; //Puntatore di supporto

    if(q == NULL)
        return 0;

    tmp = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo
    tmp->value = value;

    if(q->tail != NULL) //Se tail non è null (non è la prima operazione di accodamento) *
        q->tail->next = tmp; //* viene collegato il nodo precedente a quello nuovo

    q->tail = tmp; //tail ora punta al nuovo nodo (la coda si estende)

    if(q->head == NULL)
        q->head = q->tail; //head punta alla stessa cella puntata da tail

    return 1;
}

struct queue_node * dequeue(struct queue_node head, struct Queue_node tail) {

    struct queue_node *ret = head;

    if (is_empty(head)) {
        return NULL;
    }
    else {
        head = ret->next;
    }

    if (head == NULL) {
        *tail = NULL;
    }
    return ret;
}
void dequeue


int main(){
  char linea = '\n'; //creo una nuova linea
  Carta mazzo[MAX_CARTE] = {"",""};
  base(mazzo);
  while('\n' == linea){
    display(mazzo);  o
    linea = getchar();
  }

  int ele = 0;
  ele -> dequeue[0]
  if (ele == D || ele == C){
      ele->*enqueue;


  }


}








#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
typedef struct queue* Queue;

void init(Queue* queue, int max_size);
bool is_full(Queue queue);
bool is_empty(Queue queue);
bool enqueue(Queue queue, Element new_element);
Element dequeue(Queue queue);

int main(int argc, char const *argv[]){
    
    Queue fila_pessoa;
    Queue fila_aux2;

    int n; //quantidade de pessoas a serem colocadas na fila
    int colocada; //colocada na fila
    int fora; //quantidade de pessoas que sairam da fila
    int saiu; //pessoa que saiu 
    int auxiliar1; //auxiliar de verificação

    scanf("%d", &n);
    init(&fila_pessoa, n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &colocada);
        enqueue(fila_pessoa, colocada);
    }
 
    scanf("%d", &fora);
    int array[fora];
    for(int i = 0; i < fora; i++){
        scanf("%d", &saiu);
        array[i] = saiu;
    }

    bool achou;
    init(&fila_aux2, n-fora);
    while(!is_empty(fila_pessoa)){
        auxiliar1 = dequeue(fila_pessoa);

        achou = false;
        for(int i = 0; i < fora && achou == false; i++){
            if(auxiliar1 == array[i]){
                achou = true;
            }
        }
        if(!achou){
            enqueue(fila_aux2, auxiliar1);
        }
    }
    
    while (!is_empty(fila_aux2)) {
        int element = dequeue(fila_aux2);
        if (element != -1) {
            printf("%d ", element);
        }
    }
    printf("\n");
    
    return 0;
}

struct queue {
    Element items[50000];
    int marks[50000];
    int last, first, size, max_size;
};


void init(Queue* queue, int max_size) {
    Queue q;
    q = malloc(sizeof(struct queue));
    q->max_size = max_size;
    q->last = -1;
    q->first = -1;
    q->size = 0;

    for (int i = 0; i < max_size; i++) {
        q->marks[i] = 0;
    }

    *queue = q;
}

bool is_full(Queue queue){
    return queue->size == queue->max_size;
}

bool is_empty(Queue queue){
    return queue->size == 0;
}

bool enqueue(Queue queue, Element new_element){
    bool answer = false;
    //if(! is_full(queue)){
        /*if(queue->last == queue->max_size - 1){
            queue->last = 0;
        }else{
            queue->last += 1;
        }*/
        queue->last += 1;
        queue->items[queue->last] = new_element;
        queue->size += 1;
        answer = true;
    //}
    return answer;
}

Element dequeue(Queue queue) {
    Element answer;

    do {
        queue->first += 1;
        answer = queue->items[queue->first];
    } while (queue->marks[queue->first] == -1);

    queue->marks[queue->first] = -1;
    queue->size -= 1;

    return answer;
}
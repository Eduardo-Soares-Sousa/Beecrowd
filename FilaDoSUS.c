#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_MAX_SIZE 25

typedef int Element;
typedef struct queue* Queue;

void init(Queue* queue);
bool is_full(Queue queue);
bool is_empty(Queue queue);
bool enqueue(Queue queue, Element new_element);
Element dequeue(Queue queue);

int main(int argc, char const *argv[]){
    
    int i, aux;
    int hora, minuto, critico, n;

    Queue filaEspera;
    init(&filaEspera);

    while (scanf("%d", &n) != EOF) {

        aux = 0;
        int tempo_total = 420;
        for (i = 0; i < n; ++i) {

            scanf("%d %d %d", &hora, &minuto, &critico);

            while (tempo_total < (hora * 60) + minuto) {
                if (!is_empty(filaEspera)) {
                    Element auxiliar = dequeue(filaEspera);
                    tempo_total = (auxiliar * 60) + minuto;
                } else {
                    tempo_total += 30;
                }
            }

            if (tempo_total - ((hora * 60) + minuto) > critico) {
                ++aux;
            } else {
                enqueue(filaEspera, hora);
            }

            tempo_total += 30;
        }

        printf("%d\n", aux);

    }

    return 0;
}

struct queue{
    Element items[QUEUE_MAX_SIZE];
    int last, first, size;
};

void init(Queue* queue){
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    q->first = -1;
    q->size = 0;
    *queue = q;
}

bool is_full(Queue queue){
    return queue->size == QUEUE_MAX_SIZE;
}

bool is_empty(Queue queue){
    return queue->size == 0;
}

bool enqueue(Queue queue, Element new_element){
    bool answer = false;
    if(! is_full(queue)){
        if(queue->last == QUEUE_MAX_SIZE - 1){
            queue->last = 0;
        }else{
            queue->last += 1;
        }
        queue->items[queue->last] = new_element;
        queue->size += 1;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue){
    Element answer;
    if(!is_empty(queue)){
        if(queue->first == QUEUE_MAX_SIZE - 1){
            queue->first = 0;
        }else{
            queue->first += 1;
        }
        queue->size -= 1;
        answer = queue->items[queue->first];
    }
    return answer;
}
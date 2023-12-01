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

struct queue{
    Element items[25];
    int last, first, size, max_size;
};

int main(int argc, char const *argv[]){
    int i, aux;
    int hora, minuto, critico, n;

    while (scanf("%d", &n) != EOF) {
        aux = 0;
        int tempo_total = 420;

        Queue fila_pessoa;
        init(&fila_pessoa, 25);

        for (i = 0; i < n; ++i) {
            scanf("%d %d %d", &hora, &minuto, &critico);

            while (tempo_total < (hora * 60) + minuto)
                tempo_total += 30;
            
            if (tempo_total - ((hora * 60) + minuto) > critico) {
                ++aux;
            }

            tempo_total += 30;

            enqueue(fila_pessoa, aux);
        }

        printf("%d\n", aux);
    }

    return 0;
}

void init(Queue* queue, int max_size){
    Queue q;
    q = malloc(sizeof(struct queue));
    q->max_size = max_size;
    q->last = -1;
    q->first = -1;
    q->size = 0;
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
    if (!is_full(queue)) {
        queue->last += 1;
        queue->items[queue->last] = new_element;
        queue->size += 1;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue){
    Element answer;
    if (!is_empty(queue)) {
        queue->first += 1;
        queue->size -= 1;
        answer = queue->items[queue->first];
    }
    return answer;
}

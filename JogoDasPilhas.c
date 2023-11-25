#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct stack* Pilha;
typedef int Tipo_Informacao;

void init(Pilha* pilha);
bool is_full(Pilha pilha);
bool is_empty(Pilha pilha);
bool push(Pilha pilha, Tipo_Informacao elemento);
bool pop(Pilha pilha, Tipo_Informacao* elemento);

int podeGanhar(int n, Pilha* pilhas);

int main() {
    int N, i;

    do{
        scanf("%d", &N);

        Pilha pilhas[N];
        for(i = 0; i < N; i++){
            init(&pilhas[i]);
        }

        for(i = 0; i < N; i++){
            int carta1, carta2, carta3;
            scanf("%d %d %d", &carta1, &carta2, &carta3);

            push(pilhas[i], carta1);
            push(pilhas[i], carta2);
            push(pilhas[i], carta3);
        }

        int resultado = podeGanhar(N, pilhas);
        printf("%d\n", resultado);

        for(i = 0; i < N; i++){
            free(pilhas[i]);
        }
    }while(N != 0);
    

    return 0;
}

int podeGanhar(int n, Pilha* pilhas) {
    int i, soma = 0;

    for(i = 0; i < n; i++){
        int somaTopo = 0;
        while(!is_empty(pilhas[i])){
            Tipo_Informacao carta;
            pop(pilhas[i], &carta);
            somaTopo += carta;
        }

        if(somaTopo % 3 != 0){
            return 0;
        }

        soma += somaTopo;
    }

    if(soma % 3 != 0){
        return 0;
    }

    return 1;
}

struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}


bool is_full(Pilha pilha){
	
	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->topo == -1 ? true : false;

}


bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_full(pilha) ){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}
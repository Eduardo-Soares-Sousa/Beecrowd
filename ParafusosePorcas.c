#include <stdio.h>

int main(int argc, char const *argv[]){

    int aux;
    int array[101];
    int i, j, inicio, fim, n;

    while(scanf("%d", &n) != EOF){
        for(i = 0; i < 101; i++){
            array[i] = 0;
        }

        for(j = 0; j < n; j++){

            scanf("%d %d", &inicio, &fim);

            for(i = inicio; i <= fim; i++){
                ++array[i];
            }    
        }

        aux = 0;
        scanf("%d", &j);
        if(array[j]){
            for (i = 1; i < j; i++){
                aux += array[i];
            }

            printf("%d found from %d to %d\n", j, aux, (aux + array[i] - 1));
        }
        else{
            printf("%d not found\n", j);
        }
    }

    return 0;
}
#include <stdio.h>
#include <locale.h>
#include <time.h>

#include "list.h"

#define randint(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

void display_list(List* l) {
    int value;

    printf("[");
    for (int i = 1; i <= list_size(l); i++) {
        if (list_get(l, i, &value) == 0) {
            printf("%d,", value);
        }
    }
    printf("]\n");
}

void fill_with_random(List* l, int min, int max) {
    for (int i = 1; i <= list_size(l); i++) {
        list_insert(l, i, randint(min, max));
    }
}

int main(int argc, char *argv[]) {
    List l;
    
    srand(time(NULL)); // for random int generation.
    setlocale(LC_ALL,"Portuguese");

    printf("Criando a lista...\n");
    l = list_create(256);

    if (list_empty(&l)) {
        printf("A lista acabou de ser criada e está vazia.\n");
    }

    // Fill list with random numbers from 1 to 1000.
    printf("Enchendo a lista com números aleatórios de 1 a 1000...\n");
    fill_with_random(&l, 0, 1000);


    if (list_full(&l)) {
        printf("A lista foi completamente preenchida.\n");
    }

    display_list(&l);


    return 0;
}
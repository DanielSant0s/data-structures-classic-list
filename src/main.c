#include <stdio.h>
#include <locale.h>
#include <time.h>

#include "list.h"

#define randint(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

int main(int argc, char *argv[]) {
    List l;
    int value;
    
    srand(time(NULL)); // for random int generation.
    setlocale(LC_ALL,"Portuguese");

    printf("Criando a lista...\n");
    l = list_create(256);

    if (list_empty(&l)) {
        printf("A lista acabou de ser criada e está vazia.\n");
    }

    // Fill list with random numbers
    printf("Enchendo a lista com números aleatórios...\n");
    for (int i = 1; i <= list_size(&l); i++) {
        list_insert(&l, i, randint(0, 1000));
    }

        if (list_full(&l)) {
        printf("A lista foi completamente preenchida.\n");
    }

    for (int i = 1; i <= list_size(&l); i++) {
        if (list_get(&l, i, &value) == 0) {
            printf("pos %d - value %d\n", i, value);
        }
    }


    return 0;
}
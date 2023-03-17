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
        } else {
            printf("empty,");
        }
    }
    printf("]\n");
}

void fill_with_random(List* l, int min, int max) {
    for (int i = 1; i <= list_size(l); i++) {
        if (list_insert(l, i, randint(min, max)) == 0) {
            printf("Item adicionado na posicao %d.\n", i);
        }
    }
}

int main(int argc, char *argv[]) {
    List l;
    int randpos, try_randpos;
    
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

    // Now we can focus on more complex tests, so let's try some brute force list manipulation to see what we can get.

    printf("\nTest: Unload 50 random slots, and insert 44556677 if the code try to remove an already unloaded slot.\n");
    printf("\nTesting 'randomness' with list slots...\n");
    for (int i = 0; i < 50; i++) {
        randpos = randint(0, list_size(&l));
        if (list_remove(&l, randpos) < 0) {
            list_insert(&l, randpos, 44556677); // Insert 44556677 if the code tries to remove an already removed slot.
        }
    }

    display_list(&l);

    printf("\nTest: Unloading 100 random slots and trying to insert randomly too, if it fails, set value to -500.\n");
    printf("\nTesting 'error catching' with list slots...\n");
    for (int i = 0; i < 100; i++) {
        randpos = randint(0, list_size(&l));
        if (list_remove(&l, randpos) < 0) {
            try_randpos = randpos;
            while (randpos == try_randpos) {
                try_randpos = randint(0, list_size(&l));
                if (list_remove(&l, try_randpos) < 0) {
                    try_randpos = randpos;
                }
            }
        }
    }

    display_list(&l);

    printf("\nInserting 500 on unloaded slots, if it fails, set value to -500....\n");

    for (int i = 1; i <= list_size(&l); i++) {
        if (list_insert(&l, i, 500) < 0) {
            list_set(&l, i, -500);
        }
    }
    display_list(&l);

    list_destroy(&l);

    return 0;
}
#include <stdio.h>
#include <locale.h>

#include "list.h"

int main(int argc, char *argv[]) {
    List l;
    
    setlocale(LC_ALL,"Portuguese");

    l = list_create(256);

    if (list_empty(&l)) {
        printf("A lista acabou de ser criada e está vazia.\n");
    }




    return 0;
}
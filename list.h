#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_SIZE 128

typedef struct {
    int* list;
    bool* mask;
    size_t used;
    size_t size;
} List;

List list_create(size_t len);
bool list_empty(List* l);
bool list_full(List* l);
size_t list_size(List* l);
int list_get(List* l, size_t pos, int* value);
int list_set(List* l, size_t pos, int value);
int list_insert(List* l, size_t pos, int value);
int list_remove(List* l, size_t pos);




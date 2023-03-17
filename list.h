#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_SIZE 128

typedef struct {
    int* list;
    size_t used;
    size_t size;
} List;

List list_create(size_t len);
bool list_empty(List* l);
bool list_full(List* l);
int list_size(List* l);
int list_get(List* l, size_t pos);
void list_set(List* l, size_t pos, int value);
void list_insert(List* l, size_t pos, int value);
void list_remove(List* l size_t pos);




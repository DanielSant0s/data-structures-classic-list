#include "list.h"

List list_create(size_t len) {
    List l;

    if (len == 0) len = DEFAULT_SIZE;

    l.list = calloc(len, sizeof(int));
    l.mask = calloc(len, sizeof(bool));
    l.used = 0;
    l.size = len;

    return l;
}

bool list_empty(List* l) {
    return (l->used == 0);
}

bool list_full(List* l) {
    return (l->used == l->size);
}

size_t list_size(List* l) {
    return l->size;
}

int list_get(List* l, size_t pos, int* value) {
    if (l->mask[pos-1] && pos <= l->size && pos > 0) {
        *value = l->list[pos-1];
        return 0;
    }

    return -1;
}

int list_set(List* l, size_t pos, int value) {
    if (l->mask[pos-1] && pos <= l->size && pos > 0) {
        l->list[pos-1] = value;
        return 0;
    }

    return -1;
}

int list_insert(List* l, size_t pos, int value) {
    if (!l->mask[pos-1] && pos <= l->size && pos > 0) {
        l->list[pos-1] = value;
        l->mask[pos-1] = true;
        l->used++;

        return 0;
    }

    return -1;
}

int list_remove(List* l, size_t pos) {
    if (l->mask[pos-1] && pos <= l->size && pos > 0) {
        l->list[pos-1] = 0;
        l->mask[pos-1] = false;
        l->used--;

        return 0;
    }

    return -1;
}
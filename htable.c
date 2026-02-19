#include "htable.h"
#include "list.h"
#include <stdlib.h>
#include <assert.h>

htable_t *htable_create(unsigned int capacity) {
    assert(capacity > 0);

    htable_t *ht = malloc(sizeof(htable_t));
    assert(ht != NULL);

    ht->arr_capacity = capacity;
    ht->size = 0;
    ht->arr = malloc(sizeof(lnode_t *) * capacity);
    assert(ht->arr != NULL);

    for (unsigned int i = 0; i < capacity; i++)
        ht->arr[i] = NULL;  // initialize empty linked lists

    return ht;
}

void htable_put(htable_t *ht, char *key, int val,
                void (*accum)(int *, int)) {
    unsigned int i = hashcode(key) % ht->arr_capacity;

    if (list_insert_with_accum(&ht->arr[i], key, val, accum))
        ht->size += 1;  // increment only if new key
}

int htable_get(htable_t *ht, char *key) {
    unsigned int i = hashcode(key) % ht->arr_capacity;
    return list_find(ht->arr[i], key);  // return int, not int *
}

int htable_get_all_tuples(htable_t *ht, kv_t *tuples, int max) {
    int count = 0;
    for (unsigned int i = 0; i < ht->arr_capacity && count < max; i++) {
        count += list_get_all_tuples(ht->arr[i], &tuples[count], max - count);
    }
    return count;
}


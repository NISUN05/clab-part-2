#pragma once
#include "list.h"

typedef struct {
    unsigned int arr_capacity;
    unsigned int size;
    lnode_t **arr;
} htable_t;

// Function prototypes
htable_t *htable_create(unsigned int capacity);
void htable_put(htable_t *ht, char *key, int val,
                void (*accum)(int *existing_val, int new_val));
int htable_get(htable_t *ht, char *key);
int htable_get_all_tuples(htable_t *ht, kv_t *tuples, int max);
unsigned int hashcode(char *s);


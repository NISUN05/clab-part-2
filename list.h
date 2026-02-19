#pragma once
#include <stdbool.h>

// Key-value struct
typedef struct {
    char *key;
    int val;
} kv_t;

// Linked list node storing key-value directly
typedef struct lnode {
    char *key;
    int val;
    struct lnode *next;
} lnode_t;

// Function declarations
void list_init(lnode_t **headdp);
void sum_accum(int *existing_val, int new_val);
bool list_insert_with_accum(lnode_t **headdp, char *key, int val,
    void (*accum)(int *existing_val, int new_val));
int list_find(lnode_t *headp, char *key);
int list_get_all_tuples(lnode_t *headp, kv_t *tuples, int max);


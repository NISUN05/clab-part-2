#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void list_init(lnode_t **headdp) {
    *headdp = NULL;
}

void sum_accum(int *existing_val, int new_val) {
    (*existing_val) += new_val;
}

bool list_insert_with_accum(lnode_t **headdp, char *key, int val,
    void (*accum)(int *, int))
{
    assert(headdp != NULL && key != NULL && accum != NULL);

    lnode_t *prev = NULL;
    lnode_t *curr = *headdp;

    while (curr && strcmp(curr->key, key) < 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr && strcmp(curr->key, key) == 0) {
        accum(&curr->val, val);
        return false;
    }

    lnode_t *new_node = malloc(sizeof(lnode_t));
    assert(new_node != NULL);
    new_node->key = key;
    new_node->val = val;
    new_node->next = curr;

    if (!prev) {
        *headdp = new_node;
    } else {
        prev->next = new_node;
    }

    return true;
}

int list_find(lnode_t *headp, char *key) {
    while (headp) {
        int cmp = strcmp(headp->key, key);
        if (cmp == 0) return headp->val;
        else if (cmp > 0) break;
        headp = headp->next;
    }
    return -1;
}

int list_get_all_tuples(lnode_t *headp, kv_t *tuples, int max) {
    int count = 0;
    while (headp && count < max) {
        tuples[count].key = headp->key;
        tuples[count].val = headp->val;
        count++;
        headp = headp->next;
    }
    return count;
}



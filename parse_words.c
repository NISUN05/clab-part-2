#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "htable.h"
#include "list.h"
#include "parse_words.h"

/////////  Bonus exercise //////////
// This function parses a NULL-terminated byte array "buf"
// to extract words and stores them in the given htable "ht".
// Words are separated from each other by newline characters '\n'.
// Returns the number of words parsed/stored.
//
// Hint: Consider using the C library function strtok_r.
// (see https://man7.org/linux/man-pages/man3/strtok.3.html)
// Note: strtok_r modifies the input buffer by replacing delimiters
// with null characters. The returned token pointers point directly
// into the original buffer, so the buffer must remain valid while
// the hash table is in use.
unsigned int parse_n_store_words(char *buf, htable_t *ht)
{
  assert(buf != NULL);
    assert(ht != NULL);

    unsigned int count = 0;

    char *saveptr;
    char *token = strtok_r(buf, "\n", &saveptr);

    while (token != NULL) {
        htable_put(ht, token, 1, sum_accum);

        count++;
        token = strtok_r(NULL, "\n", &saveptr);
    }

    return count;
}



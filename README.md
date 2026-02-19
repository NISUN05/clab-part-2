# C Lab Part 2

This lab builds on Part 1 to introduce more advanced C programming concepts including strings, linked lists, and hash tables.

## Overview

The lab consists of four source files, each focusing on different concepts:

| File | Concepts Covered |
|------|------------------|
| `str.c` | String manipulation, character arrays, hex conversion |
| `list.c` | Linked lists, sorted insertion, pointer manipulation |
| `htable.c` | Hash tables, hash functions, data structures |
| `parse_words.c` | String tokenization, combining data structures (bonus) |

## Building and Testing

```bash
make          # Compile all files
./clab2_test   # Run all tests
./clab2_test -t 1  # Run only str tests
./clab2_test -t 2  # Run only list tests
./clab2_test -t 3  # Run only htable tests
./clab2_test -t 4  # Run only parse_words tests (bonus)
```

## Files to Modify

You need to implement the TODO sections in:

- **str.c**: `string_len`, `string_cmp`, `int_to_hex`
- **list.c**: `list_init`, `list_insert_with_accum`, `list_find`, `list_get_all_tuples`
- **htable.c**: `htable_create`, `hashcode`, `htable_put`, `htable_get`, `htable_get_all_tuples`
- **parse_words.c**: `parse_n_store_words` (bonus)

## Key Implementation Notes

### list.c
- The linked list must be maintained in **sorted order by key** (alphabetically, ascending)
- When inserting, if a key already exists, use the accumulator function to update the value
- `list_get_all_tuples` returns tuples in sorted order since the list is sorted

### str.c
- `string_cmp` should compare characters as unsigned values (like `strcmp`)
- `int_to_hex` must output exactly 8 lowercase hex characters, zero-padded

### htable.c
- Hash function: `hashcode = s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]`
- Use modulo with array capacity to map hashcode to bucket index

### parse_words.c (bonus)
- `strtok_r` modifies the input buffer by inserting null characters
- Token pointers point into the original buffer, so keep the buffer valid

## Prerequisites

Before starting, you should be familiar with:

- C strings (null-terminated character arrays)
- Dynamic memory allocation (`malloc`, `free`)
- Pointers and double pointers
- Linked list concepts
- Hash table concepts


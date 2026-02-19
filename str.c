#include <stdio.h>
#include <assert.h>

#include "string.h"


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  assert(s != NULL);
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;

}

unsigned int hashcode(char *s) {
    unsigned int hash = 0;
    while (*s) {
        hash = hash * 31 + (unsigned char)(*s);
        s++;
    }
    return hash;
}


// Compare strings "s1" and "s2". It returns less than, equal to or greater than zero
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number.
// Note that we use the ASCII values of characters as basis for comparison.
// As the ASCII value of 'a' is greater than the ASCII value of '0',
// "aa" is considered to be greater than "a0".
//
// Important: Characters should be compared as unsigned values (like strcmp does).
// This matters for characters with values > 127.
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
  assert(s1 != NULL && s2 != NULL);

    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2)
            return *p1 - *p2;   // compare unsigned values
        p1++;
        p2++;
        }

    // If one string ended, return difference of terminating characters
    return *p1 - *p2;

}

// Convert integer x into hex format and store the resulting hex string to "str".
// For example, if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a".
//
// Requirements:
// - The output must be exactly 8 lowercase hex characters, zero-padded on the left
// - Followed by a null terminator (so 9 bytes total)
// - Use lowercase letters 'a'-'f' for hex digits 10-15
//
// We assume the caller has allocated an array of at least 9 characters for "str".
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str)
{
  assert(str != NULL);

    // process 8 hex digits, from most significant to least
    for (int i = 7; i >= 0; i--) {
        unsigned int digit = x & 0xF;   // last 4 bits
        if (digit < 10)
            str[i] = '0' + digit;
        else
            str[i] = 'a' + (digit - 10);
        x >>= 4;  // shift to next 4 bits
    }

    str[8] = '\0'; 
}


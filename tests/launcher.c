/*
 * Simple MD5 implementation
 *
 * Compile with: gcc -o md5 md5.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "md5.h"

int main(int argc, char **argv) {
    char *msg;
    size_t len;
    int i;
    uint8_t result[16];
 
    if (argc < 2) {
        printf("usage: %s 'string'\n", argv[0]);
        return 1;
    }
    msg = argv[1];
 
    len = strlen(msg);
 
    // benchmark
    for (i = 0; i < 1000000; i++) {
        md5((uint8_t*)msg, len, result);
    }
 
    // display result
    for (i = 0; i < 16; i++)
        printf("%2.2x", result[i]);
    puts("");
 
    return 0;
}


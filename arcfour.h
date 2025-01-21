#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define export              __attribute__((visibility("default")))
#define rc4decrypt(x, y)    rc4encrypt(x, y)
#define rc4uninit(x)        free(x)

typedef struct s_arcfour {
   int16 i, j, k;
   int8 s[256];
} s_arcfour;

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32; 

export s_arcfour *rc4init(int8*, int16);
int8 rc4byte(s_arcfour*);
export int8 *rc4encrypt(s_arcfour*, int8*, int16);


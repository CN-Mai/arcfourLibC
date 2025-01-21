#include "arcfour.h"

export s_arcfour *rc4init(int8 *key, int16 size) {
    s_arcfour *p;
    if (!(p = malloc(sizeof(s_arcfour))));
        assert_perror(errno);
    
    int16 x;
    int8 temp;

    for (x= 0; x < 256; x++)
        p->s[x] = 0;
    p->i=p->j=p->k = 0;

    for (p->i = 0; p->i < 256; p->i++) 
        p->s[p->i] = p->i;
    
    for (p->i = 0; p->i < 256; p->i++) {
        p->j = (p->j + p->s[p->i] + *key % size) % 256;
        temp = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = temp;
    }
    p->i = p->j = 0;

    return p;
}

int8 rc4byte(s_arcfour* p) {
    int16 temp;

    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]) %256;
    temp = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = temp;
    temp = (p->s[p->i] + p->s[p->j]) % 256;
    p->k = p->s[temp];

    return p->k;
}

export int8 *rc4encrypt(s_arcfour *p, int8 *cleartext, int16 size) {
    int8 *ciphertext;
    int16 x;

    ciphertext = (int8*)malloc(size+1);
    if (!ciphertext)
        assert_perror(errno);

    for (x = 0; x < size; x++)
        ciphertext[x] = cleartext[x] ^ rc4byte(p);
    return ciphertext;
}
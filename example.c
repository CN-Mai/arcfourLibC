/* example.c */
#include "arcfour.h"

#define F fflush(stdout);

void printbin(int8 *input, const int16 size) {
    int16 i;
    int8 *p;

    assert(size > 0);

    for (i = size, p = input; i; i--, p++) {
        if (!(i % 2)) 
            printf(" ");
        printf("%.02x", *p);
    }
    printf("\n");

    return;
}

int main(void);

int main() {
    s_arcfour *rc4;
    int16 skey, stext;
    char *key, *from, *encrypted, *decrypted;

    key=from=encrypted=decrypted = 0;
    skey = stext = 0;
    
    key = "tomatoes"; /* 8 BITS -> 2048 BITS*/
    skey = strlen(key);
    from = "Shall I compare thee to a summer's day?";
    stext = strlen(from);

    printf("Intializing encryption..."); F;
    rc4 = rc4init(key, skey);
    printf("done\n");

    printf("%s\n ->", from);
    encrypted = rc4encrypt(rc4, from, stext);
    printbin((int8*)key, skey);
    
    return 0;
}
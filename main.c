#include <stdio.h>

#define stringify(s) #s
#define seed 5381
#define hash0(s) (sizeof(stringify(s)) > 3 ? hash1(s) * 33 + stringify(s)[3] : 0)
#define hash1(s) (sizeof(stringify(s)) > 2 ? hash2(s) * 33 + stringify(s)[2] : 0)
#define hash2(s) (sizeof(stringify(s)) > 1 ? hash3(s) * 33 + stringify(s)[1] : 0)
#define hash3(s) (seed * 33 + stringify(s)[0])

int function_to_validate_hash_is_constant() {
    static int a = hash0(abcdefg); 
    return a;
}

int djb2_hash(unsigned char *str){
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

int main() {
    printf("hash via macro %d\n", function_to_validate_hash_is_constant());
    printf("hash via func  %d\n", djb2_hash("abcd"));
    return 0;
}
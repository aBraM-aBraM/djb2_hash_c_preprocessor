#include <stdio.h>
#include <assert.h>

#include "errors.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
int function_to_validate_hash_is_constant() {
    static int a = hash0(abcdefg); 
    return a;
}
#pragma GCC diagnostic pop


int djb2_hash(unsigned char *str){
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

int main() {
    assert(function_to_validate_hash_is_constant() == djb2_hash("abcd"));

    create_errors();
    for (MyError* err = g_errors; err < g_errors + g_error_count; ++err) {
        printf(ERROR_FMT, err->id, err->msg);
    }
    return 0;
}
#include <stddef.h>

#define stringify(s) #s
#define seed 5381
#define hash0(s) (sizeof(stringify(s)) > 3 ? hash1(s) * 33 + stringify(s)[3] : hash1(s))
#define hash1(s) (sizeof(stringify(s)) > 2 ? hash2(s) * 33 + stringify(s)[2] : hash2(s))
#define hash2(s) (sizeof(stringify(s)) > 1 ? hash3(s) * 33 + stringify(s)[1] : hash3(s))
#define hash3(s) (seed * 33 + stringify(s)[0])


typedef struct MyError {
#ifdef DEBUG
    char id[64];
#else
    int id;
#endif
    char msg[64];
} MyError;

extern MyError* g_errors;
extern size_t   g_error_count;
void create_errors();

#ifdef DEBUG
#define MYERROR(name, msg) {stringify(name), msg}
#define ERROR_FMT "Error: %s\t%s\n"
#else
#define MYERROR(name, msg) {hash0(name), msg}
#define ERROR_FMT "Error: %d\t%s\n"
#endif
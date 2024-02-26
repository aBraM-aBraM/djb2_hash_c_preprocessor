#include "errors.h"


MyError* g_errors;
size_t   g_error_count;

// I don't care about overflow errors because thats a hash
// a value only used for identification
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
void create_errors() {
    static MyError errors[] = {
        MYERROR(GENERAL_ERROR, "Unknown error!"),
        MYERROR(OS_ERROR, "operating system error!"),
    };
    g_errors = errors;
    g_error_count = sizeof(errors) / sizeof(MyError);
}
#pragma GCC diagnostic pop


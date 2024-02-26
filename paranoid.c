#include <assert.h>
#include "errors.h"

int main() {
    size_t count = 0;
    for (MyError* i = g_errors; i < g_errors + g_error_count; ++i) {
        for (MyError* j = g_errors; j < g_errors + g_error_count; ++j) {
            count += i->id == j->id;
        }
        assert(count == 1);
        count = 0;
    }
    return 0;
}
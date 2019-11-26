#include "my_vars.h"

int local_var = 3;
int global_var = 42;


void increment_local_var(int amount) {
    local_var += amount;
}

void increment_global_var(int amount) {
    global_var += amount;
}

int get_local_var() {
    return local_var;
}


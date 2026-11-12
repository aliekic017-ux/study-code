#include "util.h"

#include <stdio.h>

int seconds_to_minutes(int seconds)
{
    return seconds / 60;
}

void print_build_variant(void)
{
#ifdef DEBUG_BUILD
    printf("Build variant: debug\n");
#else
    printf("Build variant: default\n");
#endif
}

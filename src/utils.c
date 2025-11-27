#include <stdio.h>
#include "utils.h"

void clearScreen() {
    printf("\033[2J\033[1;1H");
    printf("Screen Cleared.\n");
}

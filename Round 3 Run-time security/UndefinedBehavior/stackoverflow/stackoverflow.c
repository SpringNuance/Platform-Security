#include <stdio.h>

int main() {
    // Initialize an array of only 5 elements
    int stackoverflow[10];
    int i;
    for (i = 0; i <= 10; i++) {
        stackoverflow[i] = i;
    }
    // Accessing the eleventh element, causing stack array overflow
    printf("%d", stackoverflow[10]);
    return 0;
}
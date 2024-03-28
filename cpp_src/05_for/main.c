#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");


    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 - i; ++j) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i + j > 3) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

/*
OOOOX   i:0   j:4
OOOXX   i:1   j:[3,4]
OOXXX   i:2   j:[2,4]
OXXXX   i:3   j:[1,4]
XXXXX   i:4   j:[0,4]
*/
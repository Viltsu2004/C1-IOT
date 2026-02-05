#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15



void print_numbers(const int *array, int count);
int random_number();

int main (void) {
    srand(time(NULL));

    int numbers[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = random_number();
    }

    print_numbers(numbers, ARRAY_SIZE);

    return 0;
}

void print_numbers(const int *array, int count) {
    for (int a = 0; a < count; a++) {
        printf("%8d\n", array[a]);
    }
}

int random_number() {
    return (1 + rand()/((RAND_MAX + 1u)/ARRAY_SIZE));
}
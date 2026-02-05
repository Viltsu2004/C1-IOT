#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYS 20

int find_first(const unsigned int *array, unsigned int what);
int random_number();
int input_ask();

int main() {
    srand(time(NULL));

    int input;
    int numbers[ARRAYS];

    numbers[ARRAYS - 1] = 0;

    for (int i = 0; i < ARRAYS - 1; i++) {
        numbers[i] = random_number();
        printf("%d\n", numbers[i]);
    }

    do {
        printf("Give a number between 1-%d: ", ARRAYS - 1);
        if (scanf("%d", &input) == 1) {
            if (input >= 0 && input < ARRAYS) {
                if (input != 0) {
                    int value = find_first(numbers, input);
                    if (value == -1) {
                        printf("Number not found!\n");
                    } else {
                        printf("%d\n", value);
                    }
                }
            } else {
                printf("Doesn't mach whit range.\n");
            }
        } else {
            while (getchar() != '\n');
            printf("Incorrect input!\n");
        }
    } while (input != 0);

    return 0;
}

/*Go thourgh all values in array*/
int find_first(const unsigned int *array, unsigned int what) {
    int count = 0;

    while (array[count] != 0) {
        if (array[count] == what) {
            return count;
        }
        count++;
    }
    return -1;
}
/*Random funktion*/
int random_number() {
    return (1 + rand()/((RAND_MAX + 1u)/(ARRAYS - 1)));
}
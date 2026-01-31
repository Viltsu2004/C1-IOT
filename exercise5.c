#include <stdio.h>

int read_range(int low, int high);

int main() {
    int low = 1;
    int high = 6;
    int count = 0;

    printf("Let's play!\n");
    while (count != 3) {
        count++;
        int value = read_range(low, high);
        if (value != high) {
            printf("I got %d. I win!\n", value + 1);
        } else {
            printf("I got %d. It is a tie!\n", value);
        }
    }
    printf("Better luck next time. Bye!\n");

    return 0;
}

int read_range(int low, int high) {

    int value = 0;

    printf("Roll a die and enter your result.\n");
    do {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &value) != 1 || value < low || value > high) {
            while (getchar() != '\n');
            printf("Invalid input\n");
            value = 0;
        }
    }
    while (value == 0);

    return value;
}
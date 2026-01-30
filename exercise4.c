#include <stdio.h>

int read_integer(void);

int main() {
    int sum = 0;
    int value = 0;
    int count = 0;
    float average = 0;

    do {
        value = read_integer();
        if (value >= 0) {
            sum += value;
            count++;
            }

    } while (value >= 0);

    average = (float)sum / count;
    printf("You entered %d positive numbers. The average is: %.3f", count, average);
    return 0;
}

int read_integer(void) {
    int value = 0;

    do {
        printf("\nEnter positive numbers or negative to stop: ");
        if (scanf("%d", &value) != 1) {
            while(getchar() != '\n');
            printf("Invalid input\n");
            value = 0;
        }
    } while (value == 0);

    return value;
}
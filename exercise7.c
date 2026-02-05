#include <stdio.h>
#include <stdbool.h>

#define MULTIPLYER 2
#define PLUS 20

bool read_positive(int *value);


int main() {
    int count = 0;
    int money = 0;

    while (count < 3) {
        int input = read_positive(&money);
        if (input == false) {
            count++;
        } else if (input == true) {
            printf("You didn't get it right. I have %d euros!\n", money * MULTIPLYER + PLUS);
        }
    }
    printf("I give up! See you later!");
}




bool read_positive(int *value) {

    int selection;

    printf("Guess how much money I have?\n");

    printf("Enter a positive number: ");
    if (scanf("%d", &selection) != 1 || selection < 0) {
        while (getchar() != '\n');
        printf("Incorrect input!\n");
        return false;
    } else {
        *value = selection;
        return true;
    }
}
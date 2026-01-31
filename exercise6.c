#include <stdio.h>
#include <stdlib.h>


int menu(void);
int selection(int value);


int main () {
    int value = 0;

    do {
        value = menu();
        int random = selection(value);
        if (value != 3) {
            printf("Number is %d!\n", random);
        }
    } while (value != 3);

    printf("Thanks for playing.\n");

    return 0;
}


int menu(void) {
    int selection = 0;

    printf("\nSelect an operation:\n");
    printf("1) Roll D6\n");
    printf("2) Roll D10\n");
    printf("3) Quit\n");

    do {
        printf("\nYour selection (1, 2 or 3): ");
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Try again!\n");
            selection = 0;
        }
        else if (selection < 1 || selection > 3) {
            printf("Your selection wasn't on the list. Select 1, 2 or 3!\n");
            selection = 0;
        }
    } while (selection == 0);

    return selection;
}

int selection(int value) {
    if (value == 1) {
        return (1 + rand()/((RAND_MAX + 1u)/6));
    }
    else if (value == 2) {
        return (1 + rand()/((RAND_MAX + 1u)/10));
    }
    else if (value == 3) {
        return 0;
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define RANDOM_NUMBER_AREA 2000
#define CLEAR 0x3F

int random_number();
int bitwise_operation(int rand_number, int number);

int main () {
    srand(time(NULL));
    char input[MAX_NUMBER];
    int number = 0;

    //while user don't enter negative value
    while (number >= 0) {
        printf("Give number between 0-15 or negative number to stop: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {

            //if user enter too long input then we clear buffer
            if (strchr(input, '\n') == NULL) {
                int i;
                while ((i = getchar()) != '\n' && i != EOF) {}
            }
            //if input is not numbers then we send error
            if (sscanf(input, "%d", &number) != 1) {
                printf("Invalid input\n");
            }
            else {
                //if number is between 0 and 15 we are happy (user can eneter 2bkdsbcjhdv and
                //it's readed like 2
                if (0 <= number && number <= 15) {

                    const int rand_number = random_number();
                    printf("Random hexadecimal is %X\n\n", rand_number);
                    const int bitwise = bitwise_operation(rand_number, number);
                    printf("Bitwise hexadecimal is: %.2X\n\n", bitwise);
                }
                //if number is over then ask again
                if (number > 15) {
                    printf("Number is too large, max number is 15\n");
                }
                // if number under we end
                if (number < 0) {
                    printf("You entered negative value, Good bye!\n");
                }
            }

        }
    }
    return 0;
}

//generate random value
int random_number() {
    const int number = rand() % RANDOM_NUMBER_AREA;
    return number;
}

// random value -> we shift bits to right as much as user has asked
int bitwise_operation(int rand_number, int number) {
    int value = rand_number >> number;
    value = value & CLEAR;
    return value;
}
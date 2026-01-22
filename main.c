#include <stdio.h>

void print_hello();
int read_number();

int main(void) {
    int number = 0;
    number = read_number();
    printf("Tämä tässä on yön numero - %d\n", number);

    return 0;
}

void print_hello() {
    printf("Hello, World!\n");
}

int read_number() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    return number;
}
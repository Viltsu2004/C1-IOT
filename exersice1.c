#include <stdio.h>

int main() {
    int selection;
    float bus_price;
    float taxi_price;
    float money;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi: ");
    scanf("%f", &taxi_price);

    printf("How much money you have: ");
    scanf("%f", &money);

    while (money >= bus_price || money >= taxi_price) {
        printf("You have %.2f euros left.\n", money);

        printf("Do you want to take\n");
        printf(" 1) bus (%.2f euros)\n", bus_price);
        printf(" 2) taxi (%.2f euros)\n", taxi_price);

        printf("Enter your selection: ");
        scanf("%d", &selection);

        switch(selection) {
            case 1:
                if (money >= bus_price) {
                    printf("You chose bus.\n");
                    money -= bus_price;
                    break;
                }
                printf("You don't have enough money for bus.\n");
                break;
            case 2:
                if (money >= taxi_price) {
                    printf("You chose taxi.\n");
                    money -= taxi_price;
                    break;
                }
                printf("You don't have enough money for taxi.\n");
                break;
        }
    }

    printf("You have %.2f euros left.\n", money);
    printf("You need to walk. Bye\n");
    }
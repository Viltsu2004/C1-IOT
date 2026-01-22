#include <stdio.h>
#define MONTHS 12

int main() {
    float income_month[MONTHS];
    float taxed_income[MONTHS];
    float income;
    float income_limit;
    float tax_rate;
    float over_limit_tax_rate;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);
    printf("Enter income limit: ");
    scanf("%f", &income_limit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &over_limit_tax_rate);

    for (int i = 0; i < MONTHS; i ++) {
        printf("Enter income for month %d:", i + 1);
        scanf("%f", &income);
        income_month[i] = income;

        if (income <= income_limit) {
            taxed_income[i] = income * (tax_rate/100);
        }
        else {
            taxed_income[i] = (income - income_limit) * (over_limit_tax_rate/100) + income_limit * (tax_rate/100);
        }
    }

    printf("month        income        tax");
    for (int a = 0; a < MONTHS; a ++) {
        printf("\n%5d %13.2f %10.2f", a + 1, income_month[a], taxed_income[a]);

    }

}




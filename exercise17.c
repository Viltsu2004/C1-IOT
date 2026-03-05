#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PASSWORD 32
#define MAX_GENERATED_PASSWORD 65


bool generator(char *new_password, int size, const char *word);


int main() {
    srand(time(NULL));
    bool boolean;
    char password[MAX_GENERATED_PASSWORD];
    char *word = password;


    while (strcmp(password, "stop") != 0) {
        printf("Enter your password: ");
        if (fgets(password, MAX_GENERATED_PASSWORD, stdin) != NULL) {
            if (strchr(password, '\n') == NULL) {
                int i;
                while ((i = getchar()) != '\n' && i != EOF) {}
            }

            if (password[strlen(password) - 1] == '\n') {
                password[strlen(password) - 1] = '\0';
            }
            if (strcmp(password, "stop") != 0) {
                boolean = generator(password, MAX_GENERATED_PASSWORD, word);
                if (boolean == false) {

                    printf("Input is invalid, password has to be maximum of "
                            "%d character long.\n", MAX_PASSWORD-1);
                }
                if (boolean == true) {
                    printf("Generated password is: %s\n", password);
                }
            }
        }
        }
    return 0;
    }




bool generator(char *new_password, int size, const char *word) {
    char new_password_array[size];
    int j = 0;

    if (strlen(word) > size/2-1 || word == NULL) {
        printf("not");
        return false;
    }
    new_password_array[j] = (char)(rand() % 94 +33);

    for (int i=0; i<strlen(word)*2+1; i++) {
        new_password_array[j++] = (char)(rand() % 94 +33);
        new_password_array[j++] = word[i];
    }
    new_password_array[j] = '\0';
    strcpy(new_password, new_password_array);


    return true;

}

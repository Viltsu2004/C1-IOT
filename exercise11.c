#include <stdio.h>

#define MAXWORD 100
#define CHARACTERS 65

int replace_char(char *str, const char *repl);


int main() {
    char str[MAXWORD];
    char repl[CHARACTERS];

    printf("Give first string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        printf("Give second string that includes only two characters: ");
        fgets(repl, sizeof(repl), stdin);
        int count = replace_char(str, repl);
        if (count == 0) {
            printf("String was not modified.\n");
        } else {
            printf("Number of changes: %d\nChanged string: %s\n", count, str);
        }
    }
    return 0;
}


int replace_char(char *str, const char *repl) {

    int replaces = 0;
    int a;

    for (a = 0; repl[a] != '\0'; a++);

    if (a == 3) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == repl[0]) {
                str[i] = repl[1];
                replaces++;
            }
        }
        if (replaces <= 0) {
            return 0;
        }
        else {
            return replaces;
        }
    } else {

        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

int main() {

    char buffer[MAXWORD];
    int end = 1;

    while (end) {
        printf("Give a string or give 'stop' to stop program: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
                if (strcmp(buffer, "stop") == 0) {
                    end = 0;
                }
                else {
                    printf("Length = %lu\n", strlen(buffer));
                }
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAXWORD 100
#define MAXSEARCH 20

int count_words(const char* str, const char *word);

int main() {
    char str[MAXWORD];
    char word[MAXSEARCH];
    int end = 1;

    while (end) {
        printf("Give string: ");
        if (fgets(str, sizeof(str), stdin) != NULL) {
            if (str[strlen(str) - 1] == '\n') {              //change end point to '/0'
                str[strlen(str) - 1] = '\0';
                }
            if (strlen(str) == 0) {                            //if user just press enter porgram don't crash
                printf("The string is empty, try again\n");
            } else {
                printf("Give string that program tryes to find from previous string or 'stop' to exit: ");
                if (fgets(word, sizeof(word), stdin) != NULL) {
                    if (word[strlen(word) - 1] == '\n') {      //change end point to '/0'
                        word[strlen(word) - 1] = '\0';
                    }
                    if (strcmp(word, "stop") == 0) {           // if second input is stop program ends
                        end = 0;
                    }
                    if (strlen(word) == 0) {
                        printf("The string is empty, try again\n");
                    }
                    else {
                        int count = count_words(str, word);
                        printf("The string 2 \"%s\" occours %d in string 1.\n", word, count);
                    }
                }
            }
        }
    }
    return 0;
}


int count_words(const char* str, const char *word) {

    int count = 0;
    char *p = str;

    while ((p = strstr(p, word)) != NULL) {
        count++;
        p += strlen(word);
    }

    return count;
}

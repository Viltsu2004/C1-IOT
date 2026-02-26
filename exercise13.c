#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINESIZE 100
#define FILENAME_MAX_LENGTH 50

FILE *open_file(const char *name, const char *mode);
int filename_input(char *name, int max_length);

int main() {
    FILE *my_file;
    char line[LINESIZE];
    int value = 0;
    int count = 0;
    int min_value;
    int max_value;

    char file_name[FILENAME_MAX_LENGTH];
    char mode1[] = "r";
    char mode2[] = "w";
    char mode3[] = "a";

    filename_input(file_name, FILENAME_MAX_LENGTH);

    my_file = open_file(file_name, mode1);
    if (my_file == NULL) {
        return 1;
    }

    while (!feof( my_file )) {
        if (fgets(line, LINESIZE, my_file) != NULL) {
            if (sscanf(line, "%d", &value) == 1) {
                count++;

                if (count == 1) {
                    min_value = value;
                    max_value = value;
                } else {
                    if (value < min_value) {
                        min_value = value;
                    }
                    else if (value > max_value) {
                        max_value = value;
                    }
                }
            }
            else {
                printf("Invalid line.\n");
                return 0;
            }
            }
        }
    fclose(my_file);
    printf("Numbers in file: %d, min number of file: %d, max number of file: %d\n", count, min_value, max_value);


    return 0;
    }


int filename_input(char *name, const int max_length) {
    printf("Enter file name that you want to be opened: ");
    if (fgets(name, max_length, stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }

    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    return 0;
}

FILE *open_file(const char *name, const char *mode) {
    FILE *file = fopen(name, mode);

    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s'", name);
    }

    return file;
}
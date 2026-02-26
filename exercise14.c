#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_LINES 100
#define MAX_LINESIZE 81
#define FILENAME_MAX_LENGTH 100

FILE *open_file(const char *name, const char *mode);
int filename_input(char *name, int max_length);

int main() {
    char line[MAX_NUMBER_LINES][MAX_LINESIZE];
    char file_name[FILENAME_MAX_LENGTH];
    char mode1[] = "r";
    char mode2[] = "w";
    char mode3[] = "a";


    FILE *my_file;
    int count_lines = 0;

    filename_input(file_name, FILENAME_MAX_LENGTH);

    my_file = open_file(file_name, mode1);
    if (my_file == NULL) {
        return 1;
    }

    while (count_lines < MAX_NUMBER_LINES && fgets(line[count_lines], MAX_LINESIZE, my_file) != NULL) {
        count_lines++;
    }
    fclose(my_file);

    for (int i = 0; i < count_lines; i++) {
        for (int j = 0; line[i][j] != '\0'; j++) {
            line[i][j] = toupper(line[i][j]);
        }
    }

    my_file = open_file(file_name, mode3);
    if (my_file == NULL) {
        return 1;
    }
    for (int i = 0; i < count_lines; i++) {
        fprintf(my_file, "%s", line[i]);
    }
}


int filename_input(char *name, const int max_length) {
    printf("Enter file name that you want to be opened: ");
    if (fgets(name, max_length, stdin) == NULL) {
        printf("Error, in input reading!\n");
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
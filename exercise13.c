#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 100

int main() {
    FILE *my_file;
    char line[LINESIZE];
    char file_name[100];
    int value = 0;
    int count = 0;
    int min_value;
    int max_value;

    printf("Eneter file name that you want to be opened: ");
    fscanf(stdin, "%s", file_name);

    my_file = fopen(file_name, "r");
    if (my_file == NULL) {
        fprintf(stderr, "Unable to open file '%s'", file_name);
    }
    else {
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
        }

    return 0;
    }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_LINES 100
#define MAX_LINESIZE 81
#define FILENAME_MAX_LENGTH 100

//Käytetään kahta funktiota, toinen avaa filen ja toinen tarkistaa user inputin
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

    //pyydetään filen nimi
    filename_input(file_name, FILENAME_MAX_LENGTH);

    //avataan file
    my_file = open_file(file_name, mode1);
    if (my_file == NULL) {
        return 1;
    }

    //tallennetaan arrayhin 100 riviä merkkejä, maksimi pituus riville 80 merkkiä plus loppu \0
    while (count_lines < MAX_NUMBER_LINES && fgets(line[count_lines], MAX_LINESIZE, my_file) != NULL) {
        count_lines++;
    }
    //suljetaan tiedosto
    fclose(my_file);

    //muutetaan merkit isoiksi
    for (int i = 0; i < count_lines; i++) {
        for (int j = 0; line[i][j] != '\0'; j++) {
            line[i][j] = toupper(line[i][j]);
        }
    }

    //avataan kirjoitus muodossa tiedoston loppuun
    my_file = open_file(file_name, mode3);
    if (my_file == NULL) {
        return 1;
    }

    //kirjoitetaan teksti rivi kerrallaan tiedostoon
    for (int i = 0; i < count_lines; i++) {
        fprintf(my_file, "%s", line[i]);
    }
    fclose(my_file);

    return 0;
}

//tarkistetaan teidooston nimi ja vaihdetana rivin vaihto loppunollaan
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

//avataan tiedosto, jos ei onnistu varoitus
FILE *open_file(const char *name, const char *mode) {
    FILE *file = fopen(name, mode);

    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s'", name);
    }

    return file;
}
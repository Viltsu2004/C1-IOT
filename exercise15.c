#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINESIZE 100
#define FILENAME_MAX_LENGTH 100
#define MAX_ITEMS 40


//Käytetään kahta funktiota, toinen avaa filen ja toinen tarkistaa user inputin
FILE *open_file(const char *name, const char *mode);
int filename_input(char *name, int max_length);

//struct
typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;


int main() {
    char file_name[FILENAME_MAX_LENGTH];
    char mode1[] = "r";
    FILE *my_file;

    //luodaan array jossa structin price ja name, max 40 riviä
    menu_item max[MAX_ITEMS];
    int count = 0;
    //rivillä max 100 merkkiä
    char lines[MAX_LINESIZE];

    //otetaan vastaan teidoston nimi
    filename_input(file_name, FILENAME_MAX_LENGTH);

    //avataan tiedosto
    my_file = open_file(file_name, mode1);
    if (my_file == NULL) {
        return 1;
    }

    //tuskaa oli tämä!! olisiko ollut paremapaa tapaa??
    //Tallennetaan bufferiin teskti tiedostosta
    while (count < MAX_ITEMS && fgets(lines, MAX_LINESIZE, my_file) != NULL) {
        //luetaan bufferista merkkejä ";" asti mutta max 49 merkkiä, tallennetaan hinta ja
        //nimi structiin omaksi tietueeksi
            if (sscanf(lines, " %49[^;]; %lf", max[count].name, &max[count].price) == 2) {
                count++;
            }
        }
    fclose(my_file);

    //kirjoitetaan tallennetut rivit terminaaliin
    for (int i = 0; i < count; i++) {
        printf("%8.2lf    %s\n", max[i].price, max[i].name);
    }

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



FILE *open_file(const char *name, const char *mode){
    FILE *file = fopen(name, mode);

    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s'", name);
    }

    return file;
}
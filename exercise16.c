#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 30


typedef struct node {
    int number;
    struct node *next;
} nnode;

int main() {
    nnode *head;
    nnode *tail;
    char input[LINE];
    int value;
    int count = 0;

    head = (nnode *) malloc(sizeof(nnode));
    head->next = NULL;
    head->number = '\0';
    tail = head;

    while (strcmp(input, "end") != 0 ) {
        printf("Enter number or 'end' to stop entering a number: ");
        if (fgets(input, sizeof(input), stdin) != NULL && input[strlen(input)] < LINE) {

            if (strchr(input, '\n') == NULL) {
                int i;
                while ((i = getchar()) != '\n' && i != EOF) {}
            }


            if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }
            if (sscanf(input, "%d", &value) != 1 && strcmp(input, "end") != 0){
                printf("Invalid input\n");
            }
            else if (sscanf(input, "%d", &value) == 1){
                tail->number = value;
                nnode *newinput;
                newinput = (nnode *) malloc(sizeof(nnode));
                newinput->next = NULL;
                newinput->number = '\0';
                tail->next = newinput;
                tail = newinput;
                count++;
            }
        }
    }

    nnode *curr = head;
    nnode *nex;

    while (curr != NULL){
        if (curr->next != NULL) {
            printf("%d\n", curr->number);
        }
        nex = curr->next;
        free(curr);
        curr = nex;
      }
    return 0;
}
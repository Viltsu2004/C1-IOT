#include <stdio.h>
#define GRADE_MAX 5
#define GRADE_MIN 0


int main() {
    int number_of_students;
    int student_nr;
    int grade;

    printf("How many students: ");
    scanf("%d", &number_of_students);

    int students_grade[number_of_students];
    int students_num[number_of_students];

    for (int i = 0; i < number_of_students; i++) {
        students_grade[i] = -1;
        students_num[i] = i + 1;
    }

    printf("Enter student number (1 - %d) or 0 to stop: ", number_of_students);
    scanf("%d", &student_nr);

     while (student_nr != 0) {

        if (student_nr < 1 || student_nr > number_of_students) {
            printf("Invalid student number!\n");
        }
        else {
            printf("Enter grade (0-5) for student %d or -1 to cancel: ", student_nr);
            scanf("%d", &grade);

            while ((grade < GRADE_MIN || grade > GRADE_MAX) && grade != -1) {
                printf("Invalid grade!\n");
                printf("Enter grade (0-5) for student %d or -1 to cancel: ", student_nr);
                scanf("%d", &grade);
            }
            students_grade[student_nr - 1] = grade;
        }
     printf("Enter student number (1 - %d) or 0 to stop: ", number_of_students);
     scanf("%d", &student_nr);
     }

    printf("%-10s %s\n", "Student", "Grade");
    for (int n = 0; n < number_of_students; n++) {
        if (students_grade[n] == -1) {
            printf("%-10d %s\n", students_num[n], "N/A");
        }
        else {
            printf("%-10d %d\n", students_num[n], students_grade[n]);
        }
    }
    }




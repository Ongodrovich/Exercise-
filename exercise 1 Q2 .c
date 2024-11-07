#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    FILE *file = fopen("students.txt", "a");  // Open file in append mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Input data for n students
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);

        // Append to file
        fprintf(file, "Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    printf("Data appended to file successfully.\n");

    return 0;
}

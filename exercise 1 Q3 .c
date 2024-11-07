#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    FILE *file;

    // Input data for n students
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    // Write to file using fwrite
    file = fopen("students.bin", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fwrite(students, sizeof(struct Student), n, file);
    fclose(file);
    printf("Data written to file successfully.\n");

    // Read from file
    file = fopen("students.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(students, sizeof(struct Student), n, file);
    fclose(file);

    // Display the data
    printf("\nData read from file:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    return 0;
}

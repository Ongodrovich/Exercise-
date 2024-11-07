#include <stdio.h>
#include <stdlib.h>

void writeSentence() {
    FILE *file = fopen("data.txt", "w"); // Open in write mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char sentence[101];
    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin); // Read sentence from user

    fprintf(file, "%s", sentence); // Write sentence to file
    fclose(file);
    printf("Sentence written to file.\n");
}

void readContent() {
    FILE *file = fopen("data.txt", "r"); // Open in read mode
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ch;
    printf("Content of data.txt:\n");
    while ((ch = fgetc(file)) != EOF) { // Read each character from file
        putchar(ch);
    }
    fclose(file);
}

void appendSentence() {
    FILE *file = fopen("data.txt", "a"); // Open in append mode
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    char sentence[101];
    printf("Enter a sentence to append (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);

    fprintf(file, "%s", sentence); // Append sentence to file
    fclose(file);
    printf("Sentence appended to file.\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Write a sentence to file\n");
        printf("2. Read content from file\n");
        printf("3. Append a sentence to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer

        switch (choice) {
            case 1:
                writeSentence();
                break;
            case 2:
                readContent();
                break;
            case 3:
                appendSentence();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

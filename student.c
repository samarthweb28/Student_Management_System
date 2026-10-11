#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Load all records from the file "data"
void loadData() {
    FILE *f = fopen("data", "r");
    if (f == NULL) return;   // no file yet, start empty

    while (count < 100 &&
           fscanf(f, "%d %s %f", &s[count].roll, s[count].name, &s[count].marks) == 3) {
        count++;
    }
    fclose(f);
}

// Save all records to the file "data"
void saveData() {
    int i;
    FILE *f = fopen("data", "w");
    if (f == NULL) {
        printf("Error: could not save data!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(f, "%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    fclose(f);
}

void addStudent() {
    printf("\n=====================================\n");
    printf("Enter roll number: ");
    scanf("%d", &s[count].roll);

    printf("Enter name: ");
    scanf(" %s", s[count].name);

    printf("Enter marks: ");
    scanf("%f", &s[count].marks);

    count++;
    saveData();

    printf("=====================================\n");
    printf("Student added successfully!\n");
    printf("=====================================\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\n=====================================\n");
    printf("            STUDENT RECORDS\n");
    printf("=====================================\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
        printf("-------------------------------------\n");
    }
    printf("=====================================\n");
}

void searchStudent() {
    int roll, i;

    printf("\n=====================================\n");
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("=====================================\n");
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            printf("=====================================\n");
            return;
        }
    }

    printf("Student not found!\n");
    printf("=====================================\n");
}

void editStudent() {
    int roll, i;

    printf("\n=====================================\n");
    printf("Enter roll number to edit: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter new name: ");
            scanf(" %s", s[i].name);

            printf("Enter new marks: ");
            scanf("%f", &s[i].marks);

            saveData();

            printf("=====================================\n");
            printf("Student updated successfully!\n");
            printf("=====================================\n");
            return;
        }
    }

    printf("Student not found!\n");
    printf("=====================================\n");
}

int main() {
    int choice;

    loadData();

    do {
        printf("\n=====================================");
        printf("\n--- Student Management System ---\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Exit\n");
        printf("=====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 100)
                    addStudent();
                else
                    printf("Student limit reached!\n");
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                editStudent();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

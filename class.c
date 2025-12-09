#include <stdio.h>

struct Student {
    int roll;
    char name[50];
};

int main() {
    struct Student s[100], temp;
    int n, rows, cols, i, j, r, c;
    int searchRoll, found = 0;

    printf("\n===== ADVANCED EXAM SEATING ARRANGEMENT SYSTEM =====\n");

    // Input number of students
    printf("\nEnter number of students: ");
    scanf("%d", &n);

    // Input with duplicate Roll number check
    for (i = 0; i < n; i++) {
        printf("\nEnter Roll No for student %d: ", i + 1);
        scanf("%d", &s[i].roll);

        for (j = 0; j < i; j++) {
            if (s[i].roll == s[j].roll) {
                printf("Duplicate Roll Number! Enter again.\n");
                i--;
                break;
            }
        }

        printf("Enter Name: ");
        scanf("%s", s[i].name);
    }

    // Sorting by roll number
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].roll > s[j].roll) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Get seating arrangement details
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\n===== Seating Arrangement =====\n");

    int index = 0;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (index < n) {
                printf("| %3d - %-10s | ", s[index].roll, s[index].name);
                index++;
            } else {
                printf("|    EMPTY     | ");
            }
        }
        printf("\n");
    }

    // Search Feature
    printf("\nEnter Roll No to find seat: ");
    scanf("%d", &searchRoll);

    index = 0;
    found = 0;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (index < n && s[index].roll == searchRoll) {
                printf("\n🎯 Student Found!\n");
                printf("Name: %s\n", s[index].name);
                printf("Seat Position: Row %d, Column %d\n", r + 1, c + 1);
                found = 1;
                break;
            }
            index++;
        }
        if (found) break;
    }

    if (!found) {
        printf("\n⚠ No student found with Roll No: %d\n", searchRoll);
    }

    printf("\n========= END =========\n");
    return 0;
}

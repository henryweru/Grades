#include <stdio.h>
#include <string.h>

// Define structures for entities
struct Student {
    int id;
    char first_name[50];
    char last_name[50];
    char email[50];
    char password[50];
    char created_at[20];
};

struct Unit {
    int id;
    char name[50];
    int lecture_id;
    char created_at[20];
};

struct Lecture {
    int id;
    char name[50];
    char created_at[20];
};

struct Grade {
    int id;
    int student_id;
    int unit_id;
    int score; // Represented as a percentage
    char grade; // A, B, C, D, E, F
    char created_at[20];
};

// Function to calculate the grade based on the score
char calculate_grade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else if (score >= 50) {
        return 'E';
    } else {
        return 'F';
    }
}

int main() {
    // Fake data for one student, multiple units, lectures, and grades
    struct Student students[3] = {
        {1, "Henry", "Waweru", "Henry@waweru.com", "password123", "2022-02-21 12:00:00"},
        {2, "Alice", "Smith", "Alice@smith.com", "pass456", "2022-02-21 12:15:00"},
        {3, "Bob", "Ross", "Bob@ross.com", "pass456", "2022-02-21 12:00"}
    };
    // Fake data for 7 units, each with a different lecturer
    struct Unit units[7] = {
        {1, "Math", 1, "2022-02-21 12:30:00"},
        {2, "English", 2, "2022-02-21 12:45:00"},
        {3, "Science", 3, "2022-02-21 13:00:00"},
        {4, "History", 4, "2022-02-21 13:15:00"},
        {5, "Programming", 5, "2022-02-21 13:30:00"},
        {6, "Art", 6, "2022-02-21 13:45:00"},
        {7, "Physical Education", 7, "2022-02-21 14:00:00"}
    };

    // Fake data for 7 lectures
    struct Lecture lectures[7] = {
        {1, "Math Lecture", "2022-02-21 12:30:00"},
        {2, "English Lecture", "2022-02-21 12:45:00"},
        {3, "Science Lecture", "2022-02-21 13:00:00"},
        {4, "History Lecture", "2022-02-21 13:15:00"},
        {5, "Programming Lecture", "2022-02-21 13:30:00"},
        {6, "Art Lecture", "2022-02-21 13:45:00"},
        {7, "Physical Education Lecture", "2022-02-21 14:00:00"}
    };

    struct Grade grades[7] = {
        {1, 1, 1, 95, 'A', "2022-02-21 14:00:00"},
        {2, 1, 2, 85, 'B', "2022-02-21 14:15:00"},
        {3, 1, 3, 75, 'C', "2022-02-21 14:30:00"},
        {4, 1, 4, 65, 'D', "2022-02-21 14:45:00"},
        {5, 1, 5, 55, 'E', "2022-02-21 15:00:00"},
        {6, 1, 6, 45, 'F', "2022-02-21 15:15:00"},
        {7, 1, 7, 75, 'C', "2022-02-21 15:30:00"}
    };

    char student[50];
    char password[50];

    // Get user input for student and password
    printf("Enter your student email: ");
    scanf("%s", student);

    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate user based on input
    int authenticated = 0;
    int studentIndex = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(student, students[i].email) == 0 &&
            strcmp(password, students[i].password) == 0) {
            authenticated = 1;
            studentIndex = i;
            break;
        }
    }

    // Display information based on authentication result
    if (authenticated) {
        printf("Logged in\n");

        // Display information for the authenticated student
        printf("Student: %s %s\n", students[studentIndex].first_name, students[studentIndex].last_name);
        printf("Email: %s\n", students[studentIndex].email);

        // Display information for each unit and its corresponding grade
        printf("\nResults for %s:\n", students[studentIndex].first_name);
        for (int i = 0; i < 7; ++i) {
            printf("\nUnit: %s\n", units[i].name);
            printf("Lecturer: %s\n", lectures[i].name);
            printf("Score: %d\n", grades[i].score);
            printf("Grade: %c\n", grades[i].grade);
        }
    } else {
        printf("Login failed\n");
    }

    return 0;
}

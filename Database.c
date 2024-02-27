#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Define structures for entities
struct Student {
    int id;
    char first_name[50];
    char last_name[50];
    char email[50];
    char password[50];
    char created_at[20];
    char university[100]; // Add university field
    int year_of_study;    // Add year of study field
    char college[50];     // Add college field
    char school[50];      // Add school field
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
    int score; 
    char created_at[20];
    char grade; 
};

char calculate_grade(int score) {
    if (score >= 91 && score <= 100) {
        return 'A';
    } else if (score >= 81 && score <= 90) {
        return 'B';
    } else if (score >= 65 && score <= 80) {
        return 'C';
    } else if (score >= 51 && score <= 64) {
        return 'D';
    } else if (score >= 30 && score <= 50) {
        return 'E';
    } else {
        return 'F';
    }
}

int main() {
    struct Student students[3] = {
        {1, "Henry", "Waweru", "Henry@waweru.com", "password123", "2022-02-21 12:00:00", "Jomo Kenyatta University", 1, "COHRED", "SOBE"},
        {2, "Alice", "Smith", "Alice@smith.com", "pass456", "2022-02-21 12:15:00", "Jomo Kenyatta University", 1, "COHRED", "SOBE"},
        {3, "Bob", "Ross", "Bob@ross.com", "pass789", "2022-02-21 12:30:00", "Jomo Kenyatta University", 1, "COHRED", "SOBE"}
    };

    struct Unit units[7] = {
        {1, "Math For business", 1, "2022-02-21 12:30:00"},
        {2, "Intro to business", 2, "2022-02-21 12:45:00"},
        {3, "Computer Orgazition", 3, "2022-02-21 13:00:00"},
        {4, "Fund. of Computer", 4, "2022-02-21 13:15:00"},
        {5, "HIV/AIDs", 5, "2022-02-21 13:30:00"},
        {6, "Communication", 6, "2022-02-21 13:45:00"},
        {7, "Operating Systems", 7, "2022-02-21 14:00:00"}
    };

    struct Lecture lectures[7] = {
        {1, "Mr. Mwangi", "2022-02-21 12:30:00"},
        {2, "Miss Wangechi", "2022-02-21 12:45:00"},
        {3, "Mr. Omondi", "2022-02-21 13:00:00"},
        {4, "Sir Wilfred", "2022-02-21 13:15:00"},
        {5, "Mr. John", "2022-02-21 13:30:00"},
        {6, "Humprey", "2022-02-21 13:45:00"},
        {7, "Prof Jane", "2022-02-21 14:00:00"}
    };

    struct Grade grades[21] = {
        {1, 1, 1, 95, "2022-02-21 14:00:00"},
        {2, 1, 2, 85, "2022-02-21 14:15:00"},
        {3, 1, 3, 75, "2022-02-21 14:30:00"},
        {4, 1, 4, 65, "2022-02-21 14:45:00"},
        {5, 1, 5, 55, "2022-02-21 15:00:00"},
        {6, 1, 6, 45, "2022-02-21 15:15:00"},
        {7, 1, 7, 75, "2022-02-21 15:30:00"},
        
        {8, 2, 1, 80, "2022-02-21 14:00:00"},
        {9, 2, 2, 70, "2022-02-21 14:15:00"},
        {10, 2, 3, 60, "2022-02-21 14:30:00"},
        {11, 2, 4, 50, "2022-02-21 14:45:00"},
        {12, 2, 5, 40, "2022-02-21 15:00:00"},
        {13, 2, 6, 70, "2022-02-21 15:15:00"},
        {14, 2, 7, 60, "2022-02-21 15:30:00"},
        
        {15, 3, 1, 75, "2022-02-21 14:00:00"},
        {16, 3, 2, 65, "2022-02-21 14:15:00"},
        {17, 3, 3, 55, "2022-02-21 14:30:00"},
        {18, 3, 4, 45, "2022-02-21 14:45:00"},
        {19, 3, 5, 35, "2022-02-21 15:00:00"},
        {20, 3, 6, 65, "2022-02-21 15:15:00"},
        {21, 3, 7, 55, "2022-02-21 15:30:00"}
    };

    char student[50];
    char password[50];

    printf("Enter your student email: ");
    scanf("%s", student);

    printf("Enter your password: ");
    scanf("%s", password);

    int authenticated = 0;
    int studentIndex = -1;
    for (int i = 0; i < 3; ++i) {
        if (strcmp(student, students[i].email) == 0 &&
            strcmp(password, students[i].password) == 0) {
            authenticated = 1;
            studentIndex = i;
            break;
        }
    }

    if (authenticated) {
        printf("Logged in\n");

        printf("Student: %s %s\n", students[studentIndex].first_name, students[studentIndex].last_name);
    printf("Email: %s\n", students[studentIndex].email);
    printf("University: %s\n", students[studentIndex].university); // Display university
    printf("Year of Study: %d\n", students[studentIndex].year_of_study); // Display year of study
    printf("College: %s\n", students[studentIndex].college); // Display college
    printf("School: %s\n", students[studentIndex].school);

    
printf("\nResults for %s:\n", students[studentIndex].first_name);
printf("| %-20s | %-20s | %-6s | %-5s |\n", "Unit", "Lecturer", "Score", "Grade");
printf("|----------------------|----------------------|--------|-------|\n");

for (int i = 0; i < 7; ++i) {
    int gradeIndex = i + (studentIndex * 7);

    printf("| %-20s | %-20s | %-6d | ", units[i].name, lectures[i].name, grades[gradeIndex].score);
    
    grades[gradeIndex].grade = calculate_grade(grades[gradeIndex].score);
    
    printf("%-5c |\n", grades[gradeIndex].grade);
}

printf("|----------------------|----------------------|--------|-------|\n");

    } else {
        printf("Login failed\n");
    }

    return 0;
}

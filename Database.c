#include <stdio.h>
#include <string.h>
#include <haru/hpdf.h> // Include LibHaru for PDF generation

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
    char created_at[20];
    char grade; // Added a grade field
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

void generate_pdf(const char *filename, const struct Student *student, const struct Unit *units,
                  const struct Lecture *lectures, const struct Grade *grades) {
    HPDF_Doc pdf;
    HPDF_Page page;

    // Create PDF document
    pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        fprintf(stderr, "Error: Cannot create PDF document\n");
        return;
    }

    // Add a page to the document
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4);

    // Set font
    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);

    // Print student information
    HPDF_Page_SetFontAndSize(page, font, 12);
    HPDF_Page_TextOut(page, 50, 750, "Student Information:");

    char student_info[100];
    snprintf(student_info, sizeof(student_info), "Name: %s %s\nEmail: %s", student->first_name, student->last_name, student->email);
    HPDF_Page_TextOut(page, 50, 730, student_info);

    // Print results table
    HPDF_Page_SetFontAndSize(page, font, 10);
    HPDF_Page_TextOut(page, 50, 700, "\nResults:");

    HPDF_Page_TextOut(page, 50, 680, "| %-20s | %-20s | %-6s | %-5s |", "Unit", "Lecturer", "Score", "Grade");
    HPDF_Page_TextOut(page, 50, 670, "|----------------------|----------------------|--------|-------|");

    for (int i = 0; i < 7; ++i) {
        int gradeIndex = i + (student->id - 1) * 7;
        char result_row[100];
        snprintf(result_row, sizeof(result_row), "| %-20s | %-20s | %-6d | %-5c |", units[i].name, lectures[i].name, grades[gradeIndex].score, grades[gradeIndex].grade);
        HPDF_Page_TextOut(page, 50, 660 - i * 10, result_row);
    }

    HPDF_Page_TextOut(page, 50, 580, "|----------------------|----------------------|--------|-------|");

    // Save the PDF to a file
    HPDF_SaveToFile(pdf, filename);

    // Clean up
    HPDF_Free(pdf);
}

int main() {
    // ... (Previous code)

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

        // ... (Previous code)

        // Generate PDF report
        generate_pdf("student_results.pdf", &students[studentIndex], units, lectures, grades);

        printf("PDF report generated successfully.\n");
    } else {
        printf("Login failed\n");
    }

    return 0;
}

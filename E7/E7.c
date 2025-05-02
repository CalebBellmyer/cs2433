#include <stdio.h>
#include <stdlib.h> // Required for malloc(), free(), exit()
#include <string.h> // Required for strcmp(), strlen(), strcspn(), snprintf()

#define MAX_ID_LEN 50
#define MAX_NAME_LEN 100
#define MAX_SALARY_LEN 20
#define MAX_LINE_LEN 200
#define FILENAME "employee.txt"

// --- GetInfo Function (Corrected Version Returning char*) ---
// This function now reads ID, Name, Salary, allocates memory for a combined
// string, formats the string, and returns a pointer to it.
// Returns NULL if any input fails or memory allocation fails.
char* GetInfo(int num) {
    // Use temporary local buffers to read input first
    char id_buffer[MAX_ID_LEN];
    char name_buffer[MAX_NAME_LEN];
    char salary_buffer[MAX_SALARY_LEN];

    printf("\n--- Enter details for Employee %d ---\n", num);

    // Read ID
    printf("Enter ID: ");
    if (fgets(id_buffer, MAX_ID_LEN, stdin) == NULL) return NULL; // Error or EOF
    id_buffer[strcspn(id_buffer, "\n")] = '\0'; // Remove newline

    // Read Name
    printf("Enter Name: ");
    if (fgets(name_buffer, MAX_NAME_LEN, stdin) == NULL) return NULL; // Error or EOF
    name_buffer[strcspn(name_buffer, "\n")] = '\0'; // Remove newline

    // Read Salary
    printf("Enter Salary: ");
    if (fgets(salary_buffer, MAX_SALARY_LEN, stdin) == NULL) return NULL; // Error or EOF
    salary_buffer[strcspn(salary_buffer, "\n")] = '\0'; // Remove newline

    // --- Prepare the combined string ---

    // Choose a separator (e.g., comma)
    const char* separator = ",";
    size_t sep_len = strlen(separator);

    // Calculate required size for the combined string: id + sep + name + sep + salary + '\0'
    size_t total_size = strlen(id_buffer) + sep_len +
                        strlen(name_buffer) + sep_len +
                        strlen(salary_buffer) + 1; // +1 for the null terminator

    // Allocate memory dynamically
    char* employee_string = (char*)malloc(total_size);
    if (employee_string == NULL) {
        // Allocation failed!
        perror("Failed to allocate memory in GetInfo");
        return NULL;
    }

    // Create the combined string using snprintf (safer)
    int written = snprintf(employee_string, total_size, "%s%s%s%s%s",
                           id_buffer, separator,
                           name_buffer, separator,
                           salary_buffer);

    // Basic check for snprintf error
    if (written < 0 || written >= total_size) {
        fprintf(stderr, "Error formatting employee string in GetInfo.\n");
        free(employee_string); // Free memory before returning NULL
        return NULL;
    }

    // Return the pointer to the newly allocated string
    return employee_string;
}


int main () {
    int numEmployees;
    FILE *employeeFile;

    // --- Part 1: Get employee data using GetInfo and write to file ---

    printf("--- Employee Data Entry ---\n");
    printf("Enter the amount of employees: ");
    scanf("%d", &numEmployees);

    // Consume the leftover newline character after scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Open file in append mode ("a")
    employeeFile = fopen(FILENAME, "a");
     if (employeeFile == NULL) {
        printf("Error: Cannot open %s for writing/appending!\n", FILENAME);
        return 1;
    }

    // Loop to get info for each employee
    for (int i = 1; i <= numEmployees; i++) {
        // Call GetInfo, which now returns a dynamically allocated string (or NULL)
        char* employee_data = GetInfo(i);

        if (employee_data != NULL) {
            // If GetInfo succeeded, write the combined string to the file
            fprintf(employeeFile, "%s\n", employee_data);

            // *** IMPORTANT: Free the memory allocated by GetInfo ***
            free(employee_data);
            employee_data = NULL; // Good practice: avoid dangling pointer

        } else {
            // Handle the case where GetInfo failed (returned NULL)
            fprintf(stderr, "Failed to get data for employee %d. Skipping record.\n", i);
            // Optional: break loop or try again
        }
    }

    fclose(employeeFile); // Close the file after the loop
    printf("\nEmployee data saved to %s\n\n", FILENAME);


    // --- Part 2: Search for employee by ID ---
    // This part needs to read the file where each line is now the combined string

    printf("--- Search Employee Data ---\n");
    char search_id[MAX_ID_LEN];
    int found = 0;
    char line_buffer[MAX_LINE_LEN]; // Buffer to read lines from file

    printf("Enter Employee ID to search for: ");
    fgets(search_id, MAX_ID_LEN, stdin);
    search_id[strcspn(search_id, "\n")] = '\0';

    employeeFile = fopen(FILENAME, "r");
    if (employeeFile == NULL) {
        printf("Error: Cannot open %s for reading!\n", FILENAME);
        return 1;
    }

    // Read the file line by line
    while (fgets(line_buffer, sizeof(line_buffer), employeeFile) != NULL) {
        line_buffer[strcspn(line_buffer, "\n")] = '\0'; // Remove newline from file line

        // --- Parse the line read from the file ---
        // Create a temporary copy because strtok modifies the string
        char temp_line[MAX_LINE_LEN];
        strcpy(temp_line, line_buffer);

        // Use strtok to split the line by the separator (comma)
        char *file_id = strtok(temp_line, ","); // Get ID part

        if (file_id != NULL) {
            // Compare the extracted ID with the search ID
            if (strcmp(file_id, search_id) == 0) {
                printf("\n--- Record Found! ---\n");
                // We already have the full original line from the file
                printf("Full Record: %s\n", line_buffer);

                // If you want to print fields separately after finding:
                // char *file_name = strtok(NULL, ","); // Get Name part
                // char *file_salary = strtok(NULL, "\n"); // Get Salary part
                // printf("ID:     %s\n", file_id);
                // if (file_name) printf("Name:   %s\n", file_name);
                // if (file_salary) printf("Salary: %s\n", file_salary);
                printf("---------------------\n");

                found = 1;
                break; // Stop searching
            }
        }
    }

    fclose(employeeFile);

    if (found == 0) {
        printf("\nRecord with ID '%s' was not found.\n", search_id);
    }

    return 0;
}
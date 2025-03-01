#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINES 50

void get_details_and_store(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    printf("Enter details to store in %s (Enter 'done' to finish):\n", filename);
    char line[MAX_LINE_LENGTH];
    while (1) {
        printf("Enter detail: ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "done") == 0) {
            break;
        }

        fprintf(file, "%s\n", line);
    }

    fclose(file);
}

void read_file_into_array(const char *filename, char lines[MAX_LINES][MAX_LINE_LENGTH], int *line_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    *line_count = 0;
    while (fgets(lines[*line_count], MAX_LINE_LENGTH, file)) {
        // Remove trailing newline
        lines[*line_count][strcspn(lines[*line_count], "\n")] = 0;
        (*line_count)++;
    }

    fclose(file);
}

void print_matching_lines(char lines1[MAX_LINES][MAX_LINE_LENGTH], int count1,
                          char lines2[MAX_LINES][MAX_LINE_LENGTH], int count2) {
    printf("Matching lines in both files:\n");
    int found = 0;
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (strcmp(lines1[i], lines2[j]) == 0) {
                printf("%s\n", lines1[i]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No matching lines found.\n");
    }
}

int main() {
    char my_file[] = "my_details.txt";
    char friend_file[] = "friend_details.txt";

    // Get and store your details
    get_details_and_store(my_file);

    // Get and store your friend's details
    get_details_and_store(friend_file);

    // Read both files into arrays
    char my_lines[MAX_LINES][MAX_LINE_LENGTH];
    char friend_lines[MAX_LINES][MAX_LINE_LENGTH];
    int my_line_count = 0, friend_line_count = 0;

    read_file_into_array(my_file, my_lines, &my_line_count);
    read_file_into_array(friend_file, friend_lines, &friend_line_count);

    // Print matching lines
    print_matching_lines(my_lines, my_line_count, friend_lines, friend_line_count);

    return 0;
}

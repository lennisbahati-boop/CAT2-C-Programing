/*
Name:Lennis Bahati
Reg no:PA106/G/28806/25
Description :CAT 2
*/
#include <stdio.h>
#include <stdlib.h>

// Function to write integers to a file
void to_file() {
    FILE *f_in;
    int i, num;

    // Error handling
    f_in = fopen("input.txt", "w");
    if (f_in == NULL) {
        perror("Error opening input.txt for writing");
        exit(EXIT_FAILURE);
    }

    printf("Writing to input.txt\n");
    printf("Please enter 10 integers:\n");

    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(f_in, "%d\n", num);
    }

    fclose(f_in);
    printf("Successfully wrote the integers to input.txt\n");
}

// Function to process the input file and write results to output.txt
void process_file() {
    FILE *f_in, *f_out;
    int count = 0, num;
    long sum = 0;
    double average;

    f_in = fopen("input.txt", "r");
    if (f_in == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }

    f_out = fopen("output.txt", "w");
    if (f_out == NULL) {
        perror("Error opening output.txt for writing");
        fclose(f_in);
        exit(EXIT_FAILURE);
    }

    printf("Processing input.txt\n");

    while (fscanf(f_in, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0) {
        average = (double)sum / count;
    } else {
        average = 0.0;
    }

    fprintf(f_out, "Total Sum: %ld\n", sum);
    fprintf(f_out, "Average: %.2lf\n", average);

    fclose(f_in);
    fclose(f_out);

    printf("Calculations complete. Results written to output.txt.\n");
}

// Function to display contents of both files
void display_files() {
    FILE *fp;
    int c;

    // Helper function inside display_files
    void print_file_contents(const char *filename) {
        fp = fopen(filename, "r");
        if (fp == NULL) {
            perror("Error opening file for display");
            return;
        }

        printf("\nContents of %s:\n", filename);
        while ((c = fgetc(fp)) != EOF) {
            putchar(c);
        }
        fclose(fp);
    }

    printf("\nDisplaying files...\n");
    print_file_contents("input.txt");
    print_file_contents("output.txt");
}

// Main function
int main() {
    // Write 10 integers
    to_file();

    // Process input.txt and write results to output.txt
    process_file();

    // Display contents of both files
    display_files();

    return 0;
}



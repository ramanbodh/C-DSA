
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *result;
    float f, sum = 0;
    int count = 0;

    // (a) Create INPUT.TXT and write 10 numbers
    fp = fopen("INPUT.TXT", "w+");

    if (fp == NULL) {
        printf("Unable to create INPUT.TXT!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Enter a number (integer or floating point): ");
        scanf("%f", &f);
        fprintf(fp, "%f ", f);
    }

    // (b) Read numbers and filter integers
    rewind(fp);

    result = fopen("RESULT.TXT", "w");

    if (result == NULL) {
        printf("Unable to create RESULT.TXT!\n");
        fclose(fp);
        return 1;
    }

    fprintf(result, "Filtered integers: ");

    while (fscanf(fp, "%f", &f) == 1) {

        if (f == (int)f) {
            fprintf(result, "%d ", (int)f);
            sum += f;
            count++;
        }
    }

    // Calculate average
    if (count > 0) {
        fprintf(result, "\nCount: %d", count);
        fprintf(result, "\nAverage: %.2f", sum / count);
    } else {
        fprintf(result, "\nNo integers found.");
    }

    // Close files
    fclose(fp);
    fclose(result);

    // (d) Read RESULT.TXT and display results
    result = fopen("RESULT.TXT", "r");

    if (result == NULL) {
        printf("Unable to open RESULT.TXT!\n");
        return 1;
    }

    printf("\n\n----- RESULTS -----\n");

    char ch;
    while ((ch = fgetc(result)) != EOF) {
        putchar(ch);
    }

    fclose(result);

    return 0;
}

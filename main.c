#include <stdio.h>

int calculateSum(int a, int b);
void saveSumResultsToFile(int a, int b, int total);

int main(void) {
    int a, b, total;
    char choice;

    do {
        printf("\n--- Summation Calculator ---\n");
        printf("Enter the starting number (a): ");
        scanf("%d", &a);
        printf("Enter the ending number (b): ");
        scanf("%d", &b);

        if (b <= a) {
            printf("Error. b must be greater than a.\n");
        } else {
            total = calculateSum(a, b);
            printf("The sum of all numbers between %d and %d is: %d\n", a, b, total);
            saveSumResultsToFile(a, b, total);
        }

        printf("\nWould you like to calculate another summation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the summation calculator!\n");
    return 0;
}

int calculateSum(int a, int b) {
    int total = 0;
    for (int i = a; i <= b; i++) {
        total += i;
    }
    return total;
}

void saveSumResultsToFile(int a, int b, int total) {
    FILE *file = fopen("summation_results.txt", "w");
    if (!file) {
        printf("Error creating results file!\n");
        return;
    }
    
    fprintf(file, "Summation Calculation:\n");
    fprintf(file, "Start Number (a): %d\n", a);
    fprintf(file, "End Number (b): %d\n", b);
    fprintf(file, "Sum Total: %d\n", total);
    
    fclose(file);
    printf("Results saved to 'summation_results.txt'.\n");
}

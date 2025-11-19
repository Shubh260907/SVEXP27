#include <stdio.h>

// Function Prototype
void generate_savings_series(int n);

int main() {
    int n;

    // 1. Takes the number of months (n) as input from the user.
    printf("Enter the number of months (n) for the savings plan (n >= 1): ");

    // Loop until valid input (n >= 1) is provided
    do {
        // Read input
        if (scanf("%d", &n) != 1) {
            // Handle non-integer input
            printf("Invalid input. Please enter an integer number of months (n >= 1): ");
            // Clear the input buffer to prevent infinite loop
            while (getchar() != '\n');
            n = 0; // Reset n to keep the loop going
            continue;
        }

        // 1. Is the input value (n) validated correctly (e.g., n >= 1)?
        if (n < 1) {
            printf("Input must be 1 or greater. Please re-enter the number of months: ");
        }
    } while (n < 1);

    // Generate and display the series
    generate_savings_series(n);

    return 0;
}

/**
 * @brief Generates and displays the Fibonacci-like savings series for n months.
 * * @param n The total number of months.
 */
void generate_savings_series(int n) {
    // 3. Are the first two months (base cases) hardcoded to ₹1 as required?
    long long month1_savings = 1; // Savings for the month before the current one (i-2)
    long long month2_savings = 1; // Savings for the previous month (i-1)
    long long current_savings;
    long long total_savings = 0;

    printf("\n--- Savings Series for %d Months ---\n", n);

    // Handle the first two months (base cases)
    if (n >= 1) {
        printf("Month 1: ₹%lld\n", month1_savings);
        total_savings += month1_savings;
    }

    if (n >= 2) {
        printf("Month 2: ₹%lld\n", month2_savings);
        total_savings += month2_savings;
    }

    // 2. Generates a series showing the savings amount for each month
    //    based on this pattern (Fibonacci logic).
    // Loop starts from month 3 (i = 3) up to n
    for (int i = 3; i <= n; i++) {
        // Savings for the current month is the sum of the previous two months
        current_savings = month1_savings + month2_savings;
        total_savings += current_savings;

        // 4. Is the series displayed clearly with month-wise labeling?
        printf("Month %d: ₹%lld\n", i, current_savings);

        // Update the savings for the next iteration (shifting the values)
        // M(i-2) becomes M(i-1)
        month1_savings = month2_savings;
        // M(i-1) becomes M(i)
        month2_savings = current_savings;
    }

    // Supplementary Problem 2: Add the total amount saved over n months and display it
    printf("\n--- Summary ---\n");
    printf("Total amount saved over %d months: **₹%lld**\n", n, total_savings);
}

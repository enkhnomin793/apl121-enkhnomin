#include <stdio.h>

int main() {
    int i, coldDay = 1;
    double celsius, fahrenheit;
    double mintemp = 999;
    double temp1, temp2, temp3, temp;
    const char *category, *clothes;

    double temperatures[7];

    printf("=== winter temperature report ===\n");

    // 1. Input and validation
    for (i = 0; i < 7; i++) {
        do {
            printf("day %d - celsius (-50 to 60): ", i + 1);
            scanf("%lf", &temperatures[i]);

            if (temperatures[i] < -50 ||
                temperatures[i] > 60) {
                printf("Invalid temperature! Try again.\n");
            }
        } while (temperatures[i] < -50 ||
                 temperatures[i] > 60);
    }

    // 2. Sort the first 3 temperatures using if
    temp1 = temperatures[0];
    temp2 = temperatures[1];
    temp3 = temperatures[2];

    if (temp1 > temp2) {
        temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }

    if (temp1 > temp3) {
        temp = temp1;
        temp1 = temp3;
        temp3 = temp;
    }

    if (temp2 > temp3) {
        temp = temp2;
        temp2 = temp3;
        temp3 = temp;
    }

    printf("\nfirst 3 temperatures (ascending): ");
    printf("%.1f, %.1f, %.1f\n", temp1, temp2, temp3);

    // 3. table heading
    printf("\n%-8s %10s %12s %-18s %-35s\n",
           "day", "celsius", "fahrenheit",
           "category", "clothing");

    printf("-------------------------------------------------------------------------------\n");

    // 4. process and display 7 days
    for (i = 0; i < 7; i++) {
        celsius = temperatures[i];

        // celsius to fahrenheit
        fahrenheit = celsius * 9.0 / 5.0 + 32.0;

        // temperature category and clothing
        if (celsius >= 0 && celsius <= 60) {
            category = "warm";
            clothes = "jacket";
        }
        else if (celsius >= -10) {
            category = "cool";
            clothes = "jacket and scarf";
        }
        else if (celsius >= -20) {
            category = "cold";
            clothes = "winter jacket";
        }
        else if (celsius >= -30) {
            category = "verycold";
            clothes = "winter jacket and scarf";
        }
        else {
            category = "extremelycold";
            clothes = "winter jacket, scarf, gloves, hat";
        }

        printf("%-8d %10.1f %12.1f %-18s %-35s\n",
               i + 1, celsius, fahrenheit,
               category, clothes);

        // find the coldest day
        if (celsius < mintemp) {
            mintemp = celsius;
            coldDay = i + 1;
        }
    }

    // 5. final results
    printf("\n=== coldest day ===\n");
    printf("Day: %d\n", coldDay);
    printf("lowest temperature: %.1f C\n", mintemp);

    return 0;
}

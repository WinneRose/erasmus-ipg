#include <stdio.h>
int decToOctal(int decimalNumber);
int main(void) {


    // Convert a character to its ASCII value
    char ChToAscii;
    printf("Enter a character: ");
    scanf("%c", &ChToAscii);
    printf("ASCII value: %d\n", ChToAscii);

    // - - - - - - -

    // Read a three-digit number and perform operations on its digits
    int HundredNumber;
    printf("Enter a three-digit number: ");
    scanf("%d", &HundredNumber);

    if (HundredNumber <= 999) {
        // Extract individual digits from the number
        int hundreds = (HundredNumber / 100) % 10;  // Get hundreds digit
        int tens = (HundredNumber / 10) % 10;       // Get tens digit
        int ones = HundredNumber % 10;              // Get ones digit

        // Reverse the number by rearranging digits
        printf("Reversed Number: %d\n", ones * 100 + tens * 10 + hundreds);

        // Calculate the sum of all digits
        printf("Sum of Digits: %d\n", hundreds + tens + ones);

    } else {
        printf("Error: Number must be 999 or less!\n");
    }

    // - - - - - - -

    // Calculate and display the minimum number of banknotes and coins for the entered amount

    float BanknotesAmount;
    // The biggest money in Turkey is 200 Turkish Liras thats why my banknote calculation depends on that
    // 200 -> 100 -> 50 -> 20 -> 10 -> 5 -> 1 -> 0.50
    printf("Enter Amount of Cash: ");
    scanf("%f", &BanknotesAmount);

    int values[] = {200, 100, 50, 20, 10, 5,1, 0.5};
    char* names[] = {"Turkish Lira Banknotes", "Turkish Lira Coins"};

    for (int i = 0; i < sizeof(values) ; i++) {


        int count = (BanknotesAmount / values[i]);

        if (count > 0) {

            if (values[i] > 1) printf("%d x %d %s\n", count, values[i], names[0]);
            else printf("%d x %d %s\n", count, values[i] , names[1]);
            BanknotesAmount -= count * values[i]; // Update remaining amount
        }

    }



    // Calculate arrival time based on departure time and travel duration
    int dep_h, dep_m, dep_s;  // Departure time
    int dur_h, dur_m, dur_s;  // Duration

    printf("Enter departure time (hh:mm:ss): ");
    scanf("%d:%d:%d", &dep_h, &dep_m, &dep_s);

    printf("Enter travel duration (hh:mm:ss): ");
    scanf("%d:%d:%d", &dur_h, &dur_m, &dur_s);

    // Convert everything to seconds
    int depSeconds = dep_h * 3600 + dep_m * 60 + dep_s;
    int durSeconds = dur_h * 3600 + dur_m * 60 + dur_s;

    // Add them up
    int totalSeconds = depSeconds + durSeconds;

    // Convert back to hh:mm:ss
    int arr_h = (totalSeconds / 3600) % 24;  // % 24 handles day overflow
    int remaining = totalSeconds % 3600;
    int arr_m = remaining / 60;
    int arr_s = remaining % 60;

    // Display result
    printf("\nArrival time: %02d:%02d:%02d\n", arr_h, arr_m, arr_s);

    // - - - - -

    // Octal Converter

    int octalNumber;
    printf("Enter number to convert octal format: ");
    scanf("%d", &octalNumber);
    printf("Octal number is %o \n", octalNumber); // built-in octal converter
    printf("Octal number with function %d \n", decToOctal(octalNumber)); // octal converter function






    return 0;
}


int decToOctal(int decimalNumber) {
    if (decimalNumber == 0) return 0;

    int digits[100];
    int i = 0;

    // Calculate octal digits
    while (decimalNumber != 0) {
        digits[i] = decimalNumber % 8;
        decimalNumber /= 8;
        i++;
    }

    // Build number from digits (reverse order)
    int octalResult = 0;
    for (int j = i - 1; j >= 0; j--) {
        octalResult = octalResult * 10 + digits[j];
    }

    return octalResult;
}
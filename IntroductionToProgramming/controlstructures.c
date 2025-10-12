#include <stdio.h>


int main(int argc, char *argv[]) {


    // Smaller to Bigger example:
    // input: 10 3
    // output: 3 10

    int input1, input2;
    printf("Enter two numbers: ");
    scanf("%d %d", &input1, &input2);

    if (input1 < input2) {
        printf("%d %d\n", input1, input2);
    } else {
        printf("%d %d\n", input2, input1);
    }

    // Print biggest number from the input
    // input: 3 10
    // output: 10
    int number1, number2;
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);

    if (number1 > number2) {
        printf("The biggest number is: %d\n", number1);
    } else {
        printf("The biggest number is: %d\n", number2);
    }


    // Select biggest number from input list

    int a, b, c , max;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("The biggest number is: %d\n", max);

    // Grade declaration system

    int grade;
    printf("Enter your grade: ");
    scanf("%d", &grade);

    if (grade >= 85 && grade <= 100) printf("Perfect grade! \n");
    else if (grade >= 75 && grade < 85) printf("Good grade! \n");
    else if (grade >= 55 && grade < 75) printf("Average grade! \n");
    else if (grade >= 45 && grade < 55) printf("Bad grade! \n");
    else printf("Worst grade! \n");

    //  - - - - -

    // IUC Tax Calculator depending on Year and Engine capacity

    int engineCapacity, registrationYear;
    float tax = 0;

    printf("Enter engine capacity (cc): ");
    scanf("%d", &engineCapacity);

    printf("Enter registration year: ");
    scanf("%d", &registrationYear);

    // Check if registered before July 1, 2007
    if (registrationYear >= 2007) {
        printf("This vehicle was registered after July 1, 2007. Cannot calculate.\n");
        return 0;
    }

    // Calculate tax based on engine capacity
    if (engineCapacity <= 1000) {
        // Up to 1,000 cc
        if (registrationYear > 1995) {
            tax = 16.50;
        } else if (registrationYear >= 1990 && registrationYear <= 1995) {
            tax = 10.40;
        } else if (registrationYear >= 1981 && registrationYear <= 1989) {
            tax = 7.30;
        }
    }
    else if (engineCapacity >= 1001 && engineCapacity <= 1300) {
        // Between 1,001 and 1,300 cc
        if (registrationYear > 1995) {
            tax = 33.10;
        } else if (registrationYear >= 1990 && registrationYear <= 1995) {
            tax = 18.60;
        } else if (registrationYear >= 1981 && registrationYear <= 1989) {
            tax = 10.40;
        }
    }
    else if (engineCapacity > 1300) {
        // More than 1,300 cc
        if (registrationYear > 1995) {
            tax = 51.70;
        } else if (registrationYear >= 1990 && registrationYear <= 1995) {
            tax = 28.90;
        } else if (registrationYear >= 1981 && registrationYear <= 1989) {
            tax = 14.50;
        }
    }

    printf("\n--- Calculation Result ---\n");
    printf("Engine Capacity: %d cc\n", engineCapacity);
    printf("Registration Year: %d\n", registrationYear);
    printf("IUC Tax to Pay: %.2f €\n", tax);

   //  - - - - -

    // Palindrome Checker [100,999]

    int number, firstDigit, middleDigit, lastDigit;

    printf("Enter a number (100-999): ");
    scanf("%d", &number);

    // Check if number is in valid range
    if (number < 100 || number > 999) {
        printf("Number must be between 100 and 999!\n");
        return 0;
    }

    // Extract digits
    firstDigit = number / 100;           // 121 / 100 = 1
    middleDigit = (number / 10) % 10;    // 121 / 10 = 12, 12 % 10 = 2
    lastDigit = number % 10;             // 121 % 10 = 1


    if (firstDigit == lastDigit) {
        printf("%d is a palindrome!\n", number);
    } else {
        printf("%d is NOT a palindrome.\n", number);
    }


    // - - - - -
    // Input a 3-digit number and find even numbers in digits then calculate sum
    // Can divide with 3 ? true : false
    // Can divide with 4 ? true : false
    // Can divide with 5 ? true : false
    int evenNumbers, evenSum, evenNum1, evenNum2, evenNum3;
    printf("Enter a three-digit number: ");
    scanf("%d", &evenNumbers);

    evenNum1 = evenNumbers / 100;
    evenNum2 = (evenNumbers / 10) % 10;
    evenNum3 = evenNumbers % 10;

    if (evenNum1 % 2 == 0) {
        evenSum += evenNum1;
    }
    if (evenNum2 % 2 == 0) {
        evenSum += evenNum2;
    }
    if (evenNum3 % 2 == 0) {
        evenSum += evenNum3;
    }


    printf("Even numbers in digits: %d\n", evenNumbers);
    printf("Even numbers sum: %d\n", evenSum);

    if ((evenNum1 + evenNum2 + evenNum3) % 3 == 0) {
        printf("Can divide with 3: true\n");
    } else {
        printf("Can divide with 3: false\n");
    }

    if ((evenNum2 + evenNum3) % 4 == 0) {
        printf("Can divide with 4: true\n");
    } else {
        printf("Can divide with 4: false\n");
    }

    if (evenNum3 % 5 == 0 || evenNum3 == 0) {
        printf("Can divide with 5: true\n");
    } else {
        printf("Can divide with 5: false\n");
    }


    // - - - - -

    // Convert small caps to Bigger Caps
    char letter, converted;

    printf("Enter a letter: ");
    scanf(" %c", &letter);

    // Check if uppercase (A-Z)
    if (letter >= 'A' && letter <= 'Z') {
        converted = letter + 32;  // Convert to lowercase
        printf("Original: %c (ASCII: %d)\n", letter, letter);
        printf("Converted: %c (ASCII: %d)\n", converted, converted);
    }
    // Check if lowercase (a-z)
    else if (letter >= 'a' && letter <= 'z') {
        converted = letter - 32;  // Convert to uppercase
        printf("Original: %c (ASCII: %d)\n", letter, letter);
        printf("Converted: %c (ASCII: %d)\n", converted, converted);
    }

    else {
        printf("Error: '%c' is not a letter!\n", letter);
    }
}

#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 

#define MAX_INPUT_LENGTH 100  // Maximum length of the input



// Initializers of the functions
int every_other_digit(long card);
int multiplyAndSum(int last);
bool checkIfValid(int sum_every_other_digit);
int numDigit(long card);

bool checkAmex(long card, int numDigit);
bool checkMasterCard(long card, int numDigit);
bool checkVisa(long card, int numDigit);
void getUserInput(char* input, int max_length);

long int getLongInput();


// MAIN

int main(void)
{
long int card;

    printf("Please enter a long integer: ");
    card = getLongInput();
    int sum_every_other_digit = every_other_digit(card);
    bool validNum = checkIfValid(sum_every_other_digit);

    int numDig = numDigit(card);

    if (validNum)
    {

        if (checkAmex(card, numDig))
        {
            printf("AMEX\n");
        }

        else if (checkMasterCard(card, numDig))
        {
            printf("Master Card\n");
        }

       else if (checkVisa(card, numDig))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// FUNCTIONS

int every_other_digit(long card)
{
    int total = 0;
    bool alter = false;
    while (card > 0)
    {
        if (alter == true)
        {
            int last = card % 10;
            int product = multiplyAndSum(last);
            total = total + product;
        }
        else
        {
            total += card % 10;
        }
        alter = !alter;
        card = card / 10;
    }
    return total;
}

int multiplyAndSum(int last)
{

    int multiply = last * 2;
    int total = 0;

    while (multiply > 0)
    {
        int last_mult = multiply % 10;
        total += last_mult;
        multiply = multiply / 10;
    }
    return total;
}

bool checkIfValid(int sum_every_other_digit)
{
    if ((sum_every_other_digit % 10) == 0)
    {
        return true;
    }

    return false;
}

int numDigit(long card)
{
    int count = 0;
    while (card > 0)
    {
        card = card / 10;
        count++;
    }
    return count;
}

// now lets check the cards

bool checkAmex(long card, int numDigit)
{

    int firstTwoDig = card / pow(10, 13);

    if (numDigit == 15 && (firstTwoDig == 34 || firstTwoDig == 37))
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool checkMasterCard(long card, int numDigit)
{

    int firstTwoDig = card / pow(10, 14);

    if (numDigit == 16 && (firstTwoDig == 51 || firstTwoDig == 52 || firstTwoDig == 53 || firstTwoDig == 54 || firstTwoDig == 55))
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool checkVisa(long card, int numDigit)
{
    int firstnum;
    while (card > 10)
    {
        card = card / 10;
        if ((card / 10) == 0)
        {
            firstnum = card;
        }
    }

    if ((numDigit == 13 || numDigit == 16) && (firstnum == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}


void getUserInput(char* input, int max_length) {
    // Clear the input buffer to avoid any remnants
    fflush(stdin);

    // Get the user input using fgets
    fgets(input, max_length, stdin);

    // Remove the trailing newline character, if present
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';
}

long int getLongInput() {
    char userInput[MAX_INPUT_LENGTH];
    getUserInput(userInput, MAX_INPUT_LENGTH);

    char* endptr; // Pointer to the end of the converted value
    long int result = strtoll(userInput, &endptr, 10);

    // Check if the conversion was successful
    if (*endptr != '\0') {
        printf("Invalid input! Please enter a valid long integer.\n");
        return getLongInput(); // Retry getting input
    }

    return result;
}

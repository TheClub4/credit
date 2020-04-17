#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare and initialize a variable
    long long cardNumber = 0;
    
    // Prompt user input
    do
    {
        cardNumber = get_long_long("Enter your credit card number: \n");
    }
    while (cardNumber < 0);

    // Determine the validity of card by couting the number of digits
    int count = 0;
    long long digits = cardNumber;
    while (digits > 0)
    {
        // Repeatedly divide cardNumber by 10 to remove the last digit
        digits = digits / 10;
        //Increment the count by each digit
        count++;
    }

    // Rule out irrelevant number of digits
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }

    // Delcare a "number" array to store digit counts of card numbers
    int number[count];
    for (int i = 0; i < count; i++)
    {
        number[i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }

    // Declare an array for the orginal card number using the above "number" array
    int originalNumber[count];
    for (int i = 1; i < count; i++)
    {
        originalNumber[i] = number[i];
    }

    // Multiply digits by starting with the number’s second-to-last digit
    for (int i = 1; i < count; i += 2)
    {
        number[i] = number[i] * 2;
    }

    int v = 0;
    int temp;
    
    // Validating 13-digit VISA cards
    if (count == 13)
    {
        for (int i = 0; i < count; i++)
        {
            // Add the sum of products' digits to the sum of the digits that weren't multiplied
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalNumber[12] == 12 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // Validating AMEX cards
    if (count == 15)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v+ temp;
        }

        // Condition for AMEX cards: card number starting with 34 or 37)
        if (originalNumber[14] == 3 && v % 10 == 0 && (originalNumber[13] == 4 || 
            originalNumber[13]  == 7))
        {
            printf("AMEX\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }

    // 16-digit VISA cards & MASTERCARD
    if (count == 16)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }

        if (originalNumber[15] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }

        else if (originalNumber[15] == 5 && v % 10 == 0 && (originalNumber[14] == 1 || 
                 originalNumber[14] == 2 || 
                 originalNumber[14] == 3 || 
                 originalNumber[14] == 4 ||                   
                 originalNumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
}

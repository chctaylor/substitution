#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    //Checking for argument input compatibility

    else if (argc == 2)
    {
        for (int array_counter = 0, argument = strlen(argv[1]); array_counter < argument; array_counter++)
        {
            if (isdigit(argv[1][array_counter]))
            {
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }
            else if (strlen(argv[1]) != 26)
            {
                printf("Key must contain 26 characters\n");
                return 1;
            }
        }

        //Checking for duplicate letters

        string argument_input = argv[1];

        //Create placeholder for a copy of user input

        char copied_input[27];

        //Making a copy of user input in order to manipulate to test for duplicate letters

        strcpy(copied_input, argument_input);

        //Make copied input all caps to check for duplicate letters

        for (int i = 0; i < strlen(copied_input); i++)
        {
            if (islower(copied_input[i]))
            {
                copied_input[i] -= 32;
            }
        }

        int duplicate_counter = 0;

        for (int i = 0; i < strlen(copied_input); i++)
        {

            for (int j = i + 1; j < strlen(copied_input); j++)
            {
                if (copied_input[i] == copied_input[j])
                {
                    duplicate_counter++;
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
        }
    }

    //Prompt user for plaintext

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    //Convert plaintext into ciphertext and print

    for (int array_plaintext_counter = 0, input_plaintext = strlen(plaintext); array_plaintext_counter < input_plaintext;
         array_plaintext_counter++)
    {
        if (isupper(plaintext[array_plaintext_counter]))
        {
            plaintext[array_plaintext_counter] -= 65;
            int key = plaintext[array_plaintext_counter];
            printf("%c", toupper(argv[1][key]));
        }
        else if (islower(plaintext[array_plaintext_counter]))
        {
            plaintext[array_plaintext_counter] -= 97;
            int key = plaintext[array_plaintext_counter];
            printf("%c", tolower(argv[1][key]));
        }
        else
        {
            printf("%c", plaintext[array_plaintext_counter]);
        }
    }
    printf("\n");
}
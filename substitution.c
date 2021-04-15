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
    else if(argc == 2)
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
        //Testing how to find duplicate letters BUT ITS NOT WORKING... maybe write a formula converting letters to upper case
        //adding all together A through Z and if the number is not == to user input it means a letter was duplicated

        string argument_input = argv[1];

        printf("%s\n", argument_input);
        int duplicate_counter = 0;

        printf("Duplicate characters: \n");

        for (int i = 0; i < strlen(argument_input); i++)
        {

            for (int j = i + 1; j < strlen(argument_input); j++)
            {
                if(argument_input[i] == argument_input[j])
                {
                    duplicate_counter++;
                    printf("%c\n",argument_input[i]);
                }
            }
        }
        printf("%i\n",duplicate_counter);
    }
}
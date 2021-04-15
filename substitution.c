//this is just a place holder

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
        //Testing how to find duplicate letters BUT ITS NOT WORKING
        
        string input = argv[1];
        
        printf("%s\n", input);
        char argument_input[] = "input";
        int duplicate_counter;

        printf("Duplicate characters: \n");

        for(int i = 0; i < strlen(argument_input); i++)
        {
            duplicate_counter = 1;

            for (int j = i + 1; j < strlen(argument_input); j++)
            {
                if(argument_input[i] == argument_input[j] && argument_input[i] != '0')
                {
                    duplicate_counter++;
                    argument_input[j] = '0';
                }
            }

            //Duplicated letters if the duplicate counter greater than 1

            if(duplicate_counter > 1 && argument_input[i] != '0')
            {
                printf("%c\n", argument_input[i]);
            }
        }
    }
}
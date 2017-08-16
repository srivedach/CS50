#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/**
 * 
 * Write, in a file called initials.c, a program that prompts a user for
 * their name (using GetString to obtain their name as a string) and then
 * outputs their initials in uppercase with no spaces or periods,
 * followed by a newline (\n) and nothing more.
 * 
 * */

int main(void)
{
    string name = GetString();
    
    //print the first initial as an uppercase letter
    printf("%c", toupper(name[0]));
    
    //loop and find space characters.
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
        {
            // print next character as an uppercase char
            printf("%c", toupper(name[i + 1]));
        }
    }
    
    //print new line
    printf("\n");
}
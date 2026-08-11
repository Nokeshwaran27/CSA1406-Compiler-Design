#include <stdio.h>
#include <string.h>

int main()
{
    char exp[50];
    int i = 0;
    char temp = 'A';

    printf("Enter the Expression: ");
    scanf("%s", exp);

    printf("\nThree Address Code:\n");

    while (strlen(exp) > 1)
    {
        for (i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '*' || exp[i] == '/')
            {
                printf("%c = %c %c %c\n", temp, exp[i-1], exp[i], exp[i+1]);
                exp[i-1] = temp;
                strcpy(&exp[i], &exp[i+2]);
                temp++;
                break;
            }
        }

        if (exp[i] == '\0')
        {
            for (i = 0; exp[i] != '\0'; i++)
            {
                if (exp[i] == '+' || exp[i] == '-')
                {
                    printf("%c = %c %c %c\n", temp, exp[i-1], exp[i], exp[i+1]);
                    exp[i-1] = temp;
                    strcpy(&exp[i], &exp[i+2]);
                    temp++;
                    break;
                }
            }
        }
    }

    return 0;
}
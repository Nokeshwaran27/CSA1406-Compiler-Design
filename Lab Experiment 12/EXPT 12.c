#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

// Function declarations
void E();
void E1();
void T();
void T1();
void F();

void E()
{
    T();
    E1();
}

void E1()
{
    if(input[i] == '+')
    {
        i++;
        T();
        E1();
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if(input[i] == '*')
    {
        i++;
        F();
        T1();
    }
}

void F()
{
    if(input[i] == '(')
    {
        i++;
        E();

        if(input[i] == ')')
            i++;
        else
        {
            printf("String Rejected\n");
            return;
        }
    }
    else if(input[i] == 'i' && input[i+1] == 'd')
    {
        i += 2;
    }
    else
    {
        printf("String Rejected\n");
    }
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if(input[i] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
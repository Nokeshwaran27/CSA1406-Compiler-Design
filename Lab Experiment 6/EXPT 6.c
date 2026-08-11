#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[]) {
    char keywords[][20] = {
        "int", "float", "char", "double", "if", "else",
        "while", "for", "return", "void", "break", "continue"
    };

    int i;
    for(i = 0; i < 12; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char id[100];
    int i, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", id);

    // Check first character
    if(!(isalpha(id[0]) || id[0] == '_'))
        valid = 0;

    // Check remaining characters
    for(i = 1; id[i] != '\0'; i++) {
        if(!(isalnum(id[i]) || id[i] == '_')) {
            valid = 0;
            break;
        }
    }

    // Check keyword
    if(isKeyword(id))
        valid = 0;

    if(valid)
        printf("%s is a Valid Identifier.\n", id);
    else
        printf("%s is an Invalid Identifier.\n", id);

    return 0;
}
#include <stdio.h>

int main() {
    char ch;
    int whitespace = 0, newline = 0;

    printf("Enter the text (Press Ctrl+Z in Windows / Ctrl+D in Linux to end):\n");

    while ((ch = getchar()) != EOF) {

        // Count spaces and tabs
        if (ch == ' ' || ch == '\t')
            whitespace++;

        // Count new line characters
        else if (ch == '\n')
            newline++;
    }

    printf("\nNumber of Whitespaces: %d\n", whitespace);
    printf("Number of Newline Characters: %d\n", newline);

    return 0;
}
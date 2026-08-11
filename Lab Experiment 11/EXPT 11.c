#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
};

struct Symbol table[100];
int count = 0;

// Insert Symbol
void insert()
{
    printf("Enter Symbol Name: ");
    scanf("%s", table[count].name);

    printf("Enter Data Type: ");
    scanf("%s", table[count].type);

    count++;
    printf("Symbol Inserted Successfully.\n");
}

// Display Symbol Table
void display()
{
    int i;

    if(count == 0)
    {
        printf("Symbol Table is Empty.\n");
        return;
    }

    printf("\n---------------------------------\n");
    printf("Index\tName\tType\n");
    printf("---------------------------------\n");

    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\n", i + 1,
               table[i].name,
               table[i].type);
    }

    printf("---------------------------------\n");
}

// Search Symbol
void search()
{
    char key[20];
    int i, found = 0;

    printf("Enter Symbol to Search: ");
    scanf("%s", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, key) == 0)
        {
            printf("Symbol Found!\n");
            printf("Name : %s\n", table[i].name);
            printf("Type : %s\n", table[i].type);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Symbol Not Found.\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== SYMBOL TABLE MENU =====\n");
        printf("1. Insert Symbol\n");
        printf("2. Display Symbol Table\n");
        printf("3. Search Symbol\n");
        printf("4. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
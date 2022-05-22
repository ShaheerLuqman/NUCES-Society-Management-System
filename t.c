#include <stdio.h>
#include <string.h>
void sort(int std_marks[], int roll_no[], char name[][5]);
void display(int roll_no[], char name[][5], int std_marks[]);
int main()
{
    int roll_no[5] = {0, 1, 2, 3, 4};
    char name[5][5] = {"ibad", "ali", "eman", "amna", "dave"};
    int std_marks[5] = {89, 77, 45, 90, 12};
    printf("part a\n");
    sort(std_marks, roll_no, name);
    printf("part b\n");
    display(roll_no, name, std_marks);
}
void sort(int std_marks[], int roll_no[], char name[][5])
{
    int i, j, temp1, temp2;
    char temp3[15];

    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (std_marks[i] < std_marks[j])
            {
                temp1 = std_marks[i];
                temp2 = roll_no[i];
                strcpy(temp3, name[i]);
                std_marks[i] = std_marks[j];
                roll_no[i] = roll_no[j];
                strcpy(name[i], name[j]);
                std_marks[j] = temp1;
                roll_no[j] = temp2;
                strcpy(name[j], temp3);
            }
        }
    }
    printf("The sorted marks are:\n");
    for (i = 0; i < 5; i++)
    {
        printf(" %d \t%s \t%d\n", roll_no[i], name[i], std_marks[i]);
    }
}
void display(int roll_no[], char name[][5], int std_marks[])
{
    int i, no;
    printf("Enter roll no: ");
    scanf("%d", &no);

    for (i = 0; i < 5; i++)
    {
        if (no == roll_no[i])
        {
            printf("\nRoll no is %d", roll_no[i]);
            printf("\nName is %s", name[i]);
            printf("\nMarks are %d", std_marks[i]);
            break;
        }
    }
}
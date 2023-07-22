#include <stdio.h>
#include <stdlib.h>
#include "school.h"

int main()
{
    int option;
    int searchtype;
    int idsearch;
    char namesearch[20];
    int status;
    printf("Welcome to the SCHOOL DATABASE\n\n");
    while (1)
    {
        // system("cls");
        printf("********************************************************\n");
        printf("\nChoose from the Following options : \n 1-add a student to the database.\n 2-edit a student.\n 3-print a student.\n 4-delete a student from the database.\n 5-print the whole school database.\n 6-call a student.\n");
        printf("********************************************************\n");

        scanf("%d", &option);
        if (option == 1)
        {
            status = addStudent();
            if (status == School_Full)
            {
                printf("the school is full delete some students first!!\n");
            }
            else if (status == OP_Failed)
            {
                printf("Something went wrong please try again :)\n");
            }
            else if (status == OP_Done)
            {
                printf("Student is added to SCHOOL :) \n");
            }
        }
        else if (option == 2)
        {
            printf("Would you like to search for the student by id or name: 1-id or 2-name \n");
            scanf("%d", &searchtype);
            while (searchtype != 1 && searchtype != 2)
            {
                printf("please choose a valid option from (1 or 2)\n ");
                scanf("%d", &searchtype);
            }
            if (searchtype == 1)
            {
                printf("enter id for student to be eddited:");
                scanf("%d", &idsearch);
                status = editStudent(searchtype, idsearch, namesearch);
            }
            else if (searchtype == 2)
            {
                printf("enter name for student to be eddited:");
                scanf("%20s", &namesearch);
                status = editStudent(searchtype, idsearch, namesearch);
            }
            if (status == School_Empty)
            {
                printf("the school is Empty add some students first!!\n");
            }
            else if (status == OP_Done)
            {
                printf("Edit is Done!\n");
            }
            else if (status == OP_Failed)
            {
                printf("Something went wrong please try again :)\n");
            }
        }
        else if (option == 3)
        {
            if (isEmpty() == School_Empty)
            {
                printf("the school is Empty add some students first!!\n");
            }
            else
            {
                printf("enter student ID: \n");
                scanf("%d", &idsearch);
                student_print(idsearch);
            }
        }
        else if (option == 4)
        {
            printf("Would you like to search for the student by id or name: 1-id or 2-name \n");
            scanf("%d", &searchtype);
            while (searchtype != 1 && searchtype != 2)
            {
                printf("please choose a valid option from (1 or 2)\n ");
                scanf("%d", &searchtype);
            }
            if (searchtype == 1)
            {
                printf("enter id for student to be deleted:");
                scanf("%d", &idsearch);
                status = deleteStudent(searchtype, idsearch, namesearch);
            }
            else if (searchtype == 2)
            {
                printf("enter name for student to be deleted:");
                scanf("%20s", &namesearch);
                status = deleteStudent(searchtype, idsearch, namesearch);
            }
            if (status == School_Empty)
            {
                printf("the school is Empty add some students first!!\n");
            }
            else if (status == OP_Done)
            {
                printf("Delete is Done!\n");
            }
            else if (status == OP_Failed)
            {
                printf("Something went wrong please try again :)\n");
            }
        }
        else if (option == 5)
        {
            student_SchoolPrint();
        }
        else if (option == 6)
        {
            printf("Would you like to search for the student by id or name: 1-id or 2-name \n");
            scanf("%d", &searchtype);
            while (searchtype != 1 && searchtype != 2)
            {
                printf("please choose a valid option from (1 or 2)\n ");
                scanf("%d", &searchtype);
            }
            if (searchtype == 1)
            {
                printf("enter id for student to be called:");
                scanf("%d", &idsearch);
                status = callStudent(searchtype, idsearch, namesearch);
            }
            else if (searchtype == 2)
            {
                printf("enter name for student to be called:");
                scanf("%20s", &namesearch);
                status = callStudent(searchtype, idsearch, namesearch);
            }
            if (status == School_Empty)
            {
                printf("the school is Empty add some students first!!\n");
            }
        }
    }

    return 0;
}
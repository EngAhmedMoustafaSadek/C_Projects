#include "school.h"

static int student_Count = 0;
static stud_t school[School_Max_size];

OP_Status isFull(void)
{
    if (student_Count == School_Max_size)
    {
        return School_Full;
    }
    return OP_Done;
}
OP_Status isEmpty(void)
{
    if (student_Count == 0)
    {
        return School_Empty;
    }
    return OP_Done;
}
void scanPhone(char *phone)
{
    int i, flag = 0;
    for (i = 2; i < 11 && flag == 0; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
        {
            printf("Error: phone number must contain only digits\n");
            flag = 1;
        }
    }
    while (string_len(phone) != 11 || (phone[0] != '0' || phone[1] != '1') || flag == 1)
    {
        flag = 0;
        printf("Error: phone number must have 11 digits and start with 01 // enter a valid number :\n");
        scanf("%s", phone);
        for (i = 2; i < 11 && flag == 0; i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                printf("Error: phone number must contain only digits\n");
                flag = 1;
            }
        }
    }
    printf("Phone number is valid: %s\n", phone);
}

void student_print(int id)
{
    printf("ID: %d    name:%20s", school[id].id, school[id].student.name);

    printf("  age:%2d   grade:%c ", school[id].student.age, school[id].grade);
    printf("  phone: %s\n", school[id].student.phone);
    printf("Father's name: %20s   age:%2d  phone: %s\n", school[id].father.name, school[id].father.age, school[id].father.phone);
    printf("Mother's name: %20s   age:%2d  phone: %s\n", school[id].mother.name, school[id].mother.age, school[id].mother.phone);
    printf("Number of brothers: %d and they are :\n", school[id].numberOfBrothers);
    for (int i = 0; i < school[id].numberOfBrothers; i++)
    {
        printf("Brother name: %20s   age:%2d  phone: %s\n", school[id].brothers[i].name, school[id].brothers[i].age, school[id].brothers[i].phone);
    }
}

/*void student_printByAddress(const stud_t *ps)
{
    // ps->age=50;
    printf("name:%20s", (*ps).student.name);

    printf("   age:%2d   grade:%c\n", ps->student.age, ps->grade);
}*/

OP_Status addStudent(void)
{
    int status = OP_Failed;
    stud_t *s = &school[student_Count];

    if (isFull() == School_Full)
    {
        status = School_Full;
    }
    else
    {
        s->id = student_Count;
        printf("enter name:");
        scanf("%20s", &s->student.name);
        printf("enter age:");
        scanf("%d", &s->student.age);
        printf("enter grade:");
        scanf(" %c", &s->grade);
        printf("enter students phone:");
        scanf("%s", &s->student.phone);
        scanPhone(s->student.phone);
        printf("enter father's name:");
        scanf("%20s", &s->father.name);
        printf("enter father's age:");
        scanf("%d", &s->father.age);
        printf("enter father's phone:");
        scanf("%s", &s->father.phone);
        scanPhone(s->father.phone);
        printf("enter mother's name:");
        scanf("%20s", &s->mother.name);
        printf("enter mother's age:");
        scanf("%d", &s->mother.age);
        printf("enter mother's phone:");
        scanf("%s", &s->mother.phone);
        scanPhone(s->mother.phone);
        printf("enter number of brothers:");
        scanf("%d", &s->numberOfBrothers);
        s->brothers = (person_t *)malloc(s->numberOfBrothers * sizeof(person_t));
        for (int j = 0; j < s->numberOfBrothers; j++)
        {
            printf("enter brother's name:");
            scanf("%20s", &s->brothers[j].name);
            printf("enter brother's age:");
            scanf("%d", &s->brothers[j].age);
            printf("enter brother's phone:");
            scanf("%s", &s->brothers[j].phone);
            scanPhone(s->brothers[j].phone);
        }
        status = OP_Done;
        student_Count++;
    }

    return status;
}

void student_SchoolPrint(void)
{
    if (isEmpty() == School_Empty)
    {
        printf("The school is EMPTY add some students first!\n");
    }
    else
    {
        printf("  ID              Name     Age   Grade    Phone\n\n");
        for (int i = 0; i < student_Count; i++)
        {
            printf("  %2d    %15s", school[i].id, school[i].student.name);

            printf("    %2d    %c ", school[i].student.age, school[i].grade);
            printf("   %s\n", school[i].student.phone);
        }
    }
}

void student_selectionSort_byAge(void)
{
    int i, j, last = student_Count - 1, max_i;
    stud_t temp;
    if (isEmpty() != School_Empty)
    {
        for (j = 0; j < student_Count; j++)
        {
            temp = school[0];
            max_i = 0;
            for (i = 0; i < student_Count - j; i++)
            {
                if (school[i].student.age > school[max_i].student.age)
                {
                    max_i = i;
                }
            }
            temp = school[last - j];
            school[last - j] = school[max_i];
            school[max_i] = temp;
        }
    }
}
void student_selectionSort_byName(void)
{
    int i, j, last = student_Count - 1, max_i;
    stud_t temp;
    if (isEmpty() != School_Empty)
    {
        for (j = 0; j < student_Count; j++)
        {
            temp = school[0];
            max_i = 0;
            for (i = 0; i < student_Count - j; i++)
            {
                if (string_compare_Sort(school[i].student.name, school[max_i].student.name) == 1)
                {
                    max_i = i;
                }
            }
            temp = school[last - j];
            school[last - j] = school[max_i];
            school[max_i] = temp;
        }
    }
}
void student_selectionSort_byGrade(void)
{
    int i, j, last = student_Count - 1, max_i;
    stud_t temp;
    if (isEmpty() != School_Empty)
    {
        for (j = 0; j < student_Count; j++)
        {
            temp = school[0];
            max_i = 0;
            for (i = 0; i < student_Count - j; i++)
            {
                if (school[i].grade >= 'a' && school[i].grade <= 'z')
                {
                    school[i].grade += 'A' - 'a';
                }
                if (school[i].grade > school[max_i].grade)
                {
                    max_i = i;
                }
            }
            temp = school[last - j];
            school[last - j] = school[max_i];
            school[max_i] = temp;
        }
    }
}
int find_oldestStudent(void)
{
    int i, maxAgeIndex = 0;
    for (i = 0; i < student_Count; i++)
    {
        if (school[i].student.age > school[maxAgeIndex].student.age)
        {
            maxAgeIndex = i;
        }
    }
    return maxAgeIndex;
}
int find_highestGradeStudent(void)
{
    int i, maxGradeIndex = 0;
    for (i = 0; i < student_Count; i++)
    {
        if (school[i].grade >= 'a' && school[i].grade <= 'z')
        {
            school[i].grade += 'A' - 'a';
        }
        if (school[i].grade < school[maxGradeIndex].grade)
        {
            maxGradeIndex = i;
        }
    }
    return maxGradeIndex;
}

OP_Status editStudent(int x, int id, char *name)
{
    int status = OP_Failed;
    int index;
    int option;

    if (isEmpty() == School_Empty)
    {
        status = School_Empty;
    }
    else
    {
        index = searchStudent(x, id, name);
        stud_t *s = &school[index];
        if (index != -1)
        {
            printf("choose editing option: 1-complete edit to all attributes of the student.\n 2-edit student age.\n 3-student grade.\n 4- student phone.\n");
            scanf("%d", &option);
            if (option == 1)
            {
                printf("enter name:");
                scanf("%20s", &s->student.name);
                printf("enter age:");
                scanf("%d", &s->student.age);
                printf("enter grade:");
                scanf(" %c", &s->grade);
                printf("enter students phone:");
                scanf("%s", &s->student.phone);
                scanPhone(s->student.phone);
                printf("enter father's name:");
                scanf("%20s", &s->father.name);
                printf("enter father's age:");
                scanf("%d", &s->father.age);
                printf("enter father's phone:");
                scanf("%s", &s->father.phone);
                scanPhone(s->father.phone);
                printf("enter mother's name:");
                scanf("%20s", &s->mother.name);
                printf("enter mother's age:");
                scanf("%d", &s->mother.age);
                printf("enter mother's phone:");
                scanf("%s", &s->mother.phone);
                scanPhone(s->mother.phone);
                printf("enter number of brothers:");
                scanf("%d", &s->numberOfBrothers);
                s->brothers = (person_t *)malloc(s->numberOfBrothers * sizeof(person_t));
                for (int j = 0; j < s->numberOfBrothers; j++)
                {
                    printf("enter brother's name:");
                    scanf("%20s", &s->brothers[j].name);
                    printf("enter brother's age:");
                    scanf("%d", &s->brothers[j].age);
                    printf("enter brother's phone:");
                    scanf("%s", &s->brothers[j].phone);
                    scanPhone(s->brothers[j].phone);
                }
                status = OP_Done;
            }
            else if (option == 2)
            {
                printf("enter student's new age: ");
                scanf("%d", &s->student.age);
                status = OP_Done;
            }
            else if (option == 3)
            {
                printf("enter student's new grade: ");
                scanf(" %c", &s->grade);
                status = OP_Done;
            }
            else if (option == 4)
            {
                printf("enter student's new phone:");
                scanf("%s", &s->student.phone);
                scanPhone(s->student.phone);
                status = OP_Done;
            }
        }
    }
    return status;
}
int searchStudent(int x, int id, char *name)
{
    int searched_index = -1;

    if (x == 1) // search by id
    {
        searched_index = id;
    }
    else if (x == 2) // search by name
    {
        for (int j = 0; j < student_Count; j++)
        {
            if (string_compare_Identical(school[j].student.name, name) == 1)
            {
                searched_index = j;
                break;
            }
        }
    }

    return searched_index;
}
OP_Status deleteStudent(int x, int id, char *name)
{
    int status = OP_Failed;
    int index;
    if (isEmpty() == School_Empty)
    {
        status = School_Empty;
    }
    else
    {
        index = searchStudent(x, id, name);
        if (index != -1)
        {
            for (int j = index; j < student_Count; j++)
            {
                school[j] = school[j + 1];
            }
            student_Count--;
            status = OP_Done;
        }
    }
    return status;
}
OP_Status callStudent(int x, int id, char *name)
{
    int index = searchStudent(x, id, name);
    int status = OP_Failed;
    if (isEmpty() == School_Empty)
    {
        status = School_Empty;
    }
    else
    {
        if (index != -1)
        {

            printf("calling %20s on %s !!!\n", school[index].student.name, school[index].student.phone);
            for (int j = 0; j < 2; j++)
            {
                fflush(stdout);
                printf("\r. . . . . .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r  . . . . .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r.  . . . .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r. .  . . .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r. . .  . .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r. . . .  .!");
                sleep(1); // pause for 1 second
                fflush(stdout);
                printf("\r. . . . .  !");
            }
            printf("Call is DONE!!\n");
            status = OP_Done;
        }
    }
    return status;
}
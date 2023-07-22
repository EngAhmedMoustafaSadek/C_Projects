#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define School_Max_size 50
typedef struct
{
    char name[20];
    int age;
    char phone[12];
} person_t;

typedef struct
{
    person_t student;
    int id;
    char grade;
    person_t father;
    person_t mother;
    int numberOfBrothers;
    person_t *brothers;
} stud_t;

typedef enum
{
    OP_Done,
    OP_Failed,
    School_Full,
    School_Empty
} OP_Status;

int string_compare_Sort(char *str1, char *str2);
int string_compare_Identical(char *str1, char *str2);
int string_len(char *str);
void copyString(char *destination, char *source);
void student_print(int id);
void student_printByAddress(const stud_t *ps);
stud_t student_scan(void);
void student_scanByAddress(stud_t *ps);
void student_SchoolPrint(void);
void student_selectionSort_byAge(void);
void student_selectionSort_byName(void);
void student_selectionSort_byGrade(void);
int find_oldestStudent(void);
int find_highestGradeStudent(void);
OP_Status addStudent(void);
OP_Status editStudent(int x, int id, char *name);
int searchStudent(int x, int id, char *name);
OP_Status deleteStudent(int x, int id, char *name);
OP_Status callStudent(int x, int id, char *name);
OP_Status isEmpty(void);
OP_Status isFull(void);
void scanPhone(char *phone);
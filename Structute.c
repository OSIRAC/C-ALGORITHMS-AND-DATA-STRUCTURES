#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
    char *name;
    int age;
} person;

typedef struct Student
{
    int school_number;
    struct Person *p;
               
} student;

int main(){

    person a;
    a.age=12;
    a.name="Elma";
    student *std;
    
    std = (student*)malloc(sizeof(student));
    std->school_number = 21;
    std->p->age = 12;
    printf("%d",std->p->age);

    return 0;
}






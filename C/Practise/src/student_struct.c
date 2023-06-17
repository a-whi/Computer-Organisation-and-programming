#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char *fullName; // the * lets us dynamically allocated character array so it can be any length
    char number[11]; // Phone numbers have a length of 11
    char grades[32]; // 32 grades will be input so there will be an array of 32
    int birthYear; // The year will be a whole number
}Student;

// To add a student to the struct

Student *addStudent(const char *fullName, const char *phonenumber, int year){
    // Allocate memory for the Student struct
    Student *new_student = (Student *)malloc(sizeof(Student));
    
    // Allocate memory for the students namespace
    new_student->fullName = (char *)malloc(strlen(fullName)+1);
    strcpy(new_student->fullName, fullName);
    
    // Add their number to the struct
    strncpy(new_student->number, phonenumber,10);
    new_student->number[10] = '\0';
    
    // Add their birth year to the struct
    new_student->birthYear = year;
    
    //To make the grades array
    for (int i = 0; i < 32; i++){
        new_student->grades[i] = '0';
    }
    return new_student;
}

void free_student(Student *student){
    if (student != NULL){
        free(student->fullName); // Free the name
        free(student); // Free the struct
    }
}


int main(){

    // Example adding of student to the struct
    Student *student1 = addStudent("Tony Flock", "0411232435", 2001);
    
    // Free the memory
    free_student(student1);
    return 0;
}
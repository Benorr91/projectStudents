#pragma once
#ifndef Student_H
#define Student_H
#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "grades.csv" 
#define FILENAME2 "grades_test.csv" 
//#include "globalHeader.h"
#include "validationHeader.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
//
////include for libaries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>//For linux System 'strdup' without  _ 
#include "Qeury_Header.h"
//struct && typedef && enum


typedef enum
{
	true = 1,
	false = 0
}bool;

typedef struct student_detailes
{


	int CS_Fundamentals;
	int Computer_Networks;
	int C_language;
	bool fix;
	struct student_detailes* next;
	float avg;
	char ID[10];
	char* error;
	char first_name[30];
	char last_name[30];

}student_detailes;


void insert_to_sort_list(student_detailes** head_list, student_detailes* newStudent_detailesNode);
student_detailes* creat_new_student(char* ID, char* first_name, char *last_name, int* Cours,int* grage,int* flag);
int Valid_Cours(void* val);
void calc_avg(student_detailes* s);
void init_err(student_detailes* newStudent, char* err);
student_detailes* read_from_file(student_detailes** head_err);
student_detailes* init_student_from_file(char* line,int *flag);
int search_Student(student_detailes* head, student_detailes* Student, int course);
void update_Student(student_detailes* Student, student_detailes* new_Student, int course);
void free_student(student_detailes** Student);
void free_list(student_detailes** head);
void printlist(student_detailes* head,void (*print_func)(student_detailes* Curr));
void printStudent(student_detailes* Curr);
void printStudentErr(student_detailes* Curr);
void serchStudentByFirstNameEqule(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByFirstNameBigger(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByFirstNameSmaller(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByFirststNameNot(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByLastNameEqule(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByLastNameBigger(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByLastNameSmaller(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByLastNameNot(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2));
void serchStudentByIDEqule(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2));
void serchStudentByIDBigger(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2));
void serchStudentByIDSmaller(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2));
void serchStudentByIDNot(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2));
void serchStudentByCourseEqule(student_detailes* head, int Course, char*grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByCourseBigger(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByCourseSmaller(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByCourseNot(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByAvgEqule(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByAvgNot(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByAvgBigger(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
void serchStudentByAvgSmaller(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2));
student_detailes* set_qurey(char* line, int* flag);
void readlistToFile(student_detailes* new_student , FILE* fp);

int cmpFun(void* val1, void* val2);
#endif






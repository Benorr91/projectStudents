#pragma once

#define Global_H
#define _CRT_SECURE_NO_WARNINGS

#include "studentHeader.h"
#include <stdio.h>
#define CHUNK 10
#include <stdlib.h>
#include <string.h>


enum COURSES {
	C_language = 0,
	Computer_Networks = 1,
	CS_Fundamentals = 2

};

enum CASE {
	PRINT_LIST = 0,
	PRINT_ERROR = 1,
	SELECT = 2,
	SET = 3,
	DELETE = 4,
	QUIT=-2

};
enum STUDENT_ARG {
	first_name = 0,
	last_name = 1,
	ID = 2,
	course = 3,
	avg = 4,
};

//typedef enum
//{
//	true = 1,
//	false = 0
//}bool;

void printHeader();
int checkCours(char* line);
void Fun_print_str(char* val);
void toUpperCase(char* str);
char* read_input_no_limit(FILE* fp, int stdinS);
void Fun_print_str(char* val);
int print_menu(char **input);
void delete_space(char **input);
void print_Table_Title();
int cmpFunNum(void* val1, void* val2);
int cmpFunAvg(void* val1, void* val2);

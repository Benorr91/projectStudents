#pragma once
#ifndef Query_Header
#define Query_Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//For linux System 'strdup' without  _ 


int select_Query(char* line, char** valueCopmare, int* operatorSign);
int cheackOperator(char* line);

#endif
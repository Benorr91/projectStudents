#include "validationHeader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globalHeader.h"

int Valid_grade(void* val) {
	int* num = (int*)val;
	return ( * num >= 0 && *num <= 100);
}

int Valid_Cours(void* val) {
	int* Cours = (int*)val;
	return *Cours >= 0 && *Cours <= 3;
}


int only_num(char* str) {

	while (*str) {
		if (*str < '0' || *str > '9')
			return 0;
		str++;
	}
	return 1;
}

int only_char(char* str) {

	while (*str) {
		if (( * str < 'A' || *str > 'Z') && *str != ' ')
			return 0;
		str++;
	}
	return 1;
}

int validID(char* str) {
	
	return (only_num(str)) && (strlen(str) == 9);
}


int check_input_valid(char* str) {

	if (strstr(str, "SET")) {
		
		if (strstr(str, "FIRST ") && strstr(str, "NAME") && strstr(str, "LAST ") && strstr(str, "ID") && checkCours(str) != -1 ) {
			return 1;
		}
	}
	else if (strstr(str, "SELECT")) {

		if (strstr(str, "FIRST ") || strstr(str, "NAME") || strstr(str, "LAST ")  || strstr(str, "ID") || checkCours(str) != -1|| strstr(str, "AVERAGE ")) {
			return 1;
		}
	}
	else if (strstr(str, "PRINT") || strstr(str, "PRINT ERR") || strstr(str, "QUIT")) {
		return 1;
	}
	
	return -1;

}
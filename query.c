#include "Qeury_Header.h"
#include "globalHeader.h"
#include "studentHeader.h"

//return int 0 if first name 1 for last name 2 for id i

int select_Query(char* line,char** valueCopmare,int *operatorSign){
	if (line == NULL) {
		return NULL;
	}
	char* token = NULL;
	if (strstr(line, "FIRST") && strstr(line, "NAME")) {
		switch (cheackOperator(line))
		{
		case 0:
			*operatorSign = 0;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				break;;
			}
			
			strcpy(*valueCopmare, token);
			break;
		case 1:
			*operatorSign = 1;
			token = strtok(line, "=");
			if (token == NULL) {
				break;;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				break;;
			}
			strcpy(*valueCopmare, token);
			break;

		case 2:
			*operatorSign = 2;
			token = strtok(line, ">");
			if (token == NULL) {
				break;;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 3:
			*operatorSign = 3;
			token = strtok(line, "<");
			if (token == NULL) {
				break;;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		default:
			break;
		} ;

		return 0;
	}
	if (strstr(line, "LAST") && strstr(line, "NAME")) {
		switch (cheackOperator(line))
		{
		case 0:
			*operatorSign = 0;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				break;
			}
			strcpy(*valueCopmare, token);
			break;
		case 1:
			*operatorSign = 1;
			token = strtok(line, "=");
			if (token == NULL) {
				
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				break;
			}
			strcpy(*valueCopmare, token);
			break;

		case 2:
			*operatorSign = 2;
			token = strtok(line, ">");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 3:
			*operatorSign = 3;
			token = strtok(line, "<");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		default:
			break;
		};
		return 1;
	}
	if (strstr(line, "ID") ) {
		switch (cheackOperator(line))
		{
		case 0:
			*operatorSign = 0;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		case 1:
			*operatorSign = 1;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 2:
			*operatorSign = 2;
			token = strtok(line, ">");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 3:
			*operatorSign = 3;
			token = strtok(line, "<");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		default:
			break;
		};
		return 2;
	}
	if (checkCours(line)!=-1) {
		switch (cheackOperator(line))
		{
		case 0:
			*operatorSign = 0;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		case 1:
			*operatorSign = 1;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 2:
			*operatorSign = 2;
			token = strtok(line, ">");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 3:
			*operatorSign = 3;
			token = strtok(line, "<");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		default:
			break;
		};
		return 3;
	}
	if (strstr(line, "AVERAGE")) {
		switch (cheackOperator(line))
		{
		case 0:
			*operatorSign = 0;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		case 1:
			*operatorSign = 1;
			token = strtok(line, "=");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 2:
			*operatorSign = 2;
			token = strtok(line, ">");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;

		case 3:
			*operatorSign = 3;
			token = strtok(line, "<");
			if (token == NULL) {
				break;
			}
			token = strtok(NULL, "\n");
			if (token == NULL) {
				break;
			}
			delete_space(&token);
			*valueCopmare = (char*)malloc(strlen(token) + 1);
			if (*valueCopmare == NULL) {
				return NULL;
			}
			strcpy(*valueCopmare, token);
			break;
		default:
			break;
		};
		return 4;
	}
	return -1;


}
//0-> !=  1->= 2-> > 3-> < 

int cheackOperator(char* line) {
	if (strstr(line, "!=")) {
		return 0;
	}
	else if (strstr(line, "=")) {
		return 1;
	}
	else if (strstr(line, ">")) {
		return 2;
	}
	else if (strstr(line, "<")) {
		return 3;
	}

	return -1;


}


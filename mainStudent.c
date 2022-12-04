#include "globalHeader.h"
#include "studentHeader.h"
#include "validationHeader.h"
#include "Qeury_Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	student_detailes* head = NULL;
	student_detailes* headError = NULL;
	int a = 100;
	int b = 0;
	int flag = 0;
	printHeader();
	head = read_from_file(&headError);
	int if_exsit = 0;
	if (head) {
		printlist(head, printStudent);
		printf("\n\n");
	}

	if (headError) {
		printlist(headError, printStudentErr);
		printf("\n\n");
	}
	student_detailes* new_student = NULL;
	int res = 0;
	char* input = NULL;
	char* valueCopmare = NULL;
	int operatorSign = 0;
	int cours = 0;
	while (res != -1)
	{
		res = print_menu(&input);
		cours = checkCours(input);
		switch (res)
		{
		case 0:
			if (head ) {


				printlist(headError, printStudentErr);
			}

			else
				printf("Empty List\n");
			break;
		case 1:
			if (headError) {

				printlist(head, printStudent);
			}
			else {
				printf("Empty List\n");
			}
			break;

		case 2:
			if (head ) {

				print_Table_Title();
				switch (select_Query(input, &valueCopmare, &operatorSign))
				{//first name
				case 0:
					switch (operatorSign)
					{
					case 0:
						serchStudentByFirststNameNot(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByFirstNameEqule(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByFirstNameBigger(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByFirstNameSmaller(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					default:
						break;
					}

					break;
					//last name
				case 1:
					switch (operatorSign)
					{
					case 0:
						serchStudentByLastNameNot(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByLastNameEqule(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByLastNameBigger(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByLastNameSmaller(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					default:
						break;
					}
					break;
					//ID
				case 2:
					switch (operatorSign)
					{
					case 0:
						serchStudentByIDNot(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByIDEqule(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByIDBigger(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByIDSmaller(head, valueCopmare, cmpFun);
						free(valueCopmare);
						break;
					default:
						break;
					}

					break;
					//cours
				case 3:

					switch (operatorSign)
					{
					case 0:
						serchStudentByCourseNot(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByCourseEqule(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByCourseBigger(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByCourseSmaller(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					default:
						break;
					}

					break;
					//avg	
				case 4:
					switch (operatorSign)
					{
					case 0:
						serchStudentByAvgNot(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByAvgEqule(head, cours, valueCopmare, cmpFunAvg);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByAvgBigger(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByAvgSmaller(head, cours, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					default:
						break;
					}
					break;
				}

			}
			break;
		case 3:

			
				new_student = set_qurey(input, &flag);
				if (new_student->error) {
					printf("You insert student not valid!\n");
					printf("ERROR--> %s \n\n", new_student->error);
					printStudent(new_student);
					putc('\n',stdout);
					free(input);
					free_student(&new_student);
					continue;
				}
				if_exsit = search_Student(head, new_student, cours);
				if (if_exsit == 0) {
					insert_to_sort_list(&head, new_student);
					printf("new Student Added\n");
					printStudent(new_student);
				}
				else {
					printf("Student %s  %s %s Updated\n",new_student->first_name,new_student->last_name,new_student->ID);
				}
			

			break;



		case -2:
			printf("Bye Bye ,see you next time\n");
			res = -1;
			break;
		default:
			printf("Invalid query!! , please try again\n\n");
			break;
		}
		free(input);

	}
	FILE* fp = fopen(FILENAME, "w");
	if (fp == NULL)
	{
		printf("Error! Could not open file, check if the file already open ,and please close it ,and enter the query again ! \n");
		free_list(&head);
		free_list(&headError);
		return 0;

	}
	FILE* fp2 = fopen(FILENAME, "a+");
	if (fp == NULL)
	{
		printf("Error! Could not open file, check if the file already open ,and please close it ,and enter the query again ! \n");
		free_list(&head);
		free_list(&headError);
		return 0;

	}
	readlistToFile(head, fp);
	readlistToFile(headError, fp2);
	fclose(fp);
	fclose(fp2);
	free_list(&head);
	free_list(&headError);

}


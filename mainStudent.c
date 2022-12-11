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
	int courses = 0;
	while (res != -1)
	{
		res = print_menu(&input);
		courses = checkCours(input);
		switch (res)
		{
		case PRINT_LIST:
			if (head ) {


				printlist(headError, printStudentErr);
			}

			else
				printf("Empty List\n");
			break;
		case PRINT_ERROR:
			if (headError) {

				printlist(head, printStudent);
			}
			else {
				printf("Empty List\n");
			}
			break;

		case SELECT:
			if (head ) {

				print_Table_Title();
				switch (select_Query(input, &valueCopmare, &operatorSign))
				{//first name
				case first_name:
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
				case last_name:
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
				case ID:
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
				case course:

					switch (operatorSign)
					{
					case 0:
						serchStudentByCourseNot(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByCourseEqule(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByCourseBigger(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByCourseSmaller(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					default:
						break;
					}

					break;
					//avg	
				case avg:
					switch (operatorSign)
					{
					case 0:
						serchStudentByAvgNot(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 1:
						serchStudentByAvgEqule(head, courses, valueCopmare, cmpFunAvg);
						free(valueCopmare);
						break;
					case 2:
						serchStudentByAvgBigger(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					case 3:
						serchStudentByAvgSmaller(head, courses, valueCopmare, cmpFunNum);
						free(valueCopmare);
						break;
					default:
						break;
					}
					break;
				}

			}
			break;
		case SET:

			
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
				//search_StudentErr(headError, new_student);
				if_exsit = search_Student(head, new_student, courses);
				if (if_exsit == 0) {
					insert_to_sort_list(&head, new_student);
					printf("new Student Added\n");
					printStudent(new_student);
				}
				else {
					printf("Student Updated\n");
				}
			

			break;
			//delete from err
		case DELETE:
			printf("\n\nPlease Enter of the index you want to delete?\n");
			int num;
			if(scanf("%d", &num))
			 delete_student(headError, num);
			 getchar();

			break;
		case QUIT:
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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentHeader.h"
#include "globalHeader.h"



void insert_to_sort_list(student_detailes** head_list, student_detailes* newStudent_detailesNode) {
    if (*head_list == NULL)//if head is null set the head and the tail to be the new student
    {
        *head_list = newStudent_detailesNode;
        return;
    }

    if (strcmp(newStudent_detailesNode->last_name, (*head_list)->last_name) <= 0) {//Comparison of the new student's last name with the head of the list Returns a negative number once it is smaller
        newStudent_detailesNode->next= (*head_list);
        (*head_list) = newStudent_detailesNode;
        return;
    }

    student_detailes* prev =*head_list;

    while (prev->next &&(strcmp(newStudent_detailesNode->last_name, prev->next->last_name) > 0))//Move the pointer until before the student we want to insert the new student
    {
        prev = prev->next;
    }

    newStudent_detailesNode->next = prev->next;
    prev->next = newStudent_detailesNode;

}


student_detailes* creat_new_student(char* ID, char* first_name, char *last_name, int* Cours, int* grade,int* flag) {
    student_detailes* newStudent = (student_detailes*)calloc(1,sizeof(student_detailes));
    if (newStudent == NULL) {
        return NULL;
    }
     
   
        switch (*Cours)
        {
        case C_language:
            newStudent->C_language = *grade;
            newStudent->Computer_Networks = -1;
            newStudent->CS_Fundamentals = -1;

            break;
        case Computer_Networks:
            newStudent->Computer_Networks = *grade;
            newStudent->CS_Fundamentals = -1;
            newStudent->C_language = -1;

            break;
        case CS_Fundamentals:
            newStudent->CS_Fundamentals = *grade;
            newStudent->Computer_Networks = -1;
            newStudent->C_language = -1;

            break;
        default:
            newStudent->CS_Fundamentals = -2;
            newStudent->Computer_Networks = -2;
            newStudent->C_language = -2;
            break;
        }
    
    
    if (Valid_grade((void*)grade) == 0) {
        char error[] = "Not Valid grade";
        init_err(newStudent, error);

    }
    if (Valid_Cours((void*)Cours) == 0) {
        char error[] = "Not Valid Cours";
        init_err(newStudent, error);

    }

    if (validID(ID) == 0) {
        char error[] = "Not Valid ID";
        init_err(newStudent, error);

    }
    if (only_char(first_name) == 0) {
        char error[] = "Not Valid first name";
        init_err(newStudent, error);

    }
    if (only_char(last_name) == 0) {
        char error[] = "Not Valid last name";
        init_err(newStudent, error);

    }

    if (Valid_grade((void*)grade) ==0|| Valid_Cours((void*)Cours) == 0|| validID(ID) == 0 || only_char((void*)first_name) == 0||only_char((void*)last_name) == 0) {
        *flag = 0;
    }
    else {
        *flag = 1;
        newStudent->avg = (float)*grade;
        newStudent->error = NULL;
    }
    strcpy(newStudent->first_name, first_name);
    strcpy(newStudent->last_name, last_name);
    strcpy(newStudent->ID, ID);
  
    newStudent->next = NULL;
 
    return newStudent;

    

}



student_detailes* read_from_file(student_detailes** head_err) {
    student_detailes* head=NULL;
    int a = 0;
    int flag = 0;
    char file_name_temp[100] = { 0 };
    FILE* fp = fopen(FILENAME, "r");
    student_detailes* head_err_temp = *head_err;
    //case file not open asking the user to enter valid file
    while (fp == NULL)
    {
        printf("Error! Could not open file, probebly not exsits!\nEnter a valid name : ");
        if (scanf("%s*c", file_name_temp)) {
            fp = fopen(file_name_temp, "r");
        }
        
       a=getchar();
    }
    char* line = NULL;
    int index = 0;
    int i = 0;
    int course = 0;
    int if_exsit = 0;

 
    while (1)
    {
        i++;
        line = read_input_no_limit(fp, 0);
        if (*line == -52) {
            break;
        }
        toUpperCase(line);
        course =checkCours(line);
        student_detailes* new_student = init_student_from_file(line,&flag);
        if_exsit=search_Student(head, new_student, course);
        if (flag == 0) {
        
            insert_to_sort_list(&head_err_temp, new_student);
        }
        else if (if_exsit==0) {
       
             insert_to_sort_list(&head, new_student);
  
        }

        free(line);

    }

    *head_err = head_err_temp;
    return head;


}


int search_Student(student_detailes* head, student_detailes* Student,int course) {


    student_detailes* ptr = head;

    while (ptr)
    {

        if ((strcmp(ptr->ID, Student->ID) == 0) ) {
            update_Student(ptr,Student,course);
            return 1;
        }

        ptr = ptr->next;

    }
    return 0;
}
void update_Student(student_detailes* Student, student_detailes* new_Student, int course) {
  
    switch (course)
    {
     case C_language:
         if(new_Student->C_language!=-2)
            Student->C_language = new_Student->C_language;
         break;
     case CS_Fundamentals:
         if (new_Student->CS_Fundamentals != -2)
            Student->CS_Fundamentals = new_Student->CS_Fundamentals;
         break;
     case Computer_Networks:
         if (new_Student->CS_Fundamentals != -2)
            Student->Computer_Networks = new_Student->Computer_Networks;
         break;
    default:
        break;
    }
    strcpy(Student->last_name, new_Student->last_name);
    strcpy(Student->first_name, new_Student->first_name);
    calc_avg(Student);

    

}


student_detailes* init_student_from_file(char* line,int* flag) {

    char* ID=NULL;
    char* first_name=NULL;
    char* last_name=NULL;
    char* token = NULL;
    int course=0;
    int grade = 0;
    token = strtok(line, ",");
    first_name = token;
    token = strtok(NULL, ",");
    last_name = token;
    token = strtok(NULL, ",");
    ID = token;
    token = strtok(NULL, ",");
    course = checkCours(token);
    token = strtok(NULL, ",");
    if (only_num(token) == 0) {
        grade = -2;
    }
    else
    {
        grade = atoi(token);

    }
    return creat_new_student(ID, first_name, last_name, &course, &grade, flag);

}

void init_err(student_detailes* newStudent, char* err) {
    if (newStudent->error) {
        newStudent->error = (char*)realloc(newStudent->error, strlen(newStudent->error) + strlen(err) + 4);
        if (newStudent->error == NULL) {
            free(newStudent);
            return NULL;
        }
        strcat(newStudent->error, "&");
        strcat(newStudent->error, err);
        return;
    }
    newStudent->error = (char*)malloc(strlen(err) + 1);
    if (newStudent->error == NULL) {
        free(newStudent);
        return NULL;
    }
    strcpy(newStudent->error, err);
}


void free_student(student_detailes** Student) {
    
    free((*Student)->error);
    (*Student)->error = NULL;
    free(*Student);
}

void free_list(student_detailes** head) {
    student_detailes* prev = NULL;
    while (*head) {
        student_detailes* prev = *head;
        *head = (*head)->next;
        free_student(&prev);
    }

}
void printStudent(student_detailes* Curr) {
    printf("%-30s %-30s %10s %10d %20d %20d %15.2lf \n",Curr->last_name,Curr->first_name ,Curr->ID, Curr->C_language, Curr->Computer_Networks, Curr->CS_Fundamentals, Curr->avg);
}
void printStudentErr(student_detailes* Curr) {
    if (Curr->fix == 0) {
        printf("%-30s %-30s %10s %10d %20d %20d %15.2lf            yes\n\n", Curr->last_name, Curr->first_name,  Curr->ID, Curr->C_language, Curr->Computer_Networks, Curr->CS_Fundamentals, Curr->avg);
        printf("Error->%s\n\n", Curr->error);

    }
}
void printlist(student_detailes* head, void (*print_func)(student_detailes* Curr)) {
    print_Table_Title();
    while (head)
    {
        print_func(head);
        head = head->next;
    }

}



int cmpFun(void* val1, void* val2) {
    delete_space((char*)&val1);
    delete_space((char*)&val2);
    char* str1 = (char*)val1;
    char* str2 = (char*)val2;
    return strcmp(str1, str2);

}



void serchStudentByFirstNameEqule(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for(;  ptr; ptr=ptr->next)
    {
        if (cmpFun((void*)ptr->first_name, (void*)FirstName)==0) {
            printStudent(ptr);
        }
    }


}
void serchStudentByFirstNameBigger(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->first_name, (void*)FirstName) > 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByFirstNameSmaller(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->first_name, (void*)FirstName) < 0) {
            printStudent(ptr);
        }
    }

}

void serchStudentByFirststNameNot(student_detailes* head, char* FirstName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->first_name, (void*)FirstName) != 0) {
            printStudent(ptr);
        }
    }


}
void serchStudentByLastNameEqule(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->last_name, (void*)LastName) == 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByLastNameBigger(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->last_name, (void*)LastName) > 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByLastNameSmaller(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->last_name, (void*)LastName) < 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByLastNameNot(student_detailes* head, char* LastName, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->last_name, (void*)LastName) != 0) {
            printStudent(ptr);
        }
    }
}
///////////
void serchStudentByIDEqule(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->ID, (void*)ID) == 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByIDBigger(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->ID, (void*)ID) > 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByIDSmaller(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->ID, (void*)ID) < 0) {
            printStudent(ptr);
        }
    }

}
void serchStudentByIDNot(student_detailes* head, char* ID, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)ptr->ID, (void*)ID) != 0) {
            printStudent(ptr);
        }
    }
}
void serchStudentByAvgEqule(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)&ptr->avg, (void*)grade) == 0) {
            printStudent(ptr);
        }
    }
}
void serchStudentByAvgNot(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)&ptr->avg, (void*)grade) != 0) {
            printStudent(ptr);
        }
    }
}
void serchStudentByAvgBigger(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)&ptr->avg, (void*)grade) > 0) {
            printStudent(ptr);
        }
    }
}
void serchStudentByAvgSmaller(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        if (cmpFun((void*)&ptr->avg, (void*)grade) < 0) {
            printStudent(ptr);
        }
    }
}

void serchStudentByCourseEqule(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        switch (Course)
        {
        case C_language:
            if (cmpFun((void*)&ptr->C_language, (void*)grade) == 0) {
                printStudent(ptr);
            }
            break;
        case CS_Fundamentals:
            if (cmpFun((void*)&ptr->CS_Fundamentals, (void*)grade) == 0) {
                printStudent(ptr);
            }
            break;
        case Computer_Networks:
            if (cmpFun((void*)&ptr->Computer_Networks, (void*)grade) == 0) {
                printStudent(ptr);
            }
            break;
        default:
            break;
        }

    }

}
void serchStudentByCourseBigger(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        switch (Course)
        {
        case C_language:
            if (cmpFun((void*)&ptr->C_language, (void*)grade) > 0) {
                printStudent(ptr);
            }
            break;
        case CS_Fundamentals:
            if (cmpFun((void*)&ptr->CS_Fundamentals, (void*)grade) > 0) {
                printStudent(ptr);
            }
            break;
        case Computer_Networks:
            if (cmpFun((void*)&ptr->Computer_Networks, (void*)grade) > 0) {
                printStudent(ptr);
            }
            break;
        default:
            break;
        }

    }

}
void serchStudentByCourseSmaller(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        switch (Course)
        {
        case C_language:
            if ((ptr->C_language!=-1)&&cmpFun((void*)(&(ptr->C_language)), (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        case CS_Fundamentals:
            if ((ptr->CS_Fundamentals != -1) && cmpFun((void*)( &(ptr->CS_Fundamentals)), (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        case Computer_Networks:
            if ((ptr->Computer_Networks != -1) && cmpFun((void*)( & (ptr->Computer_Networks)), (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        default:
            break;
        }

    }

}

void serchStudentByCourseNot(student_detailes* head, int Course, char* grade, int (*cmpFun)(void* val1, void* val2)) {
    student_detailes* ptr = head;
    for (; ptr; ptr = ptr->next)
    {
        switch (Course)
        {
        case C_language:
            if (cmpFun((void*)&ptr->C_language, (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        case CS_Fundamentals:
            if (cmpFun((void*)&ptr->CS_Fundamentals, (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        case Computer_Networks:
            if (cmpFun((void*)&ptr->Computer_Networks, (void*)grade) < 0) {
                printStudent(ptr);
            }
            break;
        default:
            break;
        }

    }

}


student_detailes* set_qurey(char * line,int *flag) {
    //0->first name  2-> last name  3->ID 4->grade
    char* ar[3] = { NULL };
    char* token = NULL;
    int grade = 0;
    int cours = checkCours(line);
    if (strstr(line, "FIRST") && strstr(line, "NAME")) {
        token = strtok(line,"=");
        if (token == NULL) {
            return token;
        }
        token = strtok(NULL,",");
        if (token == NULL) {
            return token;
        }
        delete_space(&token);
        ar[0] = token;
    }
    
    token = strtok(NULL, "=");
    if (token == NULL) {
        return token;
    }
    if (strstr(token, "LAST") && strstr(token, "NAME")) {
        token = strtok(NULL, ",");
        if (token == NULL) {
            return token;
        }
        delete_space(&token);
        ar[1] = token;
    }
    token = strtok(NULL, "=");
    if (token == NULL) {
        return token;
    }
    if (strstr(token, "ID") ) {
        token = strtok(NULL, ",");
        if (token == NULL) {
            return token;
        }
        delete_space(&token);
        ar[2] = token;
    }
    token = strtok(NULL, "=");
    if (token == NULL) {
        return token;
    }
    token = strtok(NULL, "\n");
    if (token == NULL) {
        return token;
    }
    delete_space(&token);
    if (only_num(token) == 0) {
        grade = -2;
    }
    else
    {
        grade = atoi(token);

    }

    return creat_new_student(ar[2], ar[0], ar[1], &cours, &grade, flag);


}
void calc_avg(student_detailes* s) {
    float sum = 0;
    int counter = 0;
    if (s->Computer_Networks != -1) {
        sum +=(float) s->Computer_Networks;
        counter++;
    }
    if (s->C_language != -1) {
        sum += (float)s->C_language;
        counter++;
    }
    if (s->CS_Fundamentals != -1) {
        sum += (float)s->CS_Fundamentals;
        counter++;
    }
    if (counter > 0) {
        s->avg = sum / counter;
    }
    
}


//A function that receives a list and prints it to a file when a student is updated or a new one is created
void readlistToFile(student_detailes* new_student, FILE* fp) {
    if (new_student == NULL) {
        return;
    }
    //goes over the list and print to file
    while (new_student->next)
    {
        if (new_student->C_language != -1)
            fprintf(fp, "%s,%s,%s,C language,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->C_language);
        if (new_student->Computer_Networks != -1)
            fprintf(fp, "%s,%s,%s,Computer Networks,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->Computer_Networks);
        if (new_student->CS_Fundamentals != -1)
            fprintf(fp, "%s,%s,%s,CS Fundamentals,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->CS_Fundamentals);

        new_student = new_student->next;
    }
    if (new_student->C_language != -1)
        fprintf(fp, "%s,%s,%s,C language,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->C_language);
    if (new_student->Computer_Networks != -1)
        fprintf(fp, "%s,%s,%s,Computer Networks,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->Computer_Networks);
    if (new_student->CS_Fundamentals != -1)
        fprintf(fp, "%s,%s,%s,CS Fundamentals,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->CS_Fundamentals);
   

}

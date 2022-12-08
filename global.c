#include "globalHeader.h"



int checkCours(char* line) {
    if (strstr(line, "FUNDAMENTALS") && strstr(line, "CS ")) {

        return CS_Fundamentals;
    }
    else if (strstr(line, "C ") && (strstr(line, "LANGUAGE"))) {

        return C_language;
    }
    else if (strstr(line, "COMPUTER ") && strstr(line, "NETWORKS")) {

        return Computer_Networks;
    }
    else
        return -1;

}
void Fun_print_str(char* val) {
    printf("%s\n", val);
}

void delete_space(char** str) {
    int i ;
    while (**str == ' ')(*str)++;
    for (i = strlen((*str)) - 1; (*str)[i] == ' '; i--);
    (*str)[++i] = '\0';
}

void printHeader() {

    printf("Welcome To Student's DB\n");
    printf("You can get information about a student by set and select queries\n");
    printf("You can print your student list if you Enter \"print\" and the Error list with \"print err\"\n");
    printf("You can delete student from the error list if you Enter \"delete\" and then give the index you want to delete \n");
    printf("Enter \"quit\" for exit! \n");
    printf("Student with -1 in is grade means that he didn't tested in this Cours\n");
    printf("For Example select average>50 OR set first name =Avi(Only letters!),  last name= Yakov (Only letters!), ID= 958478321 (9 numbers only! ), C language= 95 ( Between 0-100 ) \n\n");

}

//Going over all the letters of the string and turning them into capital letters

void toUpperCase(char* str) {

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
}


char* read_input_no_limit(FILE* fp, int stdinS)
{

    char* input = NULL;
    char tempbuf[CHUNK];
    unsigned char* tmp;
    size_t inputlen = 0, templen = 0;
    if (stdinS == 0) {
        do {//We will divide our string into segments and when we reach the last segment that has a \n or the length of the string is greater than less than the amount of the segment, we will return the line
            fgets(tempbuf, 10, fp);
            templen = strlen(tempbuf);

            tmp = (char*)realloc(input, inputlen + templen + 1);


            if (tmp == NULL)
            {
                return tmp;
            }
            
            input = tmp;
            strcpy(input + inputlen, tempbuf);//Moving the pointer to the end of the string to copy the new string there
            inputlen += templen;//The length scheme of the strings to allocate appropriate memory


        } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
    }
    else {
        do {//We will divide our string into segments and when we reach the last segment that has a \n or the length of the string is greater than less than the amount of the segment, we will return the line
            fgets(tempbuf, 10, stdin);//for the user 
            templen = strlen(tempbuf);
            tmp = (char*)realloc(input, inputlen + templen + 1);
            if (tmp == NULL)
            {

                return input;
            }
            else
                input = tmp;
            strcpy(input + inputlen, tempbuf);//Moving the pointer to the end of the string to copy the new string there
            inputlen += templen;//The length scheme of the strings to allocate appropriate memory


        } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
    }

    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    return input;
}
int print_menu(char **inputS) {
 
    printf("\n\nPlease Enter Your Query (Enter quit for quit): \n");
    printf("PROMPT--> ");
    *inputS = read_input_no_limit(NULL, 1);

    if (inputS == NULL) {
        return -1;
    }
    delete_space(&inputS);
    toUpperCase(*inputS);
    if (check_input_valid(*inputS) <=0) {
        return -3;
    }
    
    if (strstr(*inputS, "QUIT")) {    
        return -2;
    }
    if (strstr(*inputS, "PRINT ERR")) {
      
        return 0;
    }
    if (strstr(*inputS, "PRINT")) {
      
        return 1;
    }
    if (strstr(*inputS, "SELECT")) {
     
        return 2;
    }
    if (strstr(*inputS, "SET")) {

     
        return 3;
    }
    if (strstr(*inputS, "DELETE")) {


        return 4;
    }
  
    return -3;


}

int cmpFunNum(void* val1, void* val2) {
    char* str_num = (char*)val2;
    int b= atoi(str_num);
    int* num1 = (int*)val1;
    return *num1 - b;

}


int cmpFunAvg(void* val1, void* val2) {
    char* str_num = (char*)val2;
    float b = atof(str_num);
    float* num1 = (float*)val1;
    return *num1 - b;

}

void print_Table_Title() {
    printf("i  Last Name                      First Name                     ID               C Language    Computer Networks   CS Fundamentals     Average         Error\n");
    printf("-  ---------------------------    ---------------------------    -----------      ----------    -----------------   ----------------    ------------    ------------- \n\n\n");
}
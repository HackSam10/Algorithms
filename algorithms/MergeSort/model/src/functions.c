#include <stdio.h>
#include <regex.h>
#include <stdlib.h>


//Function prototypes

int arg_check(int argc); //check num args

int *fill_array(char **input, int NumArgs); //Validates and converts input user

int user_flag(char *flag); //check user flag

//enums
enum order{
    ORDER_ERROR, ASCENDING, DESCENDING 
};




int main(int argc, char *argv[]){

int NumArgs = 0, *array = NULL, index = 0, user_option = 0;

NumArgs = arg_check(argc);
array = fill_array(argv + 2, NumArgs); 
user_option = user_flag(argv[1]);

if(!user_option){
   free(array);
   return 1;
}


//deselvolver o algoritmo


for(index = 0; index < NumArgs; index++){
printf("%d ", array[index]);
}

putchar(10);
free(array);
return 0;
}




//check num args
int arg_check(int argc){

int NumArg = 0;    

if(argc < 3){
puts("Insufficient Arguments");
exit(1);
}

return NumArg = argc - 2;
}


//Validates and converts input user
int *fill_array(char **input, int NumArgs){

int *buffer = NULL, index = 0, status = 0;
char reg_exp[] = "^[0-9]{1,9}$";
regex_t cmp = {0};

if(!(buffer = (int *)calloc(NumArgs, sizeof(int)))){
puts("Error Allocating Memory");
exit(1);
    }

regcomp(&cmp, reg_exp, REG_EXTENDED);

while(index < NumArgs){
    if(status = regexec(&cmp, input[index], 0, NULL, 0)){
    puts("Invalid Arguments");
    free(buffer);
    regfree(&cmp);
    exit(1);
        }
buffer[index] = atoi(input[index]);
index++;
    }

regfree(&cmp);
return buffer;
}


//check user flag
int user_flag(char *flag){

int key = 0;

switch(*flag){

    case 'A':
    case 'a': {
              key = ASCENDING;
              break;
              }

    case 'D':
    case 'd': {
              key = DESCENDING;
              break;
              }
    
    default: {
             puts("Invalid Flag");
             key = ORDER_ERROR;
             break;
             }
    }

return key;
} 

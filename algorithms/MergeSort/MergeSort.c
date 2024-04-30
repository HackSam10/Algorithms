#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>


//Function prototypes

int arg_check(int argc); //check argc

int *fill_array(char **input, int NumArgs); //Validates and converts input user



int main(int argc, char *argv[]){

int NumArgs = 0, *array = NULL, index = 0;


NumArgs = arg_check(argc);
array = fill_array(argv + 2, NumArgs); 

//verificar a flag

//deselvolver o algoritmo


for(index = 0; index < NumArgs; index++){
printf("%d ", array[index]);
}

putchar(10);
free(array);
return 0;
}







//check argc
int arg_check(int argc){

int NumArg = 0;    

if(argc < 3){
puts("Insufficient Arguments");
exit(1);
}

return NumArg = argc - 2;
}



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




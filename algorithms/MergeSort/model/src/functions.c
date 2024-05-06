#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"



long int *input_parsing(char **input, int elements_size); //Validates and converts input user


//check num args
int arg_check(int argc){

int elements_size = 0;

if(argc < 3){
puts("Insufficient Arguments");
exit(1);
}

return elements_size = argc - 2;
}




//Validates and converts input user
long int *input_parsing(char **input, int elements_size){

long int *buffer = NULL;
int index = 0,status = 0;
char reg_exp[] = "^[0-9]{1,9}$";
regex_t cmp = {0};

if(!(buffer = (long int *)calloc(elements_size, sizeof(long int)))){
puts("Error Allocating Memory");
exit(1);
    }

regcomp(&cmp, reg_exp, REG_EXTENDED);

while(index < elements_size){
    if(status = regexec(&cmp, input[index], 0, NULL, 0)){
    puts("Invalid Arguments");
    free(buffer);
    regfree(&cmp);
    exit(1);
        }
buffer[index] = atol(input[index]);
index++;
    }

regfree(&cmp);
return buffer;
}




//check user flag
order_mode user_flag(char *input){

typedef struct token{
    char *token;
    order_mode value;
}token;

int index = 0, flag_size = 10;

token flag[] = {{"A", ASCENDING}, {"a", ASCENDING},
                {"D", DESCENDING}, {"d", DESCENDING},
                {"R", RANDOM_ASCENDING}, {"r", RANDOM_ASCENDING},
                {"ra", RANDOM_ASCENDING}, {"RA", RANDOM_ASCENDING},  
                {"rd", RANDOM_DESCENDING}, {"RD", RANDOM_DESCENDING}};


for(index = 0; index < flag_size; index++){

    if(!(strcmp(flag[index].token, input))) return flag[index].value;
}


return ORDER_ERROR;
} 




long int *array_build(char **input, int *elements_size, order_mode flag){

long int *ptr_buffer = NULL, array_size = 0, counter = 0;

if(flag == ASCENDING || flag == DESCENDING){

return input_parsing(input, *elements_size);
}

ptr_buffer = input_parsing(input, 1);
array_size = *ptr_buffer;
*ptr_buffer = 0;

if(!(ptr_buffer = (long int *)realloc(ptr_buffer, array_size * sizeof(long int)))){
puts("Error Allocating Memory");
exit(1);
    }

for(counter = 0; counter < array_size; couter++){
srand(times(NULL) + (counter / 2));
ptr_buffer[counter] = rand() % array_size;
 }

return ptr_buffer;
}












#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"



long int *input_parsing(char **input, int elements_size); //Validates and converts input user


//check num args
int arg_check(int argc){

int NumArgs = 0;

if(argc < 3){
puts("Insufficient Arguments");
exit(1);
}

return NumArgs = argc - 2;
}




//Validates and converts input user
long int *input_parsing(char **input, int elements_size){

long int *buffer = NULL;
int index = 0, status = 0;
char reg_exp[] = "^[0-9]{1,18}$"; //alterar para validar o tamanho de um long int
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

struct token{
    char *token;
    order_mode value;
};

int index = 0, flag_size = 10;

struct token flag[] = {{"A", ASCENDING}, {"a", ASCENDING},
                {"D", DESCENDING}, {"d", DESCENDING},
                {"R", RANDOM_ASCENDING}, {"r", RANDOM_ASCENDING},
                {"ra", RANDOM_ASCENDING}, {"RA", RANDOM_ASCENDING},  
                {"rd", RANDOM_DESCENDING}, {"RD", RANDOM_DESCENDING}};


for(index = 0; index < flag_size; index++){

    if(!(strcmp(flag[index].token, input))) return flag[index].value;
}

puts("Invalid Flag!");
return ORDER_ERROR;
} 



//Builds an array based on user input
long int *array_build(char **input, long int *elements_size, bool random_flag){

long int *ptr_buffer = NULL, array_size = 0, counter = 0;

if(!random_flag) return input_parsing(input, *elements_size);


ptr_buffer = input_parsing(input, 1);
array_size = *ptr_buffer;
*ptr_buffer = 0;

if(!(ptr_buffer = (long int *)realloc(ptr_buffer, array_size * sizeof(long int)))){
puts("Error Allocating Memory");
exit(1);
    }

for(counter = 0; counter < array_size; counter++){
srand(time(NULL) + ((counter + 1) / 2));
ptr_buffer[counter] = rand() % 101;
 }

*elements_size = array_size;
return ptr_buffer;
}




void print_array(long int *array, long int array_size, double exec_time, bool random_flag){

long int index = 0, minutes = 0, seconds = 0, milliseconds = 0;

if(!random_flag){
for(index = 0; index < array_size; index++){
printf("%li ", array[index]);
    }
putchar(10);
}

else{
    if(array_size > 4){
printf("%li, %li, %li...%li, %li\n", array[0], array[1], array[2],
                                      array[array_size - 2], 
                                      array[array_size - 1]);
    }
    else{

    for(index = 0; index < array_size; index++){
printf("%li ", array[index]);
    }

putchar(10);
        }



minutes = (long int)exec_time / 60;
seconds = (long int)exec_time % 60;
milliseconds = (long int)((exec_time - (minutes * 60 + seconds)) * 1000);

printf("The algorithm execution time is:\t %li min : %li sec : %li ms\n", minutes, seconds, milliseconds); 
    }

}






void create_random_number(long int *array, long int start, long int end){

long int aux_recursive = 0;

        if(start < end){
                       aux_recursive = end / 2;
                       create_random_number(array, start, aux_recursive);
                       procedimento_assincrono(array, start, aux_recursive);

                       create_random_number(array, aux_recursive + 1, end);
                       procedimento_assincrono(array, aux_recursive, end);
                       
                       }

}

#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "header.h"


typedef struct args_thread{
   long int *array;
   long int start, end; 
}args_thread;

typedef struct config_thread_loop{
    int max_thread;
    args_thread *args;
}config_thread_loop;




long int *input_parsing(char **input, int elements_size); //Validates and converts input user

bool create_random(long int *array, long int size);

config_thread_loop calculate_thread_loop(const long int number, const int max_thread, long int *array);

void *routines_threads(void *args);

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
char reg_exp[] = "^[0-9]{1,10}$"; 
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

create_random(ptr_buffer, array_size);

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
    
print_random(array, array_size);

minutes = (long int)exec_time / 60;
seconds = (long int)exec_time % 60;
milliseconds = (long int)((exec_time - (minutes * 60 + seconds)) * 1000);

printf("The algorithm execution time is:\t %li min : %li sec : %li ms\n", minutes, seconds, milliseconds); 
    }

}

//printf array random
void print_random(long int *array, long int array_size){

long int index = 0;

if(array_size > 4){
printf("%li, %li, %li...%li, %li.\n", array[0], array[1], array[2],
                                      array[array_size - 2], 
                                      array[array_size - 1]);
    }
    else{

    for(index = 0; index < array_size; index++){
printf("%li ", array[index]);
    }

putchar(10);
        }    
}




bool create_random(long int *array, long int size){

int counter = 0;
pthread_t threads[MAX_THREAD];
config_thread_loop config = {0};


config = calculate_thread_loop(size, MAX_THREAD, array);

for(counter = 0; counter < config.max_thread; counter++){

    pthread_create(&threads[counter], NULL, routines_threads, (void *)&config.args[counter]);
}


for(counter = 0; counter < config.max_thread; counter++){
    pthread_join(threads[counter] , NULL);
}

free(config.args);
return 0;
}





//calculates and sets threads arguments
config_thread_loop calculate_thread_loop(const long int number, const int max_thread, long int *array){

config_thread_loop config = {0};
long int buffer_calculator = 0, buffer_number = 0, save_number = 0, buffer_start = 0, buffer_end = 0;
long int remainder = 0;
int index = 0;

buffer_calculator = number / max_thread;
buffer_number = number;

if(!(config.args = (args_thread *)calloc(max_thread, sizeof(args_thread)))){
puts("Error Allocating Memory");
exit(1);
}


if(buffer_calculator <= NUMBERS_PER_THREAD){

    for(index = 0, buffer_start = 0, buffer_end = 0; 
        buffer_number > 0;
        index++, buffer_start = buffer_end){

        save_number = buffer_number;
        buffer_number -= NUMBERS_PER_THREAD;

        if(buffer_number > 0) buffer_end += NUMBERS_PER_THREAD;
        else buffer_end += save_number;

        config.args[index].start = buffer_start;
        config.args[index].end = buffer_end;
        config.args[index].array = array;
        config.max_thread++;
    }
}

else{

for(index = 0, buffer_start = 0, buffer_end = buffer_calculator;
    index < max_thread;
    index++){

        config.args[index].start = buffer_start;
        config.args[index].end = buffer_end;
        config.args[index].array = array;
        config.max_thread++;

        buffer_start = buffer_end;
        buffer_end += buffer_calculator;
         }

if((remainder = number % max_thread)){

   index--;
   config.args[index].end += remainder;

    }
}
return config;
}




void *routines_threads(void *args){

args_thread *ptr_args = (args_thread *)args;
long int index = 0;

printf("Criando do ponto %li até o %li\n", ptr_args->start, ptr_args->end);

for(index = ptr_args->start; index < ptr_args->end; index++){

srand(time(NULL) + ((index + 1) / 2));

ptr_args->array[index] = rand() % 100000;

}

return NULL;
}






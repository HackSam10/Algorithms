#ifndef HEADER_H
#define HEADER_H
#include <stdbool.h>

//enums
typedef enum order_mode{
    ORDER_ERROR, ASCENDING, DESCENDING, RANDOM_ASCENDING, RANDOM_DESCENDING
}order_mode;



//Function prototypes

int arg_check(int argc); //check num args

order_mode user_flag(char *input); //check user flag

long int *array_build(char **input, long int *elements_size, bool random_flag); //Builds an array based on user input

void print_array(long int *array, long int array_size, double exec_time, bool random_flag);

void print_random(long int *array, long int array_size); //print array random

#endif

#ifndef HEADER_H
#define HEADER_H

//enums
typedef enum order_mode{
    ORDER_ERROR, ASCENDING, DESCENDING, RANDOM_ASCENDING, RANDOM_DESCENDING
}order_mode;



//Function prototypes

int arg_check(int argc); //check num args

order_mode user_flag(char *input); //check user flag

long int *array_build(char **input, int *elements_size, order_mode flag); //Build array


#endif

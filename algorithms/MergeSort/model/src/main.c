#include <stdio.h>
#include <stdbool.h>
#include "header.h"





int main(int argc, char *argv[]){

long int *array = NULL, elements_size = 0, index = 0;
order_mode user_option = 0;
bool random_flag = NULL;

elements_size = arg_check(argc);
user_option = user_flag(argv[1]); 

if(!user_option) return 1;
random_flag = user_option == RANDOM_ASCENDING || user_option == RANDOM_DESCENDING;

array = array_build(argv + 2, &elements_size, user_option);


//desenvolver o bloco inline que marca o tempo de execução do algoritmo


//deselvolver o algoritmo

print_array(array, elements_size, exec_time, random_flag);

free(array);
return 0;
}






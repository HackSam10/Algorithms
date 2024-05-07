#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h> //apagar




int main(int argc, char *argv[]){

long int teste = 0, teste2 = 0; //apagar
long int *array = NULL, elements_size = 0, index = 0;
order_mode user_option = 0;
bool random_flag = false, ascending_flag = false;
struct timespec time_start = {0}, time_end = {0};
double exec_time = 0;

elements_size = arg_check(argc);
user_option = user_flag(argv[1]); 

if(!user_option) return 1;
random_flag = user_option == RANDOM_ASCENDING || user_option == RANDOM_DESCENDING;
ascending_flag = user_option == ASCENDING || user_option == RANDOM_ASCENDING;

array = array_build(argv + 2, &elements_size, random_flag);


//calls the algorithm and counts its execution time
if(random_flag){
    puts("Começa aqui em 2s");//apagar
    sleep(2);//apagar
clock_gettime(CLOCK_MONOTONIC_RAW, &time_start);

//call function here
for(teste2 = 0; teste2 < 1000; teste2++){//apagar
for(teste = 0; teste < elements_size; teste++){//apagar
    array[teste] -= 1;//apagar
}//apagar
}//apagar
clock_gettime(CLOCK_MONOTONIC_RAW, &time_end);
exec_time = (time_end.tv_sec - time_start.tv_sec) + ((time_end.tv_nsec - time_start.tv_nsec) / 1000000000.0);
}


//calls the algorithm without counting its execution time
else{


}



print_array(array, elements_size, exec_time, random_flag);
free(array);
return 0;
}

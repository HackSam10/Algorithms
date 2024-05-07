#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include "header.h"





int main(int argc, char *argv[]){

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
clock_gettime(CLOCK_MONOTOMIC_RAW, &time_start);

//call function here

clock_gettime(CLOCK_MONOTOMIC_RAW, &time_end);
exec_time = (time_end.tv_sec - time_start.tv_sec) + ((time_end.tv_nsec - time_start.tv_nsec) / 1000000000.0);
}


//calls the algorithm without counting its execution time
else{


}




print_array(array, elements_size, exec_time, random_flag);

free(array);
return 0;
}






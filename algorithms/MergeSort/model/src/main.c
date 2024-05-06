#include <stdio.h>
#include "header.h"





int main(int argc, char *argv[]){

long int array = NULL, elements_size = 0, index = 0;
order_mode user_option = 0;


elements_size = arg_check(argc);
user_option = user_flag(argv[1]); 

if(!user_option) return 1;


array = array_build(argv + 2, &elements_size, user_option);



//deselvolver o algoritmo


for(index = 0; index < elements_size; index++){
printf("%d ", array[index]);
}

putchar(10);
free(array);
return 0;
}






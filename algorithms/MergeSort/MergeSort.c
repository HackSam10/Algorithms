#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>


//Function prototypes

int arg_check(int argc);





int main(int argc, char *argv[]){

int NumArgs = 0;


NumArgs = arg_check(argc);

//alocar memoria
//fazer parsing
//verificar a flag

//deselvolver o algoritmo

printf("%d\n", NumArgs);
return 0;
}




int arg_check(int argc){

int NumArg = 0;    

if(argc < 3){
puts("Insufficient Arguments");
exit(1);
}

return NumArg = argc - 2;
}

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

void convercao(char *string[], int numeros[], int quantidade);

void SelectionSort(int entrada[], int tamanho);


int main(int argc, char *argv[]){

register int j = 0;
int *entrada = NULL;
int tamanho = argc - 1;
bool flag = 0;

if(argc < 3){
puts("O programa contém argumentos insuficientes.\n");
exit(1);
}


if(!(entrada = (int *)calloc(tamanho, sizeof(int)))){
puts("Erro ao alocar memória\n");
exit(1);
}

convercao(&argv[1], entrada, tamanho);

SelectionSort(entrada, tamanho);


for(j = 0; j < tamanho; j++){
	printf("%d ", entrada[j]);
}

puts("");
free(entrada);
return 0;
}



void convercao(char *string[], int numeros[], int quantidade){

register int j = 0;
int status = 1;
regex_t compilacao;
char er[] = "^[0-9]+$";

regcomp(&compilacao, er, REG_EXTENDED);

while(j < quantidade){

status = regexec(&compilacao, string[j], 0, NULL, 0);

if(status){
puts("Você digitou um argumento inválido.\n");
exit(1);
}

else numeros[j] = atoi(string[j]);

j++;

}

regfree(&compilacao);

}



void SelectionSort(int entrada[], int tamanho){


}




#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

void convercao(char *string[], int numeros[], int quantidade);

void InsertionSort(int entrada[], int tamanho, bool flag);


int main(int argc, char *argv[]){

register int j = 0;
int *entrada = NULL;
int tamanho = argc - 2;
bool flag = 0;

if(argc < 4){
puts("O programa contém argumentos insuficientes.\n");
exit(1);
}


if(!(entrada = (int *)calloc(tamanho, sizeof(int)))){
puts("Erro ao alocar memória\n");
exit(1);
}

switch(*argv[1]){

	case 'c':
	case 'C': {
			flag = 0;
			break;
		}
	case 'd':
	case 'D':{
			flag = 1;
			break;
		}

	default: {
		puts("Você escolheu um argumento inválido!\nPor favor, escolha (C) para Crescente ou (D) para Decrescente\n");
		exit(1);
		}
}

convercao(&argv[2], entrada, tamanho);


InsertionSort(entrada, tamanho, flag);




for(j = 0; j < tamanho; j++){
	printf("%d ", entrada[j]);
}

puts("\n");
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



//a flag passada como parametro para esta função não dara certo sem aumentar a complexidade
void InsertionSort(int entrada[], int tamanho, bool flag){

register int i = 0, j = 0;
int chave = 0;

for(j = 1; j < tamanho ;j++){

chave = entrada[j];
i = j - 1;

if(!flag){
while(i >= 0 && entrada[i] > chave){
entrada[i + 1] = entrada[i];
i--;
	}
}

else {
while(i >= 0 && entrada[i] < chave){
entrada[i + 1] = entrada[i];
i--;
	}
}
entrada[i + 1] = chave;
}


}

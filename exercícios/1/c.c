#include <stdio.h>
#include <stdlib.h>

#define erro \
puts("Argumento inválido, tente novamente mais tarde");\
exit(1)


int array[] = {10, 3, 5, 41, 60, 8, 14, 7, 2, 1};



//algoritmo de Busca em array.
int *BuscaLinear(int vetor[], size_t tamanho, int v);


int main(int argc, char *argv[]){
int v = 0;
int *retorno = NULL;
if(argc != 2){
erro;
}

v = atoi(argv[1]);

retorno = BuscaLinear(array, sizeof(array) / sizeof(int), v);


if(retorno) printf("O número esta armazenado no endereço %p, ou seja, na posição %d do array\n", (void*)retorno, (retorno - array) + 1);

else puts("O número indicado não esta presente no array, e o valor de retorno é NULL.");


return 0;
}



int *BuscaLinear(int vetor[], size_t tamanho, int v){
register int j = 0;

for( j = 0; j < tamanho; j++){

	if(vetor[j] == v) return &array[j];

}

return NULL;

}

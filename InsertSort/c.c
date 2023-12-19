#include <stdio.h>


void insert(int entrada[], size_t tam);


int main(void){
register int i = 0, K = 0;
int entrada[] = {5, 2 , 4, 6, 1, 3};


for( K = 0; K < 6; K++){

printf("%d ", entrada[K]);
}


puts("\n");



insert(entrada, sizeof(entrada) / sizeof(int));

/*
for( i = 0; i < 6; i++){

printf("%d\n", entrada[i]);

}
*/

return 0;
}



void insert(int entrada[], size_t tam){

register int j = 0, i = 0, K = 0;
int chave = 0;

for( j = 1; j < tam ; j++){

chave = entrada[j];
i = j - 1;


for( K = 0; K < 6; K++){
printf("%d ", entrada[K]);
}

printf("	i = %d j = %d chave = %d\n", i, j, chave);


while(i >= 0 && entrada[i] > chave){
entrada[i + 1] = entrada[i];
i--;
/*
for( K = 0; K < 6; K++){
printf("%d ", entrada[K]);
}

printf("	i = %d j = %d chave = %d\n", i, j, chave); */
	}


entrada[i + 1] = chave;
/*
for( K = 0; K < 6; K++){

printf("%d ", entrada[K]);
}
*/

puts("\n");

}


}

#include <stdio.h>
#include <stdlib.h>

#define linha 4
#define coluna 4

void soma(int matriza[][coluna], int matrizb[][coluna]){
	int i, j;
	int matrizc[linha][coluna];
	
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			matrizc[i][j] = (matriza[i][j] + matrizb[i][j]);
		}
	}
	
	printf("\n");
	printf("Matriz C(Soma): \n");
	for(i=0; i<linha; i++){
		printf("\n");
		for(j=0; j<coluna; j++){
			printf(" %d ", matrizc[i][j]);
		}
	}
	printf("\n");
	
}

void cria_matriz(int m[][coluna]){
	int i, j;
	
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			m[i][j] = rand()%99;
		}
	}
	
	
	
}

int main(){
	int i, j, matriza[linha][coluna], matrizb[linha][coluna];
	srand(time(NULL));
	
	cria_matriz(matriza);
	
	printf("Matriz A: \n");
	for(i=0; i<linha; i++){
		printf("\n");
		for(j=0; j<coluna; j++){
			printf(" %d ", matriza[i][j]);
		}
	}
	
	printf("\n");
	
	cria_matriz(matrizb);
	
	printf("\nMatriz B: \n");
	for(i=0; i<linha; i++){
		printf("\n");
		for(j=0; j<coluna; j++){
			printf(" %d ", matrizb[i][j]);
		}
	}
	
	printf("\n");
	
	soma(matriza, matrizb);
	
	return 0;
}

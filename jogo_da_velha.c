#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


#define linha 3
#define coluna 3

void imprimir (char matriz[][3]){
	int i, j;
	
	printf("    1  2  3\n");
	printf("    v  v  v\n");
	for(i=0; i<linha; i++){
		printf("   ---------\n");
		printf("%d> ", (i+1));
		for(j=0; j<coluna; j++){
			printf("|%c|", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int analisar_jogo(char matriz[][3]) {
	int i, j, contX = 0, contO = 0, contP = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(matriz[i][j] == 'X') {
				contX++;
			}
			if(matriz[i][j] == 'O') {
				contO++;
			}
		}
		
		if(contX == 3) {
			return 1;
		}else if(contO == 3) {
			return 2;
		} 
		contX = 0;
		contO = 0;
	}
	
	for(j = 0; j < 3; j++) {
		for(i = 0; i < 3; i++) {
			if(matriz[i][j] == 'X') {
				contX++;
			}
			if(matriz[i][j] == 'O') {
				contO++;
			}
		}
		
		if(contX == 3) {
			return 1;
		}else if(contO == 3) {
			return 2;
		}
		contX = 0;
		contO = 0;
	}
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(i == j) {
				if(matriz[i][j] == 'X') {
					contX++;
				}else if(matriz[i][j] == 'O') {
					contO++;
				}
			}
		}
	}
	if(contX == 3) {
			return 1;
	}else if(contO == 3) {
		return 2;
	}
	contX = 0;
	contO = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(i+j == 3-1) {
				if(matriz[i][j] == 'X') {
					contX++;
				}else if(matriz[i][j] == 'O') {
					contO++;
				}
			}
		}
	}
	if(contX == 3) {
		return 1;
	}else if(contO == 3) {
		return 2;
	}
	contX = 0;
	contO = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(matriz[i][j] == '.') {
				return 4;
			}
		}
	}
	
	return 3;
}

bool jogada_valida(char matriz[][3], char jogador, int l, int c) {
	if(l-1 < 0 || l-1 > 2) {
		return false;
	}else if(c-1 < 0 || c-1 > 2) {
		return false;
	}
	
	if(matriz[l-1][c-1] == '.') {
		matriz[l-1][c-1] = jogador;
	}else {
		return false;
	}
	
	return true;
}
	



int main(){
	setlocale(LC_ALL,"Portuguese");
	
	char matriz[linha][coluna], jogador;
	int i, j, z, l, c, k, valida, tentativa;
	tentativa = 0;
	
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			matriz[i][j] = '.';
		}
	}
	
	printf("--Jogo da velha!(Por Joaquim Pereira *TM)--\n");
	printf("\n");
	while(tentativa < 9){
		
		imprimir(matriz);
		
		if(tentativa%2==0){
			jogador = 'X';
		}
		else{
			jogador = 'O';
		}
		printf("\nJogador %c escolha a posição (linha e coluna respectivamente): ", jogador);
		scanf("%d%d",&l,&c);
		
		
		if(tentativa%2 == 0) {
			if(jogada_valida(matriz, 'X', l, c) == true) {
				jogada_valida(matriz, 'X', l, c);
				tentativa++;
			}else{
				printf("\nJOGADA INVÁLIDA!\n");
			}
		}else {
			if(jogada_valida(matriz, 'O', l, c) == true) {
				jogada_valida(matriz, 'O', l, c);
				tentativa++;
			}else{
				printf("\nJOGADA INVÁLIDA!\n");
			}
		}
		
		
			z = analisar_jogo(matriz);
		
		if(z == 1) {
			imprimir(matriz);
			printf("\nO jogador X ganhou!\n");
			break;
		}else if(z == 2) {
			imprimir(matriz);
			printf("\nO jogador O ganhou!\n");
			break;
		}
	}	
	
	if(z == 3) {
		printf("O jogo deu empate!");
	}
	
	return 0;
}

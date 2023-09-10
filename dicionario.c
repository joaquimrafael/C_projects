#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define linha 100
#define tamanho 1000


/*Projeto 2 - Dicion�rio de Samuel - Alogritmos e Programa��o II
Ci�ncia da Computa��o -  02G12 - Manh�
---------------------------------------------------------------------
C�digo feito por: Antonio Carlos Sciamarelli Neto RA: 42209935 &
Joaquim Rafael Mariano Prieto Pereira RA 42201731 &
Henrique �rabe Neres de Farias RA: 42246830
*/

// Fun��o para Busca Bin�ria
int busca_binaria(char matriz[][linha], int n, char palavra[]) {
	int i, inicio, fim, meio;
	inicio = 0;
	fim = n-1;

	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		
		int comparacao =  strcmp(matriz[meio],  palavra);
		if (comparacao == 0) {
			return meio;
		}
		else if (comparacao < 0) {
			inicio = meio+1;
		}
		else {
			fim = meio-1;
		}
	}
	
	return -1;
}

// Fun��o para Ordena��o da matriz de palavras
void ord(char matriz[][linha], int linhas) {
    int i, j;
    char temp[linha];

    for (i = 0; i < linhas - 1; i++) {
        for (j = 0; j < linhas - i; j++) {
            if (strcmp(matriz[j], matriz[j + 1]) > 0) {
                strcpy(temp, matriz[j]);
                strcpy(matriz[j], matriz[j + 1]);
                strcpy(matriz[j + 1], temp);
            }
        }
    }
}

// Fun��o para sele��o da palavra, verifica��o e contagem
void dic(FILE*arquivo, char matriz[][linha]) {
	char palavra[linha];
	int i, contadorPalavras;
	contadorPalavras = 0;
	while (fscanf(arquivo, "%s", palavra) != EOF) {
    	strlwr(palavra);
        if(busca_binaria(matriz, contadorPalavras, palavra) == -1) {
        	strcpy(matriz[contadorPalavras], palavra);
        	ord(matriz, contadorPalavras);
        	contadorPalavras++;
		}

        if (contadorPalavras == linha) {
            printf("Limite m�ximo de palavras atingido.\n");
            break;
        }
    }

    fclose(arquivo);
    
    for (i = 0; i < contadorPalavras; i++) {
        printf("%s\n", matriz[i]);
    }
    
    printf("\nTOTAL DE PALAVRAS: %d", contadorPalavras);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    char matrizPalavras[tamanho][linha];
    int i;

    FILE *arquivo;
    arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("DICION�RIO DE SAMUEL: \n");
    printf("\n");
    dic(arquivo, matrizPalavras);
    

    return 0;
}

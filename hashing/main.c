#include <stdio.h>
#include <stdlib.h>

#define TAM_MATRICULA 11
#define TAM_NOME 53
#define QTD_ALUNOS 25
#define NOME_ARQV "alunos.dat"

typedef struct {
	unsigned char matricula[TAM_MATRICULA], nome[TAM_NOME];
	//unsigned short int flag; // Não Ocupado = 0, Ocupado = 1 
}tAluno;

int main() {
//Declarações
	tAluno tempAlunos;
	FILE *arqvAlunos;
	unsigned int contQtd, qtdAlunos;
//Inicializações
	arqvAlunos = NULL;
	tempAlunos.matricula = '\0';
	tempAlunos.nome = '\0';
	qtdAlunos = 0;
//Instruções
	if((arqvAlunos = fopen(NOME_ARQV, "rb+")) == NULL){
		printf("\n*** ERRO AO ABRIR ARQUIVO! ***\n\n");
	}else{
		fseek(arqvAlunos, 0, SEEK_SET);
		/*if((pAlunos = (tAluno *) calloc(1, sizeof(tAluno))) == NULL){
			printf("*** ERRO AO ALOCAR MEMORIA! ****\n\n");
		}else{
			while(fread(pAlunos[qtdAlunos].matricula, (sizeof(char) * TAM_MATRICULA), 1, arqvAlunos) == 1){
				if((fread(pAlunos[qtdAlunos].nome, (sizeof(char) * TAM_NOME), 1, arqvAlunos)) != 1){
					printf("\n*** ERRO AO REALIZAR LEITURA! ***\n\n");
					break;
				}else{
					qtdAlunos++;
					pAlunos = (tAluno *) realloc(pAlunos, (qtdAlunos + 1) * sizeof(tAluno));
				}
			}*/
			while(fread()){
				
			}
		
			for(contQtd = 0; contQtd < qtdAlunos; contQtd++){
				printf("%s %s\n", pAlunos[contQtd].matricula, pAlunos[contQtd].nome);	
			}
		}
	}
	
	free(pAlunos);
	fclose(arqvAlunos);
	
	return 0;
}

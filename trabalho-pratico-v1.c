#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct dadosAluno {
    char nome[100], curso[50], telefone[12];
    float nota1, nota2;
};

float calcularMedia(struct dadosAluno X){
    float mediaAluno = (X.nota1 + X.nota2) /2;
    return(mediaAluno);  
}


int main(){
	
    FILE *f1, *f2;
    char linha[94];

    f1 = fopen("DadosEntrada.csv", "r");
    f2 = fopen("SituacaoFinal.csv", "w");
    
    setlocale(LC_ALL, "Portuguese");

    if((f1 == NULL) || (f2 == NULL)){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while(fgets(linha, sizeof(linha), f1) != NULL){
    	char *divString; //nosso token
    	struct dadosAluno aluno; //chamando a struct e renomeando
		
    	
    	divString = strtok(linha, ","); //leitura encerra na vírgula
    	strcpy(aluno.nome, divString); //copiando dado do token para a variavel nome
    	
    	divString = strtok(NULL, ","); //leitura encerra na vírgula
    	strcpy(aluno.telefone, divString);
    	
    	divString = strtok(NULL, ","); //leitura encerra na vírgula
    	strcpy(aluno.curso, divString);
    	
    	divString = strtok(NULL, ","); //leitura encerra na vírgula
    	aluno.nota1 = atof(divString);
    	
    	divString = strtok(NULL, ""); //leitura encerra na vírgula
    	aluno.nota2 = atof(divString);    	
    	
        fprintf(f2, "%s,%s,%s,%s,%s\n", aluno.nome, aluno.telefone, aluno.curso, aluno.nota1, aluno.nota2);
    }

    fclose(f1);
    fclose(f2);
    return 0;
}

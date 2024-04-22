/* TRABALHO PRÁTICO nº 01 - Manipulando arquivos (versão Final)
PROFESSOR: Marcelo Eustaquio Soares de Lima Junior
ALUNOS:
    Daniel Augusto Silva de Souza
    Déborah Araujo Mendes
    Emanuelly Gomes Queiroz
    Maria Eduarda Ribeiro Coutinho
*/

// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct que guarda dados de cada aluno presente no arquivo de entrada 
struct dadosAluno {
    char nome[100], curso[50], telefone[12];
    float nota1, nota2;
};

// Função que calcula a média e determina a situação do aluno
float calcularMedia(struct dadosAluno X, float media, char situacao[18]) {
    media = (X.nota1 + X.nota2) /2;
    
    // Definindo a situação do aluno
    if (media >= 0 && media < 7) {
    	strcpy(situacao, "REPROVADO");
	} else if (media >= 7 && media <= 10) {
		strcpy(situacao, "APROVADO");
	}else {
	    strcpy(situacao, "ERRO AO VERIFICAR"); // Acontecera caso o valor de alguma das notas esteja errada (acima de 10)
	}
    
    return(media);
}

// Função responsável pela leitura e processamento dos dados dos arquivos
void processarDados(FILE *arquivoEntrada, FILE *arquivoSaida) {
    // Variáveis da função
    char linha[94];
    float media;
    char situacao[18];

    // Comando para ignorar o que esta presente na primeira linha do arquivo de leitura (cabeçalho)
    fgets(linha, sizeof(linha), arquivoEntrada);

    // Laço de repetição para ir de linha em linha do arquivo de leitura
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        char *divString; // TOKEN
        struct dadosAluno aluno; // Chamando a struct e renomeando

        divString = strtok(linha, ","); // Comando para que a leitura encerre assim que encontrar a vírgula
        strcpy(aluno.nome, divString); // Comando usado para copiar o dado lido do token na variável
   
        divString = strtok(NULL, ","); 
        strcpy(aluno.telefone, divString);
   
        divString = strtok(NULL, ","); 
        strcpy(aluno.curso, divString);
   
        divString = strtok(NULL, ",");
        aluno.nota1 = atof(divString);
   
        divString = strtok(NULL, " "); // Comando para que a leitura encerre assim que encontrar o espaço
        aluno.nota2 = atof(divString);   
	
 	    // Chamando a função que calcula a média e colocando a resposta na variável
  	    media = calcularMedia(aluno, media, situacao);
    
        // imprimindo os dados selecionados no arquivo de saída
        fprintf(arquivoSaida, "%s, %.2f, %s\n", aluno.nome, media, situacao);
    }
}

int main() {
    // Determinando arquivos usado e gerado pelo algoritmo
    FILE *arquivoEntrada, *arquivoSaida;
    
    // Abrindo o arquivo que será usado para leitura
    arquivoEntrada = fopen("DadosEntrada.csv", "r");
    
    // Determinando o arquivo que será usado para escrita (gerado (caso não exista) ou modificado (caso exista))
    arquivoSaida = fopen("SituacaoFinal.csv", "w");
    
    // Condicional para possibilidade de erro ao tentar abrir, gerar ou modificar o arquivo
    if ((arquivoEntrada == NULL) || (arquivoSaida == NULL)) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    // Chamando a função para ler e processar os dados
    processarDados(arquivoEntrada, arquivoSaida);

    // print no terminal informando que o arquivo foi gerado corretamente
    printf("\n\nArquivo de saida foi gerado com sucesso!\n\n");

    // Fechando os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    return 0;
}

/* NOTAS DE MODIFICAÇÃO ENTRE AS VERSÕES 2 E FINAL:
1- Criação e edição de comentários.

2- linha 25: alteração de {<= 6.99} para {< 7}.
    Motivo: da forma como estava as notas entre 6.99 e 7.00 (ex: 6.995) cairiam na saída "ERRO AO VERIFICAR".

3- Modificação dos nomes das seguintes variavéis:
    mediaFinalAluno --> situacao
    mediaAluno --> media
    f1 --> arquivoEntrada
    f2 --> arquivoSaida
    Motivo: facilitar a leitura e compreenção do código.

4- EXCLUSÃO: tudo que estava presente na linha 23 {situacao[18];}
    Motivo: redundância, pois a variável já estava definida na linha 21.

5- CRIAÇÃO da função processarDados.
    Motivo: Encapsulamento de código. Na nova função entram a parte do código responsável pela leitura e
    processamento de dados dos arquivos, código esse que estava presente na MAIN. O encapsulamento deixa o
    código mais flexivel, melhora na compreenção e torna mais fácil a detecção de possíveis erros.
*/
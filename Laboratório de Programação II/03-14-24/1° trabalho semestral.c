#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct pessoa {
        int codigo;
        char nome[81];
        float peso;
        int altura;
        float IMC;
        char faixa[15];
    };
    typedef struct pessoa Pessoa;


void relatorioDados(Pessoa vet[], int tamanho){

    int i;

    printf("\n\n1° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        printf("\n%d° pessoa:\n", i+1);
        printf("\nCódigo: %d", vet[i].codigo);
        printf("\nNome: %s", vet[i].nome);
        printf("\nPeso: %.2f kg", vet[i].peso);
        printf("\nAltura: %d cm", vet[i].altura);
        printf("\nIMC: %.2f", vet[i].IMC);
        printf("\nFaixa do IMC: %s\n", vet[i].faixa);
    }

}

void relatorioSobrepeso(Pessoa vet[], int tamanho){

    int i, flag = 0;

    printf("\n\n2° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC >= 24.9 && vet[i].IMC <= 30){
            printf("\n%s está com sobrepeso de acordo com o teste do IMC!\n", vet[i].nome);
            flag = 1;
        }
    }

    if (flag == 0){
        printf("\n --------------- \n");
    }

}

void relatorioObesidade(Pessoa vet[], int tamanho){

    int i, flag = 0;

    printf("\n\n3° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC > 30){
            printf("\nA pessoa de código %d está com obesidade de acordo com o teste do IMC!\n", vet[i].codigo);
            flag = 1;
        }
    }

    if (flag == 0){
        printf("\n --------------- \n");
    }

}

float relatorioMediaPesos(Pessoa vet[], int tamanho){

    int i;
    float media = 0;

    printf("\n\n4° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        media = media + vet[i].peso;
    }

    media = media / tamanho;
    printf("\nO valor médio dos pesos inseridos é de %.2f!\n", media);

    return media;

}

void relatorioQuantAcimaMediaPesos(Pessoa vet[], int tamanho, float mediaPesos){

    int i, quant = 0;

    printf("\n\n5° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        if (vet[i].peso > mediaPesos){
            quant++;
        }
    }

    printf("\n%d pessoas tem o peso acima da média de pesos;\n", quant);

}

void relatorioQuantForaFaixaNormal(Pessoa vet[], int tamanho){

    int i, quant = 0;

    printf("\n\n6° RELATÓRIO:\n");

    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC >= 18.5 && vet[i].IMC < 24.9){
            continue;
        }
        else {
            quant++;
        }
    }

    printf("\n%d pessoas não tem o IMC na faixa considerada \"Normal\";\n", quant);

}

void relatorioNomeFaixaNormalAbaixoMediaPesos(Pessoa vet[], int tamanho, float mediaPesos){

    int i, flag = 0;

    printf("\n\n7° RELATÓRIO:\n");


    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC >= 18.5 && vet[i].IMC < 24.9){
            if (vet[i].peso < mediaPesos){
                printf("\n%s tem o peso na faixa normal do IMC e está abaixo da média de pesos inseridos;\n", vet[i].nome);
                flag = 1;
            }
        }
    }

    if (flag == 0){
        printf("\n --------------- \n");
    }

}

void relatorioMaiorIMC(Pessoa vet[], int tamanho){

    int i, flagMaiorIMC[tamanho];
    float maiorIMC = 0;

    printf("\n\n8° RELATÓRIO:\n\n");

    for (i = 0; i < tamanho; i++){
        flagMaiorIMC[i] = 0;
    }
    
    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC > maiorIMC){
            maiorIMC = vet[i].IMC;
        }
    }
    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC == maiorIMC){
            flagMaiorIMC[i] = 1;
        }
    }

    for (i = 0; i < tamanho; i++){
        if (flagMaiorIMC[i] != 0){
            printf("%s obteve o maior IMC!\n", vet[i].nome);
        }
    }

}

void relatorioMenorIMC(Pessoa vet[], int tamanho){

    int i, flagMenorIMC[tamanho];
    float menorIMC = 9999;

    printf("\n\n9° RELATÓRIO:\n\n");

    for (i = 0; i < tamanho; i++){
        flagMenorIMC[i] = 0;
    }
    
    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC < menorIMC){
            menorIMC = vet[i].IMC;
        }
    }
    for (i = 0; i < tamanho; i++){
        if (vet[i].IMC == menorIMC){
            flagMenorIMC[i] = 1;
        }
    }

    for (i = 0; i < tamanho; i++){
        if (flagMenorIMC[i] != 0){
            printf("%s obteve o menor IMC!\n", vet[i].nome);
        }
    }

}

int main(){

    #define TAM 25

    int i;
    float altMetros, mediaPesos;

    Pessoa vet[TAM];

    printf("\nNeste código, deve ser inserido diversos dados de %d pessoas, para assim terem seu IMC calculados e dados variados gerados;\n", TAM);

    for (i = 0; i < TAM; i++){
        printf("\nInforme os dados da %d° pessoa!\n", i+1);
        printf("\nInforme o código:\n");
        scanf("%d", &vet[i].codigo);
        printf("Informe o nome:\n");
        scanf("%s", &vet[i].nome);
        printf("Informe o peso da pessoa em KG:\n");
        scanf("%f", &vet[i].peso);
        printf("Informe a altura da pessoa em CM:\n");
        scanf("%d", &vet[i].altura);

        altMetros = (float)vet[i].altura/100;
        vet[i].IMC = vet[i].peso/(altMetros * altMetros);
        if (vet[i].IMC < 18.5){
            strcpy(vet[i].faixa, "Magreza");
        }
        else if (vet[i].IMC >= 18.5 && vet[i].IMC < 24.9){
            strcpy(vet[i].faixa, "Normal");
        }
        else if (vet[i].IMC >= 24.9 && vet[i].IMC <= 30){
            strcpy(vet[i].faixa, "Sobrepeso");
        }
        else if (vet[i].IMC > 30){
            strcpy(vet[i].faixa, "Obesidade");
        }
    }

    for (i = 0; i < TAM; i++){
        printf("\ni = %d; codigo = %d; nome = %s; peso = %.2f; altura = %d;\n", i, vet[i].codigo, vet[i].nome, vet[i].peso, vet[i].altura);
    }

    relatorioDados(vet, TAM);
    relatorioSobrepeso(vet, TAM);
    relatorioObesidade(vet, TAM);
    mediaPesos = relatorioMediaPesos(vet, TAM);
    relatorioQuantAcimaMediaPesos(vet, TAM, mediaPesos);
    relatorioQuantForaFaixaNormal(vet, TAM);
    relatorioNomeFaixaNormalAbaixoMediaPesos(vet, TAM, mediaPesos);
    relatorioMaiorIMC(vet, TAM);
    relatorioMenorIMC(vet, TAM);


    system("pause");
    return 0;
}
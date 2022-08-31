// 01. Na usina de Angra dos Reis, os técnicos analisam a perda de massa de um material radioativo. Sabendo-se que este perde 25% de sua massa a cada
// 30 segundos, criar um programa que imprima o tempo necessário para que a massa deste material se torne menor que 0,10 gramas. O programa pode
// calcular o tempo para varias massas.
int main()
{
    int i = 0; 
    float massa;
    int segundos = 30;
    
    printf("Digite a massa do material: ");
    scanf("%f", &massa);
    
    while(massa > 0.10){
        massa = massa - (massa/4);
        i++;
        printf(" Massa: %f \n", massa);
    }
    
    segundos = segundos * i;
    printf("O total de segundos é igual a: %d segundos", segundos);
}

/* 02. Entrar com a idade de varias pessoas ate o usuário informar que deseja parar. e imprimir o total de pessoas com menos de 21 e total de pessoas
maiores que 50 */

int main()
{
   int idade;
   int totalMenor21 = 0;
   int totalMaior50 = 0;
   
   
   printf("Coloque as idade aqui, digite um numero negativo para parar\n");
   do{
        printf("Digite a idade a ser armazenada: ");
       scanf("%d", &idade);
       
       if (idade < 21){
           totalMenor21++;
       }else if (idade > 50){
           totalMaior50++;
       }
   }while(idade > 0);
   
   printf("Total com menos de 21: %d \nTotal com mais de 50: %d", totalMenor21, totalMaior50);
}

// 03. Dado um pais A, com 5.000.000 de habitantes e uma taxa de natalidade de 3% ao ano, e um pais B com 7.000.000 de habitantes e uma taxa de
// natalidade de 2% ao ano. calcular e imprimir o tempo necessário para que a população do pais A ultrapasse a população do pais B

int main()
{
    int i;
    int paisA = 5000000;
    int paisB = 7000000;

    for(i = 0; paisA <= paisB ; i++){
        paisA = paisA + (paisA*0.03);
        paisB = paisB + (paisB*0.02);
    }
   
    printf("O tempo necessário é de : %d anos", i); // 35 ????
}


// 04. Chico tem 1.50m e cresce 2 centímetros por ano, enquanto Juca tem 1.10m e  cresce 3 cm por ano. construir um programa que calcule e imprima
// quantos anos serão necessários para Juca seja maior que Chico;

int main()
{
    int i;
    float chico = 1.5;
    float juca = 1.1;

    for(i = 0; juca <= chico ; i++){
        chico = chico + 0.02;
        juca = juca + 0.03;
    }
   
    printf("Serão necessários : %d anos, para que Juca seja maior do que Chico", i); // 41 anos???
}

// 05. Criar um programa que deixe entrar com nome e idade de 20 pessoas e armazene em um vetor todos os nomes que comecem com a letara no
// intervalo L-S
#define TAMNOME 30
#define TAM 20
int main()
{
    int i = 0;
    int j, k;
    char nome[TAMNOME];
    char nomesLS[(TAM*TAMNOME) + TAM];
    int idade;
    int contagemNomes = 0;
    
    do{
        printf("Digite o seu nome: ");
        fgets(nome, TAMNOME, stdin);
        printf("Digite a sua idade: ");
        scanf("%d", &idade);
        getchar();
        if(nome[0] >= 'L' && nome[0] <= 'S' || nome[0] >= 'l' && nome[0] <= 's' ){
            for(j = 1; nome[j] != '\0'; j++);
            for(k = 0; k < j; k++){
                nomesLS[contagemNomes] = nome[k];
                contagemNomes++;
            }
            nomesLS[contagemNomes] = ' ';
        }
        i++;
        printf("\n");
    } while( i < TAM);
    
    contagemNomes++;
    nomesLS[contagemNomes] = '\0';
    
    puts(nomesLS);
}

// 06. Armazenar nomes e nota 1, 2, de 15 alunos. calcular e armazenar a media. Armazenar tambem a situação do aluno: AP ou RP. 
// Imprimir uma listagem contendo nome, notas, media e a situação de cada aluno.
#define NUMEROALUNOS 15
#define TAMNOME 41
int main(){
    struct notasAlunos
    {
        float nota1, nota2;
        float media;
        char nome[TAMNOME], situacao[4];
    }alunos[NUMEROALUNOS];
    
    for(int i=0; i < NUMEROALUNOS; i++){
        printf("Digite o nome do %dº aluno: ", i+1);
        fgets(alunos[i].nome, TAMNOME, stdin);
            
        printf("Digite a primeira nota do aluno: ");
        scanf("%f", &alunos[i].nota1);
        
        printf("Digite a segunda nota do aluno: ");
        scanf("%f", &alunos[i].nota2);
        getchar();
        
        printf("------------------------ \n");
            
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2;
            
        if(alunos[i].media > 5){
            strcpy(alunos[i].situacao,"AP.");
        } else {
            strcpy(alunos[i].situacao,"RP.");
        }
    }
    
    for( int j = 0; j < NUMEROALUNOS; j++) {
        printf("\n ======= Estudante número %d  ======= ", j+1);
        printf("\n Nome: %s", alunos[j].nome);
        printf("\n Nota 1: %.2f", alunos[j].nota1);
        printf("\n Nota 2: %.2f", alunos[j].nota2);
        printf("\n Média: %.2f", alunos[j].media);
        printf("\n Situação: %s", alunos[j].situacao);
    }
}

// 07. Criar programa que leia dois conjuntos de números inteiros, tendo cada um 10 e 20 elementos e apresente os elementos comuns aos conjuntos.
// lembre-se de que os elementos podem se repetir mas não podem aparecer repetidos na saída.
#define TRUE 1
#define FALSE 0
#define TAMARRAY10 10
#define TAMARRAY20 20
#include <stdio.h>
int main()
{
    int i, j, aux;
    int igual;
    int array10[TAMARRAY10] = {6, 8, 9, 16, 10, 89, 92, 19, 10, 7};
    int array20[TAMARRAY20] = {1, 2, 3, 4, 5, 6, 16, 8, 9, 10, 89, 11, 12, 92, 13, 14, 15, 100, 500, 0};
    
    for(i = 0; i < TAMARRAY20; i++){
        aux = array20[i];
        igual = FALSE;
        for(j = 0; j < TAMARRAY10; j++){
            if(aux == array10[j]) igual = TRUE;
        }
        if(igual == FALSE) printf("%d \n", aux);
    }
}

// 08. Criar programa que leia dados de 20 elementos inteiros. imprimir o maior e o menor, sem ordenar, o percentual de números pares e a
// media dos elementos do vetor
#define TAM 20
int main()
{
    int array[TAM] = {10, 2, 3, 4, 5, 6, 7, 8, 21, 19, 11, 12, 13, 14, 15, 16, 17, 18, 1, 9};
    float menorValor = array[0];
    float maiorValor = array[0];
    float numeroPares;
    float percentualPares;
    float media;
    
    for(int i = 0; i < TAM; i++){
        if(array[i] < menorValor) menorValor = array[i];
        if(array[i] > maiorValor) maiorValor = array[i];
        if(array[i] % 2 == 0) numeroPares++;
        media += array[i];
    }
    media /= 20; 
    percentualPares = (numeroPares / TAM)*100;
    
    printf(" O menor valor é de %.2f \n O maior valor é de %.2f \n O percentual de números pares é de: %.2f porcento \n", menorValor, maiorValor, percentualPares);
    printf("A média dos elementos do vetor é igual a: %.2f", media);
}

// 09. Criar programa que leia elementos de uma matriz inteira de 10x10 e escreva os elementos da diagonal principal
#define TAM 10
int main()
{
    int matriz[TAM][TAM] = {{11, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                           {1, 12, 3, 4, 5, 6, 7, 8, 9, 10},
                           {1, 2, 13, 4, 5, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 14, 5, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 15, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 16, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 17, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 7, 18, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 7, 8, 19, 10}, 
                            {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}};
    int i;
    
    for(i = 0; i < TAM; i++){
        printf("Item %d da diagonal principal =  %d \n", i, matriz[i][i]);
    }
}

// 10. Criar programa que leia e armazena os elementos de uma matriz M inteira 10x10 e imprima todos os elementos 
// que estão em linhas pares e colunas impares
#define TAM 10
int main()
{
    int matriz[TAM][TAM] = {{11, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                           {1, 12, 3, 4, 5, 6, 7, 8, 9, 10},
                           {1, 2, 13, 4, 5, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 14, 5, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 15, 6, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 16, 7, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 17, 8, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 7, 18, 9, 10}, 
                           {1, 2, 3, 4, 5, 6, 7, 8, 19, 10}, 
                            {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}};
    int i;
    int linhaPar[TAM];
    int colulaImpar[TAM];
    
    for(i = 0; i < TAM; i++){
        if(i % 2 == 0){
            for(int j = 0; j < TAM; j++){
                 printf("Item da linha %d (par) =  %d \n", i, matriz[i][j]);
            }
        }
        printf("------------------------------\n");
    }
    
    for(i = 0; i < TAM; i++){
        if(i % 2 != 0){
            for(int j = 0; j < TAM; j++){
                 printf("Item da coluna %d (impar) =  %d \n", i,  matriz[j][i]);
            }
        }
        printf("------------------------------\n");
    }
}

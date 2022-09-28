// 1) Que imprima o horóscopo de varias pessoas, a aprtir da sua data de nascimento (ddmm). O fim é determinado quando se digita 9999 para data. considera que a data foi digitada corretamente.

// 01-20 Capricornio
// 02-19 Aquario
// 03-20 Peixes
// 04-20 Aries
// 05-20 Touro
// 06-20 Gemeos
// 07-21 Cancer
// 08-22 Leão
// 09-22 Virgem
// 10-22 Libra
// 11-21 Escorpião
// 12-21   Sargitario
#include <stdio.h>

int main()
{
    int aniversario, dia, mes;
    
    do{
        printf("Digite seu aniversario DDMM:\n (Digite 9999 para encerrar o programa)) \n");
        scanf("%d", &aniversario);
        
        dia = aniversario / 100;
        mes = aniversario % 100;
        
        switch(mes){
            case 1:{
                if(dia >= 1 && dia <= 20) printf("\n Seu signo é Capricórnio \n");
                if(dia >= 21 && dia <=31) printf("\n Seu signo é Aquário \n");
                break;
            }
            case 2:{
                if(dia >= 1 && dia <=19) printf("\n Seu signo é Aquário \n");
                if(dia >= 20 && dia <= 29) printf("\n Seu signo é Peixes \n");
                break;
            }
            case 3:{
                if(dia >= 1 && dia <= 20) printf("\n Seu signo é Peixes \n");
                if(dia >= 21 && dia <=31) printf("\n Seu signo é Áries \n");
                break;
            }
            case 4:{
                if(dia >= 1 && dia <= 20) printf("\n Seu signo é Áries \n");
                if(dia >= 21 && dia <=30) printf("\n Seu signo é Touro \n");
                break;
            }
            case 5:{
                if(dia >= 1 && dia <= 20) printf("\n Seu signo é Touro \n");
                if(dia >= 21 && dia <=31) printf("\n Seu signo é Gêmeos \n");
                break;
            }
            case 6:{
                if(dia >= 1 && dia <= 20) printf("\n Seu signo é Gêmeos \n");
                if(dia >= 21 && dia <=30) printf("\n Seu signo é Câncer \n");
                break;
            }
            case 7:{
                if(dia >= 1 && dia <= 21) printf("\n Seu signo é Câncer \n");
                if(dia >= 22 && dia <=31) printf("\n Seu signo é Leão \n");
                break;
            }
            case 8:{
                if(dia >= 1 && dia <= 22) printf("\n Seu signo é Leão \n");
                if(dia >= 23 && dia <=31) printf("\n Seu signo é Virgem \n");
                break;
            }
            case 9:{
                if(dia >= 1 && dia <= 22) printf("\n Seu signo é Virgem \n");
                if(dia >= 23 && dia <=30) printf("\n Seu signo é Libra \n");
                break;
            }
            case 10:{
                if(dia >= 1 && dia <= 22) printf("\n Seu signo é Libra \n");
                if(dia >= 23 && dia <=31) printf("\n Seu signo é Escorpião \n");
                break;
            }
            case 11:{
                if(dia >= 1 && dia <= 21) printf("\n Seu signo é Escorpião \n");
                if(dia >= 22 && dia <=30) printf("\n Seu signo é Sagitário \n");
                break;
            }
            case 12:{
                if(dia >= 1 && dia <= 21) printf("\n Seu signo é Sagitário \n");
                if(dia >= 22 && dia <=31) printf("\n Seu signo é Capricórnio \n");
                break;
            }
        }

    }while(aniversario =! 9999);
}

#include <stdio.h>
// 2) Que dado dois vetores de 10 posições, efetue operações basicas aritmeticas, indicadas por um terceiro vetor cujos dados 
// tambem são fornecidos pelo usuario, gerando e imprimindo um quarto vetor.
#define TAM 10
#define OP 4

#include <stdio.h>

int main()
{
   int A [TAM];
   int B [TAM];
   int calculos [OP]={1, 2, 3, 4};
   int resultado [TAM];
   int n, i;

   printf("Digite os valores dentro dos vetores: ");
   
   for (i=0; i<TAM; i++){
       printf("Digite o valor %d: \n",i);
       scanf("%d",&A[i]);
   }
   
   for ( i=0; i<TAM; i++){
       printf("Digite o valor %d: \n",i);
       scanf("%d",&B[i]);
   }
   
   printf("Digite a operacao que voce deseja fazer: \n");
   printf("Opcoes disponiveis: 1 - soma\n, 2 - subtracao\n, 3 - multiplicacao\n 4 - divisao");
   scanf("%d", &n);
   
   for (i=0;i<OP;i++){
       if (n==calculos[i]){
           if (n==1) for (int j=0;j<TAM;j++) resultado [j] = A[j] + B[j];
           if (n==2) for (int j=0;j<TAM;j++) resultado [j] = A[j] - B[j];
           if (n==3) for (int j=0;j<TAM;j++) resultado [j] = A[j] * B[j];
           if (n==4) for (int j=0;j<TAM;j++) resultado [j] = A[j] / B[j];
       }
   }
   
    printf("Os resultados foram: \n");
    for (i = 0 ; i < TAM ; i++) printf("%d  ", resultado[i]);
}

#include <stdio.h>
// 3) Que  entre com dados num vetor VET do tipo inteiro com 20 posiçoes, onde podem existir varios elementos repetidos. 
// Gere um vetor VET1 que tambem será ordenado e terá somente os elementos do vetor VET que não sao repetidos.

#define TAM 20

int main()
{
    int vet[TAM] = {5, 4, 5, 4, 7, 6, 16, 89, 92, 10, 23, 5, 2, 10, 65, 200, 16, 6, 25, 2018}; // 1 2 4 5 5
     int i, j, l, aux;
     int cont= 0;
   
   // Ordenação do vetor:
    for(i = 0; i < TAM-1; i++){
        for(j = i+1; j < TAM; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    // Imprime o vetor ordenado:
    for(i = 0; i < TAM-cont; i++) printf(" %d ", vet[i]);
    
    // Conta o número de repetições:
    for(i = 0; i < TAM; i++) if(vet[i] == vet[i+1]) cont++;
    // Cria o novo vetor VET2 no tamanho ideal (sem contar as repetições):
    int vet2[TAM - cont];
   
   // Atribui ao novo vetor VET2 os valores não repetidos
    for(i = 0, l = 0; i < TAM; i++){
        if(vet[i] != vet[i+1]){
            vet2[l] = vet[i];
            l++;
        }
    }
    
    printf("\n--------------------------------- \n");
    for(i = 0; i < TAM-cont; i++) printf(" %d ", vet2[i]);
}

// 4) Que armazene 10 numeros em um vetor. Na entrada de dados, o numero ja deve ser armazenado na
// sua posição definitiva em ordem decrescente. imprimir o vetor logo apos a entrada de dados;
#include <stdio.h>
#define TAM 10
int main()
{
    int i, j, k, l, aux;
    int array[10] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
    
    printf("Digite números abaixo de 1000: ");    
    for (i = 0; i < TAM ; i++){
       printf("\n Array [%d]: ", i);
       scanf("%d", &array[i]);
       for(j = 1 ; j < TAM; j++){
           aux = array[j];
            for( k = j - 1; k >= 0 && aux < array[k] ; k--){
                array[k+1] = array[k];
            }
            array[k+1] = aux;
        }
        printf("\n O vetor ordenado é igual a: \n");
        for (l = 0 ; l < TAM ; l++) printf("%d  ", array[l]);
    }
  
}

#include <stdio.h>
//5) Que leia os elemntos de uma matrix 10x10 e mostre somente os elementos abaixo da diagonal;
#define TAM 10
int main()
{
    int matriz[TAM][TAM] = {{3, 43, 5, 66, 8, 3, 64, 5, 36, 8},
                            {6, 7, 8, 9, 10, 11, 16, 5, 3, 18}, 
                            {1, 55, 2, 77, 9, 1, 5, 226, 7, 91},
                            {1, 2, 11, 2, 1, 1, 25, 17, 29, 12}, 
                            {0, 40, 0, 30, 0, 20, 0, 90, 0, 92},
                            {10, 9, 8, 7, 6, 15, 4, 13, 29, 11},
                            {6, 16, 9, 10, 4, 6, 16, 9, 10, 41},
                            {22, 23, 4, 5, 26, 27, 8, 29, 0, 1}, 
                            {5, 15, 5, 3, 45, 5, 65, 75, 8, 95},
                            {5, 7, 10, 50, 5, 5, 7, 10, 52, 58}};
    int i, j;
    
    for(i = 0; i < TAM ; i++){
        for(j = 0; j < TAM; j++){
            if(i > j) printf(" %d ", matriz[i][j]);
        }    
    }
}

// 6)  Que leia e armazene os elemntos de uma matriz inteira (10,10) e imprima. depois troque os dados da segunda linha pela oitava.
// da quarta pela decima, a diagonal principal pela diagonal segundaria.
#include <stdio.h>
#define DIM 10
int main()
{
    int matriz[DIM][DIM] = {{3, 43, 5, 66, 8, 3, 64, 5, 36, 8},
                            {6, 7, 8, 9, 10, 11, 16, 5, 3, 18}, //2
                            {1, 55, 2, 77, 9, 1, 5, 226, 7, 91},
                            {1, 2, 11, 2, 1, 1, 25, 17, 29, 12}, // -> 4
                            {0, 40, 0, 30, 0, 20, 0, 90, 0, 92},
                            {10, 9, 8, 7, 6, 15, 4, 13, 29, 11},
                            {6, 16, 9, 10, 4, 6, 16, 9, 10, 41},
                            {22, 23, 4, 5, 26, 27, 8, 29, 0, 1}, //8
                            {5, 15, 5, 3, 45, 5, 65, 75, 8, 95},
                            {5, 7, 10, 50, 5, 5, 7, 10, 52, 58}}; // -> 10
    int i, j;
    int arrayTemp[DIM];
    
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++) printf(" %d ", matriz[i][j]);
        printf("\n");
    }
    printf("------------------------------- \n");
    
    // Trocando as linha 2 pela linha 8 e a linha 4 pela linha 10
    for(i = 0; i < DIM; i++){
        arrayTemp[i] = matriz[1][i];
        matriz[1][i] = matriz[7][i];
        matriz[7][i] = arrayTemp[i];
        arrayTemp[i] = matriz[3][i];
        matriz[3][i] = matriz[9][i];
        matriz[9][i] = arrayTemp[i];
    }
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++) printf(" %d ", matriz[i][j]);
        printf("\n");
    }
    printf("------------------------------- \n");
    
    // Trocando a diagonal principal pela secundária: 
    for(i = 0; i < DIM; i++){
        arrayTemp[i] = matriz[i][i];
        matriz[i][i] = matriz[i][DIM - i - 1];
        matriz[i][DIM - i - 1] = arrayTemp[i];
    }
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++) printf(" %d ", matriz[i][j]);
        printf("\n");
    }

}

#include <stdio.h>
// 7) Que declare uma matriz 5x5 e armazene em um vetor o MAIOR elemento cadastrado em cada COLUNA da matriz,
// e em um vetor b o menor elemento cadastrado em cada coluna da matriz e imprima: a) toda a matrix; b) o vetor a; c) o vetor b; d)(a+b)/2
#define TAM 5
int main()
{
    float matriz[TAM][TAM] = {{19, 8, 7, 16, 26},
                           {44, 600, 6, 89, 92},
                           {16, -5, 572, 35, 11},
                           {68, 5, 61, -55, 8},
                           {71, 252, 9, 10, 9}};
    float maior[TAM];
    float menor[TAM];
    int menorValor, maiorValor;
    float resultado[TAM];
    int i , j, k;

    printf("\n TODA A MATRIZ: \n");
    for (j = 0 ; j < TAM ; j++){
        for (i = 0; i < TAM ; i++){
            menorValor = matriz[i][j];
            maiorValor = matriz[i][j];
            for(k = 0; k < TAM ; k++){
                if (matriz[k][j] < menorValor) menorValor = matriz[k][j];
                if (matriz[k][j] > maiorValor) maiorValor = matriz[k][j];
            }
            //a) Imprime toda a matriz:
            printf(" %.2f ", matriz[j][i]);
        }
        menor [j] = menorValor;
        maior [j] = maiorValor;
        printf("\n");
    }
   
   //b) Imprime o vetor maior:
    printf("\n MAIORES:\n");
    for (i = 0; i < TAM ; i++) {
        printf("%.2f ", maior[i]);
    }
    printf("\n__________________\n\n");
    
    //c) Imprime o vetor menor:
    printf("\n MENORES:\n");
    for (i = 0; i < TAM ; i++) {
        printf("%.2f ", menor[i]);
    }
        printf("\n__________________\n\n");
    
    //d) Faz a operação (a+b)/2 e imprime:
    printf("\n RESULTADO:\n");
    for(i = 0; i < TAM; i++){
        resultado[i] =  (maior[i] + menor[i])/2;
        printf("%.2f ", resultado[i]);
    }
}

//8) Que deixe entrar com valores de uma matriz de ordem cinco e verificar se ela é ou nao uma matriz triangular superior.
#include <stdio.h>
#define TAM 5

int main()
{
    int matriz[TAM][TAM];
    int i, j;
    int cont = 0;
    
    for (i = 0; i < TAM ; i++){
        for(j = 0; j < TAM ; j++){
           printf("\n Array [%d][%d]: ", i, j);
           scanf("%d", &matriz[i][j]);
        }
    }
    
    for (i = 0; i < TAM ; i++){
        for(j = 0; j < TAM ; j++){
           if((i < j || i == j) && matriz[i][j] != 0) cont ++;
           if(i > j && matriz[i][j] == 0) cont ++;
        }
    }
    printf("\n ------------------------------- \n");
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++) printf(" %d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n ------------------------------- \n");
    
    if(cont == TAM*TAM) printf("A matriz digitada É uma matriz Triagular Superior.");
    else printf("A matriz digitada NÃO É uma matriz Triagular Superior.");
}


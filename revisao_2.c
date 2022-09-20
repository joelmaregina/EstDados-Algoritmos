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

#include <stdio.h>
// 7) Que declare uma matriz 5x5 e armazene em um vetor o MAIOR elemento cadastrado em cada COLUNA da matriz,
// e em um vetor b o menor elemento cadastrado em cada coluna da matriz e imprima: a) toda a matrix; b) o vetor a; c) o vetor b; d)(a+b)/2
#define TAM 3
// *******************************INCOMPLETA!!*********************************************
int main()
{
    int vetor[TAM][TAM] = {{9,8,7},
                       {4, 5, 6},
                       {7, 2, 9}};
    int maior[TAM];
    int menor[TAM];
    int menorValor, maiorValor;
    int i,j;

   
    for (i = 0 ; i < TAM ; i++){
        for (j = 0; j < TAM ; j++){
            menorValor = vetor [j][i];
            maiorValor = vetor [j][i];
            if (menorValor > vetor [j][i]){
                menorValor=vetor [j][i];
            }
           
            if (maiorValor < vetor [j][i]){
                maiorValor = vetor [j][i];
            }
        }
         menor [i] = menorValor;
         maior [i] = maiorValor;
    }
   
   
    for (i = 0; i < TAM ; i++) {
        printf("%d\n", maior[i]);
    }
    printf("__________________\n");
   
    for (i = 0; i < TAM ; i++) {
        printf("%d\n", menor[i]);
    }
}

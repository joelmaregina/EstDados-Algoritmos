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

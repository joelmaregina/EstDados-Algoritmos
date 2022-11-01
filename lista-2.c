//Q.02 Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo algoritmo da bolha.
#include <stdio.h>
 #include <string.h>
#define TAM 50

int main()
{
    char string[50];
    int i, j;

    printf("Digite a string a ser ordenada alfabeticamente: ");
    fgets(string, TAM, stdin);
    puts(string);
    
    for(i = 0; i < strlen(string) -1 ; i++){
        for( j = i+1 ; j  < strlen(string) ; j++){
            char aux;
            if(string[i] > string[j]){
                aux = string[j];
                string[j] = string[i];
                string[i] = aux;
            }
        }
    }
    
    puts(string);
}

#include <stdio.h>
#include <string.h>
#define TAM 50

// Q. 07 Faça uma função que, dado um valor inteiro N positivo, aloque dinamicamente um vetor de Aluno, leia do teclado os N pares de valores
// (Matricula, Nota) e retorne o vetor alocado. Imprima, ao final do programa, duas listas: (1) alunos ordenados por nota final
// e (2) alunos ordenados por número de matrícula. Utilize algoritmos de ordenação vistos em aula e justifique as suas escolhas.

typedef struct _pessoa_ {
    unsigned int matricula;
    float nota;
} Aluno;


int main()
{
    Aluno alunos[TAM];
    int qtdAlunos;
}

int inscreveAluno (Aluno alunos[], int qtdAlunos){
    
     printf("============ CADASTRO DE ALUNOS ============ \n");
    
    printf("Digite sua matricula: ");
    scanf("%u", &alunos[qtdAlunos].matricula);
    
    printf("Digite sua nota: ");
    scanf("%u", &alunos[qtdAlunos].nota);
}



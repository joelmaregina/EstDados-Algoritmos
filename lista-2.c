#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
#define TAMNOME 15
//Q.01. Faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo da inserção. No final, o programa deve mostrar todos os nomes ordenados alfabeticamente.

int main()
{
  int i, j, k, l;
  int numNomes;
  char nomeAux[TAMNOME];
  //  ARRAY USADO PARA TESTES
  char nomes[TAM][TAMNOME]= {"Joelma", "Flavia", "Maria", "Luisa", "Priscila", "Ana", "Anna", "Patricia", "Mariana", "Alice"};

  for (i = 0; i < TAM ; i++){
    for(j = 1 ; j < TAM; j++){
      strcpy(nomeAux, nomes[j]);
      for( l = j - 1; TAM >= 0 && strcmp(nomes[l], nomes[l+1]) > 0; l--){
        strcpy(nomes[l+1], nomes[l]);
      }
      strcpy(nomes[l+1], nomeAux);
    }
  }
  for(i = 0; i < TAM; i++) printf("Nome %d: %s\n", i+1, nomes[i]);
}

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



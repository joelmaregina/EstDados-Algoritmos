#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
#define TAMNOME 15
//Q.01. Faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia do 
// algoritmo da inserção. No final, o programa deve mostrar todos os nomes ordenados alfabeticamente.

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
#include <stdlib.h>
#include <string.h>
#define TAM 10
#define TAMNOME 15
//Q.03 Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo 
//da SELEÇÃO. No final, o algoritmo deve mostrar todos os nomes ordenados.

int main()
{
  int i, j, menor;
  char troca[TAMNOME];
  //  ARRAY USADO PARA TESTES
  char nomes[TAM][TAMNOME]= {"Joelma", "Flavia", "Maria", "Luisa", "Priscila", "Ana", "Anna", "Patricia", "Mariana", "Alice"};

  for (i = 0; i < TAM -1 ; i++){
    menor = i;
    for(j = i + 1; j < TAM; j++){
      if (strcmp(nomes[j], nomes[menor]) < 0){
        menor = j;
      }
    }
    if(i != menor){
      strcpy(troca, nomes[i]);
      strcpy(nomes[i], nomes[menor]);
      strcpy(nomes[menor], troca); 
    }
  }

  for(i = 0; i < TAM; i++) printf("Nome %d: %s\n", i+1, nomes[i]);
}

//Q4 - QUESTÃO SOBRE HEAPSORT - ASSUNTO NÃO ABORDADO NA MATÉRIA

#include <stdio.h>
#include <string.h>
#define TAMNOME 10
#define TAM 5
// Q. 07 Faça uma função que, dado um valor inteiro N positivo, aloque dinamicamente um vetor de Aluno, leia do teclado os N pares de valores
// (Matricula, Nota) e retorne o vetor alocado. Imprima, ao final do programa, duas listas: (1) alunos ordenados por nota final
// e (2) alunos ordenados por número de matrícula. Utilize algoritmos de ordenação vistos em aula e justifique as suas escolhas.

typedef struct _pessoa_ {
    unsigned int matricula;
    float nota;
    char nome[TAMNOME];
} Aluno;

void listarOrdenadoPorMatricula(Aluno alunos[], int qtdAlunos);
void listarOrdenadoPorNota(Aluno alunos[], int qtdAlunos);
int inscreveAluno(Aluno alunos[], int qtdAlunos);

int menuAluno() {
  int opcao;
  printf("\n============ ÁREA DO ALUNO ============ \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Aluno \n  2 - Listar Alunos por Ordem de Nota \n  3 - Listar Alunos por Ordem de Matricula\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int main()
{
    Aluno alunos[TAM];
    int qtdAlunos;

    int opcao = 1;
  
    while (opcao != 0) {
      opcao = menuAluno();
  
      switch (opcao) {
        case 0:{
          printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
          break;
        } 
        case 1: {
          qtdAlunos = inscreveAluno(alunos, qtdAlunos);
          break;
        }
        case 2: {
          listarOrdenadoPorNota(alunos, qtdAlunos);
          break;
        }
        case 3: {
          listarOrdenadoPorMatricula(alunos, qtdAlunos);
          break;
        }
        default:
          printf("Opção Inválida. Digite um número entre 0 e 5.");
      }
    }
  
    return qtdAlunos;
}

int inscreveAluno(Aluno alunos[], int qtdAlunos){
    
    printf("\n\n============ CADASTRO DE ALUNOS ============ \n");
    
    getchar();
    printf("Digite seu nome: ");
    fgets(alunos[qtdAlunos].nome, TAMNOME, stdin);
    
    printf("Digite sua matricula: ");
    scanf("%u", &alunos[qtdAlunos].matricula);
    
    printf("Digite sua nota: ");
    scanf("%f", &alunos[qtdAlunos].nota);

    qtdAlunos++;
    return qtdAlunos;
}


void listarOrdenadoPorNota(Aluno alunos[], int qtdAlunos){
  int i, j, k;
  Aluno alunoAux;
  float aux;
  
  for(j = 1 ; j < qtdAlunos; j++){
    aux = alunos[j].nota;
    alunoAux = alunos[j];
    for( k = j - 1; k >= 0 && aux < alunos[k].nota; k--){
        alunos[k+1] = alunos[k];
    }
    alunos[k+1] = alunoAux;
  }

  printf("\n============ ALUNOS ORDENADOS POR NOTA ============ \n");
  for(i = 0; i < qtdAlunos; i++) printf("Nota: %f | Nome: %s | ID: %d\n", alunos[i].nota, alunos[i].nome, alunos[i].matricula);

}

void listarOrdenadoPorMatricula(Aluno alunos[], int qtdAlunos){
  int i, j, k;
  Aluno alunoAux;
  float aux;
  
  for(j = 1 ; j < qtdAlunos; j++){
    aux = alunos[j].matricula;
    alunoAux = alunos[j];
    for( k = j - 1; k >= 0 && aux > alunos[k].matricula; k--){
        alunos[k+1] = alunos[k];
    }
    alunos[k+1] = alunoAux;
  }
  
  printf("\n============ ALUNOS ORDENADOS POR MATRICULA ============ \n");
  for(i = 0; i < qtdAlunos; i++) printf("ID: %d | Nome: %s | Nota: %f\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota);
  
}

#include <stdio.h>
#include <string.h>
#define TAM 15
//Q.09 Refaça as funções de busca sequencial e busca binária assumindo que o vetor possui chaves que
//podem ocorrer múltiplas vezes no vetor. Neste caso, você deve retornar, em um outro vetor, 
//todas as posições onde a chave foi encontrada. 
//Protótipo:
//int busca(int vet[], int n, int chave, int posicoes[]);
//Sua função deve retornar o número de ocorrências da chave no vetor e, para cada uma destas 
//ocorrências, indicar no vetor posicoes[], as posições de vet que possuem a chave.

void ordenaVet(int vetOrdenar[]);
int buscaBinaria(int vet[], int n, int chave, int posicoes[]);
int buscaSequencial(int vet[], int n, int chave, int posicoes[], int primeiraPosicao);

int main()
{
    int vet[TAM] = {16, 6, 8, 6, 9, 7, 8, 16, 10, 6, 8, 15, 16, 10, 9};
    int posicoes[TAM];
    int n = 0;
    int chave;
    int primeiraPosicao;
    
    printf("Digite o número que você quer encontrar no vetor (exceto '-1'): ");
    scanf("%d", &chave);
    
    // Zera o vetor de posições:
    for(int i = 0; i < TAM; i++) posicoes[i] = -1;
    
    // Ordena o vetor para a busca binária:
    ordenaVet(vet);
    //for(int i = 0; i < TAM ; i++) printf(" \n %d ", vet[i]);
    
    //Acha a posição da primeira aparição da chave através da busca binária:
    primeiraPosicao = buscaBinaria(vet, n, chave, posicoes);
    printf("\n --> Primeira aparição: %d ", primeiraPosicao);
    
    //Contabiliza o número de aparições da chave no vetor e mostra as respectivas posições:
    n =  buscaSequencial(vet, n, chave, posicoes, primeiraPosicao);
    printf("\nNúmero de aparicões da chave digitada: %d \n", n);
    printf("Posicões em que a chave aparece no vetor: \n");
    for(int i = 0; posicoes[i] != -1; i++) printf(" %d ", posicoes[i]);
}

void ordenaVet(int vet[]){
  int i, j, aux;
  
  for(i = 1; i < TAM; i++){
    aux = vet[i];
    for (j =  i - 1; j >= 0 && aux < vet[j] ; j--){
      vet[j+1] = vet[j];
    }
    vet[j+1] = aux;
  }
}

int buscaBinaria(int vet[], int n, int chave, int posicoes[]){
    int posicao = -1;
    int inicio = 0;
    int meio;
    int fim = TAM -1;
  
  while (inicio <= fim && posicao < 0){
      meio = ((fim - inicio) / 2) + inicio;
      if (vet[meio] == chave){
          if (vet[meio-1] == chave) for(int i = meio; vet[i] == chave; i--) posicao = i;
          else posicao = meio;
      } else if (vet[meio] > chave){
          fim = meio - 1;
      } else {
          inicio = meio + 1;
      }
  }
  
  return posicao;
  
}

int buscaSequencial(int vet[], int n, int chave, int posicoes[], int primeiraPosicao){
    int i, j;
    
    for (i = primeiraPosicao, j = 0; vet[i] == chave ; i++){
        if (vet[i] == chave){
          n++;
          posicoes[j++] = i;
        }
    }
    
    return n;
}



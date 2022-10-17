#include <stdio.h>
// Q01.1 => uma função que recebe como parâmetro o dia, o mês, o ano e uma estrutura do tipo Data, onde o resultado deve
// ser armazenado, e retorna verdadeiro se a data estiver válida; caso contrário, retorna falso. A validação da data pode
// ser feita da seguinte forma:
// ■ meses com 30 dias: 04, 06, 09 e 11;
// ■ meses com 31 dias: 01, 03, 05, 07, 08, 10,12;
// ■ cálculo de ano bissexto: cada ano divisível por 4 é um ano bissexto(E); cada ano divisível por 100 não é bissexto
// (OU); todo ano divisível por 400 sempre é um ano bissexto;
#define VERDADEIRO 1
#define FALSO 0
typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;
int validaData(int dia, int mes, int ano);

int main(){
    Data inputData;
    int resultado;
    
    printf("Digite a data a ser validada: ");
    scanf("%d %d %d", &inputData.dia, &inputData.mes, &inputData.ano);
    
    resultado = validaData(inputData.dia, inputData.mes, inputData.ano);
    
    if(resultado == 0) printf("A data digitada é falsa!");
    else printf("A data digitada é verdadeira!");
    
}

int validaData(int dia, int mes, int ano){
    int valor = VERDADEIRO;
    
    // Valida os meses de 30 dias:
    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) valor = FALSO;
    
    // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
    if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
        if (mes == 2 && dia > 29) valor = FALSO;
    } else {
        if(mes == 2 && dia > 28) valor = FALSO;
    }
    
    // Valida se as datas digitadas existem:
    if(dia > 31 || dia < 1 || mes > 12 || mes  < 1 ) valor = FALSO;
    
    return valor;
}

#include <stdio.h>
#include <stdlib.h>
// Q01.2 => Uma função que recebe como parâmetro uma data do tipo string (no formato DD/MM/AAAA) e uma estrutura do
// tipo Data, onde o resultado deve ser armazenado, e retorna verdadeiro se a data estiver válida; caso contrário, retorna
// falso;
#define VERDADEIRO 1
#define FALSO 0
#define TAMDATA 11

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

int validaData(char stringData[]);
Data quebraData(char stringData[]);

int main(){
    char inputData[TAMDATA];
    int resultado;
    
    printf("Digite a data a ser validada: ");
    fgets(inputData, TAMDATA, stdin);
    
    resultado = validaData(inputData);
    
    if(resultado == 0) printf("A data digitada é falsa!");
    else printf("A data digitada é verdadeira!");
    
}

int validaData(char stringData[]){
    int valor = VERDADEIRO;
    
    Data dataQuebrada = quebraData(stringData);
    
    // Valida os meses de 30 dias:
    if((dataQuebrada.mes == 4 || dataQuebrada.mes == 6 || dataQuebrada.mes == 9 || dataQuebrada.mes == 11) && dataQuebrada.dia > 30) valor = FALSO;
    
    // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
    if ((dataQuebrada.ano % 4 == 0)  && ((dataQuebrada.ano % 100 != 0) || (dataQuebrada.ano % 400 == 0))){
        if (dataQuebrada.mes == 2 && dataQuebrada.dia > 29) valor = FALSO;
    } else {
        if(dataQuebrada.mes == 2 && dataQuebrada.dia > 28) valor = FALSO;
    }
    
    // Valida se as datas digitadas existem:
    if(dataQuebrada.dia > 31 || dataQuebrada.dia < 1 || dataQuebrada.mes > 12 || dataQuebrada.mes  < 1 ) valor = FALSO;
    
    return valor;
}

Data quebraData(char stringData[]){
    int i, j, k, h;
    Data dataQuebrada;
    char stringDia[3];
    char stringMes[3];
    char stringAno[5];
    
    for(i = 0, j =0, k = 0, h = 0; i < TAMDATA; i++){
        if(stringData[i] >= '0' && stringData[i] <= '9'){
            if(i < 2){
               stringDia[j] = stringData[i];
               j++;
            } 
            if(i > 2 && i < 5){
                stringMes[k] = stringData[i];
                k++;
            } 
            if(i > 5 && i < 10){
                stringAno[h] = stringData[i];
                h++;
            } 
        }   
    }
    
    stringDia[2] = '\0';
    stringMes[2] = '\0';
    stringAno[4] = '\0';

    dataQuebrada.dia = atoi(stringDia);
    dataQuebrada.mes = atoi(stringMes);
    dataQuebrada.ano = atoi(stringAno);
    
    printf("Data quebrada: %d/%d/%d \n", dataQuebrada.dia, dataQuebrada.mes, dataQuebrada.ano);
    
    return dataQuebrada;
}

#include <stdio.h>
//Q01.3 Uma função que recebe como parâmetro uma estrutura do tipo Data e um número inteiro, e retorna a soma do número de dias da data recebida;
#define VERDADEIRO 1
#define FALSO 0
typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;
int validaData(int dia, int mes, int ano);
int ehBissexto(int ano);

int main(){
    Data inputData;
    int valida;
    int qtdDias;
    int somaDias;
    int inteiro;
    int mes31 = 31;
    int mes30 = 30;
    
    printf("Digite a data a ser contada os dias: ");
    scanf("%d %d %d", &inputData.dia, &inputData.mes, &inputData.ano);
    valida = validaData(inputData.dia, inputData.mes, inputData.ano);
    if(valida == 0){
      printf("A data digitada é falsa! Favor digitar uma data válida. \n");
      return 0;
    }
    printf("Digite o intero a ser somado: ");
    scanf("%d", &inteiro);
    
    int diasFev;
    if(ehBissexto(inputData.ano)) diasFev = 29;
    else diasFev = 28;

    switch(inputData.mes){
      case 1: qtdDias = inputData.dia; break;
      case 2: qtdDias = mes31 + inputData.dia; break;
      case 3: qtdDias = mes31 + diasFev + inputData.dia; break;
      case 4: qtdDias = (mes31*2) + diasFev + inputData.dia; break;
      case 5: qtdDias = (mes31*2) + mes30 + diasFev + inputData.dia; break;
      case 6: qtdDias = (mes31*3) + mes30 + diasFev + inputData.dia; break;
      case 7: qtdDias = (mes31*3) + (mes30*2) + diasFev + inputData.dia; break;
      case 8: qtdDias = (mes31*4) + (mes30*2) + diasFev + inputData.dia; break;
      case 9: qtdDias = (mes31*5) + (mes30*2) + diasFev + inputData.dia; break;
      case 10: qtdDias = (mes31*5) + (mes30*3) + diasFev + inputData.dia; break;
      case 11: qtdDias = (mes31*6) + (mes30*3) + diasFev + inputData.dia; break;
      case 12: qtdDias = (mes31*6) + (mes30*4) + diasFev + inputData.dia; break;
    }
    
    printf("A quantidade de dias deste ano é de: %d \n", qtdDias);
    qtdDias += inteiro;
    printf("A quantidade de dias deste ano é somada ao intero é de: %d", qtdDias);
 
}


int validaData(int dia, int mes, int ano){
  int valor = VERDADEIRO;
  int bissexto;
  // Valida os meses de 30 dias:
  if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) valor = FALSO;
  
  // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
  bissexto = ehBissexto(ano);
  
  if (mes == 2){
    if ((bissexto == 1) && dia > 29) valor = FALSO;
    else if ((bissexto == 0) && dia > 28) valor = FALSO;
  }
  
  // Valida se as datas digitadas existem:
  if(dia > 31 || dia < 1 || mes > 12 || mes  < 1 ) valor = FALSO;
  
  return valor;
}

int ehBissexto(int ano){
  if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
    return VERDADEIRO;
  } else {
    return FALSO;
  }
}

#include <stdio.h>
//Q01.4 Uma função que recebe como parâmetro uma estrutura do tipo Data e um número inteiro, e retorna a subtração do número de dias da data recebida;
#define VERDADEIRO 1
#define FALSO 0
typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;
int validaData(int dia, int mes, int ano);
int ehBissexto(int ano);

int main(){
    Data inputData;
    int valida;
    int qtdDias;
    int somaDias;
    int inteiro;
    int mes31 = 31;
    int mes30 = 30;
    
    //printf("Digite a data a ser contada os dias: ");
    printf("Digite a data a ser subtraida os dias: ");
    scanf("%d %d %d", &inputData.dia, &inputData.mes, &inputData.ano);
    valida = validaData(inputData.dia, inputData.mes, inputData.ano);
    if(valida == 0){
      printf("A data digitada é falsa! Favor digitar uma data válida. \n");
      return 0;
    }
    printf("Digite o intero a ser subtraido: ");
    scanf("%d", &inteiro);
    
    int diasFev;
    if(ehBissexto(inputData.ano)) diasFev = 29;
    else diasFev = 28;

    // Soma os dias e subtrai o inteiro?
    // switch(inputData.mes){
    //   case 1: qtdDias = inputData.dia; break;
    //   case 2: qtdDias = mes31 + inputData.dia; break;
    //   case 3: qtdDias = mes31 + diasFev + inputData.dia; break;
    //   case 4: qtdDias = (mes31*2) + diasFev + inputData.dia; break;
    //   case 5: qtdDias = (mes31*2) + mes30 + diasFev + inputData.dia; break;
    //   case 6: qtdDias = (mes31*3) + mes30 + diasFev + inputData.dia; break;
    //   case 7: qtdDias = (mes31*3) + (mes30*2) + diasFev + inputData.dia; break;
    //   case 8: qtdDias = (mes31*4) + (mes30*2) + diasFev + inputData.dia; break;
    //   case 9: qtdDias = (mes31*5) + (mes30*2) + diasFev + inputData.dia; break;
    //   case 10: qtdDias = (mes31*5) + (mes30*3) + diasFev + inputData.dia; break;
    //   case 11: qtdDias = (mes31*6) + (mes30*3) + diasFev + inputData.dia; break;
    //   case 12: qtdDias = (mes31*6) + (mes30*4) + diasFev + inputData.dia; break;
    // }
  
    // Ou subtrai os dias e o inteiro?
    switch(inputData.mes){
      case 1: qtdDias = 0 - inputData.dia; break;
      case 2: qtdDias = 0 - mes31 - inputData.dia; break;
      case 3: qtdDias = 0 - mes31 - diasFev - inputData.dia; break;
      case 4: qtdDias = 0 - (mes31*2) - diasFev - inputData.dia; break;
      case 5: qtdDias = 0 - (mes31*2) - mes30 - diasFev - inputData.dia; break;
      case 6: qtdDias = 0 - (mes31*3) - mes30 - diasFev - inputData.dia; break;
      case 7: qtdDias = 0 - (mes31*3) - (mes30*2) - diasFev - inputData.dia; break;
      case 8: qtdDias = 0 - (mes31*4) - (mes30*2) - diasFev - inputData.dia; break;
      case 9: qtdDias = 0 - (mes31*5) - (mes30*2) - diasFev - inputData.dia; break;
      case 10: qtdDias = 0 - (mes31*5) - (mes30*3) - diasFev - inputData.dia; break;
      case 11: qtdDias = 0 - (mes31*6) - (mes30*3) - diasFev - inputData.dia; break;
      case 12: qtdDias = 0 - (mes31*6) - (mes30*4) - diasFev - inputData.dia; break;
    }
    
    // printf("A quantidade de dias deste ano é de: %d \n", qtdDias);
    printf("A subtração dos dias deste ano é de: %d \n", qtdDias);
    // qtdDias += inteiro;
    qtdDias -= inteiro;
    printf("A quantidade de dias deste ano é subtraida ao intero é de: %d", qtdDias);
 
}


int validaData(int dia, int mes, int ano){
  int valor = VERDADEIRO;
  int bissexto;
  // Valida os meses de 30 dias:
  if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) valor = FALSO;
  
  // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
  bissexto = ehBissexto(ano);
  
  if (mes == 2){
    if ((bissexto == 1) && dia > 29) valor = FALSO;
    else if ((bissexto == 0) && dia > 28) valor = FALSO;
  }
  
  // Valida se as datas digitadas existem:
  if(dia > 31 || dia < 1 || mes > 12 || mes  < 1 ) valor = FALSO;
  
  return valor;
}

int ehBissexto(int ano){
  if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
    return VERDADEIRO;
  } else {
    return FALSO;
  }
}

#include <stdio.h>
//Q01.5 Uma função que recebe como parâmetro uma data e escreve essa data por extenso. Por exemplo, 25/03/2007 deve ser escrito como 25 de março de 2007.
// A função deve retornar verdadeiro se a operação for realizada com sucesso e falso, caso contrário;
#define VERDADEIRO 1
#define FALSO 0
typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;
int validaData(int dia, int mes, int ano);
int ehBissexto(int ano);

int main(){
    Data inputData;
    int valida;
    char meses[12][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    printf("Digite a data a ser escrita por extenso: ");
    scanf("%d %d %d", &inputData.dia, &inputData.mes, &inputData.ano);
  
    valida = validaData(inputData.dia, inputData.mes, inputData.ano);
    if(valida == 0){
      printf("A data digitada é falsa! Favor digitar uma data válida. \n");
      return 0;
    } else {
      printf("A data digitada é válida! \n");
      printf("Data por extenso: %d de %s de %d", inputData.dia, meses[inputData.mes - 1] , inputData.ano);
    }
}


int validaData(int dia, int mes, int ano){
  int valor = VERDADEIRO;
  int bissexto;
  // Valida os meses de 30 dias:
  if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) valor = FALSO;
  
  // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
  bissexto = ehBissexto(ano);
  
  if (mes == 2){
    if ((bissexto == 1) && dia > 29) valor = FALSO;
    else if ((bissexto == 0) && dia > 28) valor = FALSO;
  }
  
  // Valida se as datas digitadas existem:
  if(dia > 31 || dia < 1 || mes > 12 || mes  < 1 ) valor = FALSO;
  
  return valor;
}

int ehBissexto(int ano){
  if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
    return VERDADEIRO;
  } else {
    return FALSO;
  }
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Q02. => Considere uma aplicação para armazenar os seguintes dados de uma pessoa em uma agenda de endereços:
// nome, endereço e telefone. Especifique um TAD para armazenar os dados das pessoas e as operações
// necessárias para inserir, consultar e excluir os dados das pessoas.
#include <stdio.h>
#include <stdlib.h>

#define TAMNOME 41
#define TAMEND 101
#define TAMNUM 18
#define NUMCONTATOS 50

typedef struct dados{
  int id;
  char nome[TAMNOME];
  char endereco[TAMEND];
  char numero[TAMNUM];
} Pessoa;

int inscreverPessoa(Pessoa contatos[],int qtdPessoas);
void listarContatos(Pessoa contatos[],int qtdPessoas);
int excluirPessoa(Pessoa contatos[],int qtdPessoas);
int getId();

int imprimeMenu(){
  int opcao;
  printf("\n========================================== \n");
  printf("Seja bem vindo a lista de contatos.\n");
  printf("Digite a opção desejada:\n");
  printf("  1 - Adicionar Contato\n  2 - Listar Contatos\n  3 - Excluir contato\n  0 - Sair da aplicação \n");
  scanf("%d", &opcao);
  return opcao;
}

int main(){
  Pessoa contatos[NUMCONTATOS];
  int qtdPessoas = 0;

  int opcao = 1;

  while(opcao != 0){
    opcao = imprimeMenu();

    switch(opcao){
      case 0: {
        printf("\n ... ENCERRANDO PROGRAMA ... \n");
        break;
      }
      case 1: {
        qtdPessoas = inscreverPessoa(contatos, qtdPessoas);
        break;
      }
      case 2: {
        listarContatos(contatos, qtdPessoas);
        break;
      }
      case 3: {
        qtdPessoas = excluirPessoa(contatos, qtdPessoas);
        break;
      }
      default: printf("\n Número digitado é inválido. Escolha uma das opçoes de 0 a 3\n ");
    }
  } 
}

int inscreverPessoa(Pessoa contatos[],int qtdPessoas){
  
  printf("============ CADASTRO DE CONTATOS ============ \n");
  contatos[qtdPessoas].id = getId();

  getchar();
  printf("Digite o seu nome: \n");
  fgets(contatos[qtdPessoas].nome, TAMNOME, stdin);
  getchar();
  
  printf("Digite o seu Endereço: \n");
  fgets(contatos[qtdPessoas].endereco, TAMEND, stdin);
  getchar();
  
  printf("Digite o seu Telefone: \n");
  fgets(contatos[qtdPessoas].numero, TAMNUM, stdin);
  getchar();

  
  qtdPessoas++;
  return qtdPessoas;
}

int getId() {
  static int id = 0;
  id++;
  return id;
}

void listarContatos(Pessoa contatos[],int qtdPessoas){
  if(qtdPessoas == 0){
    printf("\n Não há contatos cadastrados! \n");
  } else {
    printf("\n ============ LISTA DE CONTATOS ============\n");
    for (int i = 0; i < qtdPessoas; i++) {
      printf("ID: %d\nNOME: %s \nENDEREÇO: %s\nTELEFONE: %s", contatos[i].id, contatos[i].nome, contatos[i].endereco, contatos[i].numero);
      printf("\n------------------------------------\n");
    } 
  }
}

int excluirPessoa(Pessoa contatos[],int qtdPessoas){
  int id;
  if(qtdPessoas == 0){
    printf("\n Não há contatos cadastrados! \n"); 
    return qtdPessoas;
  } else {
    printf("Digite o id da pessoa que gostaria de excluir: \n");
    scanf("%d",&id);
  
    for(int i = 0; i < qtdPessoas; i++){
      if (contatos[i].id == id){
        for(int j = i; j < qtdPessoas - 1; j++){
          contatos[j] = contatos[j+1];
        }
        printf("\n Contato excluído com sucesso! \n");
        qtdPessoas --;
        return qtdPessoas;
      }
    }
    printf("\n Pessoa não encontrada: Id inválido! \n");
    return qtdPessoas;
  }
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Q03. => Considere uma aplicação para armazenar os seguintes dados de carros para uma garagem: placa, marca/modelo e cor.
// Especifique um TAD para armazenar os dados dos carros e as operações necessárias para inserir, consultar e excluir os dados dos carros.
#include <stdio.h>

#define NUMCARROS 50
#define TAMPLACA 8
#define TAMNOME 20

typedef struct dados{
  int id;
  char placa[TAMPLACA];
  char marca[TAMNOME];
  char modelo[TAMNOME];
  char cor[TAMNOME];
} Carro;

int inscreveCarro(Carro carros[],int qtdCarros);
void listarCarros(Carro carros[],int qtdCarros);
int excluirCarro(Carro carros[],int qtdCarros);
int getId();

int imprimeMenu(){
  int opcao;
  printf("\n========================================== \n");
  printf("Seja bem vindo a lista de carros.\n");
  printf("Digite a opção desejada:\n");
  printf("  1 - Adicionar carro\n  2 - Listar Carros\n  3 - Excluir carro\n  0 - Sair da aplicação \n");
  scanf("%d", &opcao);
  return opcao;
}

int main(){
  Carro carros[NUMCARROS];
  int qtdCarros = 0;

  int opcao = 1;

  while(opcao != 0){
    opcao = imprimeMenu();

    switch(opcao){
      case 0: {
        printf("\n ... ENCERRANDO PROGRAMA ... \n");
        break;
      }
      case 1: {
        qtdCarros = inscreveCarro(carros, qtdCarros);
        break;
      }
      case 2: {
        listarCarros(carros, qtdCarros);
        break;
      }
      case 3: {
        qtdCarros = excluirCarro(carros, qtdCarros);
        break;
      }
      default: printf("\n Número digitado é inválido. Escolha uma das opçoes de 0 a 3 \n");
    }
  } 
}

int inscreveCarro(Carro carros[],int qtdCarros){
  
  printf("============ CADASTRO DE CARROS ============ \n");
  carros[qtdCarros].id = getId();

  getchar();
  printf("Digite a placa do carro: \n");
  fgets(carros[qtdCarros].placa, TAMPLACA, stdin);
  getchar();
  
  printf("Digite a marca do carro: \n");
  fgets(carros[qtdCarros].marca, TAMNOME, stdin);
  getchar();
  
  printf("Digite o modelo do carro: \n");
  fgets(carros[qtdCarros].modelo, TAMNOME, stdin);
  getchar();
  
  printf("Digite a cor do carro: \n");
  fgets(carros[qtdCarros].cor, TAMNOME, stdin);
  getchar();

  qtdCarros++;
  return qtdCarros;
}

int getId() {
  static int id = 0;
  id++;
  return id;
}

void listarCarros(Carro carros[],int qtdCarros){
  if(qtdCarros == 0){
    printf("\n Não há carros cadastrados! \n"); 
  } else {
    printf("\n ============ LISTA DE CARROSS ============\n");
    for (int i = 0; i < qtdCarros; i++) {
      printf("ID: %d\nPLACA: %s \nMARCA: %s\nMODELO: %s\nCOR: %s", carros[i].id, carros[i].placa, carros[i].marca, carros[i].modelo, carros[i].cor);
      printf("\n------------------------------------\n");
    } 
  }
}

int excluirCarro(Carro carros[],int qtdCarros){
  int id;

  if(qtdCarros == 0){
    printf("\n Não há carros cadastrados! \n"); 
    return qtdCarros;
  } else {
    printf("Digite o id do carro que gostaria de excluir: \n");
    scanf("%d",&id);
  
    for(int i = 0; i < qtdCarros; i++){
      if (carros[i].id == id){
        for(int j = i; j < qtdCarros - 1; j++){
          carros[j] = carros[j+1];
        }
        printf("\n Carro excluído com sucesso! \n");
        qtdCarros --;
        return qtdCarros;
      }
    }
    printf("\n Carro não encontrado: Id inválido! \n");
    return qtdCarros; 
  }
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Q04. =>  Considere uma empresa que precisa armazenar os seguintes dados de um cliente: 
// ■ Nome completo;
// ■ Ano de nascimento;
// ■ Renda mensal do cliente.
// Especifique um TAD para armazenar os dados de um cliente e as operações  necessárias para inserir, consultar e excluir os dados dos clientes.
// Especifique também operações para exibir o número de clientes com renda mensal acima da média,
//e exibir o número de clientes que nasceram entre 1980 e 2000.
#include <stdio.h>

#define TAMNOME 101
#define NUMCLIENTES 50

typedef struct dados {
  int id;
  char nome[TAMNOME];
  int anoDeNasc;
  float rendaMensal;
} Cliente;

int getId();
int inscreverPessoa(Cliente clientes[], int qtdClientes);
void listarContatos(Cliente clientes[], int qtdClientes);
int excluirPessoa(Cliente clientes[], int qtdClientes);
int numeroRendaAcimaDaMedia(Cliente clientes[], int qtdClientes);
int numeroClientesNascidos(Cliente clientes[], int qtdClientes);

int imprimeMenu() {
  int opcao;
  printf("\n========================================== \n");
  printf("Seja bem vindo a lista de clientes.\n");
  printf("Digite a opção desejada:\n");
  printf("  1 - Adicionar Cliente\n  2 - Listar Clientes\n  3 - Excluir clientes\n  4 - Exibir n° de clientes com renda mensal acima da média\n  5 - Exibir n° de clientes que nasceram entre 1980 e 2000\n  0 - Sair da aplicação\n");
  scanf("%d", &opcao);
  return opcao;
}

int main() {
  Cliente clientes[NUMCLIENTES];
  int qtdClientes = 0;
  int numero;

  int opcao = 1;

  while (opcao != 0) {
    opcao = imprimeMenu();

    switch (opcao) {
      case 0: {
        printf("\n ... ENCERRANDO PROGRAMA ... \n");
        break;
      }
      case 1: {
        qtdClientes = inscreverPessoa(clientes, qtdClientes);
        break;
      }
      case 2: {
        listarContatos(clientes, qtdClientes);
        break;
      }
      case 3: {
        qtdClientes = excluirPessoa(clientes, qtdClientes);
        break;
      }
      case 4: {
        numero = numeroRendaAcimaDaMedia(clientes, qtdClientes);
        if (numero == -1) printf("\n Não há clientes cadastrados! \n");
        else if (numero == 0) printf("\n Não há clientes com renda acima da média \n");
        else printf("\n Existe(m) %d cliente(s) com renda acima da média \n", numero);
        break;
      }
      case 5: {
        numero = numeroClientesNascidos(clientes, qtdClientes);
        if (numero == -1) printf("\n Não há clientes cadastrados! \n");
        else if (numero == 0) printf("\n Não há clientes nascidos entre 1980 e 2000 \n");
        else printf("\n Existe(m) %d cliente(s) nascido(s) entre 1980 e 2000 \n", numero);
        break;
      }
    default:
      printf("\n Número digitado é inválido. Escolha uma das opções de 0 a 5: \n");
    }
  }
}

int inscreverPessoa(Cliente clientes[], int qtdClientes) {

  printf("============ CADASTRO DE CONTATOS ============ \n");
  clientes[qtdClientes].id = getId();

  getchar();
  printf("Digite o seu nome: \n");
  fgets(clientes[qtdClientes].nome, TAMNOME, stdin);
  getchar();

  printf("Digite o seu ano de nascimento: \n");
  scanf("%d", &clientes[qtdClientes].anoDeNasc);

  printf("Digite a sua renda mensal: \n");
  scanf("%f", &clientes[qtdClientes].rendaMensal);

  qtdClientes++;
  return qtdClientes;
}

int getId() {
  static int id = 0;
  id++;
  return id;
}

void listarContatos(Cliente clientes[], int qtdClientes) {
  if (qtdClientes == 0) {
    printf("\n Não há clientes cadastrados! \n");
  } else {
    printf("\n ============ LISTA DE CLIENTES ============\n");
    for (int i = 0; i < qtdClientes; i++) {
      printf("ID: %d\nNOME: %s \nANO DE NASCIMENTO: %d\nRENDA MENSAL: %.2f", clientes[i].id, clientes[i].nome, clientes[i].anoDeNasc, clientes[i].rendaMensal);
      printf("\n------------------------------------\n");
    }
  }
}

int excluirPessoa(Cliente clientes[], int qtdClientes) {
  int id;
  if (qtdClientes == 0) {
    printf("\n Não há clientes cadastrados! \n");
    return qtdClientes;
  }else {
    printf("Digite o id do cliente que gostaria de excluir: \n");
    scanf("%d", &id);
  
    for (int i = 0; i < qtdClientes; i++) {
      if (clientes[i].id == id) {
        for (int j = i; j < qtdClientes - 1; j++) {
          clientes[j] = clientes[j + 1];
        }
        printf("\n Cliente excluído com sucesso! \n");
        qtdClientes--;
        return qtdClientes;
      }
    }
    printf("\n Cliente não encontrada: Id inválido! \n");
    return qtdClientes;
  }
}

int numeroRendaAcimaDaMedia(Cliente clientes[], int qtdClientes) {
  float soma;
  float media;
  int i;
  int numero = 0;
  
  if (qtdClientes == 0) {
    return -1;
  }else {
    for(i = 0; i < qtdClientes; i++){
      soma += clientes[i].rendaMensal;
    }
    media = soma/i;

    printf("\n A média dos salários é de: %.2f \n", media);

    for(i =0 ; i < qtdClientes; i++){
      if(clientes[i].rendaMensal > media){
        numero++;
      }
    }
    return numero;
  }
}

int numeroClientesNascidos(Cliente clientes[], int qtdClientes) {
  int numero = 0;

  if (qtdClientes == 0) {
    return -1;
  }else {
    for(int i = 0; i < qtdClientes; i++){
      if(clientes[i].anoDeNasc >= 1980 && clientes[i].anoDeNasc <= 2000) numero++;
    }
    return numero;
  }
}

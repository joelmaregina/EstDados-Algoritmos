#include <stdio.h>
// uma função que recebe como parâmetro o dia, o mês, o ano e uma estrutura do tipo Data, onde o resultado deve
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


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

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <stdio.h>
// Uma função que recebe como parâmetro uma data do tipo string (no formato DD/MM/AAAA) e uma estrutura do
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
    int i, j;
    Data dataQuebrada;
    char stringDia[3];
    char stringMes[3];
    char stringAno[5];
    
    for(i = 0, j =0; i < TAMDATA; i++, j++) if(stringData[i] >= '0' && stringData[i] <= '9') dia[j] = stringData[i]; 
    dia[3] = '\0';
    i++;
    
    for(j =0; i < TAMDATA; i++, j++) if(stringData[i] >= '0' && stringData[i] <= '9') mes[j] = stringData[i]; 
    mes[3] = '\0';
    i++;
    
    for(j =0; i < TAMDATA; i++, j++) if(stringData[i] >= '0' && stringData[i] <= '9') ano[j] = stringData[i]; 
    ano[5] = '\0';

    dataQuebrada.dia = atoi(stringDia);
    dataQuebrada.mes = atoi(stringMes);
    dataQuebrada.ano = atoi(stringAno);
    
    return dataQuebrada;
    
}


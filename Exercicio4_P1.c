#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//Declaração das constantes de tamanho dos arrays
#define SZ_STR 19
#define SZ_INT 14

//Declaração das variáveis globais
char strCnpj[SZ_STR]; // String de 19 caracteres, inseridos pelo usuário, sendo 18 caracteres para o CNPJ e 1 para o '\0'
int contFuncMascara; // Variável para contar a quantidade de vezes que a função colocarMascaraCnpj foi executada.

//Declaração de funções
void colocarMascaraCnpj();

//Função principal
int exercicio4_parte1()
{
    do {
        int numCnpj[SZ_INT]; // Array de números do cnpj, inteiros e sem máscara
        int i, j; // Iteradores

        contFuncMascara = 0;

        // Inicializando os arrays de CNPJ
        for(i = 0; i < SZ_STR; i++)
            strCnpj[i] = '\0';
        for(i = 0; i < SZ_INT; i++)
            numCnpj[i] = -1;

        // Recebendo o número do CNPJ com máscara
        for(i = 0; i < SZ_INT; i++)
        {
            system("CLS");
            printf("---   PROGRAMA PARA VERIFICAR SE UM N%CMERO DE CNPJ %C V%CLIDO OU N%CO   ---\n\n\n", 233, 144, 181, 199);

            if(i == 0)
            {
                printf("Digite o n%cmero do CNPJ: ", 163);
                strCnpj[strlen(strCnpj)] = getche();
                colocarMascaraCnpj();
            }
            else
            {
                colocarMascaraCnpj();
                printf("Digite o n%cmero do CNPJ: %s", 163, strCnpj);
                strCnpj[strlen(strCnpj)] = getche();
            }
        }

        //Removendo a máscara e convertendo os caracteres para int
        j = 0;
        for(i = 0; i < sizeof(strCnpj) - 1; i++)
            if(i != 2 && i != 6 && i != 10 && i != 15)
                numCnpj[j++] = (int)strCnpj[i] - 48;

        //Calculando o Primeiro Dígito Verificador
        int matriz1[3][SZ_INT - 2];
        int pesos1[] = {5,4,3,2,9,8,7,6,5,4,3,2};
        int soma1 = 0;

        for(i = 0; i < SZ_INT - 2; i++)
        {
            matriz1[0][i] = numCnpj[i]; // Preenchendo a primeira linha da matriz com o número do CNPJ
            matriz1[1][i] = pesos1[i]; // Preenchendo a segunda linha da matriz com os pesos
            matriz1[2][i] = matriz1[0][i] * matriz1[1][i]; // Preenchendo a terceira linha da matriz com a multiplicação
            soma1 += matriz1[2][i]; // Somando todos os valores da terceira linha da matriz
        }

        int digitoVerificador1;
        int restoDivisao1 = soma1 % 11;
        if(restoDivisao1 < 2)
            digitoVerificador1 = 0;
        else
            digitoVerificador1 = 11 - restoDivisao1;

        //Calculando o Segundo Dígito Verificador
        int matriz2[3][SZ_INT - 1];
        int pesos2[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
        int soma2 = 0;

        for(i = 0; i < SZ_INT - 1; i++)
        {
            if(i == SZ_INT - 2)
                matriz2[0][i] = digitoVerificador1; // Preenchendo a última coluna da primeira linha da matriz com o dígito verificador encontrado
            else
                matriz2[0][i] = numCnpj[i]; // Preenchendo a primeira linha da matriz com o número do CNPJ

            matriz2[1][i] = pesos2[i]; //Preenchendo a segunda linha da matriz com os pesos
            matriz2[2][i] = matriz2[0][i] * matriz2[1][i]; // Preenchendo a terceira linha da matriz com a multiplicação
            soma2 += matriz2[2][i]; // Somando todos os valores da terceira linha da matriz
        }

        int digitoVerificador2;
        int restoDivisao2 = soma2 % 11;
        if(restoDivisao2 < 2)
            digitoVerificador2 = 0;
        else
            digitoVerificador2 = 11 - restoDivisao2;

        // Verificando se o cnpj digitado é válido ou inválido
        if(numCnpj[SZ_INT - 2] == digitoVerificador1 && numCnpj[SZ_INT - 1] == digitoVerificador2)
            printf("\n\n\nCNPJ V%cLIDO!\n\n\n", 181);
        else
            printf("\n\n\nCNPJ INV%cLIDO!\n\n\n", 181);

        printf("\nDeseja verificar outro CNPJ? [s/n]: ");
    } while(tolower(getche()) == 's');

    return 0;
}

void colocarMascaraCnpj()
{
    switch(contFuncMascara)
    {
        case 2:
            strCnpj[strlen(strCnpj)] = '.';
            break;
        case 5:
            strCnpj[strlen(strCnpj)] = '.';
            break;
        case 8:
            strCnpj[strlen(strCnpj)] = '/';
            break;
        case 12:
            strCnpj[strlen(strCnpj)] = '-';
            break;
    }

    contFuncMascara++;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int exercicio4_parte1();
int exercicio4_parte2();

int exercicio4()
{
    int num = 0;
    int ex = 1;

    do {
        ex = 1;
        system("CLS");
        printf("---   EXERC%cCIO 4   ---\n\n\n", 214);
        printf("[1] Parte 1 - Valida%c%co de CNPJ\n", 135, 198);
        printf("[2] Parte 2 - Criptografia de Mensagens\n");
        printf("\nQual parte desse exerc%ccio deseja executar? [0 para voltar]: ", 161);
        scanf("%d", &num);

        switch(num)
        {
            case 0:
                ex = 0;
                break;
            case 1:
                system("CLS");
                exercicio4_parte1();
                break;
            case 2:
                system("CLS");
                printf("---   PARTE 2 - CRIPTOGRAFIA DE MENSAGENS   ---\n\n\n");
                exercicio4_parte2();
                break;
            default:
                printf("\n\nOp%c%co inv%clida!!!\n", 135, 198, 160);
                sleep(2);
                break;
        }
    } while(ex != 0);

    return 0;
}

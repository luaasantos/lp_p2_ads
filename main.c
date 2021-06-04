#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int exercicio2();
int exercicio4();

int main()
{
    int num = 0;
    int ex = 1;

    do {
        int i;
        ex = 1;

        system("CLS");
        printf("LISTA DE EXERC%cCIOS FINAL\n\n", 214);
        for(i = 2; i <= 4; i += 2)
        {
            printf("[%d] Exerc%ccio %d \n", i, 161, i);
        }
        printf("\nQual exerc%ccio deseja executar? [0 para sair]: ", 161);
        scanf("%d", &num);

        switch(num)
        {
            case 0:
                ex = 0;
                break;
            case 2:
                system("CLS");
                exercicio2();
                break;
            case 4:
                system("CLS");
                exercicio4();
                break;
            default:
                printf("\n\nOp%c%co inv%clida!!!\n", 135, 198, 160);
                sleep(2);
        }
    } while(ex != 0);

    return 0;
}

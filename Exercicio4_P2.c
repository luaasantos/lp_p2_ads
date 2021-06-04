#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio4_parte2()
{
    char mensagem[1000];
    int i = 0;

    fflush(stdin); // Descarrega o buffer do teclado
    printf("Digite a mensagem que deseja criptografar (at%c 1000 caracteres):\n\n", 130);
    fgets(mensagem, sizeof(mensagem), stdin);

    // Primeira passada
    while(mensagem[i] != '\0')
    {
        if((mensagem[i] >= 65 && mensagem[i] <= 90) || (mensagem[i] >= 97 && mensagem[i] <= 122)) // Verifica se os caracteres são letras maiúsculas ou minúsculas
            mensagem[i] += 3; // Desloca os caracteres 3 posições à direita na tabela ASCII
        i++;
    }

    // Segunda passada
    strrev(mensagem); // Inverte a mensagem

    // Terceira passada
    if(i % 2 != 0)
        i++; // Ajusta o iterador para ser divisível por 2
    i /= 2; // Encontra a posição do meio da mensagem
    while(mensagem[i] != '\0')
    {
        mensagem[i] -= 1; // Desloca os caracteres 1 posição à esquerda na tabela ASCII
        i++;
    }

    printf("\n----------------------------\n\nMensagem criptografada:\n\n");
    puts(mensagem);

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

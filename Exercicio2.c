#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

//Declaração das constantes de valores boolean
#define true 1
#define false 0

struct Produto {
    int codigo;
    char descricao[100];
    float precoUnit;
};
typedef struct Produto Produto; // Criação do tipo Produto ao invés de struct Produto

struct Carrinho {
    int numitem;
    Produto* produto[100];
    int qtds[100];
    int qtdTotal;
    float precoTotal;
};
typedef struct Carrinho Carrinho; // Criação do tipo Carrinho ao invés de struct Carrinho

Carrinho carrinho;
Produto produtosAVenda[10]; // Array de: produtos que estarão disponíveis para venda
int carrinhoInicializado = false;

// Declaração das Funções
void inserirItensParaVender();
void inicializarProduto(Produto* produto);
void inicializarCarrinho();
void adicionarAoCarrinho(Produto* produto, int qtd);
void exibirCarrinho();
void pagarCompra();
void finalizarCompra();

int exercicio2()
{
    // Inserindo produtos para vender
    inserirItensParaVender();

    do {
        int num = 0;
        int i, qtd;
        int continuarLoop = false;

        do {
            system("CLS"); //Limpando a tela
            printf("---   EXERC%cCIO 2   ---\n\n\n", 214);
            printf("*** SUPERMERCADO XXX ***\n\n\nPRODUTOS A VENDA:\n\n");
            for(i = 0; i < 10; i++)
                printf("[%d] %s   | Pre%co: R%c %.2f\n", i + 1, produtosAVenda[i].descricao, 135, 36, produtosAVenda[i].precoUnit);
            printf("\n\nQual produto deseja comprar? [0 para sair]: ");
            scanf("%d", &num);

            continuarLoop = false;

            if(num == 0)
                return 0;
            else if(num > 10 || num < 1)
            {
                printf("\n\nOp%c%co inv%clida!!!\n", 135, 198, 160);
                sleep(2);
                continuarLoop = true;
            }
        } while(continuarLoop);

        printf("Quantos itens desse deseja comprar? ");
        scanf("%d", &qtd);

        if(! carrinhoInicializado)
            inicializarCarrinho();

        switch(num)
        {
            case 1:
                adicionarAoCarrinho(&produtosAVenda[0], qtd);
                break;
            case 2:
                adicionarAoCarrinho(&produtosAVenda[1], qtd);
                break;
            case 3:
                adicionarAoCarrinho(&produtosAVenda[2], qtd);
                break;
            case 4:
                adicionarAoCarrinho(&produtosAVenda[3], qtd);
                break;
            case 5:
                adicionarAoCarrinho(&produtosAVenda[4], qtd);
                break;
            case 6:
                adicionarAoCarrinho(&produtosAVenda[5], qtd);
                break;
            case 7:
                adicionarAoCarrinho(&produtosAVenda[6], qtd);
                break;
            case 8:
                adicionarAoCarrinho(&produtosAVenda[7], qtd);
                break;
            case 9:
                adicionarAoCarrinho(&produtosAVenda[8], qtd);
                break;
            case 10:
                adicionarAoCarrinho(&produtosAVenda[9], qtd);
                break;
            default:
                break;
        }

        exibirCarrinho();

        printf("\nDeseja continuar comprando? [s/n]: ");
    } while(tolower(getche()) == 's');

    int t;
    do {
        printf("\n\nO que deseja fazer?\n\n[f] Finalizar a compra\n[c] Cancelar e limpar o carrinho\n\nEscolha: ");
        t = getche();
        if(tolower(t) == 'f')
        {
            pagarCompra();
            finalizarCompra();
            break;
        }
        else if(tolower(t) == 'c')
        {
            printf("\n\n\nCOMPRA CANCELADA!!!");
            carrinhoInicializado = false;
            break;
        }
        else
        {
            printf("\n\n\nOp%c%co inv%clida!!!\n", 135, 198, 160);
            sleep(2);
        }
    } while(t != 'f' && t != 'c');

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

void inserirItensParaVender()
{
    int i;
    for(i = 0; i < 10; i++)
        inicializarProduto(&produtosAVenda[i]);

    produtosAVenda[0] = (Produto){ .codigo = 12311, .descricao = "COCA-COLA 2 LT", .precoUnit = 5.98 };
    produtosAVenda[1] = (Produto){ .codigo = 13111, .descricao = "FANTA 2 LT", .precoUnit = 5.23 };
    produtosAVenda[2] = (Produto){ .codigo = 14422, .descricao = "SKOL LATINHA", .precoUnit = 2.98 };
    produtosAVenda[3] = (Produto){ .codigo = 14221, .descricao = "SKOL GARRAFA", .precoUnit = 3.11 };
    produtosAVenda[4] = (Produto){ .codigo = 15245, .descricao = "ARROZ 5KG", .precoUnit = 15.18 };
    produtosAVenda[5] = (Produto){ .codigo = 15400, .descricao = "FARINHA DE TRIGO 1KG", .precoUnit = 8.55 };
    produtosAVenda[6] = (Produto){ .codigo = 16850, .descricao = "DANONE MORANGO", .precoUnit = 3.98 };
    produtosAVenda[7] = (Produto){ .codigo = 16999, .descricao = "PIPOCA DE MICROONDAS", .precoUnit = 2.11 };
    produtosAVenda[8] = (Produto){ .codigo = 17555, .descricao = "OVOS 1 DUZIA", .precoUnit = 6.25 };
    produtosAVenda[9] = (Produto){ .codigo = 18001, .descricao = "MUSSARELA 250G", .precoUnit = 12.50 };
}

void inicializarProduto(Produto* produto)
{
    int i;

    produto->codigo = -1; // Zera o código do produto
    for(i = 0; i< 100; i++)
        produto->descricao[i] = '\0'; // Zera todos os caracteres da descrição do produto
    produto->precoUnit = 0.00; // Zera o preço unitário
}

void inicializarCarrinho()
{
    int i;
    int min = 10000, max = 99999; // Valores mínimo e máximo para o código de compra
    srand(time(0)); // Utiliza a hora como semente de geração de números aleatórios

    carrinho.numitem = (rand() % (max - min + 1)) + min; // Gera um número aleatório como código da compra
    for(i = 0; i < 100; i++)
    {
        carrinho.produto[i] = NULL; // Zera todos os produtos do carrinho
        carrinho.qtds[i] = 0; // Zera todas as quantidade de produtos do carrinho
    }
    carrinho.qtdTotal = 0;
    carrinho.precoTotal = 0.00;

    carrinhoInicializado = true;
}

void adicionarAoCarrinho(Produto* produto, int qtd)
{
    int primeiraPosicaoVazia = 0;
    int i;

    for(i = 0; i < 100; i++)
        if(carrinho.produto[i] == NULL)
        {
            primeiraPosicaoVazia = i;
            break;
        }

    carrinho.produto[primeiraPosicaoVazia] = produto;
    carrinho.qtds[primeiraPosicaoVazia] = qtd;
    carrinho.qtdTotal += qtd;
    carrinho.precoTotal += produto->precoUnit * qtd;
}

void exibirCarrinho()
{
    printf("\n\n\n-----------------------------------\n        CARRINHO DE COMPRAS\n-----------------------------------\n\n");
    printf("C%cdigo da Compra: %d\n\nItens no carrinho: %d\nValor total: R%c %.2f\n", 162, carrinho.numitem, carrinho.qtdTotal, 36, carrinho.precoTotal);
    printf("\n-----------------------------------\n\n\n");
}

void pagarCompra()
{
    char numCartao[16];
    int validCartao;

    system("CLS");
    printf("\n\n---------------------------------------------------------------------------\n                               PAGAMENTO\n---------------------------------------------------------------------------\n\n");
    printf("Valor a Pagar: R%c %.2f\n\n\n", 36, carrinho.precoTotal);
    fflush(stdin); // Descarrega o buffer do teclado
    printf("Digite o n%cmero do seu cart%co de cr%cdito [16 d%cgitos]: ", 163, 198, 130, 161);
    fgets(numCartao, sizeof(numCartao), stdin);
    fflush(stdin); // Descarrega o buffer do teclado
    printf("Digite o c%cdigo de valida%c%co do cart%co [3 d%cgitos]: ", 162, 135, 198, 198, 161);
    scanf("%d", &validCartao);
    printf("\nProcessando pagamento... Aguarde!");
    sleep(1); // Faz a aplicação aguardar 1 segundo antes de continuar a executar a próxima função
    printf("\n...");
    sleep(1);
    printf("\n...");
    sleep(1);
    printf("\n...");
    sleep(1);
    printf("\n...");
    sleep(1);
    printf("\n\n\n\t*** PAGAMENTO APROVADO! ***\n\n\n");
    system("PAUSE");
}

void finalizarCompra()
{
    int i;
    int totalProdCarrinho = 0;

    system("CLS");
    printf("\n\n---------------------------------------------------\n                RECIBO DE COMPRA\n---------------------------------------------------\n\n");
    printf("C%cdigo da Compra: %d\n\nItens Comprados:\n\n", 162, carrinho.numitem);
    for(i = 0; i < 100; i++)
        if(carrinho.produto[i] == NULL)
        {
            totalProdCarrinho = i;
            break;
        }
    for(i = 0; i < totalProdCarrinho; i++)
        printf("\t%d | %s  | Qtd: %d = R%c %.2f\n", carrinho.produto[i]->codigo, carrinho.produto[i]->descricao, carrinho.qtds[i], 36, carrinho.qtds[i] * carrinho.produto[i]->precoUnit);
    printf("\nTotal de itens comprados: %d\nValor total: R%c %.2f\n", carrinho.qtdTotal, 36, carrinho.precoTotal);
    printf("\n---------------------------------------------------\n\n");

    carrinhoInicializado = false;
}

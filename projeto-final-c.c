#include <stdio.h>

void mostrar_menu()
{
    printf("\n");
    printf("=================================\n");
    printf("     LEAGUE BATTLE SIMULATOR\n");
    printf("=================================\n");
    printf("1 - Jogar\n");
    printf("2 - Ver campeoes\n");
    printf("3 - Sair\n");
    printf("=================================\n");
}

void mostrar_campeoes()
{
    printf("\n");
    printf("========== CAMPEOES ==========\n");
    printf("1 - Vi\n");
    printf("2 - Jinx\n");
    printf("3 - Yasuo\n");
    printf("4 - Lee Sin\n");
}

int main()
{
    int escolha;

    do
    {
        mostrar_menu();

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                printf("\nO jogo vai comecar em breve!\n");
                break;

            case 2:
                mostrar_campeoes();
                break;

            case 3:
                printf("\nA sair do jogo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (escolha != 3);

    return 0;
}
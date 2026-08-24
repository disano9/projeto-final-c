#include <stdio.h>

void mostrar_menu()
{
    printf("\n");
    printf("==============================================\n");
    printf("          LEAGUE BATTLE SIMULATOR             \n");
    printf("==============================================\n");
    printf("\n");
    printf("  \"You control the pace. You control the map.\n");
    printf("   You control the game.\"\n");
    printf("\n");
    printf("----------------------------------------------\n");
    printf("             [1] PLAY\n");
    printf("             [2] CHAMPIONS\n");
    printf("             [3] EXIT\n");
    printf("----------------------------------------------\n");
}

void mostrar_campeoes()
{
    printf("\n");
    printf("==============================================\n");
    printf("                 CHAMPIONS                    \n");
    printf("==============================================\n");
    printf("1 - Vi\n");
    printf("2 - Jarvan IV\n");
    printf("3 - Lee Sin\n");
    printf("4 - Nidalee\n");
    printf("==============================================\n");
}

void escolher_campeao()
{
    int escolha;

    mostrar_campeoes();

    printf("\nChoose your champion: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
        case 1:
            printf("\nYou chose Vi!\n");
            printf("\"Punch first. Ask questions while punching.\"\n");
            printf("- Vi\n");
            break;

        case 2:
            printf("\nYou chose Jarvan IV!\n");
            printf("\"Today is a good day to die!\"\n");
            printf("- Jarvan IV\n");
            break;

        case 3:
            printf("\nYou chose Lee Sin!\n");
            printf("\"I will struggle, I will fail, but to surrender is a privilege I do not have.\"\n");
            printf("- Lee Sin\n");
            break;

        case 4:
            printf("\nYou chose Nidalee!\n");
            printf("\"Mmm, the taste of coward.\"\n");
            printf("- Nidalee\n");
            break;

        default:
            printf("\nInvalid champion!\n");
    }
}

int main()
{
    int escolha;

    do
    {
        mostrar_menu();

        printf("\nChoose an option: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                escolher_campeao();
                break;

            case 2:
                mostrar_campeoes();
                break;

            case 3:
                printf("\nExiting the game...\n");
                break;

            default:
                printf("\nInvalid option!\n");
        }

    } while (escolha != 3);

    return 0;
}
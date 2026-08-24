#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int escolher_campeao()
{
    int escolha;

    mostrar_campeoes();

    do
    {
        printf("\nChoose your champion: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 4)
        {
            printf("Invalid champion! Choose a number between 1 and 4.\n");
        }

    } while (escolha < 1 || escolha > 4);

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
    }

    return escolha;
}

void fight(int campeao)
{
    int player_health = 100;
    int enemy_health = 100;
    int enemy_champion;
    int action;

    enemy_champion = rand() % 4 + 1;

    while (enemy_champion == campeao)
    {
        enemy_champion = rand() % 4 + 1;
    }

    printf("\n");
    printf("==============================================\n");
    printf("                 BATTLE START                \n");
    printf("==============================================\n");

    printf("\n");

    printf("Your champion: ");

    switch (campeao)
    {
        case 1:
            printf("Vi\n");
            break;

        case 2:
            printf("Jarvan IV\n");
            break;

        case 3:
            printf("Lee Sin\n");
            break;

        case 4:
            printf("Nidalee\n");
            break;
    }

    printf("Enemy champion: ");

    switch (enemy_champion)
    {
        case 1:
            printf("Vi\n");
            break;

        case 2:
            printf("Jarvan IV\n");
            break;

        case 3:
            printf("Lee Sin\n");
            break;

        case 4:
            printf("Nidalee\n");
            break;
    }

    printf("\n==============================================\n");

    while (player_health > 0 && enemy_health > 0)
    {
        printf("\nYour HP: %d\n", player_health);
        printf("Enemy HP: %d\n", enemy_health);

        printf("\n");
        printf("----------------------------------------------\n");
        printf("[1] Attack\n");
        printf("[2] Run\n");
        printf("----------------------------------------------\n");

        printf("Choose an action: ");
        scanf("%d", &action);

        switch (action)
        {
            case 1:
                enemy_health = enemy_health - 20;

                printf("\nYou attacked the enemy!\n");
                printf("You dealt 20 damage!\n");

                if (enemy_health <= 0)
                {
                    printf("\n==============================================\n");
                    printf("                  VICTORY!                   \n");
                    printf("==============================================\n");
                    printf("You defeated the enemy!\n");
                    break;
                }

                player_health = player_health - 15;

                printf("\nThe enemy attacked you!\n");
                printf("You received 15 damage!\n");
                break;

            case 2:
                printf("\nYou ran away from the battle!\n");
                return;

            default:
                printf("\nInvalid action!\n");
                break;
        }
    }

    if (player_health <= 0)
    {
        printf("\n==============================================\n");
        printf("                  DEFEAT                     \n");
        printf("==============================================\n");
        printf("You were defeated!\n");
    }
}

int main()
{
    int escolha;
    int campeao;

    srand(time(NULL));

    do
    {
        mostrar_menu();

        printf("\nChoose an option: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                campeao = escolher_campeao();
                fight(campeao);
                break;

            case 2:
                mostrar_campeoes();
                break;

            case 3:
                printf("\nExiting the game...\n");
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }

    } while (escolha != 3);

    return 0;
}
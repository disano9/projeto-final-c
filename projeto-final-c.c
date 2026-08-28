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
    int player_health;
    int enemy_health;

    int player_defense;
    int enemy_defense;

    int enemy_champion;

    int action;

    int damage;
    int ability_damage;

    int enemy_damage;
    int enemy_ability_special;

    int enemy_action;

    int actual_damage;

    /* ESCOLHER INIMIGO */
    
    printf("\nChoose your enemy:\n");
    printf("1 - Jinx\n");
    printf("2 - Sylas\n");
    printf("3 - Swain\n");
    printf("4 - Rengar\n");

    do
    {
        printf("\nChoose enemy champion: ");
        scanf("%d", &enemy_champion);

        if (enemy_champion < 1 || enemy_champion > 4)
        {
            printf("Invalid enemy! Choose a number between 1 and 4.\n");
        }

    } while (enemy_champion < 1 || enemy_champion > 4);

    /* INICIO DA BATALHA */
 
    printf("\n");
    printf("==============================================\n");
    printf("                 BATTLE START                \n");
    printf("==============================================\n");

    printf("\n");

    /* STATUS DO JOGADOR */

    printf("Your champion: ");

    switch (campeao)
    {
        case 1:
            printf("Vi\n");

            player_health = 120;
            player_defense = 10;
            damage = 20;

            break;

        case 2:
            printf("Jarvan IV\n");

            player_health = 140;
            player_defense = 15;
            damage = 15;

            break;

        case 3:
            printf("Lee Sin\n");

            player_health = 100;
            player_defense = 8;
            damage = 25;

            break;

        case 4:
            printf("Nidalee\n");

            player_health = 90;
            player_defense = 5;
            damage = 10;

            break;
    }

    /* STATUS DO INIMIGO */

    switch (enemy_champion)
    {
        case 1:
            enemy_health = 90;
            enemy_defense = 5;
            enemy_damage = 15;
            enemy_ability_special = 35;

            break;

        case 2:
            enemy_health = 120;
            enemy_defense = 10;
            enemy_damage = 18;
            enemy_ability_special = 40;

            break;

        case 3:
            enemy_health = 140;
            enemy_defense = 15;
            enemy_damage = 20;
            enemy_ability_special = 45;

            break;

        case 4:
            enemy_health = 110;
            enemy_defense = 8;
            enemy_damage = 25;
            enemy_ability_special = 50;

            break;
    }

    /* DANO DA HABILIDADE DO JOGADOR */

    switch (campeao)
    {
        case 1:
            ability_damage = 40;
            break;

        case 2:
            ability_damage = 35;
            break;

        case 3:
            ability_damage = 45;
            break;

        case 4:
            ability_damage = 30;
            break;
    }

    /* MOSTRAR INIMIGO */

    printf("Enemy champion: ");

    switch (enemy_champion)
    {
        case 1:
            printf("Jinx\n");
            break;

        case 2:
            printf("Sylas\n");
            break;

        case 3:
            printf("Swain\n");
            break;

        case 4:
            printf("Rengar\n");
            break;
    }

    printf("\n==============================================\n");

    /* COMBATE */
  
    while (player_health > 0 && enemy_health > 0)
    {
        printf("\nYour HP: %d\n", player_health);
        printf("Your Defense: %d\n", player_defense);

        printf("\nEnemy HP: %d\n", enemy_health);
        printf("Enemy Defense: %d\n", enemy_defense);

        printf("\n");

        printf("----------------------------------------------\n");
        printf("[1] Attack\n");
        printf("[2] Special Ability\n");
        printf("[3] Run\n");
        printf("----------------------------------------------\n");

        printf("Choose an action: ");
        scanf("%d", &action);

        /* ATAQUE NORMAL */

        switch (action)
        {
            case 1:

                actual_damage = damage - enemy_defense;

                if (actual_damage < 1)
                {
                    actual_damage = 1;
                }

                enemy_health = enemy_health - actual_damage;

                printf("\nYou attacked the enemy!\n");
                printf("You dealt %d damage!\n", actual_damage);

                /* VERIFICAR SE O INIMIGO MORREU */

                if (enemy_health <= 0)
                {
                    printf("\n==============================================\n");
                    printf("                  VICTORY!                   \n");
                    printf("==============================================\n");

                    printf("You defeated the enemy!\n");

                    break;
                }

                /* TURNO DO INIMIGO */

                enemy_action = rand() % 2 + 1;

                /* ATAQUE NORMAL DO INIMIGO */

                if (enemy_action == 1)
                {
                    actual_damage = enemy_damage - player_defense;

                    if (actual_damage < 1)
                    {
                        actual_damage = 1;
                    }

                    player_health = player_health - actual_damage;

                    printf("\nThe enemy attacked you!\n");
                    printf("You received %d damage!\n", actual_damage);
                }

                /* HABILIDADE DO INIMIGO */

                else
                {
                    actual_damage = enemy_ability_special - player_defense;

                    if (actual_damage < 1)
                    {
                        actual_damage = 1;
                    }

                    player_health = player_health - actual_damage;


                    switch (enemy_champion)
                    {
                        case 1:
                            printf("\nJinx used Super Mega Death Rocket!\n");
                            break;

                        case 2:
                            printf("\nSylas used Hijack!\n");
                            break;

                        case 3:
                            printf("\nSwain used Demonic Ascension!\n");
                            break;

                        case 4:
                            printf("\nRengar used Thrill of the Hunt!\n");
                            break;
                    }

                    printf("You received %d damage!\n", actual_damage);
                }

                break;

            /* HABILIDADE ESPECIAL DO JOGADOR */

            case 2:

                actual_damage = ability_damage - enemy_defense;

                if (actual_damage < 1)
                {
                    actual_damage = 1;
                }

                enemy_health = enemy_health - actual_damage;


                switch (campeao)
                {
                    case 1:
                        printf("\nVi used Assault and Battery!\n");
                        break;

                    case 2:
                        printf("\nJarvan IV used Cataclysm!\n");
                        break;

                    case 3:
                        printf("\nLee Sin used Dragon's Rage!\n");
                        break;

                    case 4:
                        printf("\nNidalee used Javelin Toss!\n");
                        break;
                }

                printf("You dealt %d damage!\n", actual_damage);


                /* VERIFICAR SE O INIMIGO MORREU */

                if (enemy_health <= 0)
                {
                    printf("\n==============================================\n");
                    printf("                  VICTORY!                   \n");
                    printf("==============================================\n");

                    printf("You defeated the enemy!\n");

                    break;
                }
                /* TURNO DO INIMIGO */

                enemy_action = rand() % 2 + 1;


                if (enemy_action == 1)
                {
                    actual_damage = enemy_damage - player_defense;

                    if (actual_damage < 1)
                    {
                        actual_damage = 1;
                    }

                    player_health = player_health - actual_damage;

                    printf("\nThe enemy attacked you!\n");
                    printf("You received %d damage!\n", actual_damage);
                }


                else
                {
                    actual_damage = enemy_ability_special - player_defense;

                    if (actual_damage < 1)
                    {
                        actual_damage = 1;
                    }

                    player_health = player_health - actual_damage;


                    switch (enemy_champion)
                    {
                        case 1:
                            printf("\nJinx used Super Mega Death Rocket!\n");
                            break;

                        case 2:
                            printf("\nSylas used Hijack!\n");
                            break;

                        case 3:
                            printf("\nSwain used Demonic Ascension!\n");
                            break;

                        case 4:
                            printf("\nRengar used Thrill of the Hunt!\n");
                            break;
                    }

                    printf("You received %d damage!\n", actual_damage);
                }

                break;

            /* FUGIR */

            case 3:

                printf("\nYou ran away from the battle!\n");

                return;
        
            /* OPÇÃO INVÁLIDA */

            default:

                printf("\nInvalid action!\n");

                break;
        }
    }
    /* DERROTA */

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
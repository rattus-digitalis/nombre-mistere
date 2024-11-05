
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int check_str(char *str) { 
    size_t i = 0;

    if (str[0] == '-') { 
        i = 1;
    }

    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0; 
        }
        i++;
    }
    return 1;
}


int main(void)
{

    srand(time(NULL));
    int recommence = 1;

    printf("Bonjour, voici le jeux du numéro magique !\n \r");
    printf(" \n \r");
    printf(" ******* Bonne chance ******* \n \r");
    printf(" \n \r");

    while (recommence == 1) {
        int random_number = rand() % 100 + 1;
        int user_guess;
        int attempts = 0;
        char input[100];
        //printf("%d" , random_number);
        while (attempts < 5) 
        {
            attempts++;

            if (attempts == 4) {
                printf(" \n \r");
                printf("Il vous reste 2 essais\n \r");
                printf(" \n \r");
            }
            else if (attempts == 5) {
                printf(" \n \r");
                printf("Il vous reste 1 essai\n \r");
                printf(" \n \r");
            }
            printf("Choisissez un nombre entre 1 et 100 : \n \r");
            printf(" \n \r");
            scanf("%s", input);
                
            user_guess = atoi(input);
            
            if (!check_str(input)) {
                printf("Entrée invalide. Veuillez entrer un nombre valide.\n \r");
                printf(" \n \r");
                attempts--; 
                continue;
            }
                else if (user_guess < 1)
            {
                    
                    printf("Entré un nombre supérieur a 0\n \r");
                    attempts--;
                    continue;
            }
            else if (user_guess > 100)
            {
                    printf("Entré un nombre inférieur a 100\n \r");
                    attempts--; 
                        continue;
            }
            user_guess = atoi(input);
            //printf(" %d \n", user_guess);
            if (user_guess < random_number) {
                printf(" \n \r");
                printf("Le nombre est plus grand\n \r");
                printf(" \n \r");
            } else if (user_guess > random_number) {
                printf(" \n \r");
                printf("Le nombre est plus petit\n \r");
                printf(" \n \r");
            } else {
                printf(" \n \r");
                printf(" *** Bien joué *** \n \r");
                printf(" \n \r");
            
                printf(" Vous avez trouvé le nombre mystère en %d essais!\n \r", attempts);
                break;
            }
        }
        if (user_guess != random_number)
        {

         printf("*** PERDU ***");
        printf(" \n \r");
        printf("Le numéro mystère était : %d\n \r", random_number);
        }
        printf(" \n \r");
        printf("Si vous voulez recommencer le jeu, tapez 1 sinon tapez 0: \n \r");
        scanf("%d", &recommence);
    }

    printf("Fin du programme ;)\n");
    return 0;

}

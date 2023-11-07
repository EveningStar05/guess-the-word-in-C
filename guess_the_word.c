#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// int check_guessed_word(char *word, char *guessed);

int main(void)
{
    // TODO:
    // Refactor code.
    // add error cases. when forced close, etc.

    srand(time(NULL));

    int max = 3;
    int count_guess = 0;
    int remaining_guess = max;

    char words[][10] = {"apple", "pear", "banana", "cherrie", "pineapple"};
    int size_words = sizeof(words) / sizeof(words[0]);

    int random_number = (rand() % size_words);
    char *guessed_word = words[random_number];
    int guess_word_length = strlen(guessed_word);

    printf("%d\n", random_number);
    char *hashed = malloc(guess_word_length + 1);

    strcpy(hashed, guessed_word);

    for (int i = 0; i < guess_word_length; i++) 
    {
        if (i % 2 == 0)
        {
            hashed[i] = *("*"); // ini apa ya ga ngerti. 
        }
    }

    printf("guessed_word: %s, hashed: %s\n\n", guessed_word, hashed); 

    do
    {
        char *user_guess;
        printf("Guess the word: %s\n", hashed);
        printf("Enter a word.... \n");

        scanf("%s", user_guess);
        if (strcmp(user_guess, guessed_word) == 0)
        {
            printf("\n!!! Correct! !!!\n");
            free(hashed);
            return 1;
        } else {
            printf("wrong answer!\n\n");
            count_guess += 1;
            remaining_guess -= 1;
            printf("Remaining guesses: %d\n ================= \n\n", 
                remaining_guess);

            if (count_guess == max)
            {
                printf("\n Game Over :( \n");
                return 1;
            }
        }

    } while (count_guess < max);

    return 0;
}



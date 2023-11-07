#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Pseudocode:

// initialize check_guessed_word
// int check_guessed_word(char *word, char *guessed);

// start
// int main(void)
//     int max = 3;
//     int words[10];
//     char guess_word[];
//     int arr_length = sizeof words / sizeof words[0];
//     int random_number = rand() % length of array;

//     for loop i = 0; i < strlen guess_word; i++:
//         if i > 3:
//            guess_word[i] = '*';
//         end if
//     end for loop

//     while max != 0:

//         char *user_word;
//         printf("Guess the word: %s\n", guess_word);
//         scanf("Enter a word to the console.... ");

        // if check_guessed_word(word, guess_word) == 0:
        //     printf("That's not it, try again!");
        //     max -= 1;
        //     printf("Guess remaining: string format integer", max);
        // end if

        // if check_guessed_word(word, guess_word) == 1:
        //     printf

        // if count_guess == 3:
        //     printf("game over!")
        //     return 1;
//         end if
//     end while loop
// end function.

// start
// int check_guessed_word(char *word, char *guessed):
//     if word is equal to guessed:
//         return 1; -> true
//     end if
//     return 0; -> false
// end check_guessed_word

// wait I still need two copies of the guess word:
//     1. modified guess word, hiding the rest of the character.
//     2. unmodified word without the asterisk.

// Then I'll use unmodified word to compare to the user's guessed word.
// I think I could make a second function to check whether the compared word is 

// if it works as intended maybe I can add an ascii art in here, not sure how :'D

// int check_guessed_word(char *word, char *guessed);

int main(int argc, char *argv[])
{
    // TODO:
    // implement random word.
    // Refactor code.
    // add error cases. when forced close, etc.
    int max = 3;
    int count_guess = 0;
    char words[][10] = {"apple", "pear", "banana", "cherrie", "pineapple"};

    char guessed_word[] = "apple"; // test
    int guess_word_length = strlen(words[4]);
    char *hashed = malloc(guess_word_length + 1);
    int remaining_guess = max;

    strcpy(hashed, words[4]);


    for (int i = 0; i < guess_word_length + 1; i++) 
    {
        if (i >= 3)
        {
            hashed[i] = *("*"); // ini apa ya ga ngerti. 
        }
    }

    do
    {
        char *user_guess;
        printf("Guess the word: %s\n", guessed_word);
        printf("Enter a word.... \n");

        scanf("%s", user_guess);
        if (strcmp(user_guess, guessed_word) == 0)
        {
            printf("Correct!\n");
            return 1;
        } else {
            printf("wrong word. try again!\n\n");
            count_guess += 1;
            remaining_guess -= 1;
            printf("Remaining guesses: %d\n ================= \n", remaining_guess);
        }
        printf("%d", remaining_guess);

    } while (count_guess < max);

    return 0;

}



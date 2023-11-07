#include <stdio.h> // standard library.
#include <string.h> // for string manipulation. strcpy, strlen, etc...
#include <stdlib.h> // malloc, srand and rand.
#include <time.h> // time

// TODO:
// add error cases. when forced close, etc.

// initialize hashed_guess_word function
int hashed_guess_word(char *word, int word_length);

int main(void)
{
    srand(time(NULL)); // seed random number, so that everytime running the
    // execution file it will always generate a new number.

    int max = 3; // maximum number of guesses.
    int count_guess = 0; // the number of words that user has guessed.
    int remaining_guess = max; // the remaining guesses that the users can guess.

    // initialize an array of string, 2d array.
    char words[][10] = {"apple", "pear", "banana", "cherrie", "pineapple"};
    int size_words = sizeof(words) / sizeof(words[0]); // length of the word array

    // generate a random number (1 - n) based on how many elements are inside
    // of the array.
    int random_number = (rand() % size_words);
    char *guess_word = words[random_number]; // generate random word. 
    int guess_word_length = strlen(guess_word); // the length of string for
    // for the selected random word.

    char *hashed = malloc(guess_word_length + 1); // memory allocation, size:


    strcpy(hashed, guess_word); // copying the random word to the new
    // allocated memory.

    hashed_guess_word(hashed, guess_word_length); // generate the hashed word

    // printf("guessed_word: %s, hashed: %s\n\n", guessed_word, hashed); 

    do
    {
        char *user_guess; // initialize empty string variable for user's input.

        printf("\n=================\n\nGuess the word: %s\n\n=================", 
            hashed);

        printf("Enter a word.... \n");

        scanf("%s", user_guess);

        if (strcmp(user_guess, guess_word) == 0) // compare the user's input
        // with the guess_word. 
        {
            printf("\n!!! Correct! !!!\n"); // print the successful messenge.
            free(hashed); // free the allocated memory.
            return 1; // stop the program.
        } 
        else { // else if it is not the same then

            printf("wrong answer!\n\n");
            count_guess += 1; // increment the count_guess
            remaining_guess -= 1; // decrement the remaining_guess
            printf("Remaining guesses: %d\n ================= \n\n", 
                remaining_guess); // print the failed messenge along with the
                // remaining guesses that the user can guess.

            if (count_guess == max) // if count guess is equal to max
            {
                printf("\n Game Over :( \n"); // show the failed messenge
                return 1; // stop the program.
            }
        }

    } while (count_guess < max); // while count_guess is less than max

    return 0;
}

int hashed_guess_word(char *word, int word_length)
{
    for (int i = 0; i < word_length; i++) 
    {
        if (i % 2 == 0)
        {
            word[i] = *("*"); // i still don't understand what this meant. 
        }
    }
}



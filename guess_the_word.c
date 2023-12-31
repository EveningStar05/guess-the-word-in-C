#include <stdio.h>  // standard library.
#include <string.h> // for string manipulation. strcpy, strlen, etc...
#include <stdlib.h> // malloc, srand and rand.
#include <time.h>   // time

// initialize struct
typedef struct word_struct
{
    char *word;
    char *hint;
} word_struct;

// initialize hashed_guess_word function.
int hashed_guess_word(char *word, int word_length);

// initialize run_guess_word function.
void run_guess_word(char *guess_word, char *hash_word, char *hint);

int main(void)
{
    srand(time(NULL)); // seed random number, so that everytime running the
    // execution file it will always generate a new number.

    // create a dictionary consisting the guess word with its hint.
    word_struct word_dict[] = {
        {"apple", "A red fruit that Snow White once ate and was cursed."}, 
        {"pear", "A fruit which is bulbous at the bottom, and tapering to the top"},
        {"banana", "A long yellow fruit, usually depicted as monkey's favorite fruit."}, 
        {"cherrie", "A small red fruit usually used as a dressing for birthday cakes like black forest."},
        {"pineapple", "A tropical fruit, spongebob's house."}
    };

    int size_words = sizeof(word_dict) / sizeof(word_dict[0]); // length of the word array

    // generate a random number (1 - n) based on how many elements are inside
    // of the array.
    int random_number = (rand() % size_words);

    char *guess_word = word_dict[random_number].word;    // generate random word.
    char *get_hint = word_dict[random_number].hint;      // get the hint based on index.
    int guess_word_length = strlen(guess_word); // the length of string for
    // for the selected random word.

    char *hashed = malloc(guess_word_length + 1); // memory allocation, size:

    if (hashed == NULL)
    {
        free(hashed); 
        return 1;
    }

    strcpy(hashed, guess_word); // copying the random word to the new
    // allocated memory.

    hashed_guess_word(hashed, guess_word_length); // generate the hashed word

    // printf("guessed_word: %s, hashed: %s\n\n", guess_word, hashed); // debug

    run_guess_word(guess_word, hashed, get_hint);

    return 0;
}

int hashed_guess_word(char *word, int word_length) // generate hashed random word
{
    for (int i = 0; i < word_length; i++) // loop through the given word based
    // on its length.
    {
        if (i % 2 == 0) // if index is even number.
        {
            word[i] = *("*"); // change the characters into asterisk.
        }
    }
}

void run_guess_word(char *guess_word, char *hash_word, char *hint)
{
    int max = 3;               // maximum number of guesses.
    int count_guess = 0;       // the number of words that user has guessed.
    int remaining_guess = max; // the remaining guesses that the users can guess.

    printf("==========================================");
    printf("\n>> Mystery word: %s\n",
           hash_word);
    printf("\n-> You only have 3 guesses, so think carefully!\n");
    printf("==========================================\n");

    do
    {
        char user_guess[100]; // initialize string with size 100 for user's input.
        printf("Enter your answer (make sure it's in lower case!) .... "); // show messenge to enter text.

        if (EOF == scanf("%s", user_guess)) // takes user input
        {
            printf("\n\nExiting the program... Good bye!\n");
            free(hash_word); 
            break;
        }

        if (strcmp(user_guess, guess_word) == 0) // compare the user's input
        // with the guess_word.
        {
            // print the successful messenge.
            printf("\n#################\n!!! Correct! !!!\n#################\n"); 
            free(hash_word); // free the allocated memory.
            break;
        }
        else
        { // else if it is not the same then

            printf("wrong answer!\n\n");
            count_guess += 1;     // increment the count_guess
            remaining_guess -= 1; // decrement the remaining_guess
            printf("Remaining guesses: %d\n---------------------\n\n",
                   remaining_guess); // print the failed messenge along with the
            // remaining guesses that the user can guess.

            if (count_guess == max) // if count guess is equal to max
            {
                printf("\n Game Over :( \n"); // show the failed messenge
                free(hash_word); 
            }
            else if (count_guess == 2)
            {
                printf("\nHint: %s\n\n", hint);
            }
        }

    } while (count_guess < max); // while count_guess is less than max

}
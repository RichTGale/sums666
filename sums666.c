#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "mycutils.h"

void print_help()
{
    printf( "This program searches a wordlist for words who's character's decimal ascii values sum to 666 and saves them to a file.\n\n"
            "USAGE:\n"
            "./sums666 <wordlist> <savefile>\n");
    exit(EXIT_FAILURE);
}

bool sums666(char* word)
{
    int wordlen = 0;
    int score = 0;

    while (word[wordlen] != '\0' && word[wordlen] != '\n')
    {
        score += (int) word[wordlen];
        wordlen++;
    }

    if (score == 666)
        return true;

    return false;
}

int main(int argc, char* argv[])
{
    FILE* wordlist;
    FILE* savefile;
    char* line;
    bool freed;
    
    if (argc < 3 || argc > 3)
        print_help();

    wordlist = openfs(argv[1], "r");
    savefile = openfs(argv[2], "w");
    freed = true; // Prevent free() error if wordlist is an empty file.

    while (readfsl(wordlist, &line))
    {
        freed = false;
        if (sums666(line))
        {
           writefss(savefile, line);
           printf("%s", line);
        }
        free(line);
        freed = true;
    }

    if (!freed)
        free(line);

    exit(EXIT_SUCCESS);
}

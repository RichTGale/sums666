#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "mycutils.h"

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

    return false;;
}

int main(int argc, char* argv[])
{
    FILE* wordlist = openfs(argv[1], "r");
    FILE* savefile = openfs(argv[2], "w");
    char* line;
    bool freed = false;

    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))
    {
        printf( "Searches a wordlist for words who's ascii sums to 666 and saves them to a file.\n\n"
                "USAGE:\n"
                "find666 <wordlist> <savefile>\n");
    }

    while (readfsl(wordlist, &line))
    {
        readfsl(wordlist, &line);
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

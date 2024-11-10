#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }
    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    int cracked = 0;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *passwords = fopen(argv[2], "r");
    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.
    while(!feof(passwords))
    {
        char *line = malloc(PASS_LEN);
        char *hash = malloc(HASH_LEN);

        if(fgets(line, PASS_LEN, passwords) != NULL)
        {
            trim(hash);
            trim(line);
            hash = md5(line, strlen(line));
            if (substringSearchAA(hash, hashes, size) != NULL)
            {
                printf("%s: %s\n", line, hash);
                cracked++;
            }
        }
        free(line);
        free(hash);
    }
    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
    fclose(passwords);
    printf("Hashes found: %d\n", cracked);
    freeAA(hashes, size);
}

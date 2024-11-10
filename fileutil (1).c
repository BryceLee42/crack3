#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

void trim(char string[100])
{
    int i = 0;
    while(string[i] != '\n' && string[i] != '\0')
    {
        i++;
    }
    string[i] = '\0';
}
// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	int numOfLines = 1;
	int capacity = 10;
	char **arr = malloc(capacity * sizeof(char*));
	while(!feof(in))
	{
		char *line = malloc(100);
		if (numOfLines>capacity)
		{
			arr = realloc(arr, (capacity+10000) * sizeof(char*));
			capacity+=10000;
		}
		
		if (fgets(line, 100, in) != NULL)
		{
			trim(line);
			int length = strlen(line);
			arr[numOfLines-1] = realloc(arr[numOfLines-1], length+1);
			strcpy(arr[numOfLines-1], line);
			numOfLines++;
		}
		free(line);
	}
	
	fclose(in);

	// The size should be the number of entries in the array.
	*size = numOfLines;
	
	// Return pointer to the array of strings.
	return arr;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i=0; i<size-1; i++)
	{
		if (strcmp(lines[i], target) == 0)
		{
			return target;
		}
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for(int i=0; i<size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void free2D(char (*arr)[COLS])
{

}
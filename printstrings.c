#include <stdlib.h>
#include <stdio.h>
#include "printstrings.h"


void printstrings(char **strings,int size)
{
  for (int h = 0 ;h != size; h++)
 	{ 
 		printf(" %s\n", strings[h]);
 		free(strings[h]);
 	}
 	free(strings);
}

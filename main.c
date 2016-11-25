#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "readtomassivenumbers.h"
#include "setstrings.h"
#include "printstrings.h"
int main( int argc, char**argv)
{	
  if(argc != 3)
  {
    printf("Wrong input");
    exit(1);
  }
	FILE *fp;
	if ( (fp = fopen(argv[2],"r") ) == NULL)
	{
		 printf ("Can't open the file.\n");
 		 exit(1);
	}
	int size = atoi(argv[1]);  
	int *quantity=(int*)malloc(sizeof(int)*size);
	set_quantity_of_numbers_strings (fp, &size, quantity);
	rewind(fp);
  char **strings =(char**)malloc(sizeof(char*)*(size+1));
	set_strings (fp, strings, size, quantity);
	fclose(fp);
	mergesort (strings, size);
 printstrings (strings, size);
	free(quantity);
	return 0;
}






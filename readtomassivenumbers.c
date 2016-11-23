#include <stdlib.h>
#include <stdio.h>
#include "readtomassivenumbers.h"



void set_quantity_of_numbers_strings (FILE *fp, int size, int *quantity)
{
	int t = 0; 
	// quantity of characters in string
	int i = 0; //quantity strings
	int ch ;
	int check = EOF;
	while( ((ch = fgetc(fp))!=EOF) &&i < size)
	{	
		check = ch;
		t++;	
		if ((ch =='\n'))
		{
			quantity[i++] = t;
			t = 0;
		}	
	}
	if (check != '\n')
	{ 
		quantity[i++] = t;
	}
	size = i; 
}

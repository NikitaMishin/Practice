#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "mergesort.h"

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
		 printf ("He удается открыть файл.\n");
 		 exit(1);
	}
	int size = atoi(argv[1]);  
	int *quantity=(int*)malloc(sizeof(int)*size);// allocation memory for  massive of sizes of strings 
	int t = 0; // quantity of characters in string
	int i = 0; //quantity strings
	int ch ;
	int check = EOF;
	while((ch = fgetc(fp))!=EOF)
	{	
		check = ch;
		t++;	
		if ((ch=='\n'))
		{
			quantity[i++] = t;
			t = 0;
		}	
	}
	if (check != '\n')
	{ 
		quantity[i++] = t;
	}
	  
	int realsize= i;
	int pos = 0;
	char **strings =(char**)malloc(sizeof(char*)*(realsize+1));
	
	rewind(fp);
	while(pos != realsize)
	{ int k;
		strings[pos] = (char*)malloc(sizeof(char)*(quantity[pos]));
		for(k=0;k!=quantity[pos]-1;++k)
		{
			strings[pos][k]=fgetc(fp);
	 	}
		ch = fgetc(fp);
		strings[pos][k]='\0';
		pos++;
	}
	
	fclose(fp);
	int choice;
	printf("Choose algorithm of sorting\n");
	printf("Bubblesort-1\nInsertsort-2\nQuicksort-3\nMergesort-4\n	Your choice is=");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			 bubblesort(strings,realsize);break;
		case 2:
			 insertsort(strings,realsize);break;
		case 3 :
			quicksort(strings,realsize-1);break;
		case 4 :
			mergesort(strings,realsize);break;
		default:
			printf("wrong\nThen will be 4\n"); 
			mergesort(strings,realsize);
			break; //then will be merge sort
	}
	
	for (int h = 0 ;h != realsize;h++)
 	{ 
 		printf("%s\n", strings[h]);
 		free(strings[h]);
 	}
 	
 	free(strings);
	free(quantity);
	return 0;
}






#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "mergesort.h"

int main(void)
{	
	FILE *fp[100];
	FILE *fout[100];
	 char filenamed[20];
	 char filename[20];
	 for ( int d=0;d<100;d++){
 sprintf(filename,"input%d.txt",d+1);

	if ((fp[d] = fopen(filename,"r")) == NULL)
	{
		 printf ("He удается открыть файл.\n");
 		 exit(1);
	}
	else printf ("FILE is open=%d\n",d);
	
	int size; 
	fscanf(fp[d],"%d",&size);  
	 int *quantity=(int*)malloc(sizeof(int)*size);// allocation memory for  massive of sizes of strings 
	int t = 0; // quantity of characters in string
	 int i = 0; //quantity strings
	int ch = fgetc(fp[d]);// '\n'-char
	int check = EOF;
	while((ch=fgetc(fp[d]))!=EOF)
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
	char  **strings =(char**)malloc(sizeof(char*)*(realsize+1));
	
	rewind(fp[d]);
	fscanf(fp[d],"%d",&size); //ok
	ch = fgetc(fp[d]); // '\n'-symbol char
	while(pos != realsize)
	{ int k;
		strings[pos] = (char *)malloc(sizeof(char)*(quantity[pos]));
		for(k=0;k!=quantity[pos]-1;++k)
		{
			strings[pos][k]=fgetc(fp[d]);
	 	}
		ch = fgetc(fp[d]);
		strings[pos][k]='\0';
		pos++;
	}
	
	fclose(fp[d]);
	int choice;
	//printf("Choose algorithm of sorting\n");
	//printf("Bubblesort-1\nInsertsort-2\nQuicksort-3\nMergesort-4\n	Your choice is=");
 //scanf("%d",&choice);
	 choice=3;
	/*switch(choice)
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
	*/
	insertsort(strings,realsize);
 sprintf(filenamed,"output%d.txt",d+1);

	fout[d] = fopen(filenamed,"w"); 
	 
	for (int h = 0 ;h != realsize;h++)
	{
	for(int m = 0; strings[h][m]!='\0';m++) 	
 		{
 			fprintf(fout[d],"%c", strings[h][m]);
 		}
 		fprintf(fout[d],"\n");
 	free(strings[h]);
 	}
 	fclose(fout[d]);
 	free(strings);
	free(quantity);
	
	}
	
	return 0;
}



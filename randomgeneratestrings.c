#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// just generate file with many strings
int main(void)
{ 
	srand ( time(NULL) );
	int numb = 101;
	FILE * file[numb];
	int p;
	long int * n = (long int*) malloc(sizeof(long int)*numb);
for (int k=0;k<numb;k++)
{

 long int size = rand()%500000+ 100000;
 
 char**strings= (char**)malloc(sizeof(char*)*size);
 int j;
 int z;
 for(int i = 0; i<size;i++)
 { 
   int c = rand()%420 + 120;
 	strings[i] = (char*)malloc(sizeof(char)*(c+2));
 	for( j = 0 ;j < c;j++)	
 	{
 	
 		 while(( (( (z = rand()%58+65))<=122 ) && (z>=65) && (z!=91) && (z!=92) && (z!=93) && (z!=94) && (z!=95) && (z!=96))==0 ) ;   
 		 strings[i][j]=z;
 	} 
 	
 	strings[i][j] ='\0';
 }
 char filename[20];
 sprintf(filename,"input%d.txt",k+1);
file[k] = fopen(filename,"w");
for(int i = 0; i<size;i++) fprintf(file[k],"%s\n",strings[i]);
fclose(file[k]);
n[k]= size;
}
file[100]=fopen("quantity.txt","w");
for (int i = 0 ;i<numb;i++){fprintf(file[100],"%ld\n",n[i]);}
fclose(file[100]);
return 0;
}

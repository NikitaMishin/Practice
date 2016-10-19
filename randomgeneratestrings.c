#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{ 
	srand ( time(NULL) );
	int numb = 100;
	FILE * file[numb];
	int p;
for (int k=0;k<numb;k++)
{
 long int size = rand()%30000+ 100;
 printf("=%ld=",size);
 char**strings= (char**)malloc(sizeof(char*)*size);
 int j;
 int z;
 for(int i = 0; i<size;i++)
 { 
   int c = rand()%120 + 20;
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
fprintf(file[k],"%ld\n",size);
for(int i = 0; i<size;i++) fprintf(file[k],"%s\n",strings[i]);
fclose(file[k]);
}

return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{ 
	int numb = 100;
	FILE * file[numb];
for (int k=0;k<numb;k++)
{

 srand ( time(NULL) ); //ok
 long int size = rand()%100000+ 2000;
 printf("=%ld=",size);
 char**strings= (char**)malloc(sizeof(char*)*size);
 int j;
 for(int i = 0; i<size;i++)
 { 
  long int c = rand()%120 + 20;
 	strings[i] = (char*)malloc(sizeof(char)*(c+2));
 	for( j = 0 ;j < c;j++)
 	{
 		strings[i][j]= rand()%58 + 65;
 		 while(!(( (strings[i][j] = rand()%58+65)<=122 )&&(strings[i][j]>=65)&&(strings[i][j]!=91)&&(strings[i][j]!=92)&&(strings[i][j]!=93)&&(strings[i][j]!=94)&&(strings[i][j]!=95&&(strings[i][j]!=96)))) ;  //91 96
 	} 
 	strings[i][j] ='\n';
 }
 char filename[20];
 sprintf(filename,"input%d.txt",k+1);
file[k] = fopen(filename,"w");
fprintf(file[k],"%ld\n",size);
for(int i = 0; i<size;i++) fprintf(file[k],"%s",strings[i]);
fclose(file[k]);
}

return 0;
}

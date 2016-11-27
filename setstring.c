#include <stdlib.h>
#include <stdio.h>
#include "setstrings.h"

void set_strings (FILE *fp,char** strings, int  size ,int *quantity)
{
  int pos = 0 ;
  int ch;
  while(pos != size)
  { 
    int k;
    strings[pos] = (char*)malloc(sizeof(char)*(quantity[pos]));
    for(k = 0;k != quantity[pos]-1;++k)
    {
      strings[pos][k]=fgetc(fp);
    }
    ch = fgetc(fp);// for \n
    strings[pos][k]='\0';
    pos++;
  }
}

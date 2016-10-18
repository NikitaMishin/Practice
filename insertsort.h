#pragma once
#include "swap.h"
#include "comparer.h"
/*
Inserssort function sorting massive of strings
*/
void  insertsort(char **m, int size)  
{ for (int i = 1 ; i != size; ++i)    
	{
		int j = i;
		while((j> 0) && comparer(m[j-1],m[j] ) ) 
		{
		swap(&m[j-1],&m[j]);
		j--;
		}
	}	
}

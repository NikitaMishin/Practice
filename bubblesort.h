#pragma once
#include "swap.h"
#include "comparer.h"

 /*
 Bubblesort function sorting massive of strings
 */

void bubblesort(char **a, int  const size) 
{   
	for(int i = 0; i != size; i++)
	 	{ 
	 		for(int j = 0 ; j != size-i-1; ++j) 
	 		 { 
	 		 	if( comparer(a[j],a[j+1] ) )
	 		  		{	
	 		  			swap(&a[j],&a[j+1]);		
	 		 		  }		
 			 }
	
		}
}

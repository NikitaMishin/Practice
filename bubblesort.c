#include "bubblesort.h"
#include "comparer.h"
#include  "swap.h"

void bubblesort(char **a, int  const size) 
{   
	for(int i = 0; i != size; i++)
	{ 
	  for(int j = 0 ; j != size-i-1; ++j) 
	  { 
      if (comparer(a[j],a[j+1]))
        {	
          swap(&a[j],&a[j+1]);		
        }		
    }
	
  }
}

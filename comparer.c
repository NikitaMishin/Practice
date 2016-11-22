#include "comparer.h" 

/*
 comparator for English letters
*/
 int comparer (char* mas1, char* mas2)  //return 1 when mas1>mas2
{	
	int i = 0;
	int f = 0;
	int s = 0;
	while((mas1[i] !='\0')&& (mas2[i]!='\0'))
	{	f = mas1[i];
		s = mas2[i];
		if ((f > 1039) && (s > 1039) && (f <1104) && (s < 1104)) //For russians without ёЁ
		{
			if ((f > 1039) && (f < 1072) && (s >= 1072) && (s < 1104))
			{
				f=+32;
			}  
			if ((f >= 1072) && (f < 1105) && (s > 1039)&& (s<1072))
			{
				s=+32;
			} ///ok
		}
		else if (f == 1025 || f == 1105 || s == 1025 || s == 1105 )// EЁ её
			{ 
					if ((f == 1025) && (s == 1105)) f += 80;//ok			
					if ((s == 1025) && (f == 1105)) s += 80;//ok
					if ((s != 1025) && (s != 1105))
						{
						 if (s == 1045|| s==1072) {f = s+1;}
						 else if (s < 1072) {f = 1045;}
						 else {f = 1077;} ;
						}
					if(f != 1025 && f !=1105)
						{
						 if (f == 1045 || f==1072) {s = f+1;}
						 else if (f < 1072) {s = 1045;}
						 else {s = 1077;} 
						} 
			}	
		else
		{
			if ((f <91) && (s >=96))  //FOR ENGLISH LETTERS
			{
				f+=32;
			};
			if ((f >= 96)&&(s < 91)) 
			{
				s+=32;
			};
		};
		if (f > s) { return 1;}
			else if(f < s) {return 0;}    
			i++;	
		}
	if (mas1[i]=='\0')return 0;
	return 1;
}



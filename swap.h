#pragma once


/*
Function swap two strings
*/

void swap(char **a,char **b)
{
	char *t = *a;
  *a = *b;
  *b = t;
 }

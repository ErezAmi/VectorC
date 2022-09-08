#pragma once
#include <stdio.h>
#include "Vector.h"
#include <stdlib.h>
 
int main()
{
	int b;
	Vector* a;
	create(&a, 2); 

	print(a);

	add(a, 72);
	print(a);
	add(a, 73);
	add(a, 74);
	add(a, 75);
	add(a, 76);
	b = getSize(a);
	print(a);
	printf("%d\n\n and now:\n\n", b);
	delete(a);
	create(&a, 2);
	add(a, 2);
	add(a, 3);
	add(a, 4);
	removeItem(a, 1);  
	print(a);

	printf("\nnaa");
	int s = 0;
	scanf_s("%d", s);
	printf("\n%d\n", s);	
	return 0;
}

 

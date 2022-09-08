#pragma once
#include "Vector.h"   // we want to be abke to see its size, create and delete it, insert and pop out of it   
#include <stdlib.h>
#include <stdio.h>

typedef struct Vector
{
	int* Values;
	int size;
	int initialCapacity;
	int capacity;

} Vector; 


int create(Vector** ptrVector, int c)
{
	(*ptrVector) = malloc(sizeof(Vector) * 1); 

	(*ptrVector)->capacity = c;
	(*ptrVector)->initialCapacity = c;
	(*ptrVector)->size = 0;
	(*ptrVector)->Values = malloc(sizeof(int) * c); //Values is pointing to a place in the memory which is equal to the size of an array of INT's, an array as long as the value of "capacity"

	return 0;
}


void add(Vector* ptrVector, int item)
{
	if (ptrVector->size >= ptrVector->capacity)
	{
		handelCapacityOverflow(ptrVector);
	}	    
	ptrVector->Values[ptrVector->size] = item;
	ptrVector->size += 1;
}


void handelCapacityOverflow(Vector* ptrVector)
{
	printf("WARNING!!!\n");
	int* newValues = malloc(sizeof(int) * (ptrVector->capacity + ptrVector->initialCapacity));
	for (int i = 0; i < (*ptrVector).size; i++)
	{
		newValues[i] = ptrVector->Values[i];
	}

	free(ptrVector->Values);
	ptrVector->Values = newValues; //works because newValues is a pointer as well. 
	ptrVector->capacity += ptrVector->initialCapacity;
}


void print(Vector* ptrVector)
{
	printf("Capacity: %d\n", ptrVector->capacity);
	printf("Size: %d\n", ptrVector->size); // the "->" sign means that we are using the pointer, looking at what it's pointing at and then accessing or changing that information. 
	//printf("%d\n", (*ptrVector).size); // using " (*ptrVector) is like using the variable inside "Vector" itself. indeed, the two lines of code here are the same. 
	printf("Values: ");
	for (int i = 0; i < (*ptrVector).size; i++)
	{
		printf("%d ", ptrVector->Values[i]);
	}
	printf("\n");
}


void delete(Vector* ptrVector)
{
	free(ptrVector->Values);
	free(ptrVector);
}


void removeItem(Vector* ptrVector, int indexToRemove)
{
	if (ptrVector->size > indexToRemove)
	{
		int* newValues = malloc(sizeof(int) * (ptrVector->size - indexToRemove));
		for (int i = indexToRemove + 1; i < ptrVector->size; i++)
			newValues[i - indexToRemove - 1] = ptrVector->Values[i];
		for (int i = indexToRemove; i < ptrVector->size; i++)
			ptrVector->Values[i] = newValues[i - indexToRemove];
		ptrVector->size -= 1;
	}
}


int getSize(Vector* ptrVector)
{
	return ptrVector->size;
}


int getCapacity(Vector* ptrVector)
{
	return ptrVector->capacity;
}

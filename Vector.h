#pragma once


typedef struct Vector Vector;

int create(Vector*, int capacity);

void add(Vector*, int item); 

void handelCapacityOverflow(Vector*);  

void print(Vector*);

void delete(Vector*);

void removeItem(Vector*, int indexToRemove);

int getSize(Vector*);

int getCapacity(Vector*); 
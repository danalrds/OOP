#pragma once
#include "Offer.h"
#define CAPACITY 10

typedef void* TElement;

typedef struct
{
	TElement* elems;
	int length;			// actual length of the array
	int capacity;		// maximum capacity of the array
} DynamicArray;


DynamicArray* createDynamicArray(int capacity);


void destroy(DynamicArray* arr);


void add(DynamicArray* arr, TElement t);


void delete(DynamicArray* arr, int pos);


void update(DynamicArray* arr, int pos, TElement t);

int getLength(DynamicArray* arr);


TElement get(DynamicArray* arr, int pos);

// Tests
void testsDynamicArray();
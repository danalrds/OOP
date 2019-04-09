#pragma once

typedef struct
{	
	char* type;
	char* dest;
	char* dep_date;
	double price;
} Offer;

Offer* createOffer(char* type, char* dest, char* dep_date, double price);
void destroyOffer(Offer* p); // the memory is freed
Offer* copyOffer(Offer* p); // copy a planet and return a pointer to the copy

char* getType(Offer* p);
char* getDest(Offer* p);
char* getDep_date(Offer* p);

double getPrice(Offer* p);

void toString(Offer* p, char str[]);
#define _CRT_SECURE_NO_WARNINGS
#include "Offer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Offer* createOffer(char* type, char* dest, char* dep_date, double price)
{
	Offer* p = (Offer*)malloc(sizeof(Offer));
	p->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(p->type, type);
	p->dest = (char*)malloc(sizeof(char) * (strlen(dest) + 1));
	strcpy(p->dest, dest);
	p->dep_date = (char*)malloc(sizeof(char) * (strlen(dep_date) + 1));
	strcpy(p->dep_date, dep_date);

	p->price = price;

	return p;
}

void destroyOffer(Offer* p)
{
	if (p == NULL)
		return;

	// free the memory which was allocated for the component fields
	
	free(p->type);
	free(p->dest);
	free(p->dep_date);

	// free the memory which was allocated for the offer structure
	free(p);
}

Offer* copyOffer(Offer* p)
{
	if (p == NULL)
		return NULL;

	Offer* newOffer = createOffer(getType(p),getDest(p),getDep_date(p), getPrice(p));
	return newOffer;
}



char* getType(Offer* p)
{
	return p->type;
}

char* getDest(Offer* p)
{
	return p->dest;
}
char* getDep_date(Offer* p)
{
	return p->dep_date;
}
double getPrice(Offer* p)
{
	return p->price;
}

void toString(Offer* p, char str[])
{
	sprintf(str, "Offer type  %s destination %s departure date %s price %.2lf.", p->type, p->dest, p->dep_date, p->price);
}
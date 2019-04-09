#pragma once
#include "Offer.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* offers;
} OfferRepo;


OfferRepo* createRepo();


void destroyRepo(OfferRepo* v);


Offer* find(OfferRepo* v, char* dest, char* dep_date);


int findPosOfOffer(OfferRepo* v, char* dest, char* dep_date);


int addOffer(OfferRepo* v, Offer* p);


void deleteOffer(OfferRepo* v, Offer* p);
void updateOffer(OfferRepo* v, Offer* p, Offer* new);

int getRepoLength(OfferRepo* v);



Offer* getOfferOnPos(OfferRepo* v, int pos);

void testsOfferRepo();
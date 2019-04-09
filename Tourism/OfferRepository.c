#include "OfferRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

OfferRepo* createRepo()
{
	OfferRepo* v = (OfferRepo*)malloc(sizeof(OfferRepo));
	v->offers = createDynamicArray(CAPACITY);

	return v;
}

void destroyRepo(OfferRepo* v)
{
	if (v == NULL)
		return;

	
	// then destroy the dynamic array
	destroy(v->offers);
	free(v);
}

int findPosOfOffer(OfferRepo * v, char * dest, char* dep_date)
{
	if (v == NULL)
		return -1;

	for (int i = 0; i < getLength(v->offers); i++)
	{
		Offer* p = get(v->offers, i);
		if (strcmp(p->dest, dest) == 0)
		{
			if (strcmp(p->dep_date, dep_date) == 0)
				return i;
		}
		
	}
	return -1;
}

Offer* find(OfferRepo* v, char* dest, char* dep_date)
{
	if (v == NULL)
		return NULL;

	int pos = findPosOfOffer(v, dest, dep_date);
	if (pos == -1)
		return NULL;
	return get(v->offers, pos);
}

int addOffer(OfferRepo* v, Offer* p)
{
	if (v == NULL)
		return 0;

	// first search for a offer with the same name as the one that is to be added and do not add it if it already exists
	if (find(v, p->dest,p->dep_date) != NULL)
		return 0;

	// a copy of the offer which was passed will be stored, such that the memory for the offer can be deallocated where it was allocated (in Controller) 
	// and the Repository will handle its own memory
	Offer* copy = copyOffer(p);
	add(v->offers, copy);

	return 1;
}

void deleteOffer(OfferRepo* v, Offer* p)
{
	if (v == NULL)
		return;

	// find the position of the offer in the repository
	
	int pos = findPosOfOffer(v, p->dest, p->dep_date);	
	Offer* pp = getOfferOnPos(v, pos);
	destroyOffer(pp);
	// delete the pointer from the dynamic array
	delete(v->offers, pos);
	
}

void updateOffer(OfferRepo* v, Offer* p, Offer* new)
{
	if (v == NULL)
		return;

	// find the position of the offer in the repository
	int pos = findPosOfOffer(v, p->dest, p->dep_date);

	// delete the pointer from the dynamic array
	update(v->offers, pos, new);

}

int getRepoLength(OfferRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->offers);
}

Offer* getOfferOnPos(OfferRepo* v, int pos)
{
	if (v == NULL)
		return NULL;

	if (pos < 0 || pos >= getLength(v->offers))
		return NULL;

	return get(v->offers, pos);
}


// Tests
void testAdd()
{
	OfferRepo* v = createRepo();

	Offer* p1 = createOffer("seaside", "Miami", "2018.08.26", 889.5);
	addOffer(v, p1);
	assert(getRepoLength(v) == 1);
	assert(strcmp(getType(getOfferOnPos(v, 0)), "seaside") == 0);
	
	Offer* p2 = createOffer("mountain", "Tirol", "2018.06.30", 450);
	assert(addOffer(v, p2) == 1);
	assert(getRepoLength(v) == 2);

	// now try to add the same offer again -> add must return 0
	assert(addOffer(v, p2) == 0);

	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the offers must be freed
	destroyOffer(p1);
	destroyOffer(p2);
}

void testDelete()
{
	OfferRepo* v = createRepo();

	Offer* p1 = createOffer("seaside", "Miami", "2018.08.26", 889.5);
	addOffer(v, p1);
	assert(getRepoLength(v) == 1);
	assert(strcmp(getType(getOfferOnPos(v, 0)), "seaside") == 0);

	Offer* p2 = createOffer("mountain", "Tirol", "2018.06.30", 450);
	assert(addOffer(v, p2) == 1);
	assert(getRepoLength(v) == 2);
	deleteOffer(v, p1);
	Offer* off = getOfferOnPos(v, 0);
	assert(strcmp(getType(off), "mountain") == 0);

	destroyOffer(p1);
	destroyOffer(p2);
	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the offers must be freed
	
	
		
}

void testUpdate()
{
	OfferRepo* v = createRepo();

	Offer* p1 = createOffer("seaside", "Miami", "2018.08.26", 889.5);
	addOffer(v, p1);	
	Offer* p2 = createOffer("mountain", "Mallorca", "2018.08.26", 450);
	
	updateOffer(v, p1, p2);	
	Offer* off = getOfferOnPos(v, 0);
	assert(strcmp(getType(off), "mountain") == 0);
	
	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the offers must be freed	
	
	destroyOffer(p1);
}


void testsOfferRepo()
{
	 testAdd();
	 testDelete();
	 testUpdate();	
}
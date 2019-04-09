#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Controller* createController(OfferRepo* r, OperationsStack* undoS, OperationsStack* redoS)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = undoS;
	c->redoStack = redoS;
	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);

	// then the operation stack
	destroyStack(c->undoStack);
	destroyStack(c->redoStack);
	// then free the memory
	free(c);
}

int addOfferCtrl(Controller* c, char* type, char* dest, char* dep_date, double price)
{
	Offer* p = createOffer(type, dest, dep_date, price);
	
	int res = addOffer(c->repo, p);

	if (res == 1) // if the offer was successfully added - register the operation
	{
		Operation* o = createOperation(p, "add");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}

	// destroy the offer that was just created, as the repository stored a copy
	destroyOffer(p);

	return res;
}

int deleteOfferCtrl(Controller* c, char* dest, char* dep_date)
{	
	int res;
	res = 0;
	Offer* p = find(c->repo, dest, dep_date);
	if (p != NULL)
	{
		res = 1;
				
		Operation* o = createOperation(p, "remove");		
		push(c->undoStack, o);
		deleteOffer(c->repo, p);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
		//destroyOffer(p);   comentat
	}	
	return res;
}

int updateOfferCtrl(Controller* c, char* type, char* dest, char* dep_date, double price)
{
	int res;
	res = 0;
	Offer* p = find(c->repo, dest, dep_date);
	if (p != NULL)
	{
		res = 1;
		Offer* new = createOffer(type, dest, dep_date, price);
		Operation* o = createOperation(p, "update");
		updateOffer(c->repo, p,new);		
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
		//destroyOffer(p);
	}
	return res;
}

OfferRepo* getRepo(Controller* c)
{
	return c->repo;
}

OfferRepo* filterByDest(Controller* c, char* dest)
{
	OfferRepo* res = createRepo();
	

	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Offer* p = getOfferOnPos(c->repo, i);
		if (strstr(getDest(p), dest) != NULL)
		{
			Offer* newOffer= createOffer(p->type, p->dest, p->dep_date, p->price);
			addOffer(res, newOffer);
			destroyOffer(newOffer);
		}
	}

	return res;
}

OfferRepo* filterByPrice(Controller* c, char* type, double price)
{
	OfferRepo* res = createRepo();


	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Offer* p = getOfferOnPos(c->repo, i);
		if (strcmp(getType(p), type) == 0)
		{
			if (getPrice(p) < price)
			{
				
				Offer* newOffer = createOffer(p->type, p->dest, p->dep_date, p->price);
				addOffer(res, newOffer);
				destroyOffer(newOffer);
			}
		}
	}

	return res;
}

OfferRepo* filterByType(Controller* c, char* type)
{
	OfferRepo* res = createRepo();


	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Offer* p = getOfferOnPos(c->repo, i);
		if (strcmp(getType(p), type) ==0)
		{
			Offer* newOffer = createOffer(p->type, p->dest, p->dep_date, p->price);
			addOffer(res, newOffer);
			destroyOffer(newOffer);
		}
	}

	return res;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Offer* offer = getOffer(operation);

		Operation* o = createOperation(offer, "add");
		push(c->redoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);

		deleteOffer(c->repo, offer);
		
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Offer* offer = getOffer(operation);		
		
		Operation* o = createOperation(offer, "remove");
		push(c->redoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);

		addOffer(c->repo, offer);
	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{		
		Offer* offer = getOffer(operation);
		Offer* now = find(c->repo, offer->dest, offer->dep_date);

		Operation* o = createOperation(now, "update");
		push(c->redoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);	
		
		deleteOffer(c->repo, now);
		addOffer(c->repo, offer);
		//updateOffer(c->repo, now,offer);
	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;

}


int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->redoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Offer* offer = getOffer(operation);

		///for undo stack
		Operation* o = createOperation(offer, "add");
		push(c->undoStack, o);		
		destroyOperation(o);
		///for undo stack

		addOffer(c->repo, offer);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Offer* offer = getOffer(operation);

		///for undo stack
		Operation* o = createOperation(offer, "remove");
		push(c->undoStack, o);
		destroyOperation(o);
		///for undo stack

		deleteOffer(c->repo, offer);
	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{
		Offer* offer = getOffer(operation);
		Offer* now = find(c->repo, offer->dest, offer->dep_date);

		///for undo stack
		Operation* o = createOperation(now, "update");
		push(c->undoStack, o);
		destroyOperation(o);
		///for undo stack

		deleteOffer(c->repo, now);
		addOffer(c->repo, offer);
		//updateOffer(c->repo, now,offer);
	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;

}
void testsController()
{	
	int res;
	OperationsStack* undos = createStack();
	OperationsStack* redos = createStack();
	OfferRepo* repo = createRepo();
	Controller* ctrl = createController(repo, undos, redos);
	
	res=addOfferCtrl(ctrl, "seaside", "Miami", "2018.04.05", 999.6);
	res=addOfferCtrl(ctrl, "mountain", "Tirol", "2018.10.05", 66666);
	res=addOfferCtrl(ctrl, "city break", "Mallorca", "2018.07.05", 888.6);
	assert(getRepoLength(ctrl->repo)==3);
	deleteOfferCtrl(ctrl,"Miami","2018.04.05");
	assert(getRepoLength(ctrl->repo) == 2);
	res = undo(ctrl);
	assert(getRepoLength(ctrl->repo) == 3);
	res = redo(ctrl);
	assert(getRepoLength(ctrl->repo) == 2);	
	
	updateOfferCtrl(ctrl,"mountain","Miami","2018.04.05",6666);
	Offer* off = getOfferOnPos(repo, 0);
	assert(strcmp(getType(off), "mountain") == 0);
	destroyController(ctrl);
   

}


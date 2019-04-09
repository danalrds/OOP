#pragma once
#include "OfferRepository.h"
#include "OperationsStack.h"

typedef struct
{
	OfferRepo* repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
} Controller;

Controller* createController(OfferRepo* r, OperationsStack* undoS, OperationsStack* redoS);
void destroyController(Controller* c);


int addOfferCtrl(Controller* c, char* type, char* dest, char* dep_date, double price);
int deleteOfferCtrl(Controller* c, char* dest, char* dep_date);
int updateOfferCtrl(Controller* c, char* type, char* dest, char* dep_date, double price);

OfferRepo* getRepo(Controller* c);

OfferRepo* filterByDest(Controller* c, char* dest);

OfferRepo* filterByType(Controller* c, char* type);


OfferRepo* filterByPrice(Controller* c, double price);

int undo(Controller* c);

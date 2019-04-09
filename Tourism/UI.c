#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "UI.h"

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}

void printMenu()
{	
	printf("1.Add an offer\n");
	printf("2.List all offers.\n");
	printf("3.Delete an offer\n");
	printf("4.Update an offer\n");
	printf("5.Filter by destination sorted ascending by price\n");
	printf("6.Lab work: Filter by type sorted ascending by destination\n");
	printf("7.Filter by type starting from a given date\n");
	printf("8.Undo\n");
	printf("9.Redo\n");
	printf("10.Filter offers of a certain type with price  < given price\n");
	printf("0 - to exit.\n");
	printf("\**********************************************************\n");
}


int validCommand(int command)
{
	if (command >= 0 && command <= 10)
		return 1;
	return 0;
}


int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}


void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

void readType(char type[50])
{
	char s[50];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		readStringWithSpaces("Please input the type: ", 50, s);
		if (strcmp(s, "seaside") == 0)
			flag = 1;
		if (strcmp(s, "mountain") == 0)
			flag = 1;
		if (strcmp(s, "city break") == 0)
			flag = 1;
		if (flag == 0)
			printf("Must be seaside/mountain/city break!\n");
	}	
	strcpy(type, s);
}

int addOfferUI(UI* ui)
{
	
	char type[50], dest[50], dep_date[50];
	double price;
	
	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	readType(type);	
	readStringWithSpaces("Please input the destination: ", 50, dest);
	readStringWithSpaces("Please input the departure date: ", 50, dep_date);
	
	printf("Please input the price: ");
	scanf("%lf", &price);

	return addOfferCtrl(ui->ctrl, type, dest, dep_date, price);
}

int deleteOfferUI(UI* ui)
{
	
	char type[50], dest[50], dep_date[50];
	double price;

	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	
	readStringWithSpaces("Please input the destination: ", 50, dest);
	readStringWithSpaces("Please input the departure date: ", 50, dep_date);
	
	return deleteOfferCtrl(ui->ctrl, dest, dep_date);
}

int updateOfferUI(UI* ui)
{

	char type[50], dest[50], dep_date[50];
	double price;

	fgetc(stdin); // read the newline, to prevent it from going further to fgets

	readStringWithSpaces("Please input the destination: ", 50, dest);
	readStringWithSpaces("Please input the departure date: ", 50, dep_date);
	Offer* p = find(ui->ctrl->repo, dest, dep_date);
	if (p != NULL)
	{		
		readType(type);
		printf("Please input the price: ");
		scanf("%lf", &price);
		return updateOfferCtrl(ui->ctrl,type, dest, dep_date,price);
	}
	return -1;
}

void listAllOffers(UI* ui)
{
	OfferRepo* repo = getRepo(ui->ctrl);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers.";
		printf("%s \n", str);
	}

	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		toString(getOfferOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listOffersByDest(UI* ui, char* dest)
{
	int ok;
	char aux[50];
	double auxx;
	OfferRepo* repo = filterByDest(ui->ctrl,dest);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers containing this as substring.";
		printf("%s \n", str);
	}	
	ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i < getRepoLength(repo)-1; i++)
		{			
			Offer* off = getOfferOnPos(repo, i);
			Offer* off2 = getOfferOnPos(repo, i+1);
			if (off->price > off2->price)
			{	
				strcpy(aux, off->type);
				strcpy(off->type, off2->type);
				strcpy(off2->type, aux);

				strcpy(aux, off->dest);
				strcpy(off->dest, off2->dest);
				strcpy(off2->dest, aux);

				strcpy(aux, off->dep_date);
				strcpy(off->dep_date, off2->dep_date);
				strcpy(off2->dep_date, aux);

				auxx = off->price;
				off->price = off2->price;
				off2->price = auxx;
				ok = 0;
			}
			
		}
	}
	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		Offer* off = getOfferOnPos(repo, i);
				
			toString(off, str);
			printf("%s\n", str);
		
	}
	destroyRepo(repo);
}


void listOffersByType(UI* ui, char* type)
{
	int ok;
	char aux[50];
	double auxx;
	OfferRepo* repo = filterByType(ui->ctrl, type);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers with this type.";
		printf("%s \n", str);
	}
	ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i < getRepoLength(repo) - 1; i++)
		{
			Offer* off = getOfferOnPos(repo, i);
			Offer* off2 = getOfferOnPos(repo, i + 1);
			if (strcmp(off->dest,off2->dest)>0)
			{				
				strcpy(aux, off->dest);
				strcpy(off->dest, off2->dest);
				strcpy(off2->dest, aux);

				strcpy(aux, off->dep_date);
				strcpy(off->dep_date, off2->dep_date);
				strcpy(off2->dep_date, aux);

				auxx = off->price;
				off->price = off2->price;
				off2->price = auxx;
				ok = 0;
			}

		}
	}
	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		Offer* off = getOfferOnPos(repo, i);

		toString(off, str);
		printf("%s\n", str);

	}
	destroyRepo(repo);
}


void showByPrice_Type(UI* ui, char* type, double price)
{
	int ok;
	char aux[50];
	double auxx;	
	OfferRepo* (*filter_ptr)(Controller* c, char[], double price) = &filterByPrice;


	// Invoking fun() using fun_ptr	

	OfferRepo* repo = (*filter_ptr)(ui->ctrl,type, price);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers with this type and a price < than the given one.";
		printf("%s \n", str);
	}

	////sorting
	ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i < getRepoLength(repo) - 1; i++)
		{
			Offer* off = getOfferOnPos(repo, i);
			Offer* off2 = getOfferOnPos(repo, i + 1);
			if (off->price>off2->price)
			{
				strcpy(aux, off->type);
				strcpy(off->type, off2->type);
				strcpy(off2->type, aux);

				strcpy(aux, off->dest);
				strcpy(off->dest, off2->dest);
				strcpy(off2->dest, aux);

				strcpy(aux, off->dep_date);
				strcpy(off->dep_date, off2->dep_date);
				strcpy(off2->dep_date, aux);

				auxx = off->price;
				off->price = off2->price;
				off2->price = auxx;
				ok = 0;
			}

		}
	}
	
	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		Offer* off = getOfferOnPos(repo, i);

		toString(off, str);
		printf("%s\n", str);

	}
	destroyRepo(repo);
}


void showOffersByType_Date(UI* ui, char* type, char* date)
{		
	int ok;
	OfferRepo* repo = filterByType(ui->ctrl, type);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers with this type.";
		printf("%s \n", str);
	}
	ok = 0;
	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		Offer* off = getOfferOnPos(repo, i);
		if (strcmp(date, off->dep_date) <= 0)
		{
			toString(off, str);
			printf("%s\n", str);
			ok = 1;
		}

	}
	if (ok == 0)
		printf("There are no offers starting with the given date!\n");
	destroyRepo(repo);
}
void startUI(UI* ui)
{
	char dest[50], type[50], date[50];	
	testsController();
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addOfferUI(ui);
			if (res == 1)
				printf("Offer successfully added.\n");
			else
				printf("There is already an offer with the same destination and departure date!\n");
			break;
		}
		case 2:
		{
			listAllOffers(ui);
			break;
		}
		case 3:
		{
			int res = deleteOfferUI(ui);
			if (res == 1)
				printf("Offer successfully deleted.\n");
			else
				printf("Inexistent offer!\n");
			break;
		}
		case 4:
		{
			int res = updateOfferUI(ui);
			if (res == 1)
				printf("Offer successfully updated.\n");
			else
				printf("Inexistent offer!\n");
			break;
		}
		case 5:
		{   
			fgetc(stdin);
			readStringWithSpaces("Please input the destination: ", 50, dest);			
			listOffersByDest(ui,dest);
			break;
		}
		case 6:
		{
			fgetc(stdin);
			readType(type);			
			listOffersByType(ui, type);
			break;
		}
		case 7:
		{
			fgetc(stdin);
			readType(type);
			readStringWithSpaces("Please input the departure date: ", 50, date);
			showOffersByType_Date(ui, type, date);
			break;
		}
		case 8:
		{
			int res = undo(ui->ctrl);
			if (res == 1)
				printf("Undo was successful.\n");
			else
				printf("No more undos to be made.\n");
			break;
		}
		case 9:
		{
			int res = redo(ui->ctrl);
			if (res == 1)
				printf("Redo was successful.\n");
			else
				printf("No more redos to be made.\n");
			break;
		}
		case 10:
		{   double price;
			fgetc(stdin);
			readType(type);
			printf("Please input the price: ");
			scanf("%lf", &price);			
			void(*fun_filter_ptr)(UI* ui, char[],  double) = &showByPrice_Type;

			// Invoking fun() using fun_ptr
			(*fun_filter_ptr)(ui, type,price);
			break;
		}
		}
	}
}
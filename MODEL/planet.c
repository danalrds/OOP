#include "planet.h"
#include <string.h>
#include <stdlib.h>

Planet *createPlanet(char *name, char *type, double distance) {
	Planet *p = (Planet *)malloc(sizeof(Planet));

	p->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy_s(p->name,sizeof name, name);

	p->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy_s(p->type, sizeof type, type);

	p->distance = distance;
	return p;
}

void destroyPlanet(Planet *p) {
	free(p->name);
	free(p->type);
	free(p);
	return;
}

char *getName(Planet *p) {
	return p->name;
}
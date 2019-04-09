#include "Controller.h"

Controller * createController(PlanetRepo * r)
{
	Controller* ctrl = (Controller*)malloc(sizeof(Controller));
	ctrl->repo = r;
	return ctrl;
}

void destroyController(Controller * ctrl)
{
	destroyRepo(ctrl->repo);
	free(ctrl);
}

void addPlanetCtrl(Controller * ctrl, Planet * p)
{
	addPlanet(p, ctrl->repo);
}
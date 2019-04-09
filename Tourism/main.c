#include "UI.h"
#include <crtdbg.h>

int main()
{
	testsDynamicArray();
	testsOfferRepo();
	testsStack();

	OfferRepo* repo = createRepo();
	OperationsStack* operationsStack = createStack();
	OperationsStack* redosStack = createStack();
	Controller* ctrl = createController(repo, operationsStack, redosStack);
	
	addOfferCtrl(ctrl, "seaside","Miami","2018.08.25",9999.9);
	
	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}
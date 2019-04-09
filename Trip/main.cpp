#include "UI.h"
#include <Windows.h>
#include "UI.h"
#include <assert.h>
using namespace std;
void tests()
{
	Repository repo{};
	Controller ctrl{ repo };
	Trip t{"Malakka",74,777};
	Trip t2{ "Maldive",8,999 };
	Trip t3{ "Maldive",8,1000};
	ctrl.addTrip(t);
	ctrl.addTrip(t2);
	std::vector<Trip> trips = ctrl.getRepo().getTrips();
	assert(trips.size() == 2);
	assert(ctrl.getRepo().findTrip("Malakka",74) == 0);
	assert(ctrl.getRepo().findTrip("Maldive", 8) == 1);
	ctrl.removeTrip(t);
	std::vector<Trip> trips1 = ctrl.getRepo().getTrips();
	assert(trips1.size() == 1);
	assert(ctrl.getRepo().findTrip("Malakka", 74) == -1);
	ctrl.updateTrip(t2,t3);
	assert(ctrl.getRepo().findTrip("Maldive", 8) == 0);
	std::vector<Trip> trips2 = ctrl.getRepo().getTrips();
	Trip tt = trips2[0];
	assert(tt.getPrice()==1000);
}
int main()
{
	system("color f1");
	tests();
	Repository repo{};	
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}
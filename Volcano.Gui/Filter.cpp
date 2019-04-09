#include "Filter.h"
#include <sstream>
using namespace std;
Filter::Filter(Repo repo, QWidget *parent) :repo{ repo }, QWidget(parent)
{
	ui.setupUi(this);
	ui.FilterWidget->clear();
	std::vector<Volcano> volcanoes = this->repo.getVolcanoes();
	int ok = 1;
	while (ok == 1)
	{
		ok = 0;
		for (int i=0;i<volcanoes.size()-1;i++)
			if (volcanoes[i].getHeight() < volcanoes[i + 1].getHeight())
			{
				Volcano aux = volcanoes[i];
				volcanoes[i] = volcanoes[i + 1];
				volcanoes[i + 1] = aux;
				ok = 1;
			}
	}
	for (auto v : volcanoes)
	{
		stringstream buffer;
		int height = v.getHeight();
		string string = static_cast<ostringstream*>(&(ostringstream() << height))->str();
		buffer<< v.getName() << " " <<string <<" " << v.getCity();
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(buffer.str()),ui.FilterWidget);
	}
}

Filter::~Filter()
{
}

#pragma once
#include <vector>
class SaleItem
{
private:
	int code;
	double price;
public:
	SaleItem(int code, double price) : code{ code }, price{ price } {}
	~SaleItem() {}
	int getCode() { return code; }
	void setPrice(double nou)
	{
		this->price = nou;
	};
	double getPrice() { return price; }
};

class Sale
{
private:
	std::vector<SaleItem> items;
public:
	Sale() {}
	void add(SaleItem s)
	{
		this->items.push_back(s);
	}
	~Sale() {};
	std::vector<SaleItem> getItems() { return items; }
};

class Discount
{
public:
	virtual double calc(Sale s) const = 0;
	virtual ~Discount() {};
	Discount() {};
};

class ItemDiscount : public Discount
{
private:
	int code;
	int percentage;
public:
	ItemDiscount(int code, int percentage) : code{ code }, percentage{ percentage } {}
	double calc(Sale sale) const override
	{
		double sum = 0;
		for (int i=0;i<sale.getItems().size();i++)
		{
			if (sale.getItems()[i].getCode() == code)
			{
				double disc = percentage * 0.01 * sale.getItems()[i].getPrice();
				//sale.getItems()[i].setPrice(sale.getItems()[i].getPrice() - disc);
				sum = sum + disc;
			}
		}
		return sum;
	}
};

class SumDiscount : public Discount
{
private:
	std::vector<Discount*> discounts;
public:
	SumDiscount() {}
	void add(Discount* d)
	{
		this->discounts.push_back(d);
	}
	double calc(Sale sale) const override
	{
		double sum = 0;
		for (auto d : this->discounts)
			sum = sum + d->calc(sale);
		return sum;
	}
};
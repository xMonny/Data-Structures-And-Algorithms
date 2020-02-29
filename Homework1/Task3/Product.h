#pragma once

extern int GlobalSKU;

class Product
{
	//My product are automobiles

private:
	int SKU;
	double Price;
	int Count;
	int HorsePower;
	int Doors;
	char* Brand;
	char* Model;
	char* Color;
	char* Category;

public:
	Product();
	Product(double, int, int, int, char*, char*, char*, char*);
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();

	void setSKU(const int &SKU);
	int getSKU() const;
	void setPrice(const double&);
	double getPrice() const;
	void setCount(const int&);
	int getCount() const;
	void setHorsePower(const int&);
	int getHorsePower() const;
	void setDoors(const int&);
	int getDoors() const;
	void setBrand(const char*&);
	char* getBrand() const;
	void setModel(const char*&);
	char* getModel() const;
	void setColor(const char*&);
	char* getColor() const;
	void setCategory(const char*&);
	char* getCategory() const;

	void print() const;

};

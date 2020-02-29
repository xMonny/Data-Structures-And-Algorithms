#include <iostream>
#include "Product.h"

int GlobalSKU = 0; //global variable responsible for sku

int strLengthProduct(char* arr) //the length of the name of the automobile
{
	int cnt = 0;
	while (arr[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

void doubleLengthProduct(char* &arr) //double the char array of the automobile
{
	char* newArr = new char[2*strLengthProduct(arr) + 1]; //2*current length + terminating 0
	for (int i = 0; i <= strLengthProduct(arr); i++) // <= strLength because of the terminating 0
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void charArrProduct(char* &arr)
{
	int charCnt = 0;
	char s;

	while (std::cin.get(s) && s != '\n')
	{
		if (charCnt == strLengthProduct(arr))
		{
			doubleLengthProduct(arr);
		}
		arr[charCnt] = s;
		charCnt++;
	}
	arr[charCnt] = '\0';
}

void strCoppyProduct(char* &place, const char* src) //copying char arrays
{
	int charCnt = 0;
	while (src[charCnt] != '\0')
	{
		if (charCnt == strLengthProduct(place))
		{
			doubleLengthProduct(place);
		}
		place[charCnt] = src[charCnt];
		charCnt++;
	}
	place[charCnt] = '\0';
}

Product::Product()
{
	SKU = GlobalSKU + 1;
	Price = 0;
	Count = 0;
	HorsePower = 0;
	Doors = 0;

	Brand = new char[10];
	Model = new char[10];
	Color = new char[10];
	Category = new char[10];
}

Product::Product(double newPrice, int newCount, int newHorsePower, int newDoors, char* newBrand, char* newModel, char* newColor, char* newCategory)
{
    setSKU(GlobalSKU);
	GlobalSKU++;
	setPrice(newPrice);
	setCount(newCount);
	setHorsePower(newHorsePower);
	setDoors(newDoors);

	Brand = new char[10];
	strCoppyProduct(Brand, newBrand);

	Model = new char[10];
	strCoppyProduct(Model, newModel);

	Color = new char[10];
	strCoppyProduct(Color, newColor);

	Category = new char[10];
	strCoppyProduct(Category, newCategory);

}

Product::Product(const Product &product)
{
	setSKU(product.getSKU());
	setPrice(product.getPrice());
	setCount(product.getCount());
	setHorsePower(product.getHorsePower());
	setDoors(product.getDoors());

	Brand = new char[10];
	strCoppyProduct(Brand, product.Brand);

	Model = new char[10];
	strCoppyProduct(Model, product.Model);

	Color = new char[10];
	strCoppyProduct(Color, product.Color);

	Category = new char[10];
	strCoppyProduct(Category, product.Category);
}

Product& Product:: operator=(const Product &product)
{
	if (this != &product)
	{
		//delete the dynamic variables of the already created object
		delete[] Brand;
		delete[] Model;
		delete[] Color;
		delete[] Category;

		setSKU(product.getSKU());
		setPrice(product.getPrice());
		setCount(product.getCount());
		setHorsePower(product.getHorsePower());
		setDoors(product.getDoors());

		Brand = new char[10];
		strCoppyProduct(Brand, product.Brand);

		Model = new char[10];
		strCoppyProduct(Model, product.Model);

		Color = new char[10];
		strCoppyProduct(Color, product.Color);

		Category = new char[10];
		strCoppyProduct(Category, product.Category);
	}
	return *this; //return the address of the new object
}

Product::~Product()
{
	//delete the dynamic memory
	delete[] Brand;
	delete[] Model;
	delete[] Color;
	delete[] Category;
}


void Product::setSKU(const int &newSKU)
{
	if (newSKU >= 1)
	{
		SKU = newSKU;
	}
}

int Product::getSKU() const
{
	return SKU;
}

void Product::setPrice(const double &newPrice)
{
	if (newPrice >= 0)
	{
		Price = newPrice;
	}
}

double Product::getPrice() const
{
	return Price;
}

void Product::setCount(const int &newCount)
{
	if (newCount > 0)
	{
		Count = newCount;
	}
}

int Product::getCount() const
{
	return Count;
}

void Product::setHorsePower(const int &newHorsePower)
{
	if (newHorsePower > 0)
	{
		HorsePower = newHorsePower;
	}
}

int Product::getHorsePower() const
{
	return HorsePower;
}

void Product::setDoors(const int &newDoors)
{
	if (newDoors > 0)
	{
		Doors = newDoors;
	}
}

int Product::getDoors() const
{
	return Doors;
}

void Product::setBrand(const char* &newBrand)
{
	strCoppyProduct(Brand, newBrand);
}

char* Product::getBrand() const
{
	return Brand;
}

void Product::setModel(const char* &newModel)
{
	strCoppyProduct(Model, newModel);
}

char* Product::getModel() const
{
	return Model;
}

void Product::setColor(const char* &newColor)
{
	strCoppyProduct(Color, newColor);
}

char* Product::getColor() const
{
	return Color;
}

void Product::setCategory(const char* &newCategory)
{
	strCoppyProduct(Category, newCategory);
}

char* Product::getCategory() const
{
	return Category;
}

void Product::print() const //print the info about the automobile
{
	std::cout << "Product's info: " << std::endl;
	std::cout << "The stock keeping unit is: " << getSKU() << std::endl;
    std::cout << "Automobile category: " << getCategory() << std::endl;
	std::cout << "The " << getCategory() << " brand is: " << getBrand() << std::endl;
	std::cout << "Model: " << getModel() << std::endl;
	std::cout << "Price: " << getPrice() <<" BGN"<< std::endl;
	std::cout << "There are available " << getCount() << " automobiles." << std::endl;
	std::cout << "Horse Power: " << getHorsePower() <<" HW"<< std::endl;
	std::cout << "Doors number: " << getDoors() << std::endl;
	std::cout << "Color: " << getColor() << std::endl;
}

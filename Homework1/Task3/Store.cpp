#include <iostream>
#include <limits>
#include "Store.h"
#include "Product.h"

int strLengthStore(char* arr) //length for the products in the store
{
	int cnt = 0;
	while (arr[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

void doubleLengthStore(char* &arr) //double the char arrays containing the names of the products in the store
{
	char* newArr = new char[2 * strLengthStore(arr) + 1]; //2*current length + terminating 0
	for (int i = 0; i <= strLengthStore(arr); i++) //<= strLength because of the terminating 0
	{
		newArr[i] = arr[i];
	}
	delete[] arr; //delete the smaller char array
	arr = newArr;
}

void charArrStore(char* &arr) //enter a new automobile from the keyboard
{
	int charCnt = 0;
	char s;

	while (std::cin.get(s) && s != '\n')
	{
		if (charCnt == strLengthStore(arr))
		{
			doubleLengthStore(arr);
		}
		arr[charCnt] = s; //the next symbol of arr is the next entered one
		charCnt++;
	}
	arr[charCnt] = '\0'; //terminating 0
	std::cin.clear();
}

void strCoppyStore(char* &place, const char* src) //string copy function
{
	int charCnt = 0;
	while (src[charCnt] != '\0')
	{
		if (charCnt == strLengthStore(place))
		{
			doubleLengthStore(place);
		}
		place[charCnt] = src[charCnt];
		charCnt++;
	}
	place[charCnt] = '\0'; //terminating zero
}

Store::Store(int numberProduct) //constructor and NumberProduct = 100 by default
{
	setNumberProduct(numberProduct);
	CurrNumberProduct = 0;
	Products = new Product[getNumberProduct()]; //new dynamic array
}

Store::Store(const Store &store)
{
	setNumberProduct(store.getNumberProduct());
	CurrNumberProduct = store.CurrNumberProduct;
	Products = new Product[getNumberProduct()];

	for (int i = 0; i < getNumberProduct(); i++)
	{
		Products[i] = store.Products[i];
	}
}

Store& Store::operator=(const Store &store) //redefining of operator =
{
	if (this != &store) //if this object is different from store object
	{
		delete[] Products;

		setNumberProduct(store.getNumberProduct());
		CurrNumberProduct = store.CurrNumberProduct;
		Products = new Product[getNumberProduct()];

		for (int i = 0; i < getNumberProduct(); i++)
		{
			Products[i] = store.Products[i];
		}
	}

	return *this;
}

Store::~Store()
{
	delete[] Products;
}

void Store::setNumberProduct(const int& newNumberProduct)
{
	NumberProduct = newNumberProduct;
}

int Store::getNumberProduct() const
{
	return NumberProduct;
}

void Store::addProduct()
{
	if (CurrNumberProduct == NumberProduct)
	{
		std::cout << "No space for more products in the store." << std::endl;
	}
	else
	{
		std::cout << "Add the new product in the store... " << std::endl;
		Product newProduct;
		CurrNumberProduct++;

		Products[CurrNumberProduct-1].setSKU(GlobalSKU);
		GlobalSKU++; //the global variable increases

		char* category = new char[10];
		std::cout << "Enter the automobile category (car, jeep, bus and etc.): " << std::endl;
		charArrStore(category);
		const char* categoryC = category;
		newProduct.setCategory(categoryC);

		char* brand = new char[10]; //new dynamic array for the name of the brand
		std::cout << "Enter the " << newProduct.getCategory() << " brand: " << std::endl;
		charArrStore(brand); //entering the brand char by char
		const char* brandC = brand;	//setter only accepts char arrays, so we make another constant variable with the same value
		newProduct.setBrand(brandC); //setter for brand

		//same
		char* model = new char[10];
		std::cout << "Enter the model: " << std::endl;
		charArrStore(model);
		const char* modelC = model;
		newProduct.setModel(modelC);

		double price;
		std::cout << "Enter the price in BGN: " << std::endl;
		std::cin >> price;

		while (std::cin.fail()) //while the input is not valid
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the price: " << std::endl;
			std::cin >> price;
		}

		newProduct.setPrice(price);

		int counts;
		std::cout << "Enter the count: " << std::endl;
		std::cin >> counts;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the count: " << std::endl;
			std::cin >> counts;
		}
		newProduct.setCount(counts);

		int horsePower;
		std::cout << "Enter the horse power: " << std::endl;
		std::cin >> horsePower;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the horse power: " << std::endl;
			std::cin >> horsePower;
		}
		newProduct.setHorsePower(horsePower);

		int doors;
		std::cout << "Enter the number of doors: " << std::endl;
		std::cin >> doors;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the number of doors: " << std::endl;
			std::cin >> doors;
		}
		newProduct.setDoors(doors);

		char* color = new char[10];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the color:" << std::endl;
		charArrStore(color);
		const char* colorC = color;
		newProduct.setColor(colorC);

		Products[CurrNumberProduct - 1] = newProduct;
	}

	std::cout << "Successfully added item! Press enter for main menu." << std::endl;
}

void Store::deleteProduct(int SKU)
{
	bool foundSKU = false;
	if (CurrNumberProduct < 1) //if there aren't any products in the store
	{
		std::cout << "Error in deleting! There are no items in the store." << std::endl;
	}
	else
	{
		for (int i = 0; i < CurrNumberProduct; i++)
		{
			if (Products[i].getSKU() == SKU)
			{
				foundSKU = true; //if the sku exists
				Products[i].setSKU(-1);
				for (int j = i; j < CurrNumberProduct - 1; j++)
				{
					Products[j] = Products[j + 1];
				}
				CurrNumberProduct--;
				std::cout << "Successfully deleted item! Press enter for main menu." << std::endl;
			}
		}
		if (!foundSKU) //if the sku doesn't exist
		{
			std::cout << "Invalid input! There's not such a SKU." << std::endl;
		}
	}
}

void Store::changeProduct(int SKU)
{
	bool foundSKU = false;
	if (CurrNumberProduct < 1) //if there are no items in the store
	{
		std::cout << "There are no items in the store." << std::endl;
	}
	for (int i = 0; i < CurrNumberProduct; i++)
	{
		if (Products[i].getSKU() == SKU)
		{
			foundSKU = true; //if this sku exists

			Product newProduct;

			// new automobile's info:

			Products[i].setSKU(GlobalSKU);
			GlobalSKU++;

			std::cin.clear();
			std::cin.ignore();

			char* category = new char[10];
			std::cout << "Enter the new automobile category (car, jeep, bus and etc.):" << std::endl;
			charArrStore(category);
			const char* categoryC = category;
			newProduct.setCategory(categoryC);

			char* brand = new char[10];
			std::cout << "Enter the new " << newProduct.getCategory() << " brand:" << std::endl;
			charArrStore(brand);
			const char* brandC = brand;
			newProduct.setBrand(brandC);

			char* model = new char[10];
			std::cout << "Enter the new model:" << std::endl;
			charArrStore(model);
			const char* modelC = model;
			newProduct.setModel(modelC);

			double price;
			std::cout << "Enter the new price in BGN:" << std::endl;
			std::cin >> price;
			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new price:" << std::endl;
				std::cin >> price;
			}
			newProduct.setPrice(price);

			int counts;
			std::cout << "Enter the new count:" << std::endl;
			std::cin >> counts;
			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new count:" << std::endl;
				std::cin >> counts;
			}
			newProduct.setCount(counts);

			std::cin.clear();
			std::cin.ignore();

			int horsePower;
			std::cout << "Enter the new horse power:" << std::endl;
			std::cin >> horsePower;
			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new horse power:" << std::endl;
				std::cin >> horsePower;
			}
			newProduct.setHorsePower(horsePower);

			int doors;
			std::cout << "Enter the new number of doors:" << std::endl;
			std::cin >> doors;
			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new number of doors:" << std::endl;
				std::cin >> doors;
			}
			newProduct.setDoors(doors);

			std::cin.clear();
			std::cin.ignore();

			char* color = new char[10];
			std::cout << "Enter the new color:" << std::endl;
			charArrStore(color);
			const char* colorConst = color;
			newProduct.setColor(colorConst);

			Products[CurrNumberProduct - 1] = newProduct;
			std::cout << "Successfully changed item! Press enter for main menu." << std::endl;
		}
	}
	if (!foundSKU)
	{
		std::cout << "Invalid SKU!" << std::endl;
	}
}

void Store::displayProducts()
{
	if (CurrNumberProduct == 0)
	{
		std::cout << "There are no items in the store." << std::endl;
	}

	for (int i = 0; i < CurrNumberProduct; i++)
	{
		Products[i].print();
		std::cout << std::endl;
	}
	std::cout << "Press enter for main menu." << std::endl;
}

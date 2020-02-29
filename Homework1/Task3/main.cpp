#include<iostream>
#include"Store.h"
#include"Product.h"
#include "Product.cpp"
#include "Store.cpp"

int strLength(char* arr)
{
	int cnt = 0;
	while (arr[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

void doubleLength(char* &arr)
{
	char* newArr = new char[2 * strLength(arr) + 1];
	for (int i = 0; i <= strLength(arr); i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void charArr(char* &arr)
{
	int charCnt = 0;
	char s;

	while (std::cin.get(s) && s != '\n')
	{
		if (charCnt == strLength(arr))
		{
			doubleLength(arr);
		}
		arr[charCnt] = s;
		charCnt++;
	}
	arr[charCnt] = '\0';
}

void strCoppy(char* &place, const char* src)
{
	int charCnt = 0;
	while (src[charCnt] != '\0')
	{
		if (charCnt == strLength(place))
		{
			doubleLength(place);
		}
		place[charCnt] = src[charCnt];
		charCnt++;
	}
	place[charCnt] = '\0';
}

int main()
{
	Store MyStore;
	char *c = new char[1];
	do
	{
		//main menu
		std::cout << "A   Add new product" << std::endl;
		std::cout << "X   Delete product" << std::endl;
		std::cout << "C   Change product" << std::endl;
		std::cout << "D   Display products" << std::endl;
		std::cout << "Q   Quit" << std::endl;

		charArr(c);
		if (strLength(c) == 1)
		{
			if (c[0] == 'a' || c[0] == 'A')
			{
				MyStore.addProduct();
				std::cin.clear();
				std::cin.ignore();
			}
			else if (c[0] == 'x' || c[0] == 'X')
			{
				int n;
				std::cout << "Enter the SKU of the product you would like to delete:" << std::endl;
				std::cin >> n;

				while (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid input. The SKU's are integer numbers greater or equal to 1." << std::endl;
					std::cout<<"Enter the SKU of the product you would like to delete:" << std::endl;
					std::cin >> n;
				}
				MyStore.deleteProduct(n);
				std::cin.clear();
				std::cin.ignore();
			}
			else if (c[0] == 'c' || c[0] == 'C')
			{
				int n;
				std::cout << "Enter the SKU of the product you would like to change:" << std::endl;
				std::cin >> n;

				while (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid input. The SKU's are integer numbers greater or equal to 1." << std::endl;
					std::cout << "Enter the SKU of the product you would like to change:" << std::endl;
					std::cin >> n;
				}
				MyStore.changeProduct(n);
				std::cin. clear();
				std::cin.ignore();
			}
			else if (c[0] == 'd' || c[0] == 'D')
			{
				MyStore.displayProducts();
				std::cin. clear();
				std::cin.ignore();
			}

			else if (c[0] == 'q' || c[0] == 'Q')
			{
				break;
			}
			else
			{
				std::cout << "Invalid input! There's not such an option in the menu. Press enter for main menu." << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
		}
		else
		{
			std::cout << "Invalid input! Too many letters." << std::endl;
		}
	}

	while (true);

    return 0;
}

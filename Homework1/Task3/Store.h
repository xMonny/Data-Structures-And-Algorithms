#pragma once
#include "Product.h"

class Store
{
private:
	Product *Products;
	int NumberProduct;
	int CurrNumberProduct;

public:
	Store(int NumberProduct = 100);
	Store(const Store&);
	Store& operator=(const Store&);
	~Store();

	void setNumberProduct(const int&);
	int getNumberProduct() const;

	void addProduct();
	void deleteProduct(int SKU);
	void changeProduct(int SKU);
	void displayProducts();
};



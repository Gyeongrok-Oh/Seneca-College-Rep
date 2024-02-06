#include "Toy.h"

using namespace std;

namespace seneca {
	Toy::Toy() : orderId(0), name(""), numOfItems(-1), price(0.00) 
	{
	}
	void Toy::update(int numItems)
	{
		numOfItems = numItems;
	}
	Toy::Toy(const std::string& toy) {
		// Find the position of ':' for each attribute
		size_t posId = toy.find(':');
		size_t posName = toy.find(':', posId + 1);
		size_t posNum = toy.find(':', posName + 1);

		// Extract substrings for each attribute
		std::string idStr = toy.substr(0, posId);
		std::string nameStr = toy.substr(posId + 1, posName - posId - 1);
		std::string numStr = toy.substr(posName + 1, posNum - posName - 1);
		std::string priceStr = toy.substr(posNum + 1);

		// Convert the extracted substrings to the appropriate types
		orderId = std::stoi(idStr);
		name = nameStr;
		numOfItems = std::stoi(numStr);
		price = std::stod(priceStr);

		// Remove leading and trailing spaces from name
		size_t firstNotSpace = name.find_first_not_of(' ');
		size_t lastNotSpace = name.find_last_not_of(' ');
		name = name.substr(firstNotSpace, lastNotSpace - firstNotSpace + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Toy& toy)
	{
		cout << "Toy ";
		cout.width(8);
		cout << toy.orderId;
		cout.width(18);
		cout.setf(ios::right);
		cout << toy.name;
		cout.width(3) << toy.numOfItems;
		cout << " items ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(8);
		cout << toy.price;
		cout << "/item subtotal:";
		cout.width(7);
		cout << toy.price * toy.numOfItems;
		cout << "tax:";
		cout.width(6);
		cout << toy.HST * toy.price * toy.numOfItems;
		cout << " total:";
		cout.width(7);
		cout << (1 + toy.HST) * toy.price * toy.numOfItems << endl;

		return os;
	}
}
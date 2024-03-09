//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

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
		size_t posId = toy.find(':');
		size_t posName = toy.find(':', posId + 1);
		size_t posNum = toy.find(':', posName + 1);

		std::string idStr = toy.substr(0, posId);
		std::string nameStr = toy.substr(posId + 1, posName - posId - 1);
		std::string numStr = toy.substr(posName + 1, posNum - posName - 1);
		std::string priceStr = toy.substr(posNum + 1);

		orderId = std::stoi(idStr);
		name = nameStr;
		numOfItems = std::stoi(numStr);
		price = std::stod(priceStr);

		size_t firstNotSpace = name.find_first_not_of(' ');
		size_t lastNotSpace = name.find_last_not_of(' ');
		name = name.substr(firstNotSpace, lastNotSpace - firstNotSpace + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Toy& toy)
	{
		os << "Toy";
		os.width(8);
		os << toy.orderId;
		os << ":";
		os.width(18);
		os.setf(ios::right);
		os << toy.name;
		os.width(3);
		os << toy.numOfItems;
		os << " items";
		os.setf(ios::fixed);
		os.precision(2);
		os.width(8);
		os << toy.price;
		os << "/item  subtotal:";
		os.width(7);
		os << toy.price * toy.numOfItems;
		os << " tax:";
		os.width(6);
		os << toy.HST * toy.price * toy.numOfItems;
		os << " total:";
		os.width(7);
		os << (1 + toy.HST) * toy.price * toy.numOfItems << endl;

		return os;
	}
}
//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <iostream>
#include <string>

namespace seneca {

	class Toy {
		size_t orderId;
		std::string name;
		int numOfItems;
		double price;
		const double HST{ 0.13 };
	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);

		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};

}

#endif
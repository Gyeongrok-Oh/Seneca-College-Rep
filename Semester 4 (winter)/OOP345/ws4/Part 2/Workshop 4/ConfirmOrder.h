//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include "Toy.h"

namespace seneca {
	class ConfirmOrder {
		const seneca::Toy** m_toys;
		size_t cnt;
		void deallocate();
	public:
		ConfirmOrder();
		~ConfirmOrder();
		ConfirmOrder& operator+=(const seneca::Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		ConfirmOrder(const ConfirmOrder& other);
		ConfirmOrder& operator=(const ConfirmOrder& other);
		ConfirmOrder(ConfirmOrder&& other) noexcept;
		ConfirmOrder& operator=(ConfirmOrder&& other)noexcept;
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& other);
	};
}

#endif

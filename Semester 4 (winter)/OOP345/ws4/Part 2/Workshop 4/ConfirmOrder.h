#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include "Toy.h"

namespace seneca {
	class ConfirmOrder {
		const seneca::Toy** m_toys;
		size_t cnt;
	public:
		ConfirmOrder();
		~ConfirmOrder();
		ConfirmOrder& operator+=(const seneca::Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& other);
	};
}

#endif

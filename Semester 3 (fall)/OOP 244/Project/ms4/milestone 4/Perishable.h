#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_

#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable : public Item {
		Date expDate{};
		char* instruction{};
	public:
		Perishable();
		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& other);
		const Date& expiry() const;
		virtual int readsku(std::istream& istr);
		std::ofstream& save(std::ofstream& of) const;
	};
}
#endif
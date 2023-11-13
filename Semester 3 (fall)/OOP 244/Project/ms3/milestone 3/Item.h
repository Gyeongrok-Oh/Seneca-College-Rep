#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

#include <fstream>
#include "iProduct.h"
#include "Status.h"
namespace sdds {
	class Item : public iProduct {
		double m_price{};
		int m_quantity{};
		int m_neededQuantity{};
		char* m_description{};
		bool m_flag{};

	protected:
		Status s{};
		int unitNum{};
		bool linear()const;
	public:
		Item();
		~Item();
		Item(const Item& item); 
		Item& operator=(const Item& item);
		int qtyNeeded() const override;
		int qty() const override;
	    operator double()const override;
	    operator bool()const override;
	    int operator-=(int value) override;
	    int operator+=(int value) override;
	    void linear(bool isLinear) override;
		void clear();
		bool operator==(int value) const override;
		bool operator==(const char* desc) const override;
	    std::ofstream& save(std::ofstream& of) const override;
	    std::ifstream& load(std::ifstream& ifstr) override;
	    std::ostream& display(std::ostream& ostr) const override;
	    std::istream& read(std::istream& istr) override;
	    int readSku(std::istream& istr) override;
	};
}
#endif

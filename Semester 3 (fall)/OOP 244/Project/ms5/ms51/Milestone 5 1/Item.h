/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.h
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      Nov 18, 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
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
		std::ofstream& save(std::ofstream& of) const;
		std::ifstream& load(std::ifstream& ifstr) override;
		std::ostream& display(std::ostream& ostr) const override;
		std::istream& read(std::istream& istr) override;
		int readSku(std::istream& istr) override;
	};
}
#endif
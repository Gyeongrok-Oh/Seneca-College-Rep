/* Citation and Sources...
Final Project Milestone 1
Module: iProduct
Filename: iProduct.h
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
#ifndef SDDS_IPRODUCT_H_
#define SDDS_IPRODUCT_H_

namespace sdds {
	class iProduct {

	public:
		virtual ~iProduct() = default;
		virtual int readSku(std::istream& istr) = 0;
		virtual int operator-=(int qty) = 0;
		virtual int operator+=(int qty) = 0;
		virtual operator double()const = 0;
		virtual operator bool()const = 0;
		virtual int qtyNeeded()const = 0;
		virtual int qty()const = 0;
		virtual void linear(bool isLinear) = 0;
		virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
		virtual std::ostream& display(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool operator==(int sku)const = 0;
		virtual bool operator== (const char* description)const = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const iProduct& iproduct);
	std::istream& operator>>(std::istream& istr, iProduct& iproduct);
}
#endif
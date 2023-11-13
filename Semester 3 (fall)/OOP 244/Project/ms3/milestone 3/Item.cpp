
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

namespace sdds {
	bool Item::linear() const
	{
		return m_flag;
	}
	Item::Item() : m_price(0.0), m_quantity(0), m_neededQuantity(0), m_description(nullptr), m_flag(false) {}

	Item::Item(const Item& item)
	{
		*this = item;
	}

	Item& Item::operator=(const Item& item)
	{
		if (this != &item) {
			m_price = item.m_price;
			m_quantity = item.m_quantity;
			m_neededQuantity = item.m_neededQuantity;
			ut.alocpy(m_description, item.m_description);
		}

		return *this;
	}

	int Item::qtyNeeded() const
	{
		return m_neededQuantity;
	}

	int Item::qty() const
	{
		return m_quantity;
	}

	Item::operator double() const
	{
		return m_price;
	}

	Item::operator bool() const
	{
		return s.operator bool();
	}

	int Item::operator-=(int value)
	{
		m_quantity -= value;
		return m_quantity;
	}

	int Item::operator+=(int value)
	{
		m_quantity += value;
		return m_quantity;
	}

	void Item::linear(bool isLinear)
	{
		m_flag = isLinear;
	}

	Item::~Item()
	{
		clear();
	}

	void Item::clear()
	{
		m_price = 0.0; 
		m_quantity = 0; 
		m_neededQuantity = 0; 
		delete[] m_description; 
		m_description = nullptr; 
		m_flag = false; 
		s.clear(); // �޸� ����
		unitNum = 0;
	}

	bool Item::operator==(int value) const
	{
		return unitNum == value;
	}

	bool Item::operator==(const char* desc) const
	{
		return (strStr(m_description,desc) != nullptr) && m_description && desc;
	}

	ofstream& Item::save(ofstream& of) const
	{
		if (*this) { 
			of << '\n' << unitNum << '\t' << m_description << '\t' << m_quantity << '\t' << m_neededQuantity << '\t'; 
			of.setf(std::ios::fixed); 
			of.precision(2); 
			of << m_price; 
		}
		
		return of;
	}

	std::ifstream& Item::load(std::ifstream& ifstr) {

		clear();
		std::string temp;
		ifstr >> unitNum;
		ifstr.ignore();
		getline(ifstr, temp, '\t');

		if (!temp.empty()) {
			ut.alocpy(m_description, temp.c_str());
		}

		ifstr >> m_quantity;
		ifstr.ignore();
		ifstr >> m_neededQuantity;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore();

		if (!ifstr) {
			s = "Input file stream read failed!";
		}

		return ifstr;
	}


	std::ostream& Item::display(std::ostream& ostr) const {
		if (*this) {
			if (m_flag) {
				ostr << unitNum << " | ";
				ostr.width(35); 
				ostr.setf(std::ios::left);

				if (m_description && strLen(m_description) > 35) {
					std::string result = subStr(m_description, 0, 35);
					strCpy(m_description, result.c_str());
					ostr << m_description << " | ";
				}
				else { 
					ostr << m_description << " | ";
				}
				
				ostr.unsetf(std::ios::left); 
				ostr.width(4); 
				ostr.setf(std::ios::right); 
				ostr << m_quantity << " | "; ostr.width(4); 
				ostr << m_neededQuantity << " | ";
				ostr.width(7); 
				ostr.setf(std::ios::fixed); ostr.precision(2); ostr << m_price << " |"; ostr.unsetf(std::ios::right); ostr.unsetf(std::ios::fixed);
			}
			else { 
				ostr << "AMA Item:" << std::endl; 
				ostr << unitNum << ": " << m_description << std::endl;
				ostr << "Quantity Needed: " << m_neededQuantity << std::endl;
				ostr << "Quantity Available: " << m_quantity << std::endl; 
				ostr << "Unit Price: $"; 
				ostr.setf(std::ios::fixed); 
				ostr.precision(2); 
				ostr << m_price << std::endl; 
				ostr << "Needed Purchase Fund: $"; 
				ostr.precision(2); 
				double value = (m_neededQuantity - m_quantity) * m_price;
				ostr << value << std::endl; 
			}
		}
		else { 
			ostr << s; 
		}
		
		return ostr;
	}
	istream& Item::read(istream& istr)
	{
		string temp; 
		cout << "AMA Item:" << endl;
		cout << "SKU: " << unitNum << endl;
		istr.ignore(); 
		cout << "Description: "; 
		getline(istr, temp, '\n'); 
		if (temp != "") { 

			ut.alocpy(m_description, temp.c_str());

		}
		
		cout << "Quantity Needed: "; 
		m_neededQuantity = ut.getint(1, 9999,"","");
		cout << "Quantity On Hand: "; 
		m_quantity = ut.getint(0, m_neededQuantity,"","");
		cout << "Unit Price: $"; 
		m_price = ut.getDouble(0.00, 9999.00,nullptr,nullptr);
		if (!istr && !cin) {
			s = "Console Entry failed";
		}
		
		return istr;
	}

	int Item::readSku(std::istream& istr) { 
		std::cout << "SKU: "; 
		unitNum = ut.getint(40000, 99999, "", "");
		
		return unitNum;
	}
}

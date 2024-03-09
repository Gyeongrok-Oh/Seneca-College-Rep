#include "CustomerOrder.h"
#include <iomanip>

using namespace std;

namespace seneca {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cnt(0), m_lstItem(nullptr){

	}

	CustomerOrder::CustomerOrder(const std::string& str) : CustomerOrder()
	{
		bool more = true; 
		size_t pos = 0u; 
		size_t count = 0u; 
		size_t itemPos = 0u; 
		size_t itemCnt = 0u; 
		Utilities util; 
		util.setFieldWidth(m_widthField);

		while (more) {
			if (count == 0) 
				m_name = util.extractToken(str, pos, more);
			else if (count == 1) 
				m_product = util.extractToken(str, pos, more);
			else if (count == 2) { 
				itemPos = pos; 
				while (more) { 
					util.extractToken(str, itemPos, more);
					itemCnt++; 
				} 
				m_cnt = itemCnt;
				
				itemCnt = 0; 
				more = true; 
				m_lstItem = new Item * [m_cnt];
			}
			else { 
				m_lstItem[itemCnt] = new Item(util.extractToken(str, pos, more));
				itemCnt++; 
			}
			
			count++;
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
		throw "deleted Copy Constructer";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : m_lstItem(nullptr), m_cnt(0){
		*this = move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this != &src) {
			m_name = src.m_name;
			m_product = src.m_product;

			for (size_t i = 0; i < m_cnt; i++) {
				delete m_lstItem[i];
			}

			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_cnt = src.m_cnt;
			m_lstItem = src.m_lstItem;

			src.m_name = "";
			src.m_product = "";
			src.m_lstItem = nullptr;
			src.m_cnt = 0;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cnt; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool seneca::CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cnt; ++i) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;  
			}
		}
		return true;  // All items are filled, return true
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool is_filled = true; 
		
		for (size_t i = 0u; i < m_cnt && is_filled; i++) { 
			is_filled = m_lstItem[i]->m_itemName == itemName ? m_lstItem[i]->m_isFilled : true; 
		}
		
		return is_filled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0u; i < m_cnt; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() >= 1) { m_lstItem[i]->m_serialNumber = station.getNextSerialNumber(); m_lstItem[i]->m_isFilled = true; station.updateQuantity(); os << "Filled " << m_name; os << ", " << m_product; os << " [" << m_lstItem[i]->m_itemName; os << "]" << std::endl; }
				else {
					os << "Unable to fill " << m_name; os << ", " << m_product; os << " [" << m_lstItem[i]->m_itemName; os << "]" << std::endl;
				}
			}
		}
	}
	
	void CustomerOrder::display(std::ostream& os) const {
		os << std::left << m_name << " - " << m_product << std::endl;

		for (size_t i = 0; i < m_cnt; i++) {
			os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName << " - ";

			os << std::setw(0); // Reset width to default
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");

			os << std::endl;
		}
	}


}



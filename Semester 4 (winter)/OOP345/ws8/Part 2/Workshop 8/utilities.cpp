//Name : Gyeongrok Oh
//Seneca Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (auto i = 0u; i < desc.size(); ++i) {
			for (auto j = 0u; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					Product* temp = new Product(desc[i].desc, price[j].price);
					if (price[j].price < 0) {

						delete temp; 
						throw std::string("*** Negative prices are invalid ***");
					}

					temp->validate(); 
				
			
					priceList += temp; 

					delete temp; 
					temp = nullptr;


				}
			}
		}

		return priceList;
	}
	

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[j].price));
					ptr->validate();
					priceList += ptr;
				}
			}
		}

		return priceList;
	}
}
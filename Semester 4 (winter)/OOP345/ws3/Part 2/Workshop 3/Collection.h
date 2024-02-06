//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student id : 119140226

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include "Pair.h"

namespace seneca {

	template <typename T, unsigned int CAPACITY>

	class Collection {

	protected:
		T elements[CAPACITY]{};
		unsigned int currElements{ 0 };
		T dummyObj{};

	public:
		Collection();
		virtual ~Collection() = default;
		int size() const;
		void display(std::ostream& os= std::cout) const;
		virtual bool add(const T& item);
		T operator[](size_t index) const;
		// Inside Collection class
		template <typename U, unsigned int CAP>
		friend std::ostream& operator<<(std::ostream& os, const Collection<U, CAP>& collection);


	};

	template <typename T, unsigned int CAPACITY>
	Collection<T, CAPACITY>::Collection(){}

	template <typename T, unsigned int CAPACITY>
	int Collection<T, CAPACITY>::size() const {
		return currElements;
	}

	template <typename T, unsigned int CAPACITY>
	void Collection<T, CAPACITY>::display(std::ostream& os) const {
		os << "----------------------" << std::endl;
		os << "| Collection Content |" << std::endl;
		os << "----------------------" << std::endl;

		for (size_t i = 0; i < currElements; i++) {
			os << elements[i] << std::endl;
		}
		os << "----------------------" << std::endl;
	}

	template <typename T, unsigned int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item) {

		if (currElements < CAPACITY) {

			elements[currElements] = item;
			currElements++;

			return true;
		}
		else {
			return false;
		}

	}

	template <typename T, unsigned int CAPACITY>
	T Collection<T, CAPACITY>::operator[](size_t index) const {
		return (index < currElements) ? elements[index] : dummyObj;
	}


	template<> 
	Collection<Pair, 100>::Collection() { 
		Pair P("No Key", "No Value"); 
		dummyObj = P; 
	};

	// Outside the Collection class
	template <typename U, unsigned int CAP>
	std::ostream& operator<<(std::ostream& os, const Collection<U, CAP>& collection) {
		for (size_t i = 0; i < collection.size(); ++i) {
			os << "Item [" << i << "]: " << collection[i] << "\n";
		}
		return os;
	}


}
#endif

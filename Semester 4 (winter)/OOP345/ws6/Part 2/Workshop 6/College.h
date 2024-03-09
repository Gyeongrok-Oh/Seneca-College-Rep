#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <list>
#include <vector>
#include "Person.h"

namespace seneca {
	class College {
		std::vector<Person*> m_persons{};
	public:
		College() = default;
		virtual ~College();
		College(const College&) = delete;
		College& operator=(const College&) = delete;
		College(College&&) = delete;
		College& operator=(College&&) = delete;
		College& operator+=(Person* thePerson);
		void display(std::ostream& out) const;
		template<typename T>
		void select(const T& src, std::list<const Person*>& persons){
			for (const auto& person : m_persons) {
				if (src(person)) {
					persons.push_back(person);
				}
			}
		}
	};
}

#endif
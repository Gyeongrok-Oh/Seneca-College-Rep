//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>


namespace seneca {
	class SpellChecker {
		static const size_t SIZE{ 6 };
		std::string m_badWords[SIZE];
		std::string m_goodWords[SIZE];
		size_t m_count[SIZE];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif
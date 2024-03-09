//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "SpellChecker.h"

using namespace std;

namespace seneca {
	seneca::SpellChecker::SpellChecker(const char* filename)
	{
		ifstream f(filename);

		if (!f) {
			throw ("Bad file name!");
		}
		else {
			string getLine{ "" };

			for (size_t i = 0; i < SIZE; i++) {
				getline(f, m_badWords[i], ' '); 
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' ')); 
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1); 
				getline(f, m_goodWords[i], '\n'); 
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' ')); 
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
			}

			f.close();
		}

		for (size_t i = 0; i < SIZE; i++) {
			m_count[i] = 0;
		}
	}


	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < SIZE; ++i) {
			size_t startPos = 0;
			while (true) {
				size_t foundPos = text.find(m_badWords[i], startPos);
				if (foundPos == string::npos) {
					break;  
				}

		
				text.replace(foundPos, m_badWords[i].length(), m_goodWords[i]);

				startPos = foundPos + m_goodWords[i].length();

				++m_count[i];
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		for (size_t i = 0; i < SIZE; ++i) {
			out.width(15);
			out << m_badWords[i];
			out << ": ";
			out << m_count[i];
			out << " replacements" << endl;
		}
	}


}

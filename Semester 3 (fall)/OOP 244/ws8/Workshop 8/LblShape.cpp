#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{
		if (label[0] != 0 && label != nullptr) {
			m_label = new char[(strlen(label) + 1)];
			strcpy(m_label, label);
		}
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& is)
	{
		string userInput{};
		getline(is, userInput, ',');

		const char * cString = userInput.c_str();
		m_label = new char(strlen(cString) + 1);
		strcpy(m_label, cString);
	}

}


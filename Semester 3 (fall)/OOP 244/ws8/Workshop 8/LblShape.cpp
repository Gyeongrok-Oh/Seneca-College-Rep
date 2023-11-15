#include <string>
#include "LblShape.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{
		if (label[0] != 0 && label != nullptr) {
			delete[] m_label;
			m_label = new char[(strLen(label) + 1)];
			strCpy(m_label, label);
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
		delete[] m_label;
		const char * cString = userInput.c_str();
		m_label = new char[strLen(cString) + 1];
		strCpy(m_label, cString);
	}

}


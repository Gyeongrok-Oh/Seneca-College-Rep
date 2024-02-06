//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Studemt ID : 119140226
#include "StringSet.h"

using namespace std;

namespace seneca {


	StringSet::StringSet(const char* fileName)
	{
		ifstream inputFile(fileName);

		string s;

		char delimiter{ ' ' };

		if (inputFile.is_open()) {

			while (getline(inputFile, s, delimiter)) {

				numStrings++;
			}

			deallocate();

			strings = new string[numStrings];

			inputFile.clear(); // reset the file stream
			inputFile.seekg(0, ios::beg); // move back beginning of the file because re-read the file again

			for (size_t i = 0; i < numStrings; i++) {
				getline(inputFile, s, delimiter);
				strings[i] = s;
			}

			inputFile.close();

		}
		else {
			cerr << "Unable to open the file!!!" << endl;
		}
	}

	size_t StringSet::size() const
	{
		return numStrings;
	}

	std::string StringSet::operator[](size_t index)
	{
		return (index < numStrings) ? strings[index] : "\0";
	}

	StringSet::StringSet(const StringSet& other) : strings(nullptr)
	{
		if (other.strings != nullptr && other.strings) {
			*this = other;
		}
	}

	StringSet& StringSet::operator=(const StringSet& other)
	{
		if (this != &other) {
			numStrings = other.numStrings;

			deallocate();
			strings = new string[numStrings];

			copy(other.strings, other.strings + numStrings, strings); // internet search
		}

		return *this;
	}

	StringSet::StringSet(StringSet&& other)noexcept {
		
		if (other.strings != nullptr && other.strings) {
			*this = move(other);
		}
	}

	StringSet& StringSet::operator=(StringSet&& other)noexcept
	{
		if (this != &other) {
			numStrings = other.numStrings;
			other.numStrings = 0;

			deallocate();
			strings = new string[numStrings];

			copy(other.strings, other.strings + numStrings, strings); // internet search

			other.deallocate();
		}

		return *this;
	}

	StringSet::~StringSet()
	{
		deallocate();
		numStrings = 0;
	}

	void StringSet::deallocate()
	{
		delete[] strings;
		strings = nullptr;
	}
}

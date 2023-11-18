/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: Utils.h
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      Nov 8,2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	const int sdds_testYear = 2023;
	const int sdds_testMon = 12;
	const int sdds_testDay = 9;
	class Utils {
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		// optional functions
		void alocpy(char*& destination, const char* source);
		int getint(const char* prompt = nullptr);
		int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
		double getDouble(const char* prompt);
		double getDouble(double min, double max, const char* prompt, const char* errMes);
	};
	extern Utils ut;
	// Function Prototypes:

	// strLen: Calculate the length of the C-String in characters
	int strLen(const char* s);

	// strCpy: Cpies the srouce character string into the destination
	void strCpy(char* des, const char* src);

	// strnCpy: Copies the source character string into the destination upto "len" characters.
	//          The destination will be null terminated only if the number
	//          of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len);

	// strCmp: Compares two C-strings
	int strCmp(const char* s1, const char* s2);

	// strnCmp: Compares two C-strings upto "len" characters.
	int strnCmp(const char* s1, const char* s2, int len);

	// strStr: returns the address of first occurance of "str2" in "str1"
	//         returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2);

	// strCat: Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src);

	std::string subStr(const char* str, size_t start, size_t length);
}
#endif
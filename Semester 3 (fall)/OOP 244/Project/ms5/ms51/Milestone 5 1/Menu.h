/***********************************************************************
// Final project Milestone 2
// Module: Menu
// File: Menu.h
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-8-2023            Reason
***********************************************************************/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {
	class Menu {
		char* menuCont{};
		unsigned int maxOption{ 15 };
	public:
		Menu(const char* oprions);
		Menu(const Menu& other) = delete;  // Disallow copy constructor
		Menu& operator=(const Menu& other) = delete;  // Disallow assignment operator
		unsigned int countOption(const char* options) const;
		~Menu();
		unsigned int run() const;
	};
}
#endif
/***********************************************************************
// Final project Milestone 2
// Module: AidMan
// File: AidMan.h
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-8-2023            Reason
***********************************************************************/
#ifndef SDDS_AIDMAN_H_
#define SDDS_AIDMAN_H_

#include "Menu.h"
#include "iProduct.h"

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		char* m_fileName{};
		Menu m_mainMenu;
		iProduct* items[sdds_max_num_items];
		int numItem;
		unsigned int menu() const;
	public:
		AidMan(const char* filename = nullptr);
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan&) = delete;
		void run();
		int list(const char* str);
	};
	extern int numOfArr;
}
#endif
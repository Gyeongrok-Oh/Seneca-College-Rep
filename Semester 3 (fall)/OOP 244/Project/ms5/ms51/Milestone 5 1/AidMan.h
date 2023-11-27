/***********************************************************************
// Final project Milestone 5
// Module: AidMan
// File: AidMan.h
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-26-2023            Reason
***********************************************************************/
#ifndef SDDS_AIDMAN_H_
#define SDDS_AIDMAN_H_

#include "Date.h"
#include "Perishable.h"
#include "Status.h"
#include "Menu.h"
#include "iProduct.h"
#include "Utils.h"
#include "Item.h"

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		char* m_fileName{};
		Menu m_mainMenu;
		iProduct* items[sdds_max_num_items];
		int numItem;
		unsigned int menu() const;
		void save();
		void deallocate();
		bool load();
	public:
		AidMan(const char* filename = nullptr);
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan&) = delete;
		void run();
		int list(const char* sub_desc = nullptr);
		~AidMan();
	};

}
#endif
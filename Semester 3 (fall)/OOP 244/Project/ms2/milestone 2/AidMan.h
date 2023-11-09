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

namespace sdds {
	class AidMan {
		char* m_fileName{};
		Menu m_mainMenu;
		unsigned int menu() const;
	public:
		AidMan(const char* filename);
		AidMan(const AidMan&) = delete; 
		AidMan& operator=(const AidMan&) = delete; 
		void run();
	};
}
#endif

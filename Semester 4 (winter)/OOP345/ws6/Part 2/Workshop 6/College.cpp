#include "College.h" 
#include <iomanip>

using namespace std;

namespace seneca {

	College::~College()
	{
		for (auto i = m_persons.begin(); i != m_persons.end(); i++) { 
			delete* i; 
		}
	}


	College& College::operator+=(Person* thePerson)
	{
		m_persons.push_back(thePerson);
		return *this;
	}

	void College::display(std::ostream& out) const
	{
		out << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		out << "|                                        Test #1 Persons in the college!                                               |" << endl; 
		out << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		
		for (auto i = m_persons.begin(); i != m_persons.end(); i++) { 
			(*i)->display(out); 
			out << std::endl; 
		}
		
		out << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		out << "|                                        Test #2 Persons in the college!                                               |" << endl; 
		out << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		
		for (auto i = m_persons.begin(); i != m_persons.end(); i++) {
			out.setf(ios::left);
			out << "| ";
			out.width(10);
			out << (*i)->status();
			out << "| ";
			out.width(10);
			out << (*i)->id();
			out << "| ";
			out.width(20);
			out << (*i)->name();
			out << " | ";
			out.width(3);
			out << (*i)->age();
			out << " |";
			out << endl;

		/*	out << std::left; out << "| " << std::setw(10) << (*i)->status() << "| "; out << std::setw(10) << (*i)->id() << "| "; out << std::setw(20) << (*i)->name() << " | ";
			out << std::setw(3) << (*i)->age() << " |"; out << std::endl;*/
		}
		
		out << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}

}
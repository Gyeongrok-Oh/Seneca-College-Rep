//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "College.h" 


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
		}
		
		out << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}

}
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Studemt ID : 119140226
#include "TimedEvents.h"

using namespace std;

namespace seneca {

	TimedEvents::TimedEvents() :  numRec(0)
	{
		for (size_t i = 0; i < MAX_EVENTS; i++) {
			events[i].durationEvent = chrono::steady_clock::duration::zero();
		}
	}

	void TimedEvents::startClock()
	{
		startTime = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		endTime = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName)
	{
		if (numRec < MAX_EVENTS) {

			events[numRec].name = string(eventName);
			events[numRec].unitTime = "nanoseconds";
			events[numRec].durationEvent = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

		}

		numRec++;
	}

	ostream& operator<<(ostream& os, const TimedEvents& timeEvent)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (size_t i = 0; i < timeEvent.numRec; i++) {
			os.width(21);
			os.setf(ios::left);
			os << timeEvent.events[i].name << " ";
			os.width(13);
			os.setf(ios::right);
			os << timeEvent.events[i].durationEvent.count() << " ";
			os.unsetf(ios::right);
			os << timeEvent.events[i].unitTime << endl;
		}

		os << "--------------------------" << endl;

		return os;
	}

}


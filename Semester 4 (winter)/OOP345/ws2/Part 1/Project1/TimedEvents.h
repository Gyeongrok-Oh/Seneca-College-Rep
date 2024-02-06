//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Studemt ID : 119140226
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace seneca{

	const int MAX_EVENTS{ 10 };

	class TimedEvents {

		size_t numRec;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct Event {
			std::string name;
			std::string unitTime;
			std::chrono::steady_clock::duration durationEvent;

		};

		Event events[MAX_EVENTS];

	public:

		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char * eventName);

		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& timeEvent);
	};
}
#endif

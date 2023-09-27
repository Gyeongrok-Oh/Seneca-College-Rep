#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_

namespace sdds {
	class Train {
		char* tName;
		int noOfpeople;
		int depTime;
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		bool validName(const char* name) const; //added
	public:
		void initialize();
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;
		// Part 2
		bool load(int& notBoarded);
		bool updateDepartureTime();
		bool transfer(const Train& otherTrain);

	};
}
#endif // !SDDS_TRAIN_H_

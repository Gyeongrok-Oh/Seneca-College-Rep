#ifndef _PHONE_H_
#define _PHONE_H_

const int MAX_LENGTH = 50;

struct Phone {
    char name[MAX_LENGTH + 1];
    char area[4];
    char prefix[4];
    char number[5];
};

namespace sdds{
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);

}

#endif 

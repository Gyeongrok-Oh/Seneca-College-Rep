#define _CRT_SECURE_NO_WARNINGS

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lower_bound, int upper_bound);

char inputCharOption(const char* valid_chars);

void inputCString(char* st, int min_len, int max_len);

void displayFormattedPhone(char* st);


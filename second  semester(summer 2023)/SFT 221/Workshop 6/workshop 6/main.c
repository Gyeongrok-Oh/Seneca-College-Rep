#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"
#include <assert.h>


int main(void)
{
	char testStr[] = { "This is a\n string with embedded newline characters and \n12345 numbers inside it as well 7890" };
	myLogFile = l4cOpen("testLog.log", 0);
	struct StringIndex index = indexString(testStr);
	int i;
	l4cInfo(&myLogFile, "this is a test to find a bug using logging");
	l4cInfo(&myLogFile, "I don't know well about if issapce is true, the return value is 8");
	printf("LINES\n");
	for (i = 0; i < index.numLines; i++)
	{
		l4cPrintf(&myLogFile, L4C_INFO, "LINE i = %d", i);
		printf("before my assert, line = %d, file = %s\n", __LINE__, __FILE__);
		assert(index.lineStarts[i] == 0 || index.lineStarts[i] == 10 || index.lineStarts[i] == 56); // to check the start line of index after \n
		printf("ASSERT SUCESS\n");
		printUntil(index.str, index.lineStarts[i], '\n');

		printf("\n");
	}
	printf("\nWORDS\n");
	for (i = 0; i < index.numWords; i++)
	{
		printUntilSpace(index.str, index.wordStarts[i]);
		printf("\n");
	}
	printf("\nNUMBERS\n");
	for (i = 0; i < index.numNumbers; i++)
	{
		printUntilSpace(index.str, index.numberStarts[i]);
		printf("\n");
	}
	return 0;
	}









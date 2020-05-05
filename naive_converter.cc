/*
 * A naive converter that converts chars to strings by subtracting the char '0'
 * from every char to get an accurate int representation. It iterates through
 * each char* back to front, each time multiplying the new char by 10. 
 */
#include "converter.hh"
#include <string.h> // for strlen
#include <stdlib.h>

//naive impementation: just go through the chars and subtract '0' from them
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
  	uint32_t temp = 0;
  	int length = strlen(lines[i]);
  	unsigned tensplace = 1;
  	for (int c = length - 1; c >= 0; c--)
  	{
  		temp += tensplace * (lines[i][c] - '0');
  		tensplace *= 10;
  	}
    nums[i] = temp;


  }
}

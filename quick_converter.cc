/*
 * same as naive_converter, but iterates through the char* front to back instead
 * of using nasty strlen
 */
#include "converter.hh"
#include <stdlib.h>

#include <iostream> //for debug

//naive impementation: just go through the chars and subtract '0' from them
// same thing this time, but different way of adding it to the temp int.
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
  	


    //to do: convert to binary and then left shift
  	char c = lines[i][0];
  	uint32_t temp = c - '0';
  	int j = 1;
  	c = lines[i][1];
  	while (c != '\0')
  	{	
  		temp = (temp * 10) + (c-'0');
  		j++;
  		c = lines[i][j];
  	}
    nums[i] = temp;


  }
}

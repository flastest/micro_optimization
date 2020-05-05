/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.hh"
#include <string.h> // for strlen
#include <stdlib.h>

#include <iostream> //for debug

//naive impementation: just go through the chars and subtract '0' from them
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
  	//std::cout <<"line " <<i<<" is " <<lines[i]<<std::endl;
  	
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

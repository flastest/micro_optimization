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
  	uint32_t temp = 0;
  	int length = strlen(lines[i]);
  	unsigned tensplace = 1;
  	//std::cout <<"line " <<i<<" is " <<lines[i]<<std::endl;
  	for (int c = length - 1; c >= 0; c--)
  	{
  		//std::cout <<"wassupe" <<std::endl;
  		temp += tensplace * (lines[i][c] - '0');
  		tensplace *= 10;
  	}
    nums[i] = temp;


  }
}

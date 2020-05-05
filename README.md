# micro_optimization

##### adding optimizations to char -> int conversion
##### Ariel Flaster or whatever my name is

These are different implementations of a converter that quickly converts char* to int. The goal was to make an optimized version that was super fast. 

#### Makefile

I made a makefile because I took 221 when they still taught that. Makefiles are the last beauty in this covid-ridden world. Make produces a naive_converter, quick_converter, and an eitan_converter. The names are pretty self explanatory, the eitan_converter is the original naïvest implementation (which uses atoi) that I kept around to compare my naive_converter to.


### Naïve converter

The first thing I wanted to optimize was conversion from `char` to `int`. I have no idea how atoi does it, but I'm fairly certain that it checks for negatives and non-number characters and stuff like that. We were promised only non-negative, non overflowing, integer-valued character lists to convert. It's a big waste of time to check for negatives, so I just took the current char in the `char*` and subtracted `'0'` from the `char`. Since `chars` can be interpreted as ascii codes (aka `ints`), subtracting `'0'` subtracts the zero ascii code from the number ascii code, leaving behind the difference between zero and the character. Yoloswag!

To put those random characters in order in an `int`, I iterated through the `char*` backwards. Every time I incremented my counter, I multiplied a tensplace int by ten. This tensplace int started at 1 and was multiplied by the current character and added to the current running total `uint32_t` called temp. So, this would start with the ones digit in the `char*`, multiply it by one, and add it to the running total. It would also then multiply tensplace by 10. Then it would iterate to the tens digit in the `char*`, multiply the current `char` by tensplace, and add it to the running total. It is a waste to iterate backwards, but it was the first thing I thought of.

This proved to be twice as quick as atoi on my computer.

### Quick converter

What I did to optimize this was iterate through the `char*` from the front. I don't want to waste time finding the length of the `char*` and iterating backwards from there! I edited the algorithm to multiply temp by ten every time a new non `'\0'` was added. Just making this one change reduced the time my algorithm took to 1/6th the original atoi time!


| algorithm | minimum time after 1000 trials (ms) |
|-----------|-------------------------------------|
|   eitan   |            31                       |
|   naive   |            16                       |
|   quick   |            5                        |

### Other edits

I had to change the timing mechanism because clock() was not doing the right thing. That's the only change I made to driver.cc

oh, I also converted everything to c++ because i wanted to use iostream for debug logs which i ended up removing for obvious reasons. c++ is cuter anyway.

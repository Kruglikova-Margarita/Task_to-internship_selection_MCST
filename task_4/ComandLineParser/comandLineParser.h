#include "../StringArray/stringArray.h"

#ifndef comandLineParser_h
#define comandLineParser_h

StringArray nonOptionsParser(int argc, char* argv[]);
void optionsParser(int argc, char* argv[], StringArray* correct_options, StringArray* incorrect_options);

#endif
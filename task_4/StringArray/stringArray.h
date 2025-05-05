#include <stdbool.h>

#ifndef stringArray_h
#define stringArray_h


typedef struct StringArray {
    char** strings;
    int size;
} StringArray;



StringArray createStringArray();
void freeStringArray(StringArray* string_array);
bool containsString(StringArray* string_array, char* string);
void addString(StringArray* string_array, char* string);
void printStringArray(StringArray* string_array);


#endif
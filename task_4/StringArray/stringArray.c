#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stringArray.h"



StringArray createStringArray() {
    StringArray string_array = {NULL, 0};

    return string_array;
}



void freeStringArray(StringArray* string_array) {
    char** strings = string_array->strings;
    int size = string_array->size;

    for (int i = 0; i < size; i++) {
        free(strings[i]);
    }

    if (size != 0) {
        free(strings);
    }
}



bool containsString(StringArray* string_array, char* string) {
    char** strings = string_array->strings;
    int size = string_array->size;

    for (int i = 0; i < size; i++) {
        if (strcmp(strings[i], string) == 0) {
            return true;
        }
    }

    return false;
}



void addString(StringArray* string_array, char* string) {
    char** old_strings = string_array->strings;
    int size = string_array->size;

    char** new_strings = (char**) calloc(size + 1, sizeof(char*));

    for (int i = 0; i < size; i++) {
        new_strings[i] = old_strings[i];
    }

    new_strings[size] = strdup(string);
    free(old_strings);
    string_array->strings = new_strings;
    (string_array->size)++;
}



void printStringArray(StringArray* string_array) {
    char** strings = string_array->strings;
    int size = string_array->size;

    for (int i = 0; i < size - 1; i++) {
        printf("%s, ", strings[i]);
    }

    printf("%s\n", strings[size - 1]);
}
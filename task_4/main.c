#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>
#include "StringArray/stringArray.h"
#include "ComandLineParser/comandLineParser.h"



int main(int argc, char* argv[]) {
    StringArray correct_options = createStringArray();
    StringArray incorrect_options = createStringArray();

    optionsParser(argc, argv, &correct_options, &incorrect_options);

    if (incorrect_options.size == 0) {
        if (correct_options.size != 0) {
            printf("Options are correct: ");
            printStringArray(&correct_options);
        } else {
            printf("There are no inputed options\n");
        }

        StringArray non_options = nonOptionsParser(argc, argv);

        if (non_options.size != 0) {
            printf("Non-options: ");
            printStringArray(&non_options);
        } else {
            printf("There are no non-options\n");
        }

        freeStringArray(&non_options);
    } else {
        printf("Error! %d incorrect options: ", incorrect_options.size);
        printStringArray(&incorrect_options);
    }


    freeStringArray(&correct_options);
    freeStringArray(&incorrect_options);

    return 0;
}
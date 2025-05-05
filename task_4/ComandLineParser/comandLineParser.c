#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>
#include "../StringArray/stringArray.h"



StringArray nonOptionsParser(int argc, char* argv[]) {
    StringArray non_options = createStringArray();

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            addString(&non_options, argv[i]);
        }
    }

    return non_options;
}



void optionsParser(int argc, char* argv[], StringArray* correct_options, StringArray* incorrect_options) {
    opterr = 0;

    char* short_opts = "mcst";
    char opt;
    int flag = 0;

    const struct option long_opts[] = {
        {"elbrus", required_argument, &flag, 1},
        {NULL, 0, NULL, 0}
    };

    int opt_index;

    while((opt = getopt_long(argc, argv, short_opts, long_opts, &opt_index)) != -1) {
        switch(opt) {
            case 'm': {
                if (!containsString(correct_options, "m")) {
                    addString(correct_options, "m");
                }

                break;
            }

            case 'c': {
                if (!containsString(correct_options, "c")) {
                    addString(correct_options, "c");
                }

                break;
            }

            case 's': {
                if (!containsString(correct_options, "s")) {
                    addString(correct_options, "s");
                }

                break;
            }

            case 't': {
                if (!containsString(correct_options, "t")) {
                    addString(correct_options, "t");
                }

                break;
            }

            case 0: {
                char* opt_with_arg = (char*) calloc(13, sizeof(char)); 
                int opt_len = strlen(long_opts[opt_index].name);

                memcpy(opt_with_arg, "--", 2);
                memcpy(opt_with_arg + 2, long_opts[opt_index].name, opt_len);
                memcpy(opt_with_arg + 2 + opt_len, "=", 1);
                memcpy(opt_with_arg + 2 + opt_len + 1, optarg, strlen(optarg));

                if (strcmp(optarg, "1c+") == 0 || strcmp(optarg, "2c+") == 0 || strcmp(optarg, "2c3") == 0 || strcmp(optarg, "4c") == 0 || strcmp(optarg, "8c") == 0 || strcmp(optarg, "16c") == 0) {
                    if (!containsString(correct_options, opt_with_arg)) {
                        addString(correct_options, opt_with_arg + 2);
                    }
                } else {
                    if (!containsString(incorrect_options, opt_with_arg)) {
                        addString(incorrect_options, opt_with_arg);
                    }
                }

                free(opt_with_arg);

                break;
            }

            case '?': {
                char* incorrect_opt = argv[optind - 1];
                
                if ((!containsString(incorrect_options, incorrect_opt)) && (optind != 1)) {
                    addString(incorrect_options, incorrect_opt);
                }
                
                break;
            }
        }
    }
}




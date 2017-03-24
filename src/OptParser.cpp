#include "../include/OptParser.h"
#include <iostream>

bool CmdLineOptParser::Parse(int argc, char* argv[]){

    bool evaluator = true;
    if(argc > 1 ){
        for(int i=1; i<argc; i++){
            char* checkForFlag = argv[i];
            char printParameter='0';
            char* printArguments = NULL;

            if('-' == *checkForFlag){
                checkForFlag++;
                printParameter = *checkForFlag;
                if((printParameter >= 65 && printParameter <= 90) || (printParameter >= 97 && printParameter <= 122)) {
                    printf("flag: %c\t", printParameter);
                    checkForFlag++;

                    /*
                     * If there is a Whitespace at this point, it means it cant be of sort "-xWert" (Type 2)
                     */
                    if (*checkForFlag == '\0') {
                        //ToDo: dont count the pointer, find smth else to get next entry
                        checkForFlag++;

                        /*
                         * If there is a "-" at this point, it means it was of sort "-x" (Type 1)
                         * else the following are the Arguments (Typ 3)
                         */

                        if ('-' == *checkForFlag) {
                            printArguments = "Bool"; //ToDo: change to smth better
                        } else {
                            i++;
                            printArguments = checkForFlag;
                        }
                        /*
                         * If there is "=" at this point its an assignment of "printparameter" to the Arguments given after "=" (Typ 4)
                         */
                    } else if ('=' == *checkForFlag) {
                        checkForFlag++;
                        printArguments = checkForFlag;
                    } else {
                        printArguments = checkForFlag;
                    }
                }else{
                    printf("Not a char \n");
                    evaluator = false;
                }
            }else{
                printf("Not a valid option at this point \n");
                evaluator = false;
            }

            if(evaluator){
                Option(printParameter,printArguments);
                printf("Argument: %s\n", printArguments);
            }
        }

    }else{
        printf("No Parameters given \n");
    }

    return evaluator;
}

bool CmdLineOptParser::Option(const char C, const char * info) {

    (void) C;
    (void) info;
    //ToDo
    return true;
}





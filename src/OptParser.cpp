#include "../include/OptParser.h"

bool CmdLineOptParser::Parse(int argc, char* argv[]){

    bool evaluator = true;
    if(argc > 1 ){
        for(int i=1; i<argc; i++){
            char* checkForFlag = argv[i];
            char printParameter = 0;
            char* printArguments = nullptr;

            if('-' == *checkForFlag){
                checkForFlag++;
                if(*checkForFlag != '\0'){
                    printParameter = *checkForFlag;
                }else{

                    return false;
                }

                if((printParameter >= 65 && printParameter <= 90) || (printParameter >= 97 && printParameter <= 122)) {
                    checkForFlag++;

                    /*
                     * If there is a Whitespace at this point, it means it cant be of sort "-xWert" (Type 2)
                     */
                    if (*checkForFlag == '\0') {

                        if(argc > i+1) {
                            checkForFlag = argv[i+1];
                            /*
                             * If there is a "-" at this point, it means it was of sort "-x" (Type 1)
                             * else the following are the Arguments (Typ 3)
                             */

                            if ('-' == *checkForFlag) {
                                printArguments = (char *) "Bool";
                            } else {
                                i++;
                                printArguments = checkForFlag;
                            }


                        }else{
                            printArguments = (char *) "Bool";
                        }
                        /*
                         * If there is "=" at this point its an assignment of "printparameter" to the Arguments given after "=" (Typ 4)
                         */
                    } else if ('=' == *checkForFlag) {
                        checkForFlag++;
                        if(*checkForFlag != '\0'){
                            printArguments = checkForFlag;
                        }else{
                            return false;
                        }
                    } else {
                        printArguments = checkForFlag;
                    }
                }else{
                    evaluator = false;
                }
            }else{
                evaluator = false;
            }

            if(evaluator){
                Option(printParameter,printArguments);
            }
        }

    }else{
    }

    return evaluator;
}

bool CmdLineOptParser::Option(const char C, const char * info) {

    (void) C;
    (void) info;
    return true;
}




